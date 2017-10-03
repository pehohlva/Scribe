#include "scribe_config.h"
#include "xslt_convert.h"

#include "OOReader.h"



int main( int argc, char ** argv )
{
    /// ok Dzip unzip("key.zip"); /// pass
    QApplication app( argc, argv );
    SCDEBUG() << "start main here...";
    QTextEdit t;
    OOReader *readodt = new OOReader("/Users/dev/github/_QOASIS/miniscribus3/src/lib/api/key.odt");
    readodt->read();
    t.setDocument(readodt->document());
    t.show();
    t.raise();
    return app.exec();
}


/*
//// test xslt handling
QMap<QString,QString> Params;
Params.insert(QString("ca ne"),QString("Giallo-sera")); ///
Xslt_Convert gox("key.xml","key.xsl","conrec.xml");
//// t.setPlainText ( gox.dmg() );
///

FopColor *fc = new FopColor();

QStringList items = fc->fopListColor();
for (int i = 0; i < items.size(); ++i)  {
    const QString name = items.at(i);
    QTextCursor c = t.textCursor();
    QPixmap e =  fc->createColorMap(name);
    t.document()->addResource(QTextDocument::ImageResource,QUrl(name),e);
    QTextImageFormat format;
    format.setName( name );
    format.setHeight ( e.height() );
    format.setWidth ( e.width() );
    format.setToolTip(name);
    t.textCursor().insertBlock();
    t.textCursor().insertImage( format );
    t.textCursor().insertText(QString(" Color-%2 Name: %1   ").arg(name).arg(i));
    QTextDocumentFragment fr;
    fr.fromHtml("<br>");
    t.textCursor().insertFragment(fr);
}
*/
