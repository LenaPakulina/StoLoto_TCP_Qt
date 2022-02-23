#include "barrelitem.h"
#include <QPainter>

#define BARREL_SIDE 70
#define BARREL_INDENT 5

BarrelItem::BarrelItem(QGraphicsItem *parent) : QGraphicsObject(parent)
{
	m_form = QRectF(BARREL_INDENT,
					BARREL_INDENT,
					BARREL_SIDE - BARREL_INDENT,
					BARREL_SIDE - BARREL_INDENT);

	m_font = QFont("Iosevka", 30);
	m_num = 0;
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
