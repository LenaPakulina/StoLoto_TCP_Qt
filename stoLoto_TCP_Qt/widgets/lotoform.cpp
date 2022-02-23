#include "lotoform.h"
#include "ui_lotoform.h"
#include "ticket.h"
#include "utils/config.h"
#include "graphics/scene.h"

LotoForm::LotoForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LotoForm)
{
	ui->setupUi(this);

	for (int num = 0; num < g_config.m_ticketCount; num++) {
		Ticket* ticket = new Ticket(this);
		ui->verticalLayout->addWidget(ticket);
	}

	m_scene = new Scene(ui->graphicsView);
	ui->graphicsView->setScene(m_scene);
	ui->graphicsView->setSceneRect(0, 0, maxSceneWidth, maxSceneHeight);
	ui->graphicsView->setMinimumHeight(maxSceneHeight);
	ui->graphicsView->setMinimumWidth(maxSceneWidth);

	adjustSize();
	m_scene->startTimer();
}

LotoForm::~LotoForm()
{
	delete ui;
}
