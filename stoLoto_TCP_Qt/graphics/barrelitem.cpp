#include "barrelitem.h"
#include <QPainter>

#define BARREL_SIDE 70
#define BARREL_INDENT 5

BarrelItem::BarrelItem(int num, QGraphicsItem *parent) :
	QGraphicsObject(parent),
	m_num(num)
{
	m_form = QRectF(BARREL_INDENT,
					BARREL_INDENT,
					BARREL_SIDE - BARREL_INDENT,
					BARREL_SIDE - BARREL_INDENT);
	m_font = QFont("Iosevka", 30);

	connect(&m_timer,
			SIGNAL(timeout()),
			SLOT(slotMoved()));

	m_timer.start(20);
}

QRectF BarrelItem::boundingRect() const
{
	return QRectF(0, 0, BARREL_SIDE, BARREL_SIDE);
}

QPainterPath BarrelItem::shape() const
{
	QPainterPath path;
	path.addEllipse(m_form);
	return path;
}

void BarrelItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QPen pen = QPen(Qt::black, 2, Qt::SolidLine);
	pen.setJoinStyle(Qt::RoundJoin);
	painter->setPen(pen);
	painter->setBrush(QBrush(QColor("#BC987E")));

	painter->setFont(m_font);
	painter->drawEllipse(m_form);
	painter->drawText(m_form, Qt::AlignCenter, QString::number(m_num));
}

void BarrelItem::slotMoved()
{
	if (scenePos().x() + BARREL_SIDE < 0) {
		this->deleteLater();
		return;
	}
	moveBy(-1, 0);
}
