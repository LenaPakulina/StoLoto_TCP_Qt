#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgets/startform.h"
#include "utils/debugsettings.h"
#include "widgets/lotoform.h"

#include <QFontDatabase>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_startForm = new StartForm(this);
	m_lotoForm = new LotoForm(this);

	connect(m_startForm,
			SIGNAL(sigLaunchGame()),
			SLOT(slotStartGame()));

	ui->stackedWidget->addWidget(m_startForm);
	ui->stackedWidget->addWidget(m_lotoForm);

	QFontDatabase::addApplicationFont(":/fonts/mono.ttf");
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::slotStartGame()
{
	GAME_OPTIONS gameOpt = m_startForm->getGameOptions();
	switch (gameOpt) {
	case (GAME_OPTIONS::MULTI_PLAY):
		ui->stackedWidget->setCurrentWidget(m_lotoForm);
		break;
	case (GAME_OPTIONS::SINGLE_PLAY):
		ui->stackedWidget->setCurrentWidget(m_lotoForm);
		break;
	case (GAME_OPTIONS::UNKNOWN):
		DEBUG("Не найден кейс Switch");
		break;
	}
}

