//======================================================================
// File:		tipdlg.cpp
// Author:	Matthias Toussaint
// Created:	Sun Nov 11 19:59:19 CET 2001
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

#include "tipdlg.h"

const QStringList TipDlg::s_tipText = {
	tr("<font size=+2>Welcome</font><p>QtDMM is a small DMM "
	"(Digital Multi Meter) readout software for Linux/UNIX"
	" and since version 0.8.11 for Mac OSX. Windows is also supported since 0.9.5."
	" If you don't want to see the tips of the day you "
	"can switch them of with"
	" the checkbox below this text. The tips can be switched "
	"on again at any time"
	 " in the preferences dialog."),

	tr("<font size=+2>QtDMM can't connect?</font><p>"
	"Make shure you have read/write permission for the device"
	" the multimeter is connected to. In doubt call a:<br>"
		" <tt>chmod a+rw /dev/&lt;device&gt;</tt> (as root) under unix like systems.<br>"
	"<tt>&lt;device&gt;</tt> will be something like <tt>ttyS0</tt>"
	" or <tt>usb/ttyUSB0</tt>. This depend on your configuration. For Windows check the group policies."),

	tr("<font size=+2>Quick help</font><p>"
	"Click on the context help button in the titlebar of the window."
	" You can click any of the controls or windows of QtDMM to get"
	" context sensitive help. This works in all windows of QtDMM."
	" Most newer windowmangers support this feature. "),

	tr("<font size=+2>Preferences</font><p>"
	"To configure QtDMM go to the preferences dialog. The preferences"
	" dialog can be reached by <b>File->Configure</b>"),

	tr("<font size=+2>Measuring averaged values</font><p>"
		"If you want averaged values just increase the"
		"\"Sample every\" value in the Recorder settings."
		" If you set it to 10sec and your DMM gives a value"
		" approx. every second, you'll get the average of"
		" the ten last measurements in the graph"),

	tr("<font size=+2>Configuration file</font><p>"
	"QtDMM writes a small configuration file (/QtDMM/QtDMM.conf). The path of it is platfom depend. It contains"
	" informations about window settings and other preferences."
	" If you want to get rid of QtDMM don't"
	" forget to remove this file too.<br>If you want to stay with it, you may want "
	"to write an email to me explaining what could be improved.<br>"
	"Matthias Toussaint <font color=blue><u><a href='mailto:qtdmm@mtoussaint.de'>qtdmm@mtoussaint.de</a>"
	"</u></font>")};

TipDlg::TipDlg(QWidget *parent) :  QDialog( parent),
  m_numTips(0),
  m_curTip(0)
{
  setupUi(this);
  ui_tip->setStyleSheet(QString("background-color: %1;").arg(palette().background().color().name()));

  // count tips
  m_numTips=s_tipText.size();
  showTipText();
}

bool TipDlg::showTips() const
{
  return !ui_showTip->isChecked();
}

void TipDlg::setShowTipsSLOT( bool on )
{
  ui_showTip->setChecked( !on );
}

void TipDlg::on_ui_previousBut_clicked()
{
  --m_curTip;
  if (m_curTip < 0)
	  m_curTip = m_numTips-1;
  showTipText();
}

void TipDlg::on_ui_nextBut_clicked()
{
  ++m_curTip;
  m_curTip = m_curTip % m_numTips;
  showTipText();
}

void TipDlg::showTipText()
{
  ui_tip->setText( s_tipText[m_curTip] );
  Q_EMIT currentTip( m_curTip );
}

void TipDlg::setCurrentTip( int num )
{
  m_curTip = num;
  showTipText();
}

void TipDlg::on_ui_closeBut_clicked()
{
  on_ui_nextBut_clicked();
  hide();
}

void TipDlg::closeEvent( QCloseEvent *ev )
{
  on_ui_nextBut_clicked();
  ev->accept();
}

void TipDlg::on_ui_showTip_toggled( bool on )
{
  Q_EMIT showTips( !on );
}
