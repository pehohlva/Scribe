#ifndef XSLT_CONVERT_H
#define XSLT_CONVERT_H

#include <QObject>
#include <QFileInfo>
#include <QFile>
#include <QDateTime>
#include <QtCore> 
#include <QTextCodec>



#include <QtGlobal>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
/* qt4 config header  */
#include "qt4config.h"
#else
/* qt5 config header  */
#include "qt5config.h"
#endif

#include "basic_config.h"

#define XMLERROR_FILE QString( "%1/libxmlerror.dat" ).arg( QDir::homePath() )

/*   compatible from old reader  */
QMap<QString,QByteArray> unzipstream( const QString file );

class Dzip
{
public:
    Dzip(const QString file);
    QStringList listFile() { return entries; }
    QMap<QString, QByteArray> listData() { return filedata; }
private:
    QStringList entries;
    QMap<QString, QByteArray> filedata;
};

class Xslt_Convert
{
    
		 
public:	 
    Xslt_Convert( const QString xmlfile , 
                  const QString xsltfile ,  
                  QString resulterxml );
    ~Xslt_Convert();
    inline QString dmg() { return MSGERROR; }
    inline QByteArray stream() { return Rstream; }
    QTextCodec *xmlcodec;
    QTextCodec *xsltcodec;
    
protected:

    QString XML_file;
    QString MSGERROR;
    QString XSLT_file;
    QString debug_msg;
    QMap<QString,QString> Params;
    void CheckError();
private:
    QByteArray Rstream;
    bool EndingJob;
	
	/*  
 signals:
 void ErrorMsg(QString);
 void DebugMsg(QString);
public slots:
private slots:
	 */


};
//
#endif // XSLT_CONVERT_H

