#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>

static int maxSceneHeight = 100;
static int maxSceneWidth = 600;
static int stepGrid = 20;
static int indent = 15;

class Scene : public QGraphicsScene
{
	Q_OBJECT
public:
	Scene(QObject *parent = nullptr);
	void startTimer();

private slots:
	void slotCreateBarrel();

protected:
	void drawBackground(QPainter *painter, const QRectF &rect);

private:
	QVector<QLineF>		m_gridLines;
	QTimer				m_timer;

private:
	void initGrid();
};

#endif // SCENE_H
