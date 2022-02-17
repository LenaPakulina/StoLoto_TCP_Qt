#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

struct Config
{
	Config();

	QString		m_name;			///< Имя игрока - пользователя
	int8_t		m_ticketCount;	///< Кол-во билетов на руках играков

	int8_t		m_vertCountNum;
	int8_t		m_horzCountNum;
	int8_t		m_goalCountNum;
};

/// Глобальная переменная с настройками игры
extern Config g_config;

#endif // CONFIG_H
