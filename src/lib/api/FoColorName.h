#ifndef FOPCOLORFORMAT_H
#define FOPCOLORFORMAT_H

#include "scribe_config.h"

qreal DPIactualDiff();
#define PDIFIX(ii) ((ii)*DPIactualDiff())





/* metric conversion from and to */
/*
QString metrics(const qreal screenpoint);
qreal FopInt(const QString datain);
qreal Unit(const QString datain);
qreal Pointo(qreal unit, const QString unita);
qreal ToUnit(qreal unit, const QString unita);
qreal ToPoint(qreal unit, const QString unita);
 */

#define _USELISTAPACHECOLOR_ 1
#define ALPHACOLPER(aa) ((aa)*2.555555)
qreal OoColorAlpha(const int i);

class QColor;
class FopColor {
public:
  FopColor();

  typedef enum {
    DarkColor = 100,
    LightColor = 200,
    Transparent = 300
  } AlternateColor;

  QColor foColor(const QString colorchunk,
                 FopColor::AlternateColor col = DarkColor);
  QString foName(const QColor e);
  QPixmap createColorMap(const QString colorchunk);
  inline QStringList fopListColor() { return fopcolorNames; }
  inline QColor color() { return currentcolor; }
  inline int size() { return fopcolorNames.count(); }

protected:
  QMap<QString, QColor> foplist; /* forever clear only construct */
  QMap<QString, QColor> avaiablelist;
  QStringList fopcolorNames;

private:
  QColor alternateColor(FopColor::AlternateColor col);
  QColor currentcolor;
  void record(const QString colorchunk, QColor item);
};

/*

    QTextEdit t;
    FopColor *fc = new FopColor();
    qDebug() << "### load color   ";
    QStringList items = fc->fopListColor();
    for (int i = 0; i < items.size(); ++i)  {
        const QString name = items.at(i);
        QTextCursor c = t.textCursor();
        QPixmap e =  fc->(name);
        t.document()->addResource(QTextDocument::ImageResource,QUrl(name),e);
        QTextImageFormat format;
        format.setName( name );
        format.setHeight ( e.height() );
        format.setWidth ( e.width() );
        format.setToolTip(name);
        t.textCursor().insertImage( format );
    }

    t.show();
*/

/*  grab color from fop format ;
    alpha color only on rgb(11,11,11,110)  last


*/

#endif
