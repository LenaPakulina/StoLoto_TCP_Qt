#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

struct Config
{
	Config();

	/// Имя игрока - пользователя
	QString		m_name;

	/// Кол-во билетов на руках играков
	int8_t		m_ticketCount;
};

/// Глобальная переменная с настройками игры
extern Config g_config;

#endif // CONFIG_H
