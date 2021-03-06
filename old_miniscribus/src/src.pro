######################################################################
# Automatically generated by qmake (2.01a) lun 25. ago 17:51:33 2008
######################################################################

TEMPLATE = app
TARGET = scribe
DEPENDPATH += . bookmark foformat paperformat textapi ui
INCLUDEPATH += . bookmark foformat paperformat textapi ui



!include( ../config.pri ) {
message( "../config.pri not found" )
}

INCLUDEPATH += $$BUILD_TREE_PATH/modules/ooo

macx {
RC_FILE = zzz.icns
QTPLUGIN     += qmng qjpeg qgif qtiff
QMAKE_INFO_PLIST = Info.plist
QMAKE_MAC_SDK=/Developer/SDKs/MacOSX10.4u.sdk
CONFIG+=x86 ppc
}


win32:RC_FILE = win.rc

unix {
TARGET = scribe
BINDIR = /usr/bin
target.path = $$BINDIR
INSTALLS += target
}


CONFIG -= app_bundle





MOC_DIR = build/.moc
RCC_DIR = build/.rcc
OBJECTS_DIR = build/.obj
####  console
CONFIG +=  qt release warn_off 
LIBS += $$BUILD_TREE_PATH/lib/libtxtscribe.$$LIB_EXTENSION
DESTDIR	+= ../
QT += xml
QT += network
QT += svg 
contains(QT_CONFIG, opengl):QT += opengl

HEADERS += ../modules/xslt/xslt_convert.h
SOURCES += ../modules/xslt/xslt_convert.cpp  

# Input
HEADERS += Config.h \
           MainWindow.h \
           SessionManager.h \
           XML_Editor.h \
           bookmark/BookMarkModel.h \
           bookmark/BookTree.h \
           bookmark/TranslateModel.h \
           foformat/Fo_Format.h \
           foformat/Fo_Reader.h \
           foformat/Fo_Writter.h \
           foformat/FoColorName.h \
           foformat/Fop_Leader_Element.h \
           paperformat/PageFormatDlg.h \
           paperformat/PageFormatGroup.h \
           BasicFoConfig.h \
           textapi/getmargin.h \
           textapi/href_gui.h \
           textapi/Image_Page_Struct_Mime.h \
           textapi/Layer_Absolute_Floating.h \
           textapi/Layer_Auto_Extended.h \
           textapi/Layer_CommandStorage.h \
           textapi/Scribe_Parser.h \
           textapi/table_setting.h \
           textapi/Text_Api.h
FORMS += ui/gmain.ui ui/pageformatdlg.ui ui/searchdlg.ui
SOURCES += main.cpp \
           MainWindow.cpp \
           SessionManager.cpp \
           XML_Editor.cpp \
           bookmark/BookMarkModel.cpp \
           bookmark/BookTree.cpp \
           bookmark/TranslateModel.cpp \
           foformat/Fo_Format.cpp \
           foformat/Fo_Reader.cpp \
           foformat/Fo_Writter.cpp \
           foformat/FoColorName.cpp \
           foformat/Fop_Leader_Element.cpp \
           paperformat/PageFormatDlg.cpp \
           paperformat/PageFormatGroup.cpp \
           BasicFoConfig.cpp \
           textapi/getmargin.cpp \
           textapi/href_gui.cpp \
           textapi/Image_Page_Struct_Mime.cpp \
           textapi/Layer_Absolute_Floating.cpp \
           textapi/Layer_Auto_Extended.cpp \
           textapi/Layer_CommandStorage.cpp \
           textapi/Scribe_Parser.cpp \
           textapi/table_setting.cpp \
           textapi/Text_Api.cpp
RESOURCES += osApplication.qrc








