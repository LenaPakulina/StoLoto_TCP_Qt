#include "lotoform.h"
#include "ui_lotoform.h"

LotoForm::LotoForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LotoForm)
{
	ui->setupUi(this);
}

LotoForm::~LotoForm()
{
	delete ui;
}
