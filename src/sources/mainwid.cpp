//======================================================================
// File:		mainwid.cpp
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:29:01 CEST 2001
//----------------------------------------------------------------------
// This file is part of QtDMM.
//
// QtDMM is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 3
// as published by the Free Software Foundation.
//
// QtDMM is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
//----------------------------------------------------------------------
// Copyright (c) 2001 Matthias Toussaint
//======================================================================

#include <QtGui>
#include <QtWidgets>
#include <QPrinter>

#include "mainwid.h"
#include "dmmgraph.h"
#include "configdlg.h"
#include "dmm.h"
#include "displaywid.h"
#include "tipdlg.h"

MainWid::MainWid( QWidget *parent ) :  QFrame( parent ),
  m_display( 0 ),
  m_tipDlg( 0 )
{
  setupUi(this);
  setWindowIcon(QPixmap(":/Symbols/icon.xpm") );

  m_dmm = new DMM( this );
  m_external = new QProcess( this );

  m_configDlg = new ConfigDlg( this );
  m_configDlg->hide();

  m_configDlg->readPrinter( &m_printer );

  m_printDlg = new qtdmm::PrintDlg( this );
  m_printDlg->hide();

  connect( m_dmm, SIGNAL( value( double, const QString &, const QString &, const QString &, bool, int )),
		   this,  SLOT( valueSLOT( double, const QString &, const QString &, const QString &, bool, int )));
  connect( m_dmm, SIGNAL( error( const QString & ) ),this, SIGNAL( error( const QString & )));
  connect( ui_graph, SIGNAL( info( const QString & ) ),this, SIGNAL( info( const QString & ) ));
  connect( ui_graph, SIGNAL( error( const QString & ) ),this, SIGNAL( error( const QString & ) ));
  connect( ui_graph, SIGNAL( running( bool ) ),this, SLOT( runningSLOT( bool ) ));
  connect( m_configDlg, SIGNAL( accepted() ),this, SLOT( applySLOT() ));
  connect( m_configDlg, SIGNAL( zoomed() ), this, SLOT( zoomedSLOT() ));
  connect( ui_graph, SIGNAL( sampleTime( int ) ), m_configDlg, SLOT( setSampleTimeSLOT( int ) ));
  connect( ui_graph, SIGNAL( graphSize( int,int ) ), m_configDlg, SLOT( setGraphSizeSLOT( int,int ) ));
  connect( ui_graph, SIGNAL( externalTriggered() ),this, SLOT( startExternalSLOT() ));
  connect( m_external, SIGNAL( finished(int,QProcess::ExitStatus)), this, SLOT( exitedSLOT() ));
  connect( ui_graph, SIGNAL( configure() ), this, SLOT( configSLOT() ));
  connect( ui_graph, SIGNAL( exportData() ),this, SLOT( exportSLOT() ));
  connect( ui_graph, SIGNAL( importData() ), this, SLOT( importSLOT() ));

  connect( ui_graph, SIGNAL( connectDMM( bool ) ), this, SIGNAL( connectDMM( bool ) ));

  connect( ui_graph, SIGNAL( zoomOut( double ) ), m_configDlg, SLOT( zoomOutSLOT( double ) ));
  connect( ui_graph, SIGNAL( zoomIn( double ) ), m_configDlg, SLOT( zoomInSLOT( double ) ));
  connect( ui_graph, SIGNAL( thresholdChanged( DMMGraph::CursorMode, double ) ),
		   m_configDlg, SLOT( thresholdChangedSLOT( DMMGraph::CursorMode, double ) ));

  ui_graph->setSettings(m_configDlg->getSettings());

  //resetSLOT();

  startTimer( 100 );

  if (m_configDlg->showTip())
	showTipsSLOT();
}

QString MainWid::deviceListText() const
{
  return m_configDlg->deviceListText();
}

void MainWid::setConsoleLogging( bool on )
{
  m_dmm->setConsoleLogging( on );
}

void MainWid::setDisplay( DisplayWid *display )
{
  m_display = display;
}

