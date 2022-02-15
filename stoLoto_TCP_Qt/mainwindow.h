#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class StartForm;
class LotoForm;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

public slots:
	void	slotStartGame();

private:
	Ui::MainWindow *ui;

	StartForm	*m_startForm;
	LotoForm	*m_lotoForm;
};
#endif // MAINWINDOW_H
