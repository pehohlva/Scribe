/********************************************************************************
** Form generated from reading UI file 'gmain.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GMAIN_H
#define UI_GMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gmain
{
public:
    QAction *actionExit;
    QAction *openfopdoc;
    QAction *pagereformat;
    QAction *actionGenralSave;
    QAction *actionSaveAs;
    QAction *convertFop;
    QAction *savescribePage;
    QAction *openScribe;
    QAction *actionNewDoc;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuExternal_doc_link;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Gmain)
    {
        if (Gmain->objectName().isEmpty())
            Gmain->setObjectName(QString::fromUtf8("Gmain"));
        Gmain->resize(603, 440);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/zzz.png"), QSize(), QIcon::Normal, QIcon::Off);
        Gmain->setWindowIcon(icon);
        actionExit = new QAction(Gmain);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        openfopdoc = new QAction(Gmain);
        openfopdoc->setObjectName(QString::fromUtf8("openfopdoc"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        openfopdoc->setIcon(icon2);
        pagereformat = new QAction(Gmain);
        pagereformat->setObjectName(QString::fromUtf8("pagereformat"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/wizard.png"), QSize(), QIcon::Normal, QIcon::Off);
        pagereformat->setIcon(icon3);
        actionGenralSave = new QAction(Gmain);
        actionGenralSave->setObjectName(QString::fromUtf8("actionGenralSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/3floppy-unmount-48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGenralSave->setIcon(icon4);
        actionSaveAs = new QAction(Gmain);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionSaveAs->setIcon(icon4);
        convertFop = new QAction(Gmain);
        convertFop->setObjectName(QString::fromUtf8("convertFop"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/arts-environment-48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        convertFop->setIcon(icon5);
        savescribePage = new QAction(Gmain);
        savescribePage->setObjectName(QString::fromUtf8("savescribePage"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/wp_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        savescribePage->setIcon(icon6);
        openScribe = new QAction(Gmain);
        openScribe->setObjectName(QString::fromUtf8("openScribe"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/wp_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openScribe->setIcon(icon7);
        actionNewDoc = new QAction(Gmain);
        actionNewDoc->setObjectName(QString::fromUtf8("actionNewDoc"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewDoc->setIcon(icon8);
        centralwidget = new QWidget(Gmain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Gmain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gmain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 603, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuExternal_doc_link = new QMenu(menubar);
        menuExternal_doc_link->setObjectName(QString::fromUtf8("menuExternal_doc_link"));
        Gmain->setMenuBar(menubar);
        statusbar = new QStatusBar(Gmain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Gmain->setStatusBar(statusbar);
        toolBar = new QToolBar(Gmain);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Gmain->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuExternal_doc_link->menuAction());
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuFile->addAction(actionGenralSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(convertFop);
        menuFile->addAction(savescribePage);
        menuFile->addAction(openScribe);
        menuFile->addSeparator();
        menuFile->addAction(actionNewDoc);
        toolBar->addAction(actionNewDoc);
        toolBar->addAction(actionGenralSave);
        toolBar->addAction(convertFop);
        toolBar->addAction(actionSaveAs);
        toolBar->addAction(savescribePage);
        toolBar->addAction(openScribe);
        toolBar->addAction(pagereformat);

        retranslateUi(Gmain);

        QMetaObject::connectSlotsByName(Gmain);
    } // setupUi

    void retranslateUi(QMainWindow *Gmain)
    {
        Gmain->setWindowTitle(QApplication::translate("Gmain", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("Gmain", "Exit", 0, QApplication::UnicodeUTF8));
        openfopdoc->setText(QApplication::translate("Gmain", "Open Fop Document", 0, QApplication::UnicodeUTF8));
        pagereformat->setText(QApplication::translate("Gmain", "Set page Format", 0, QApplication::UnicodeUTF8));
        actionGenralSave->setText(QApplication::translate("Gmain", "Save Document", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("Gmain", "Save as...", 0, QApplication::UnicodeUTF8));
        convertFop->setText(QApplication::translate("Gmain", "Apache FOP convert", 0, QApplication::UnicodeUTF8));
        savescribePage->setText(QApplication::translate("Gmain", "Save as Page Scribe Format", 0, QApplication::UnicodeUTF8));
        openScribe->setText(QApplication::translate("Gmain", "Open Scribe Page Format", 0, QApplication::UnicodeUTF8));
        actionNewDoc->setText(QApplication::translate("Gmain", "New Document", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("Gmain", "File", 0, QApplication::UnicodeUTF8));
        menuExternal_doc_link->setTitle(QApplication::translate("Gmain", "External doc link", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("Gmain", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Gmain: public Ui_Gmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GMAIN_H
