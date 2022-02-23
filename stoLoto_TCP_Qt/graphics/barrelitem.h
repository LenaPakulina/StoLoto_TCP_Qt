#ifndef BARRELITEM_H
#define BARRELITEM_H

#include <QGraphicsObject>
#include <QFont>
#include <QRectF>

class BarrelItem : public QGraphicsObject
{
	Q_OBJECT
public:
	BarrelItem(QGraphicsItem *parent = nullptr);

	// QGraphicsItem interface
public:
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	QRectF		m_form;
	QFont		m_font;
	int8_t		m_num;
};

#endif // BARRELITEM_H
