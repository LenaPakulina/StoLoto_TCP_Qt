#include "scene.h"
#include "barrelitem.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
	QGraphicsItem *item = new BarrelItem();
	addItem(item);
	item->setPos(0, 0);
}
