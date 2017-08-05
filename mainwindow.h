#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

#include "thunder.h"
#include "customthunderdialog.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
	void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;
	void timerEvent(QTimerEvent *) Q_DECL_OVERRIDE;

private slots:
	void about();
	void on_actionLowLevel_triggered();
	void on_actionMidLevel_triggered();
	void on_actionHighLevel_triggered();
	void on_actionCustomLevel_triggered();

public slots:
	void onCustom(int, int, int);

private:
	Ui::MainWindow *ui;
	CustomThunderDialog *customDialog;
	Thunder *gameController;

	int quareWidth;	//方格宽度
	int marginTop;	//距离顶部的间距
	int marginLeft;	//左边距

	QTime startTime;
	int countDownTimerID; //倒计时ID
};

#endif // MAINWINDOW_H
