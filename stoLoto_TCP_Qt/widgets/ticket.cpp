#include "ticket.h"
#include "ticketcell.h"
#include "utils/config.h"
#include "utils/debugsettings.h"
#include <QGridLayout>
#include <QSet>
#include <QRandomGenerator>

Ticket::Ticket(QWidget *parent) : QWidget(parent)
{
	m_layout = new QGridLayout(this);
	m_layout->setSpacing(1);
	m_layout->setMargin(0);
	m_activeNumCount = 0;

	init();

	adjustSize();
}

Ticket::~Ticket()
{
	if (m_layout) {
		m_layout->deleteLater();
	}
	clear();
}

void Ticket::init()
{
	clear();
	m_activeNumCount = 0;

	m_cells.reserve(g_config.m_vertCountNum);
	for (int i = 0; i < g_config.m_vertCountNum; i++) {
		QVector<TicketCell*> t_row;
		t_row.reserve(g_config.m_horzCountNum);
		for (int j = 0; j < g_config.m_horzCountNum; j++) {
			t_row.append(new TicketCell(this));
		}
		m_cells.append(t_row);
	}

	setTicketDistribution();

	// filling Layout
	for (int i = 0; i < g_config.m_vertCountNum; i++) {
		for (int j = 0; j < g_config.m_horzCountNum; j++) {
			m_layout->addWidget(m_cells.at(i).at(j), i, j);
		}
	}
}

void Ticket::clear()
{
	for (QVector<TicketCell*>& row: m_cells) {
		for (TicketCell* cell: row) {
			cell->deleteLater();
		}
	}
	m_cells.clear();
}

void Ticket::setTicketDistribution()
{
	QSet<int8_t> indexRepeatsSet;
	const int repeatCount = g_config.m_goalCountNum - g_config.m_horzCountNum;
	if (repeatCount > g_config.m_horzCountNum) {
		DEBUG("Код ошибки: 18-02-2022. Неправильно заданные параметры");
		return;
	}

	while (indexRepeatsSet.count() != repeatCount) {
		indexRepeatsSet << QRandomGenerator::global()->bounded(0, g_config.m_horzCountNum);
	}

	for (int i = 0; i < g_config.m_horzCountNum; i++) {
		QSet<int8_t> vertIndexs;
		while (vertIndexs.count() != (1 + indexRepeatsSet.contains(i))) {
			vertIndexs << QRandomGenerator::global()->bounded(0, g_config.m_vertCountNum);
		}

		for (const int8_t& vPosNum: vertIndexs) {
			int minV = i*10;
			int maxV = (i+1)*10;
			if (i == (g_config.m_horzCountNum - 1)) {
				maxV++;
			}
			m_cells[vPosNum][i]->setNumCell(QRandomGenerator::global()->bounded(minV, maxV));
		}
	}
}
