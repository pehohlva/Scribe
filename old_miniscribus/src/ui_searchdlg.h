/********************************************************************************
** Form generated from reading UI file 'searchdlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDLG_H
#define UI_SEARCHDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeSearchDlg
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QTextEdit *wquery;
    QTextEdit *ramplace;
    QCheckBox *oosensi;
    QCheckBox *ooregularex;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout1;
    QPushButton *dd1;
    QPushButton *dd2;
    QPushButton *dd3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QRadioButton *ssup;
    QRadioButton *ssdown;
    QPushButton *dd4;
    QSpacerItem *spacerItem1;

    void setupUi(QWidget *MeSearchDlg)
    {
        if (MeSearchDlg->objectName().isEmpty())
            MeSearchDlg->setObjectName(QString::fromUtf8("MeSearchDlg"));
        MeSearchDlg->resize(400, 300);
        gridLayout = new QGridLayout(MeSearchDlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        wquery = new QTextEdit(MeSearchDlg);
        wquery->setObjectName(QString::fromUtf8("wquery"));
        wquery->setMaximumSize(QSize(16777215, 80));
        wquery->setAcceptRichText(false);

        vboxLayout->addWidget(wquery);

        ramplace = new QTextEdit(MeSearchDlg);
        ramplace->setObjectName(QString::fromUtf8("ramplace"));
        ramplace->setMaximumSize(QSize(16777215, 80));
        ramplace->setAcceptRichText(false);

        vboxLayout->addWidget(ramplace);

        oosensi = new QCheckBox(MeSearchDlg);
        oosensi->setObjectName(QString::fromUtf8("oosensi"));

        vboxLayout->addWidget(oosensi);

        ooregularex = new QCheckBox(MeSearchDlg);
        ooregularex->setObjectName(QString::fromUtf8("ooregularex"));

        vboxLayout->addWidget(ooregularex);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        dd1 = new QPushButton(MeSearchDlg);
        dd1->setObjectName(QString::fromUtf8("dd1"));

        vboxLayout1->addWidget(dd1);

        dd2 = new QPushButton(MeSearchDlg);
        dd2->setObjectName(QString::fromUtf8("dd2"));

        vboxLayout1->addWidget(dd2);

        dd3 = new QPushButton(MeSearchDlg);
        dd3->setObjectName(QString::fromUtf8("dd3"));
        dd3->setEnabled(false);

        vboxLayout1->addWidget(dd3);

        groupBox = new QGroupBox(MeSearchDlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout1 = new QGridLayout(groupBox);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        ssup = new QRadioButton(groupBox);
        ssup->setObjectName(QString::fromUtf8("ssup"));

        gridLayout1->addWidget(ssup, 1, 0, 1, 1);

        ssdown = new QRadioButton(groupBox);
        ssdown->setObjectName(QString::fromUtf8("ssdown"));
        ssdown->setChecked(true);

        gridLayout1->addWidget(ssdown, 2, 0, 1, 1);


        vboxLayout1->addWidget(groupBox);

        dd4 = new QPushButton(MeSearchDlg);
        dd4->setObjectName(QString::fromUtf8("dd4"));

        vboxLayout1->addWidget(dd4);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem1);


        gridLayout->addLayout(vboxLayout1, 0, 1, 1, 1);


        retranslateUi(MeSearchDlg);
        QObject::connect(dd4, SIGNAL(clicked()), MeSearchDlg, SLOT(hide()));
        QObject::connect(wquery, SIGNAL(undoAvailable(bool)), dd3, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MeSearchDlg);
    } // setupUi

    void retranslateUi(QWidget *MeSearchDlg)
    {
        MeSearchDlg->setWindowTitle(QApplication::translate("MeSearchDlg", "Search or Query replace  CTR+F", 0, QApplication::UnicodeUTF8));
        ramplace->setDocumentTitle(QString());
        oosensi->setText(QApplication::translate("MeSearchDlg", "case sensitive", 0, QApplication::UnicodeUTF8));
        ooregularex->setText(QApplication::translate("MeSearchDlg", "regular expression", 0, QApplication::UnicodeUTF8));
        dd1->setText(QApplication::translate("MeSearchDlg", "Search word", 0, QApplication::UnicodeUTF8));
        dd2->setText(QApplication::translate("MeSearchDlg", "Next", 0, QApplication::UnicodeUTF8));
        dd3->setText(QApplication::translate("MeSearchDlg", "Replace", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MeSearchDlg", "Direction", 0, QApplication::UnicodeUTF8));
        ssup->setText(QApplication::translate("MeSearchDlg", "search up", 0, QApplication::UnicodeUTF8));
        ssdown->setText(QApplication::translate("MeSearchDlg", "search down", 0, QApplication::UnicodeUTF8));
        dd4->setText(QApplication::translate("MeSearchDlg", "Abort", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MeSearchDlg: public Ui_MeSearchDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDLG_H
