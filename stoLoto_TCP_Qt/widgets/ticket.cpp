#include "ticket.h"
#include "ticketcell.h"
#include <QGridLayout>

Ticket::Ticket(QWidget *parent) : QWidget(parent)
{
	m_layout = new QGridLayout(this);
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
//	m_activeMinesCount = 0;

//	// initial grid creation
//	m_cells.reserve(g_cfg.m_height);
//	for (int i = 0; i < g_cfg.m_height; i++) {
//		QVector<Cell*> t_row;
//		t_row.reserve(g_cfg.m_width);
//		for (int j = 0; j < g_cfg.m_width; j++) {
//			t_row.append(new Cell(this));
//		}
//		m_cells.append(t_row);
//	}

//	// Filling in the grid
//	while(m_activeMinesCount != g_cfg.m_mineCount) {
//		while(!setMine()) {
//			// nothing ToDo
//		}
//	}

//	// filling Layout
//	for (int i = 0; i < g_cfg.m_height; i++) {
//		for (int j = 0; j < g_cfg.m_width; j++) {
//			m_layout->addWidget(m_cells.at(i).at(j), i, j);
//		}
//	}

//	// Determine the number of Mines
//	setNumbersAboutMines();

//	m_activeFreeCount = g_cfg.m_width * g_cfg.m_width;
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
