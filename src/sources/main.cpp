//======================================================================
// File:		main.cpp
// Author:	Matthias Toussaint
// Created:	Tue Apr 10 17:36:39 CEST 2001
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

#include "mainwin.h"
#include "config.h"


void myMessageOutput( QtMsgType type,const QMessageLogContext &, const QString &msg )
{
  switch ( type )
  {
	case QtDebugMsg:
#ifdef QT_DEBUG
		  qDebug()<<"Debug: "<<msg;
#endif
		break;
	case QtWarningMsg:
		if (msg.contains( "Absolute index" ))
			abort();
		else
			qWarning()<<"Warning: "<<msg;
		break;
	case QtFatalMsg:
		 qFatal(QString("Fatal: %1").arg(msg).toUtf8());
	case QtCriticalMsg:
		  qCritical()<<"Critial: "<<msg;
		break;
	case QtInfoMsg:
		  qInfo()<<"Info: "<<msg;
		break;
  }
}

int main( int argc, char **argv )
{
  qInstallMessageHandler( myMessageOutput );
  QApplication app( argc, argv );

  app.setApplicationName(APP_NAME);
  app.setApplicationVersion(APP_VERSION);
  app.setOrganizationName(APP_ORGANIZATION);

  QTranslator QtTranslation;
  QTranslator AppTranslation;

  QString QtTranslationPath=QLibraryInfo::location(QLibraryInfo::TranslationsPath);
  QString AppTranslationPath=QtTranslationPath;
#ifdef Q_OS_WIN
  AppTranslationPath="./";
#endif

  QtTranslation.load(QString("qt_%1").arg(QLocale::system().name()),QtTranslationPath);
  AppTranslation.load(QString("%1_%2").arg(app.applicationName().toLower()).arg(QLocale::system().name()),AppTranslationPath);

  if((!AppTranslation.isEmpty()) && (!QtTranslation.isEmpty()))
  {
	app.installTranslator(&QtTranslation);
	app.installTranslator(&AppTranslation);
  }
  MainWin mainWin;

  QCommandLineParser parser;
  parser.addOption(QCommandLineOption("console"));

  parser.process(app);
  if(parser.isSet("console"))
	mainWin.setConsoleLogging( true );
  mainWin.show();
  mainWin.move( 100, 100 );

  return app.exec();
}