bool MainWid::closeWin()
{
  m_dmm->close();
  m_configDlg->setWinRect( parentRect() );
  m_configDlg->on_ui_buttonBox_accepted();

  Q_EMIT setConnect( false );

  if (ui_graph->dirty() && m_configDlg->alertUnsavedData())
  {
	QMessageBox question( tr("QtDMM: Unsaved data" ),
						  tr("<font size=+2><b>Unsaved data</b></font><p>"
							 "You still have unsaved measured data in memory."
							 " If you quit now it will be lost."
							 "<p>Do you want to export your unsaved data first?" ),
							 QMessageBox::Information,
							 QMessageBox::Yes | QMessageBox::Default,
							 QMessageBox::No,
							 QMessageBox::Cancel | QMessageBox::Escape );

	question.setButtonText( QMessageBox::Yes, tr("Export data first") );
	question.setButtonText( QMessageBox::No, tr("Quit without saving") );
	question.setIconPixmap( QPixmap(":/Symbols/icon.xpm" ) );

	switch (question.exec())
	{
		case QMessageBox::Yes:
		  return ui_graph->exportDataSLOT();

		case QMessageBox::No:
		  break;

		case QMessageBox::Cancel:
		  return false;
	}
  }

  return true;
}

QRect MainWid::winRect() const
{
  return m_configDlg->winRect();
}

bool MainWid::saveWindowPosition() const
{
  return m_configDlg->saveWindowPosition();
}

bool MainWid::saveWindowSize() const
{
  return m_configDlg->saveWindowSize();
}

QRect MainWid::parentRect() const
{
  QRect fRect = parentWidget()->frameGeometry();
  QRect rect  = parentWidget()->rect();

  return QRect( fRect.x(), fRect.y(), rect.width(), rect.height() );
}

void MainWid::timerEvent( QTimerEvent * )
{
  ui_graph->addValue( m_dval );
}

void MainWid::valueSLOT( double dval, const QString & val, const QString & u,const QString & s,  bool showBar,int id )
{
/*  cerr << "valueSLOT " << dval
	   << " val=" << val.latin1()
	   << " u=" << u.latin1()
	   << " s=" << s.latin1()
	   << " showBar=" << showBar
	   << " id=" << id << endl;  */

  m_display->setShowBar( showBar );
  m_display->setValue( id, val );

  m_display->setMode( id, s );

  QString tmpUnit = u;

  m_display->setUnit( id, tmpUnit );

  if (0 == id)
  {
	if (m_lastUnit != s)
	{
	  resetSLOT();
	  ui_graph->setUnit( u );
	}
	m_lastUnit = s;

	if (dval > m_max)
	{
	  m_max = dval;
	  m_display->setMaxUnit( u );
	  m_display->setMaxValue( val );
	}

	if (dval < m_min)
	{
	  m_min = dval;
	  m_display->setMinUnit( u );
	  m_display->setMinValue( val );
	}

	m_dval = dval;
  }

  m_display->update();
}

void MainWid::resetSLOT()
{
  m_min =  1.0E20;
  m_max = -1.0E20;

  m_display->setMinValue( "" );
  m_display->setMaxValue( "" );
  m_display->setMinUnit( "" );
  m_display->setMaxUnit( "" );
}

void MainWid::connectSLOT( bool on )
{
  if (on)
  {
	m_dmm->open();
	ui_graph->clearSLOT();
  }
  else
  {
	m_dmm->close();
	ui_graph->stopSLOT();
  }

  m_configDlg->connectSLOT( on );

  ui_graph->connectSLOT( on );
}

void MainWid::quitSLOT()
{
  if (closeWin()) qApp->quit();
}

void MainWid::helpSLOT()
{
  QWhatsThis::enterWhatsThisMode();
}

void MainWid::configSLOT()
{
  m_configDlg->show();
  m_configDlg->raise();
}

void MainWid::configDmmSLOT()
{
  m_configDlg->show();
  m_configDlg->raise();

  m_configDlg->showPage( ConfigDlg::DMM );
}

void MainWid::configRecorderSLOT()
{
  m_configDlg->show();
  m_configDlg->raise();

  m_configDlg->showPage( ConfigDlg::Recorder );
}

