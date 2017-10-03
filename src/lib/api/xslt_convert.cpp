#include "xslt_convert.h"
//
/*  Save file as xslt_convert.cpp  */
/*  incomming class name Xslt_Convert */
//
#include <stdio.h>



/*  set as private header not show in app!! */

#include <libxml/nanoftp.h>
#include <libxml/nanohttp.h>
#include <libxml/parser.h>
#include <libxslt/xslt.h>
#include <libxslt/xsltInternals.h>
#include <libxslt/transform.h>
#include <libxslt/xsltutils.h>
#include <libxml/xmlmemory.h>
#include <libxml/debugXML.h>
#include <libxml/HTMLtree.h>
#include <libxml/xmlIO.h>
#include <libxml/xinclude.h>
#include <libxml/catalog.h>
#include "kzip.h"

/*  set as private header not show in app!! */


#include "basic_config.h"


void qt_libxml_error_handler(void *ctx, const char *msg, ...)
{
    va_list args;
    QString message;
    QStringList errorlined;
    errorlined.clear();
    int size = 256;
    char * buf = new char[ size ];

    while( 1 ) {
       va_start(args, msg);
       int retval = ::vsnprintf( buf, size, msg, args );
       va_end(args);
     
       if( -1 < retval && retval < size ) { // everything was OK
          message = buf;
           if (message.size() > 0) {
           message.replace("&", "&amp;"); 
           errorlined.append(message);  
            /*qDebug() << "### 1 error captured to insert on class as list or so.... " << ;*/
           }
          break;
       }
       else if( retval > -1 ) { // buffer too small
           size = retval + 1;
           delete [] buf;
           buf = new char[ size ];
       }
       else {  // error
          // ...
          break;
       }
    }

    delete [] buf;
      QFile f( XMLERROR_FILE );
	if ( f.open( QFile::Append | QFile::Text ) )
	{
		QTextStream sw( &f );
		sw << errorlined.join("");
		f.close();
	}
}

Xslt_Convert::~Xslt_Convert()
{
   EndingJob = true;
   qt_unlink(XMLERROR_FILE);  /* remove debug or error message from last */
}

Xslt_Convert::Xslt_Convert( const QString xmlfile , const QString xsltfile ,  QString resulterxml )
 :EndingJob(false),xmlcodec(0),xsltcodec(0)
{
    SCDEBUG() << "### Start Xslt_Convert  ->" << UmanTimeFromUnix(QTime_Null());
    qt_unlink(XMLERROR_FILE);  /* remove debug or error message from last */
    qt_unlink(resulterxml);  /* if exist */
    QFile *xfile = new QFile( xmlfile );
    if (!xfile->exists()) {
    MSGERROR.append(QString("File %1 not exist!").arg(xmlfile));
    return;
    }
    QFile *sfile = new QFile( xsltfile );
    if (!sfile->exists()) {
    MSGERROR.append(QString("File %1 not exist!").arg(xsltfile));
    return;
    }
    xmlcodec = GetcodecfromXml(xmlfile);
    xsltcodec = GetcodecfromXml(xsltfile);
    const QString maildate = QString("\"%1\"").arg(UmanTimeFromUnix(QTime_Null()));
    const QString unixtime = QString("\"%1\"").arg(QTime_Null());
    const char* params[2];  
    params[0] = NULL;
    params[1] = NULL; 
    
    
    /* ######################################### */
         xsltStylesheetPtr cur = NULL;
         xmlDocPtr doc, outputDoc;
         xmlSubstituteEntitiesDefault(1);
         xmlLoadExtDtdDefaultValue = 1;
    /* ######################################### */
        char* xslt_errors;
        xsltSetGenericErrorFunc(&xslt_errors, qt_libxml_error_handler);
        xmlSetGenericErrorFunc(&xslt_errors, qt_libxml_error_handler);
        xsltSetGenericDebugFunc(&xslt_errors, qt_libxml_error_handler);
        QByteArray gocharxslt = QFile::encodeName(xsltfile); 
        cur = xsltParseStylesheetFile( (const xmlChar*)gocharxslt.data() );
        doc = xmlParseFile( QFile::encodeName(xmlfile) );
        outputDoc = xsltApplyStylesheet(cur, doc, params);
        xmlFreeDoc( doc ); /* free ram from xml! */
        doc = outputDoc; /* swap input and output */
        FILE* outfile = fopen( QFile::encodeName( resulterxml ), "w" );
        xsltSaveResultToFile( outfile, doc, cur );
        fclose( outfile );
        xsltFreeStylesheet(cur);
        xmlFreeDoc( outputDoc );
        xsltCleanupGlobals();
        xmlCleanupParser();
        SCDEBUG() << "### resulterxml ..........................  " << resulterxml;
        SCDEBUG() << "### XMLERROR_FILE ..........................  " << XMLERROR_FILE;
        Rstream = StreamFromFile(resulterxml);
        debug_msg = ReadFileUtf8Xml(XMLERROR_FILE);
        //// /SCDEBUG() << "### resulterxml ..........................  " << debug_msg;
        qt_unlink(XMLERROR_FILE); 
        EndingJob = true;
        MSGERROR.append(debug_msg);

}



void Xslt_Convert::CheckError()
{
    SCDEBUG() << "### CheckError ..........................  ->" << UmanTimeFromUnix(QTime_Null());
    SCDEBUG() << "### EndingJob ..........................  ->" << EndingJob;
}


/*   compatible from old reader  */
QMap<QString,QByteArray> unzipstream( const QString file )
{
    QMap<QString,QByteArray> nullvalue;
    KZipStream *Kzip = new KZipStream(file);
      if (Kzip->canread()) {
         return Kzip->listData();
      }
    return nullvalue;
}

Dzip::Dzip(const QString file)
{
    /* only include hesder from this lib not all zip zlib ecc.. */
    KZipStream *Kzip = new KZipStream(file);
      if (Kzip->canread()) {
         entries =Kzip->filelist();
               for (int x = 0; x < entries.size(); x++) {
                 QString line = entries.at(x) + QString("\n");
                  SCDEBUG() << line;
               }
         filedata = Kzip->listData();
      }
}




