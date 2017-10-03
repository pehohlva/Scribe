/*
    Copyright (C)  2017 Piter K. <pehohlva@gmail.com>
    This library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 2.1 of the License, or
    (at your option) any later version.
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CONFIGQT5_RUN
#define CONFIGQT5_RUN

#include <QtGlobal>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))


#include <QMainWindow>
#include <QApplication>
#include <QtGui>
#include <QFontDatabase>
#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <QByteArray>
#include <QString>
#include <QProcess>
#include <QElapsedTimer>
#include <QXmlSimpleReader>
#include <QXmlInputSource>

#include <QtCore/qfile.h>
#include <QtCore/qstring.h>
#include <QtCore/QMap>
#include <QtCore/QDebug>
#include <QtCore/QBuffer>
#include <QtCore/qiodevice.h>
#include <QtCore/qbytearray.h>
#include <qstringlist.h>
#include <QtXml/QDomDocument>
#include <QtGui/QTextDocument>
#include <QtCore/QByteArray>
#include <QtCore/QMap>
#include <QtCore/QDebug>
#include <QImage>
#include <QtCore/qfile.h>
#include <QtCore/qstring.h>
#include <QtCore/QMap>
#include <QtCore/QDebug>
#include <QtCore/QBuffer>
#include <QtCore/qiodevice.h>
#include <QtCore/qbytearray.h>
#include <QtXml/QDomDocument>
#include <QTextDocument>
#include <qstringlist.h>
#include <QtCore/QByteArray>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QImage>
#include <QtCore/QObject>
#include <QMimeDatabase>
#include <QSet>
#include <QColor>
#include <QDebug>
#include <QMap>
#include <QPixmap>
#include <QtCore>
#include <QtSvg>
#include <QTextDocumentFragment>

#include <QCryptographicHash>

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtWidgets>


#define Q_WS_MAC  Q_OS_MAC
#define Q_WS_WIN  Q_OS_WIN
#define Q_WS_X11  Q_OS_X11
#define Q_WS_LINUX Q_OS_LINUX

namespace Qt {
inline static QString stringHtmlEscapedqt5( QString x) {
    return QString(x).toHtmlEscaped();
}
#define escape stringHtmlEscapedqt5
}

#define toAscii toLatin1
#define fromAscii fromLatin1


#if 1 //// 1 or 0
#define SCDEBUG qDebug
#define STAGE 1
#define _debuglogfile_                                                         \
  QString("/Volumes/dati/mim_log.txt")
#else
#define SCDEBUG                                                              \
  if (0)                                                                       \
  qDebug
#define STAGE 0
#define _debuglogfile_ QString("")
#endif
#endif


#define READONFIGOK


#endif
