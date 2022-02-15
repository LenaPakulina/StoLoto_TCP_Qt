#ifndef DEBUGSETTINGS_H
#define DEBUGSETTINGS_H

#ifdef QT_DEBUG
#define DEBUG(...) qDebug()<<__VA_ARGS__
#include <QDebug>
#else
#define DEBUG(...) //qDebug()<<__VA_ARGS__
#endif

#endif // DEBUGSETTINGS_H
