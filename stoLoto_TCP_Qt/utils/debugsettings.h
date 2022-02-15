#ifndef DEBUGSETTINGS_H
#define DEBUGSETTINGS_H

//#define DEBUG_ON
#ifdef DEBUG_ON
#define DEBUG(...) qDebug()<<__VA_ARGS__
#include <QDebug>
#else
#define DEBUG(...) //qDebug()<<__VA_ARGS__
#endif

#endif // DEBUGSETTINGS_H
