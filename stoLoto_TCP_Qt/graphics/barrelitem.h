#ifndef BARRELITEM_H
#define BARRELITEM_H

#include <QGraphicsObject>
#include <QFont>
#include <QRectF>
#include <QTimer>

class BarrelItem : public QGraphicsObject
{
	Q_OBJECT
public:
	BarrelItem(int num, QGraphicsItem *parent = nullptr);

	// QGraphicsItem interface
public:
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private slots:
	void slotMoved();

private:
	QRectF		m_form;
	QFont		m_font;
	int8_t		m_num;
	QTimer		m_timer;
};

#endif // BARRELITEM_H