void MainWid::applySLOT()
{
  readConfig();
  ui_graph->setAlertUnsaved( m_configDlg->alertUnsavedData() );
  m_dmm->setName( m_configDlg->dmmName() );
}

void MainWid::zoomedSLOT()
{
  ui_graph->setGraphSize( m_configDlg->windowSeconds(),
						  m_configDlg->totalSeconds() );
}

void MainWid::exportSLOT()
{
  ui_graph->exportDataSLOT();
}

void MainWid::importSLOT()
{
  ui_graph->importDataSLOT();
}

void MainWid::printSLOT()
{
  m_printDlg->setPrinter( &m_printer );

  if (m_printDlg->exec())
  {
	m_configDlg->writePrinter( &m_printer );
	ui_graph->print( &m_printer, m_printDlg->title(), m_printDlg->comment() );
  }
}

void MainWid::clearSLOT()
{
  ui_graph->clearSLOT();
}

void MainWid::startSLOT()
{
  ui_graph->startSLOT();
}

void MainWid::stopSLOT()
{
  ui_graph->stopSLOT();
}

void MainWid::readConfig()
{
  bool reopen = false;

  if (m_dmm->isOpen())
  {
	m_dmm->close();
	reopen = true;
  }

  m_dmm->setDevice( m_configDlg->device() );
  m_dmm->setSpeed( m_configDlg->speed() );
  m_dmm->setFormat( m_configDlg->format() );
  m_dmm->setPortSettings( static_cast<QSerialPort::DataBits>(m_configDlg->bits()), static_cast<QSerialPort::StopBits>(m_configDlg->stopBits()),
						  m_configDlg->parity(), m_configDlg->externalSetup(),
						  m_configDlg->rts(), m_configDlg->cts(),
						  m_configDlg->dsr(), m_configDlg->dtr()
						);

  ui_graph->setGraphSize( m_configDlg->windowSeconds(),
						  m_configDlg->totalSeconds() );
  ui_graph->setStartTime( m_configDlg->startTime() );
  ui_graph->setMode( m_configDlg->sampleMode() );

  ui_graph->setSampleTime( m_configDlg->sampleStep() );
  ui_graph->setSampleLength( m_configDlg->sampleLength() );

  ui_graph->setCrosshair( m_configDlg->crosshair() );

  ui_graph->setThresholds( m_configDlg->fallingThreshold(),
						   m_configDlg->raisingThreshold() );

  ui_graph->setScale( m_configDlg->automaticScale(),
					  m_configDlg->includeZero(),
					  m_configDlg->scaleMin(),
					  m_configDlg->scaleMax() );

  ui_graph->setColors( m_configDlg->bgColor(),
					   m_configDlg->gridColor(),
					   m_configDlg->dataColor(),
					   m_configDlg->cursorColor(),
					   m_configDlg->startColor(),
					   m_configDlg->externalColor(),
					   m_configDlg->intColor(),
					   m_configDlg->intThresholdColor() );

  ui_graph->setExternal( m_configDlg->startExternal(),
						 m_configDlg->externalFalling(),
						 m_configDlg->externalThreshold() );

  ui_graph->setLineStyle( m_configDlg->lineMode(),
						  m_configDlg->pointMode(),
						  m_configDlg->intLineMode(),
						  m_configDlg->intPointMode() );

  QPalette cg = palette();
  cg.setColor( QPalette::Window, m_configDlg->displayBgColor() );
  cg.setColor( QPalette::WindowText, m_configDlg->displayTextColor() );

  m_display->setPalette(cg);
  m_display->setDisplayMode( m_configDlg->display(), m_configDlg->showMinMax(),
							 m_configDlg->showBar(), m_configDlg->numValues() );
  m_dmm->setNumValues( m_configDlg->numValues() );

  ui_graph->setLine( m_configDlg->lineWidth(), m_configDlg->intLineWidth() );

  ui_graph->setIntegration( m_configDlg->showIntegration(),
							m_configDlg->intScale(),
							m_configDlg->intThreshold(),
							m_configDlg->intOffset() );

  if (m_configDlg->sampleMode() == DMMGraph::Time)
	  Q_EMIT info( tr("Automatic start at %1").arg(m_configDlg->startTime().toString()) );
  else if (m_configDlg->sampleMode() == DMMGraph::Raising)
	  Q_EMIT info( tr("Raising threshold %1").arg(m_configDlg->raisingThreshold()) );
  else if (m_configDlg->sampleMode() == DMMGraph::Falling)
	  Q_EMIT info( tr("Falling threshold %1").arg(m_configDlg->fallingThreshold()) );
  Q_EMIT useTextLabel( m_configDlg->useTextLabel() );
  Q_EMIT toolbarVisibility( m_configDlg->showDisplay(),
						  m_configDlg->showDmmToolbar(),
						  m_configDlg->showGraphToolbar(),
						  m_configDlg->showFileToolbar(),
						  m_configDlg->showHelpToolbar() );

  if (reopen)
	m_dmm->open();
}

