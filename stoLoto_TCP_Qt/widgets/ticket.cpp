#include "ticket.h"
#include "ticketcell.h"
#include "utils/config.h"
#include "utils/debugsettings.h"
#include <QGridLayout>
#include <QSet>
#include <QRandomGenerator>

#define COUNT_NUM_IN_LINE (g_config.m_goalCountNum / g_config.m_vertCountNum)

Ticket::Ticket(QWidget *parent) : QWidget(parent)
{
	m_layout = new QGridLayout(this);
	m_layout->setSpacing(0);
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
	QVector<QSet<int>> ticketLines;
	QSet<int> tempSet;
	do {
		ticketLines.clear();
		tempSet.clear();
		for (int i = 0; i < g_config.m_vertCountNum; i++) {
			QSet<int> line;
			makeDistributionByLine(line);
			ticketLines << line;
			tempSet = tempSet + line;
		}
	} while (tempSet.count() != g_config.m_horzCountNum);

	tempSet.clear();
	for (int i = 0; i < g_config.m_vertCountNum; i++) {
		const QSet<int>& line = ticketLines[i];
		for (const int collPosition: line.values()) {
			int minV = collPosition*10;
			if (collPosition == 0) {
				minV += 1;
			}
			int maxV = (collPosition+1)*10;
			if (collPosition == (g_config.m_horzCountNum - 1)) {
				maxV++;
			}
			int numCell = QRandomGenerator::global()->bounded(minV, maxV);
			while (tempSet.contains(numCell) == true) {
				numCell = QRandomGenerator::global()->bounded(minV, maxV);
			}
			tempSet << numCell;
			m_cells[i][collPosition]->setNumCell(numCell);
		}
	}
}

void Ticket::makeDistributionByLine(QSet<int> &indexNum)
{
	while (indexNum.count() != COUNT_NUM_IN_LINE) {
		indexNum << QRandomGenerator::global()->bounded(0, g_config.m_horzCountNum);
	}
}
