#ifndef UITIPDLG_H
#define UITIPDLG_H

#include <qvariant.h>


#include <Qt3Support/Q3TextView>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UITipDlg
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    Q3TextView *ui_tip;
    QVBoxLayout *vboxLayout1;
    QLabel *ui_logo;
    QSpacerItem *Spacer2;
    QHBoxLayout *hboxLayout1;
    QCheckBox *ui_showTip;
    QPushButton *ui_previousBut;
    QPushButton *ui_nextBut;
    QSpacerItem *Spacer1;
    QPushButton *ui_closeBut;

    void setupUi(QDialog *UITipDlg)
    {
        if (UITipDlg->objectName().isEmpty())
            UITipDlg->setObjectName(QString::fromUtf8("UITipDlg"));
        UITipDlg->resize(510, 246);
        UITipDlg->setWindowIcon(qt_get_icon(image0_ID));
        vboxLayout = new QVBoxLayout(UITipDlg);
        vboxLayout->setSpacing(5);
        vboxLayout->setContentsMargins(10, 10, 10, 10);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(5);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        ui_tip = new Q3TextView(UITipDlg);
        ui_tip->setObjectName(QString::fromUtf8("ui_tip"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ui_tip->sizePolicy().hasHeightForWidth());
        ui_tip->setSizePolicy(sizePolicy);
        ui_tip->setMinimumSize(QSize(400, 50));
        ui_tip->setMaximumSize(QSize(32767, 32767));
        ui_tip->setFrameShape(QFrame::NoFrame);
        ui_tip->setResizePolicy(Q3ScrollView::Manual);
        ui_tip->setVScrollBarMode(Q3ScrollView::AlwaysOff);
        ui_tip->setHScrollBarMode(Q3ScrollView::AlwaysOff);

        hboxLayout->addWidget(ui_tip);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(0);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        ui_logo = new QLabel(UITipDlg);
        ui_logo->setObjectName(QString::fromUtf8("ui_logo"));
        ui_logo->setMargin(3);
        ui_logo->setPixmap(qt_get_icon(image1_ID));
        ui_logo->setScaledContents(true);
        ui_logo->setWordWrap(false);

        vboxLayout1->addWidget(ui_logo);

        Spacer2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(Spacer2);


        hboxLayout->addLayout(vboxLayout1);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(5);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        ui_showTip = new QCheckBox(UITipDlg);
        ui_showTip->setObjectName(QString::fromUtf8("ui_showTip"));

        hboxLayout1->addWidget(ui_showTip);

        ui_previousBut = new QPushButton(UITipDlg);
        ui_previousBut->setObjectName(QString::fromUtf8("ui_previousBut"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ui_previousBut->sizePolicy().hasHeightForWidth());
        ui_previousBut->setSizePolicy(sizePolicy1);
        ui_previousBut->setAutoDefault(false);

        hboxLayout1->addWidget(ui_previousBut);

        ui_nextBut = new QPushButton(UITipDlg);
        ui_nextBut->setObjectName(QString::fromUtf8("ui_nextBut"));
        sizePolicy1.setHeightForWidth(ui_nextBut->sizePolicy().hasHeightForWidth());
        ui_nextBut->setSizePolicy(sizePolicy1);
        ui_nextBut->setAutoDefault(false);

        hboxLayout1->addWidget(ui_nextBut);

        Spacer1 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(Spacer1);

        ui_closeBut = new QPushButton(UITipDlg);
        ui_closeBut->setObjectName(QString::fromUtf8("ui_closeBut"));
        ui_closeBut->setDefault(true);

        hboxLayout1->addWidget(ui_closeBut);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(UITipDlg);

        QMetaObject::connectSlotsByName(UITipDlg);
    } // setupUi

    void retranslateUi(QDialog *UITipDlg)
    {
        UITipDlg->setWindowTitle(QApplication::translate("UITipDlg", "QtDMM: Tip of the day", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ui_logo->setProperty("whatsThis", QVariant(QApplication::translate("UITipDlg", "Calvin :)", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_WHATSTHIS
        ui_showTip->setText(QApplication::translate("UITipDlg", "Don't show tips again", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ui_showTip->setProperty("whatsThis", QVariant(QApplication::translate("UITipDlg", "<font size=+1><b>Don't show tips again</b></font><p>Check this if you don't want to see the tip of the day at startup. You can activate the tips at any time in the preferences again.", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_WHATSTHIS
        ui_previousBut->setText(QApplication::translate("UITipDlg", "&Previous", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ui_previousBut->setProperty("whatsThis", QVariant(QApplication::translate("UITipDlg", "<font size=+1><b>Previous</b></font><p>Go to previous tip.", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_WHATSTHIS
        ui_nextBut->setText(QApplication::translate("UITipDlg", "&Next", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ui_nextBut->setProperty("whatsThis", QVariant(QApplication::translate("UITipDlg", "<font size=+1><b>Next</b></font><p>Go to next tip.", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_WHATSTHIS
        ui_closeBut->setText(QApplication::translate("UITipDlg", "&Close", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ui_closeBut->setProperty("whatsThis", QVariant(QApplication::translate("UITipDlg", "<font size=+1><b>Close</b></font><p>Close this dialog.", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi


protected:
    enum IconID
    {
        image0_ID,
        image1_ID,
        unknown_ID
    };
    static QPixmap qt_get_icon(IconID id)
    {
    static const unsigned char image0_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20,
    0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 0x7a, 0x7a, 0xf4, 0x00, 0x00, 0x01,
    0xff, 0x49, 0x44, 0x41, 0x54, 0x78, 0x9c, 0xc5, 0x57, 0x3d, 0x4e, 0xc3,
    0x30, 0x18, 0x7d, 0x46, 0x5c, 0xa0, 0x48, 0xec, 0x44, 0x42, 0xec, 0xd9,
    0xc8, 0x97, 0x13, 0x70, 0x84, 0x96, 0x23, 0x24, 0x13, 0x15, 0x13, 0xea,
    0x84, 0x98, 0x10, 0x4c, 0xc9, 0x09, 0x50, 0x92, 0x23, 0x70, 0x82, 0xa4,
    0x6c, 0x19, 0x41, 0x15, 0x12, 0xbd, 0x89, 0x19, 0x8a, 0x8d, 0x71, 0xfc,
    0x97, 0x12, 0xc4, 0x93, 0x2a, 0xc7, 0xf6, 0x27, 0xbf, 0xf7, 0xbd, 0x2f,
    0xb5, 0x1d, 0xd6, 0x75, 0x1d, 0xfe, 0x13, 0x87, 0xb6, 0x09, 0x22, 0xe2,
    0x53, 0x93, 0x75, 0x5d, 0xc7, 0x82, 0x04, 0x10, 0x11, 0xbf, 0x59, 0xdd,
    0x4c, 0xcd, 0x0f, 0x22, 0xe2, 0xba, 0x88, 0x81, 0x00, 0x41, 0xfe, 0xf1,
    0xfe, 0x31, 0xb9, 0x80, 0xe4, 0x3c, 0x19, 0x88, 0xb0, 0x96, 0x00, 0x00,
    0xea, 0xa6, 0x9e, 0x8c, 0x7c, 0x31, 0x5f, 0x18, 0xc7, 0x9d, 0x02, 0x00,
    0xa0, 0xdd, 0xb4, 0xbf, 0x26, 0x4f, 0xcf, 0x52, 0xeb, 0xdc, 0x41, 0xe8,
    0x02, 0xe2, 0x67, 0x5a, 0x58, 0x6d, 0xd5, 0x38, 0x17, 0xf1, 0x28, 0x01,
    0xed, 0xa6, 0x0d, 0x72, 0x22, 0x34, 0x4e, 0x85, 0xb7, 0x04, 0x80, 0x3b,
    0x13, 0x75, 0x2e, 0x24, 0xe3, 0xbd, 0x04, 0x88, 0xac, 0x74, 0x02, 0xd3,
    0xf8, 0x58, 0x07, 0x46, 0xbd, 0x03, 0x6a, 0x3f, 0x34, 0xd6, 0x87, 0x51,
    0x0e, 0xf8, 0xfa, 0xbe, 0x38, 0x13, 0x82, 0x1d, 0xe8, 0x9f, 0x7b, 0x63,
    0xfb, 0x5b, 0x04, 0x09, 0xf8, 0x4b, 0x8c, 0x2a, 0x41, 0x7b, 0x61, 0x6e,
    0xff, 0x54, 0xc0, 0x14, 0x36, 0xef, 0x2d, 0xc0, 0xb6, 0x7f, 0x4f, 0x09,
    0xe7, 0x3b, 0x50, 0x35, 0x35, 0xaa, 0x09, 0x0f, 0xa4, 0x28, 0x8a, 0x06,
    0x63, 0x56, 0x07, 0xaa, 0xa6, 0x06, 0x38, 0x07, 0x18, 0x43, 0xd5, 0xd4,
    0xb8, 0x74, 0xb8, 0x11, 0x7a, 0x6a, 0x26, 0xe7, 0x49, 0xb8, 0x00, 0x89,
    0x2f, 0x11, 0x2e, 0xd2, 0xa2, 0x2c, 0x82, 0x04, 0x54, 0x4f, 0x55, 0xb8,
    0x80, 0xcb, 0xf9, 0x02, 0xd5, 0x17, 0xb1, 0xc8, 0x3e, 0x84, 0x34, 0x9b,
    0xe7, 0x28, 0x9b, 0xef, 0xb9, 0xfc, 0x36, 0xdb, 0xc5, 0xaf, 0x4a, 0x63,
    0x3c, 0xd3, 0x2f, 0xa5, 0x44, 0xc4, 0xf5, 0x97, 0x4f, 0x10, 0xfb, 0x32,
    0xcd, 0xe6, 0xb9, 0x7c, 0x2e, 0x9b, 0x42, 0x92, 0x0b, 0x24, 0x27, 0x84,
    0xf5, 0xcb, 0x1a, 0xde, 0x1b, 0x51, 0x74, 0x1a, 0xe1, 0xee, 0xf6, 0x4e,
    0xf6, 0x4d, 0xc4, 0x71, 0x1c, 0x03, 0x00, 0xfa, 0xbe, 0x97, 0x7d, 0x35,
    0xf3, 0x50, 0x58, 0x4b, 0x60, 0x23, 0x15, 0x84, 0xa2, 0x15, 0xd0, 0xfb,
    0x71, 0x1c, 0xa3, 0x58, 0x95, 0x3f, 0x4a, 0x50, 0x3d, 0x8d, 0x10, 0xa0,
    0xd7, 0x52, 0x25, 0x51, 0xad, 0xee, 0xde, 0x5a, 0x63, 0x8c, 0x4c, 0xc4,
    0x52, 0x7b, 0xaf, 0x00, 0x01, 0x35, 0x6b, 0x61, 0xbb, 0x2f, 0xde, 0x24,
    0x64, 0x2f, 0x01, 0x36, 0x72, 0x76, 0xa4, 0x46, 0x69, 0x97, 0x94, 0x6e,
    0xe7, 0x48, 0x7e, 0x9f, 0xa1, 0xb8, 0x2e, 0x07, 0xeb, 0xe8, 0x70, 0xee,
    0x84, 0x26, 0xf2, 0x94, 0xdc, 0x67, 0x43, 0x4a, 0x29, 0xd2, 0x05, 0x49,
    0x11, 0x3e, 0x04, 0x9d, 0x86, 0xea, 0xe2, 0x9c, 0x73, 0x30, 0xc6, 0x8c,
    0xbb, 0xda, 0xfa, 0x65, 0xbd, 0x7b, 0xd8, 0x32, 0xe0, 0xe4, 0xfb, 0xcb,
    0xce, 0x55, 0x0e, 0xef, 0x7d, 0x20, 0xcb, 0x72, 0x10, 0xa5, 0x32, 0x73,
    0x4a, 0x08, 0x9c, 0x73, 0xbc, 0xbe, 0xbf, 0x0e, 0x62, 0x7f, 0x88, 0xda,
    0xee, 0xfe, 0xea, 0x3e, 0x17, 0xf6, 0xba, 0x90, 0xcc, 0x8e, 0x67, 0x00,
    0xe0, 0x17, 0x11, 0x80, 0xc1, 0x4e, 0xb8, 0xbc, 0x5a, 0x4e, 0xfe, 0x55,
    0xac, 0xe3, 0xe1, 0xf1, 0x41, 0xee, 0x84, 0x9f, 0xc0, 0x01, 0xed, 0xdc,
    0x05, 0x2a, 0x55, 0xeb, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44,
    0xae, 0x42, 0x60, 0x82
};

    static const unsigned char image1_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x30,
    0x08, 0x06, 0x00, 0x00, 0x00, 0x57, 0x02, 0xf9, 0x87, 0x00, 0x00, 0x06,
    0xe9, 0x49, 0x44, 0x41, 0x54, 0x78, 0x9c, 0xd5, 0x99, 0x6d, 0x6c, 0x53,
    0xd7, 0x19, 0xc7, 0x7f, 0xa9, 0x0a, 0x24, 0x8e, 0xad, 0x24, 0xbe, 0xd7,
    0x2f, 0x59, 0xad, 0x14, 0x02, 0x26, 0xa4, 0xa4, 0x05, 0xb5, 0xac, 0xd4,
    0x8b, 0xd6, 0x04, 0xcf, 0x95, 0x98, 0x48, 0x61, 0x74, 0xa8, 0x1d, 0x53,
    0xa5, 0xb6, 0x6a, 0x36, 0xb6, 0xf1, 0x6d, 0x9a, 0xb4, 0x09, 0x8d, 0x55,
    0x53, 0xd7, 0xaa, 0x93, 0x86, 0xc4, 0x87, 0x6d, 0x88, 0x35, 0x12, 0xa1,
    0xb4, 0x42, 0x53, 0x4b, 0x8b, 0x42, 0x90, 0x3a, 0x0d, 0x41, 0x42, 0x47,
    0xc6, 0xeb, 0xc0, 0x2c, 0xa4, 0x49, 0x93, 0x36, 0x64, 0x9a, 0x14, 0x3b,
    0x7e, 0x4b, 0xe4, 0x37, 0x20, 0x51, 0xbd, 0x0f, 0x97, 0x7b, 0xb9, 0xd7,
    0xb9, 0xd7, 0x6f, 0x71, 0x3a, 0xfa, 0x97, 0x2c, 0x1d, 0x9d, 0xf3, 0xdc,
    0xc7, 0xff, 0xff, 0x39, 0xcf, 0x79, 0xce, 0x5b, 0xc5, 0xc0, 0xc0, 0x00,
    0x5f, 0x67, 0x3c, 0xf0, 0xff, 0x26, 0xb0, 0x50, 0x3c, 0x58, 0xa8, 0x61,
    0x5b, 0x5b, 0x7b, 0x66, 0x31, 0x89, 0xe4, 0x42, 0x7f, 0x7f, 0x5f, 0x85,
    0x51, 0x5b, 0x41, 0x02, 0x7e, 0xf0, 0xc2, 0x0b, 0x19, 0x8f, 0xa7, 0xb5,
    0x7c, 0x8c, 0x8a, 0x44, 0x5b, 0x5b, 0x7b, 0xc6, 0x48, 0x44, 0x5e, 0x01,
    0x6d, 0x6d, 0xed, 0x19, 0x8f, 0xa7, 0x15, 0x9f, 0xcf, 0x57, 0x7e, 0x66,
    0x05, 0x20, 0x99, 0x0e, 0x33, 0x34, 0x3c, 0x64, 0x28, 0xa2, 0x22, 0xd7,
    0x24, 0xfe, 0x6e, 0xc7, 0x96, 0xcc, 0xf3, 0x3b, 0x76, 0x2c, 0x2a, 0xc1,
    0x7c, 0x88, 0x86, 0x22, 0x84, 0x22, 0x31, 0x86, 0x86, 0x87, 0x98, 0x89,
    0xc5, 0xe6, 0x85, 0x93, 0xe1, 0x08, 0xb4, 0xb5, 0xb5, 0x67, 0x4c, 0x96,
    0x6a, 0xac, 0x82, 0x19, 0x80, 0xb1, 0xe1, 0x09, 0x3e, 0x1d, 0x19, 0x25,
    0x11, 0x9f, 0x5e, 0x64, 0xca, 0x12, 0xcc, 0x96, 0x5a, 0x44, 0x51, 0xc4,
    0x26, 0xd4, 0x01, 0x60, 0x5a, 0xb6, 0x94, 0x19, 0x1d, 0xbb, 0x82, 0x27,
    0x31, 0xc0, 0xe8, 0xe8, 0x08, 0x00, 0x35, 0x75, 0x75, 0x0b, 0x26, 0x98,
    0x0b, 0xb3, 0x73, 0x77, 0x98, 0x0c, 0x04, 0x01, 0x14, 0x01, 0x46, 0x28,
    0x4a, 0x00, 0xc0, 0xe9, 0xc1, 0x53, 0xa5, 0xb1, 0x2a, 0x12, 0x1d, 0x9e,
    0x6d, 0x05, 0x8d, 0xf6, 0x7d, 0xbb, 0x0e, 0x2c, 0x79, 0x70, 0x69, 0x41,
    0x76, 0x25, 0x0b, 0xd8, 0xb5, 0x7d, 0x37, 0xde, 0x16, 0x9f, 0xf2, 0xd3,
    0x83, 0xba, 0x5e, 0x5d, 0x36, 0xfa, 0xd6, 0xc8, 0x4f, 0x2e, 0x14, 0x1d,
    0x42, 0x32, 0x0e, 0x7e, 0xf4, 0xa7, 0xa2, 0xfe, 0xd8, 0x64, 0xa9, 0x2e,
    0xf9, 0xdb, 0x5c, 0xf8, 0xca, 0x42, 0x28, 0x15, 0x4f, 0x2e, 0x8a, 0xdf,
    0x92, 0x47, 0x60, 0xd7, 0xf6, 0xdd, 0x8c, 0x8e, 0x8e, 0x68, 0x7a, 0x56,
    0x0f, 0x7a, 0x3d, 0xbc, 0xd0, 0x5e, 0x57, 0xa3, 0x2c, 0x21, 0xd4, 0xe1,
    0xd9, 0xa6, 0x6b, 0xa3, 0xce, 0x58, 0xd9, 0xa4, 0xcb, 0x95, 0xcd, 0xca,
    0x12, 0x42, 0x8b, 0x15, 0x1e, 0x85, 0x60, 0xc1, 0x21, 0x94, 0x0d, 0x6f,
    0x8b, 0x4f, 0xb7, 0x77, 0xdd, 0xee, 0x26, 0xa5, 0xec, 0xf1, 0xb4, 0x6a,
    0x46, 0x44, 0xb6, 0x57, 0xdb, 0x14, 0x8a, 0xb2, 0x84, 0x90, 0x1a, 0x46,
    0xa1, 0xa1, 0xb6, 0x7f, 0xe3, 0xed, 0xdf, 0x16, 0xe5, 0x33, 0x17, 0xee,
    0xdb, 0x85, 0xac, 0x50, 0x94, 0x2c, 0x40, 0xbd, 0x08, 0xe5, 0x2a, 0x2f,
    0x36, 0xbe, 0xf6, 0x23, 0x50, 0xf2, 0x1c, 0x50, 0xc7, 0x7a, 0x21, 0xe5,
    0xc5, 0xc2, 0x7d, 0x3b, 0x02, 0xb3, 0x73, 0x77, 0x0a, 0xb2, 0x2b, 0x7a,
    0x04, 0xbc, 0x2d, 0xbe, 0xaf, 0xe4, 0x3c, 0x90, 0x8a, 0x27, 0x79, 0xc8,
    0xe9, 0xca, 0x6b, 0x5b, 0x94, 0x00, 0x39, 0x4f, 0x2f, 0xfa, 0xa9, 0x6c,
    0xd9, 0x52, 0x1e, 0x72, 0xba, 0x10, 0x45, 0x31, 0xaf, 0x69, 0x51, 0x02,
    0x9a, 0x9b, 0xdc, 0x4a, 0xd9, 0x6a, 0x13, 0x8a, 0x27, 0x56, 0x02, 0xa2,
    0xa1, 0x48, 0xce, 0xf6, 0xa2, 0x04, 0x74, 0x9d, 0x39, 0xad, 0x94, 0x3b,
    0x37, 0x79, 0xb1, 0xda, 0x84, 0xbc, 0x7f, 0x20, 0xa3, 0x54, 0xc1, 0x56,
    0x9b, 0x80, 0xd5, 0x26, 0x10, 0x0e, 0x87, 0xe1, 0xee, 0x31, 0x53, 0x8d,
    0x82, 0x04, 0xac, 0xfa, 0xf4, 0x3f, 0x6c, 0x8b, 0xcf, 0x51, 0xd3, 0xd9,
    0xc9, 0xf9, 0xab, 0x9f, 0xd1, 0x7c, 0xe5, 0x2c, 0x1d, 0x97, 0x2e, 0x32,
    0xb7, 0x61, 0x23, 0x17, 0xed, 0xf3, 0x45, 0x64, 0x93, 0x8d, 0x86, 0x22,
    0x9c, 0xfb, 0xc7, 0xf9, 0x92, 0x42, 0xcf, 0x6c, 0xa9, 0xd5, 0x8c, 0x7c,
    0x49, 0x02, 0xd6, 0xc6, 0x67, 0x69, 0xbe, 0x72, 0x16, 0xde, 0xef, 0x26,
    0x75, 0xf9, 0x14, 0x3c, 0x7f, 0x96, 0xef, 0x25, 0x12, 0x1c, 0xbf, 0x7c,
    0x81, 0xe8, 0x37, 0x9f, 0x9c, 0x67, 0x2f, 0x0b, 0xea, 0xe9, 0xed, 0x9d,
    0xd7, 0x96, 0x6f, 0xfb, 0xad, 0x46, 0x2a, 0x9e, 0xc4, 0x94, 0x4c, 0x20,
    0x8a, 0xa2, 0xa1, 0xf8, 0xe2, 0xb3, 0xd0, 0x06, 0x1f, 0x03, 0x27, 0x7a,
    0x58, 0xfb, 0xec, 0x56, 0xa5, 0x4e, 0xdd, 0xe3, 0xdd, 0x87, 0x0e, 0xe3,
    0x76, 0x37, 0x69, 0x36, 0x7a, 0x26, 0x4b, 0x35, 0x3f, 0xd9, 0xf5, 0x32,
    0xd5, 0x55, 0xf9, 0x27, 0x65, 0x36, 0x92, 0xe9, 0x30, 0xff, 0x3c, 0x77,
    0x8d, 0xd4, 0x6d, 0xfd, 0xb4, 0x5a, 0x90, 0x80, 0x1b, 0x96, 0x25, 0xf0,
    0xc4, 0xd3, 0x3c, 0xf5, 0xe6, 0x9b, 0x20, 0x8a, 0x7c, 0x0b, 0x38, 0xff,
    0xc4, 0xd3, 0xcc, 0x59, 0x96, 0x00, 0x19, 0x25, 0x3c, 0x26, 0x03, 0x41,
    0xea, 0x9d, 0x0e, 0x85, 0xbc, 0x7c, 0x1d, 0x69, 0x13, 0xea, 0x68, 0x70,
    0xad, 0xc6, 0x61, 0x33, 0x11, 0x0c, 0xa5, 0x00, 0x68, 0x72, 0x0b, 0xd8,
    0x6a, 0x3e, 0x60, 0x74, 0x62, 0x0b, 0xc1, 0x50, 0x0a, 0x87, 0xcd, 0x04,
    0xc0, 0xd0, 0xf0, 0x7f, 0x39, 0xf7, 0xef, 0xcd, 0x00, 0xb4, 0x3e, 0xfa,
    0x31, 0x0d, 0xae, 0xd5, 0x8c, 0x09, 0x13, 0x86, 0xdc, 0xf2, 0x0a, 0x88,
    0x46, 0x12, 0x8c, 0x35, 0x37, 0xf0, 0xf1, 0xf0, 0x04, 0x5d, 0x5d, 0x5d,
    0x4a, 0xfd, 0xbe, 0x4d, 0x5e, 0x7a, 0x7a, 0x4f, 0x00, 0xd2, 0x3d, 0xd1,
    0x4c, 0x2c, 0x06, 0xc0, 0x64, 0x20, 0xc8, 0xd6, 0x8e, 0x0e, 0x76, 0xee,
    0x94, 0x0e, 0x39, 0x32, 0xe1, 0xec, 0x72, 0x83, 0xfd, 0x2d, 0x56, 0x36,
    0x0e, 0x32, 0x3a, 0xb1, 0x45, 0xd3, 0x76, 0xfa, 0x5f, 0xcf, 0xf1, 0xc9,
    0x05, 0x29, 0x5d, 0xdf, 0x9e, 0x35, 0xe1, 0x7d, 0xfc, 0xc3, 0x9c, 0xfc,
    0x72, 0x0a, 0x48, 0xc5, 0x93, 0x4a, 0x3c, 0x5b, 0x6d, 0x02, 0x9d, 0x9b,
    0xbc, 0x6c, 0xce, 0x54, 0xf0, 0xb3, 0x93, 0x27, 0x30, 0xf5, 0x9f, 0x51,
    0xec, 0x5e, 0x7d, 0xf5, 0x87, 0x9a, 0xf0, 0x10, 0x04, 0xab, 0x86, 0x6c,
    0x36, 0x9e, 0x69, 0x7d, 0x9b, 0x95, 0x8d, 0x83, 0x00, 0x6c, 0xdf, 0xfc,
    0x23, 0xae, 0xf9, 0xdb, 0x39, 0x79, 0xa6, 0x8d, 0x03, 0xc7, 0x76, 0x32,
    0x35, 0xb5, 0x5c, 0xb1, 0xfb, 0xe4, 0x42, 0x13, 0x23, 0xe3, 0x3b, 0x71,
    0xd7, 0x9c, 0x2a, 0xed, 0x66, 0xce, 0x64, 0xa9, 0xc6, 0x6a, 0x13, 0xe8,
    0x3e, 0x74, 0x98, 0x7a, 0xa7, 0x03, 0xb3, 0xa5, 0x96, 0x9e, 0xbb, 0xe1,
    0x91, 0x8a, 0x27, 0xf1, 0x78, 0x5a, 0x75, 0xc3, 0x43, 0x0e, 0x07, 0x19,
    0xea, 0xfa, 0xda, 0xda, 0x2a, 0xe2, 0x71, 0x91, 0x6b, 0xfe, 0x76, 0x89,
    0xc0, 0xd2, 0x5a, 0x62, 0xe9, 0x1d, 0xc0, 0xa8, 0x86, 0xbc, 0x8c, 0xa9,
    0xa9, 0xe5, 0xb8, 0x6b, 0x8c, 0x39, 0xe6, 0x0d, 0x21, 0xf9, 0x6e, 0x74,
    0x32, 0x10, 0x54, 0xf2, 0x70, 0xbd, 0xd3, 0xc1, 0x2f, 0x7f, 0xb5, 0x47,
    0x43, 0x3a, 0xbb, 0xc7, 0x9d, 0xf5, 0x2b, 0x00, 0x08, 0x4c, 0x8e, 0xcf,
    0xf3, 0x79, 0xfe, 0xfa, 0xf6, 0xac, 0x9a, 0x08, 0x82, 0x60, 0xc5, 0x6e,
    0xbf, 0x39, 0x4f, 0x84, 0xdd, 0x7e, 0x33, 0x27, 0xbf, 0x82, 0xe6, 0xc0,
    0xde, 0xbd, 0xaf, 0xe9, 0xb6, 0xa9, 0x27, 0xe4, 0xf4, 0x74, 0x5a, 0x23,
    0x26, 0x18, 0xba, 0xa1, 0x6b, 0xaf, 0x17, 0x5a, 0xf2, 0xc8, 0xfc, 0xfa,
    0xc7, 0x7f, 0xe3, 0xfd, 0xbf, 0xb7, 0x2b, 0x73, 0xe0, 0xdb, 0x1b, 0x47,
    0xf0, 0x3e, 0xfe, 0x21, 0xfe, 0xab, 0x75, 0x0c, 0x0d, 0x2f, 0x20, 0x0b,
    0x3d, 0xb2, 0xc6, 0x85, 0xfb, 0xe1, 0x93, 0x4a, 0xc6, 0xc8, 0x86, 0x9a,
    0xfc, 0x53, 0x8f, 0x7d, 0xa4, 0x69, 0x8b, 0xa5, 0x3b, 0x99, 0x9e, 0x4e,
    0xeb, 0xfa, 0x55, 0xfb, 0xaa, 0xac, 0x72, 0xe2, 0xb0, 0xa5, 0xd9, 0xd8,
    0xfc, 0x17, 0x96, 0x2d, 0x79, 0x11, 0x90, 0xb2, 0x90, 0x20, 0x58, 0x73,
    0x72, 0x2b, 0x48, 0xc0, 0x8a, 0xfa, 0xf7, 0x68, 0x69, 0xee, 0x53, 0x32,
    0x86, 0x11, 0x11, 0x87, 0xcd, 0xc4, 0xfa, 0x75, 0x7d, 0x9a, 0xb6, 0xcf,
    0xbf, 0x08, 0x53, 0x59, 0xb5, 0x7f, 0xde, 0x37, 0xd9, 0xa1, 0x75, 0x2b,
    0x1d, 0x20, 0x18, 0x4a, 0xd1, 0xe0, 0x5a, 0x4d, 0x83, 0xeb, 0xe2, 0xdd,
    0x5a, 0x2b, 0x91, 0x48, 0x74, 0xe1, 0x02, 0xd4, 0x44, 0xe5, 0xe1, 0x1e,
    0x19, 0xbd, 0xb7, 0x7d, 0x68, 0x72, 0x0b, 0x54, 0x56, 0x39, 0x75, 0xbf,
    0x59, 0xd9, 0x38, 0xc8, 0x94, 0x5f, 0x2a, 0x67, 0xec, 0xf7, 0xea, 0x9d,
    0xac, 0xa0, 0xb6, 0x36, 0x40, 0x65, 0x95, 0x93, 0xc0, 0xe4, 0xb8, 0xc6,
    0x9f, 0x1a, 0x65, 0x19, 0x01, 0x35, 0xd1, 0xe9, 0xe9, 0xb4, 0x26, 0x24,
    0x1c, 0x36, 0x13, 0x95, 0x55, 0x4e, 0x32, 0x76, 0xa8, 0x98, 0x82, 0x37,
    0xf6, 0xbf, 0x46, 0x32, 0x1d, 0x56, 0xda, 0xa3, 0x91, 0x04, 0x70, 0x44,
    0xe3, 0x27, 0x1a, 0x8a, 0xe0, 0xf5, 0x3d, 0xc3, 0x63, 0xbe, 0xb5, 0x64,
    0x80, 0xe0, 0xf5, 0x14, 0x3d, 0x7d, 0x4f, 0xb2, 0xb5, 0xfd, 0xa2, 0xc6,
    0x2f, 0x48, 0x0b, 0x5b, 0xd9, 0x04, 0x54, 0x56, 0x39, 0x61, 0x7a, 0x5c,
    0x13, 0x32, 0x72, 0xb6, 0xa9, 0x98, 0x02, 0xff, 0xf5, 0x1b, 0xbc, 0xfe,
    0xba, 0xfe, 0x95, 0x89, 0x1e, 0x9a, 0xdc, 0xd2, 0x16, 0xe4, 0xdc, 0xe0,
    0x06, 0x06, 0xfc, 0x8d, 0xac, 0x5f, 0xf5, 0x2e, 0x0d, 0xae, 0xd5, 0x80,
    0x94, 0xc5, 0x6e, 0xa5, 0x03, 0x79, 0x7d, 0x14, 0x25, 0x20, 0x30, 0x39,
    0xae, 0xc9, 0x3c, 0x72, 0xd8, 0x64, 0xec, 0xf0, 0xce, 0xbe, 0x23, 0x74,
    0x1f, 0x3a, 0x5c, 0xb0, 0xaf, 0x9e, 0xde, 0x5e, 0x2e, 0x5d, 0xbe, 0xc4,
    0xac, 0xb5, 0x9f, 0x44, 0x5a, 0x3a, 0xe1, 0xfd, 0xf9, 0xd8, 0x6f, 0x78,
    0xf6, 0x3b, 0x63, 0x3c, 0xb7, 0x69, 0x48, 0x0a, 0x37, 0xe3, 0x1d, 0x44,
    0x69, 0x02, 0xd4, 0x3d, 0xbf, 0xec, 0x61, 0x27, 0x19, 0xa4, 0x9e, 0x7f,
    0x67, 0xdf, 0x11, 0xac, 0x82, 0x99, 0x97, 0x5f, 0x79, 0x49, 0x11, 0x51,
    0xef, 0x74, 0x18, 0xfa, 0x91, 0x9f, 0x8f, 0xa4, 0xb5, 0x65, 0x0d, 0x5f,
    0x8a, 0xb7, 0x30, 0x59, 0x66, 0x48, 0xc5, 0x6b, 0x88, 0x84, 0xa5, 0x63,
    0x7a, 0xd0, 0x3f, 0x7f, 0xfd, 0x58, 0xb0, 0x00, 0x87, 0xcd, 0x74, 0x2f,
    0x26, 0xfd, 0xe3, 0xca, 0x64, 0xee, 0x3e, 0x74, 0x98, 0x9f, 0xff, 0x62,
    0x37, 0x07, 0xdf, 0xfa, 0x3d, 0x23, 0xc3, 0x63, 0xdc, 0x1c, 0x1f, 0x63,
    0xf9, 0x8a, 0x55, 0x86, 0x7e, 0x66, 0x92, 0x09, 0xcd, 0x7d, 0xaa, 0xf9,
    0xb6, 0x40, 0x82, 0x7b, 0x93, 0x58, 0x9d, 0x5e, 0xcb, 0x3a, 0x89, 0x01,
    0x7c, 0xfd, 0x17, 0xa4, 0xb3, 0x01, 0x70, 0xdc, 0x6c, 0x66, 0x4f, 0x4a,
    0x22, 0x72, 0xf4, 0xdd, 0x0f, 0x88, 0x46, 0x12, 0xf4, 0x1d, 0x3f, 0xc6,
    0xef, 0xfe, 0x78, 0x80, 0x7d, 0xfb, 0xff, 0xc0, 0xba, 0x96, 0xf5, 0xba,
    0x3e, 0xd6, 0xb5, 0xac, 0x57, 0x9e, 0x4d, 0x41, 0xda, 0x96, 0x3c, 0x10,
    0xaf, 0xe4, 0x4b, 0xf1, 0x16, 0x03, 0xfe, 0x46, 0xae, 0x7f, 0x56, 0xc7,
    0x4f, 0xbf, 0x7f, 0x94, 0x47, 0xd6, 0xb8, 0x72, 0xee, 0xa9, 0x20, 0xcf,
    0xb5, 0x8a, 0xdc, 0x4b, 0x16, 0x4b, 0x38, 0xaf, 0xcd, 0x4c, 0x32, 0xc1,
    0xc8, 0xf0, 0x18, 0x07, 0x8e, 0xfe, 0x15, 0xff, 0xd5, 0x2b, 0xa4, 0xe2,
    0x49, 0x6e, 0x8e, 0x8f, 0x49, 0x47, 0x41, 0x1d, 0xd8, 0x45, 0xbb, 0xee,
    0xed, 0x46, 0x2a, 0x5e, 0x43, 0x22, 0x5d, 0x97, 0xb7, 0xe7, 0x65, 0xe4,
    0xdd, 0xcc, 0x01, 0xc4, 0xe3, 0x22, 0x9f, 0x7f, 0xd1, 0x42, 0x30, 0x94,
    0xe2, 0x1b, 0x06, 0xb6, 0x35, 0xd5, 0xd2, 0x9e, 0x69, 0xcf, 0xde, 0x3d,
    0x80, 0x34, 0x07, 0x52, 0xb7, 0xef, 0x60, 0xb6, 0xe8, 0xdb, 0x8b, 0xa2,
    0x88, 0x28, 0x8a, 0xf8, 0x07, 0xaf, 0x29, 0x9d, 0x60, 0xb2, 0x48, 0xfb,
    0x4d, 0x73, 0x55, 0x4c, 0x59, 0xc0, 0x22, 0x91, 0x28, 0xa1, 0x48, 0xcc,
    0x70, 0x37, 0x6a, 0xf8, 0x52, 0xdf, 0xd9, 0xb9, 0x2b, 0x23, 0x5f, 0x6b,
    0xa8, 0xdf, 0x6a, 0x43, 0x91, 0x98, 0xc6, 0x4e, 0xee, 0xe1, 0x42, 0xae,
    0x40, 0x8c, 0x10, 0x0e, 0x87, 0x0b, 0xfa, 0x3e, 0x1c, 0x0e, 0xd3, 0xd5,
    0x75, 0x50, 0xf3, 0x52, 0xff, 0x3f, 0x86, 0xad, 0xe1, 0xd7, 0xb6, 0xaf,
    0x9f, 0x10, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42,
    0x60, 0x82
};

    switch (id) {
        case image0_ID:  { QImage img; img.loadFromData(image0_data, sizeof(image0_data), "PNG"); return QPixmap::fromImage(img); }
        case image1_ID:  { QImage img; img.loadFromData(image1_data, sizeof(image1_data), "PNG"); return QPixmap::fromImage(img); }
        default: return QPixmap();
    } // switch
    } // icon

};

namespace Ui {
    class UITipDlg: public Ui_UITipDlg {};
} // namespace Ui

QT_END_NAMESPACE

class UITipDlg : public QDialog, public Ui::UITipDlg
{
    Q_OBJECT

public:
    UITipDlg(QWidget* parent = 0, const char* name = 0, bool modal = false, Qt::WindowFlags fl = 0);
    ~UITipDlg();

protected slots:
    virtual void languageChange();

};

#endif // UITIPDLG_H