void MainWid::runningSLOT( bool on )
{
  Q_EMIT running( on );
}

void MainWid::startExternalSLOT()
{
  if (m_external->state() == QProcess::Running)
  {
	QMessageBox question( tr("QtDMM: Launch error" ),
						  tr("<font size=+2><b>Launch error</b></font><p>"
							 "Application %1 is still running!<p>"
							 "Do you want to kill it now").arg(m_configDlg->externalCommand()),
						  QMessageBox::Information,
						  QMessageBox::Yes | QMessageBox::Default,
						  QMessageBox::No,
						  Qt::NoButton );

	question.setButtonText( QMessageBox::Yes, tr("Yes, kill it!") );
	question.setButtonText( QMessageBox::Yes, tr("No, keep running") );
	question.setIconPixmap( QPixmap(":/Symbols/icon.xpm" ) );

	switch (question.exec())
	{
		case QMessageBox::Yes:
		  m_external->kill();
		  break;
		default:
		  return;
	}
  }

  if (m_configDlg->disconnectExternal())
	Q_EMIT setConnect( false );

  QStringList args;
  args.append( m_configDlg->externalCommand() );
  m_external->setArguments( args );

  // mt: call with empty string
  m_external->start();
  if (m_external->state() != QProcess::Starting)
  {
	QMessageBox question( tr("QtDMM: Launch error" ),
						  tr("<font size=+2><b>Launch error</b></font><p>"
							 "Couldn't launch %1").arg(m_configDlg->externalCommand()),
						  QMessageBox::Information,
						  QMessageBox::Yes | QMessageBox::Default,
						  Qt::NoButton,
						  Qt::NoButton );

	question.setButtonText( QMessageBox::Yes, tr("Bummer!") );
	question.setIconPixmap( QPixmap(":/Symbols/icon.xpm" ) );

	question.exec();
  }
  else
	  Q_EMIT error( tr("Launched %1").arg(m_configDlg->externalCommand()) );
}

void MainWid::exitedSLOT()
{
  Q_EMIT error( tr("%1 terminated with exit code %2.").arg(m_configDlg->externalCommand()).arg(m_external->exitStatus()) );
}

void MainWid::showTipsSLOT()
{
  if (!m_tipDlg)
  {
	m_tipDlg = new TipDlg( this );

	m_tipDlg->setShowTipsSLOT( m_configDlg->showTip() );
	m_tipDlg->setCurrentTip( m_configDlg->currentTipId() );

	connect( m_tipDlg, SIGNAL( showTips( bool ) ),
			 m_configDlg, SLOT( setShowTipsSLOT( bool ) ));
	connect( m_configDlg, SIGNAL( showTips( bool ) ),
			 m_tipDlg, SLOT( setShowTipsSLOT( bool ) ));
	connect( m_tipDlg, SIGNAL( currentTip( int ) ),
			 m_configDlg, SLOT( setCurrentTipSLOT( int ) ));

  }

  m_tipDlg->show();
}

void MainWid::setToolbarVisibility( bool disp, bool dmm, bool graph, bool file, bool help )
{
  m_configDlg->setToolbarVisibility( disp, dmm, graph, file, help );
}
