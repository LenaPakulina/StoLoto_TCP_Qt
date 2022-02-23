#ifndef LOTOFORM_H
#define LOTOFORM_H

#include <QWidget>

class Scene;
namespace Ui {
class LotoForm;
}

class LotoForm : public QWidget
{
	Q_OBJECT

public:
	explicit LotoForm(QWidget *parent = nullptr);
	~LotoForm();

private:
	Ui::LotoForm *ui;
	Scene			*m_scene;
};

#endif // LOTOFORM_H
