#ifndef GETFILES_H
#define GETFILES_H

#include "scribe_config.h"

#include <QObject>
#include <QThread>


class PushDoc : public QThread
{
public:
   PushDoc( QObject *parent )
    : QThread(parent)
   {
      setTerminationEnabled ( true );
   }
protected:
    void run() { exec(); }
};





class GetFiles : public QObject
{
    Q_OBJECT
public:
    explicit GetFiles(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GETFILES_H
