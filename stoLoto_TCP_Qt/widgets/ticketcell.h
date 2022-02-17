#ifndef TICKETCELL_H
#define TICKETCELL_H

#include <QPushButton>

class TicketCell : public QPushButton
{
public:
	TicketCell(QWidget *parent);
	void	setNumCell(int numCell);

private:
	int		m_numCell; ///< Число в ячейке
};

#endif // TICKETCELL_H
