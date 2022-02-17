#include "lotoform.h"
#include "ui_lotoform.h"
#include "ticket.h"
#include "utils/config.h"

LotoForm::LotoForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LotoForm)
{
	ui->setupUi(this);

	for (int num = 0; num < g_config.m_ticketCount; num++) {
		Ticket* ticket = new Ticket(this);
		ui->verticalLayout->addWidget(ticket);
	}
}

LotoForm::~LotoForm()
{
	delete ui;
}
