#include "startform.h"
#include "ui_startform.h"
#include "utils/config.h"

StartForm::StartForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::StartForm)
{
	ui->setupUi(this);
	m_gameOptions = GAME_OPTIONS::UNKNOWN;
	ui->pb_playingOnline->setEnabled(false);
	ui->le_name->setText(g_config.m_name);

	connect(ui->pb_playSingle,
			SIGNAL(clicked(bool)),
			SLOT(slotStartSinglePlay()));
	connect(ui->pb_playingOnline,
			SIGNAL(clicked(bool)),
			SLOT(slotStartOnlinePlay()));
}

StartForm::~StartForm()
{
	delete ui;
}

GAME_OPTIONS StartForm::getGameOptions() const
{
	return m_gameOptions;
}

void StartForm::slotStartSinglePlay()
{
	m_gameOptions = GAME_OPTIONS::SINGLE_PLAY;

	applyOptions();
}

void StartForm::slotStartOnlinePlay()
{
	m_gameOptions = GAME_OPTIONS::MULTI_PLAY;

	applyOptions();
}

void StartForm::applyOptions()
{
	g_config.m_name = ui->le_name->text();
	emit sigLaunchGame();
}
