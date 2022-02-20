#include "ticketcell.h"

#define TO_STR(temp) QString::number(temp)
#define SIDE_SIZE 30

TicketCell::TicketCell(QWidget *parent) : QPushButton(parent)
{
	m_numCell = -1;
	setText(QString());
	setEnabled(false);

	setMinimumHeight(SIDE_SIZE);
	setMaximumHeight(SIDE_SIZE);
	setMinimumWidth(SIDE_SIZE);
	setMaximumWidth(SIDE_SIZE);
}

void TicketCell::setNumCell(int numCell)
{
	m_numCell = numCell;
	setText(TO_STR(m_numCell));
	setEnabled(true);
}
