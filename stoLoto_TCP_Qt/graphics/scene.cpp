#include "scene.h"
#include "barrelitem.h"
#include <QPainter>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
	connect(&m_timer,
			SIGNAL(timeout()),
			SLOT(slotCreateBarrel()));

	initGrid();
}

void Scene::startTimer()
{
	m_timer.start(4000);
}

void Scene::slotCreateBarrel()
{
	int newNum = 0;
	QGraphicsItem *item = new BarrelItem(newNum);
	addItem(item);
	item->setPos(maxSceneWidth, indent);
}

void Scene::initGrid()
{
	m_gridLines.clear();
	// горизонтальные линии
	for (int i = 0; i < maxSceneHeight/stepGrid; i++) {
		m_gridLines.push_back(QLineF(0, i * stepGrid,
								  maxSceneWidth, i * stepGrid));
	}
	// вертикальные линии
	for (int i = 0; i < maxSceneWidth/stepGrid; i++) {
		m_gridLines.push_back(QLineF(i * stepGrid, 0,
								  i * stepGrid, maxSceneHeight));
	}
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
	Q_UNUSED(rect)
	painter->setPen(QColor("#979AAA"));
	painter->setBrush(QBrush(QColor("#FFF8E7")));
	painter->drawRect(0, 0, maxSceneWidth, maxSceneHeight);
	painter->drawLines(m_gridLines.data(), m_gridLines.count());
}
