#ifndef TICKET_H
#define TICKET_H

#include <QWidget>
#include <QVector>

class QGridLayout;
class TicketCell;
typedef QVector<QVector<TicketCell*>> VVCell;

class Ticket : public QWidget
{
	Q_OBJECT
public:
	explicit Ticket(QWidget *parent = nullptr);
	~Ticket();
	void	init();

signals:

private:
	QGridLayout		*m_layout;
	VVCell			m_cells;

	int				m_activeNumCount;

private:
	void	clear();
	void	setTicketDistribution();
};

#endif // TICKET_H
