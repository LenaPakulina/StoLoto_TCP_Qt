#ifndef STARTFORM_H
#define STARTFORM_H

#include <QWidget>

namespace Ui {
class StartForm;
}

enum class GAME_OPTIONS {
	SINGLE_PLAY,
	MULTI_PLAY,
	UNKNOWN
};

class StartForm : public QWidget
{
	Q_OBJECT

public:
	explicit StartForm(QWidget *parent = nullptr);
	~StartForm();

	GAME_OPTIONS	getGameOptions() const;

public slots:
	void slotStartSinglePlay();
	void slotStartOnlinePlay();

signals:
	void sigLaunchGame();

private:
	Ui::StartForm *ui;
	GAME_OPTIONS	m_gameOptions;
};

#endif // STARTFORM_H
