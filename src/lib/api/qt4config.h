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
#ifndef CONFIGQT4_RUN
#define CONFIGQT4_RUN


#include <QtGlobal>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)

#include <QApplication>
#include <QCoreApplication>
#include <QtGui>
#include <QSvgRenderer>
#include <QColor>
#include <QCoreApplication>
#include <QDebug>
#include <QMap>
#include <QPixmap>
#include <QtCore>
#include <QTextDocumentFragment>
#include <QCryptographicHash>
#endif


#define READONFIGOK


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
