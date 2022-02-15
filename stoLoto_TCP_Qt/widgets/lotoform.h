#ifndef LOTOFORM_H
#define LOTOFORM_H

#include <QWidget>

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
};

#endif // LOTOFORM_H
