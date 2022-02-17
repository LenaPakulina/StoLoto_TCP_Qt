#include "config.h"

Config g_config;

Config::Config()
{
	m_ticketCount = 3;
	m_vertCountNum = 3;
	m_horzCountNum = 9;
	m_goalCountNum = 15; // 15 из 27 ячекк должны быть заполнены

#ifdef Q_OS_LINUX
	m_name = QString::fromLocal8Bit(qgetenv("USER"));
#else
	m_name = QString::fromLocal8Bit(qgetenv("USERNAME"));
#endif
}
