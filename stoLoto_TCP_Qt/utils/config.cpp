#include "config.h"

Config g_config;

Config::Config()
{
	m_ticketCount = 3;

#ifdef Q_OS_LINUX
	m_name = QString::fromLocal8Bit(qgetenv("USER"));
#else
	m_name = QString::fromLocal8Bit(qgetenv("USERNAME"));
#endif
}
