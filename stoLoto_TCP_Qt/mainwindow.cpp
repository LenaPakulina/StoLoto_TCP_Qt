#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgets/startform.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	StartForm *startForm = new StartForm(this);

	connect(startForm,
			SIGNAL(sigLaunchGame()),
			SLOT(slotStartGame()));

	ui->stackedWidget->addWidget(startForm);
//	ui->stackedWidget->addWidget();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::slotStartGame()
{
}

