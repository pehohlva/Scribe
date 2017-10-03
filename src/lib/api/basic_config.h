#ifndef BASICFOCONFIG_H
#define BASICFOCONFIG_H


#ifndef READONFIGOK
#include <QtGlobal>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include  "qt4config.h"
#else
#include  "qt5config.h"
#endif
#endif

#include "scribe_config.h"
#include <iostream>
#include <stdio.h>

#define _GSCACHE_                                                              \
  QString("%1/.ghosti_CACHE/").arg(QDir::homePath()) /* gs tmp */

/* help functions */
uint QTime_Null();
int dateswap(QString form, uint unixtime );
QString Unique_Stamp();
QString UmanTimeFromUnix( uint unixtime );
QString ReadFileUtf8Xml( const QString fullFileName );
bool qt_unlink(const QString fullFileName);
QTextCodec *GetcodecfromXml( const QString xmlfile  );
QPixmap BruschChess(qreal chesswidth = 50.);
QIcon createPenStyleIco(QPen item);
/* allowed char on file name image to save */
QString Imagename(const QString txt);
/* 12mm to point , 12cm , 2inch */
/* metric conversion from and to */
qreal Unit(const QString datain);
qreal FopInt(const QString datain);
qreal Pointo(qreal unit, const QString unita);
qreal Unit(qreal unit, const QString unita);
qreal ToUnit(qreal unit, const QString unita);
qreal ToPoint(qreal unit, const QString unita);
bool Cache(const QString dirpath); /* mkdir */
QString PathConvert(QString path); /* QDir::toNativeSeparators  */
bool fwriteutf8(const QString file, QString xml);
QString ReadFile(const QString fullFileName); /* read utf8 text */
/* read the contenet of a local file as QByteArray*/
QByteArray StreamFromFile(const QString fullFileName);
QString decodeBase64(QString xml);
QString encodeBase64(QString xml);
#ifdef CONFIGQT4_RUN
QPixmap RenderPixmapFromSvgByte(QByteArray streams);
#endif
QRectF Reduce(QRectF rect, const int percentual);
QRectF CenterRectSlaveFromMaster(const QRectF Master, QRectF Slave);
QIcon createColorToolButtonIcon(const QString &imageFile, QColor color);
QIcon createColorIcon(QColor color);
QString getGSLinuxPath(QString apps = QString("gs"));
QString getGSDefaultExeName();
double getGSVersion();
double JavaVersion();
int callGS(const QStringList args);
QPixmap LoadPS(QString fn, const QString arguments_append = QString());
QPixmap LoadPDF(QString fn, int Page, int w);

#endif // BASICFOCONFIG_H
