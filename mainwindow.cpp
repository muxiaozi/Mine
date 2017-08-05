#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>

#define min(x,y) (x) > (y) ? (y) : (x)

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
	gameController = new Thunder;
	ui->lblFlag->setText(tr("标记: %1").arg(gameController->getRestFlag()));

    connect(ui->actionExitGame, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(about()));

	customDialog = NULL;
	countDownTimerID = startTimer(1000);
	startTime = QTime::currentTime();
}

MainWindow::~MainWindow(){
	killTimer(countDownTimerID);
	if(customDialog != NULL){
		delete customDialog;
	}
	delete gameController;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
	//计算每一个小块的宽度
	marginTop = statusBar()->height() + 40;
	quareWidth = min(contentsRect().width() / gameController->getWidth(),
						 (contentsRect().height() - marginTop) / gameController->getHeight());
	marginLeft = (contentsRect().width() - gameController->getWidth() * quareWidth) / 2;

    QMainWindow::paintEvent(event);
    QPainter painter(this);
	QPixmap pixmap(":/images/block.png");

	for(int w = 0; w < gameController->getWidth(); w++){
		for(int h = 0; h < gameController->getHeight(); h++){
			Node *node = gameController->at(h, w);
			painter.drawRect(quareWidth * w + marginLeft, quareWidth * h + marginTop,
				quareWidth, quareWidth);
			if(node->type == SHOW){
				painter.fillRect(quareWidth * w + 1 + marginLeft, quareWidth * h + marginTop + 1,
					quareWidth - 1, quareWidth - 1, QColor(200, 200, 200));
				if(node->num == -1){	//雷
					painter.drawPixmap(quareWidth * w + marginLeft, quareWidth * h + marginTop,
						quareWidth, quareWidth, pixmap, 512, 128, 128, 128);
				}else if(node->num == 0){	//空白
				}else{
					if(node->num < 7){
						painter.drawPixmap(quareWidth * w + marginLeft, quareWidth * h + marginTop,
							quareWidth, quareWidth, pixmap, 128 * (node->num - 1), 0, 128, 128);
					}else{
						painter.drawPixmap(quareWidth * w + marginLeft, quareWidth * h + marginTop,
							quareWidth, quareWidth, pixmap, 128 * (node->num - 7), 128, 128, 128);
					}
				}
			}else{
				painter.fillRect(quareWidth * w + 1 + marginLeft, quareWidth * h + marginTop + 1,
					quareWidth - 1, quareWidth - 1, QColor(100, 100, 100));
				switch(node->type){
				case UNKNOW:
					break;
				case FLAG:
					painter.drawPixmap(quareWidth * w + marginLeft, quareWidth * h + marginTop,
						quareWidth, quareWidth, pixmap, 256, 128, 128, 128);
					break;
				case MARK:
					painter.drawPixmap(quareWidth * w + marginLeft, quareWidth * h + marginTop,
						quareWidth, quareWidth, pixmap, 384, 128, 128, 128);
					break;
				}
			}
		}
	}
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	QMainWindow::mousePressEvent(event);

	//点击游戏外部区域不做判断
	if(event->pos().x() < marginLeft ||
			contentsRect().width() - event->pos().x() < marginLeft) return;
	if(event->pos().y() < marginTop ||
			event->pos().y() > marginTop + gameController->getHeight() * quareWidth) return;

	int y = (event->pos().x() - marginLeft) / quareWidth;
	int x = (event->pos().y()  - marginTop) / quareWidth;

	if(event->button() == Qt::LeftButton){
		if(!gameController->leftClick(x, y)){
			if(QMessageBox::warning(this, tr("游戏失败"), tr("是否重来?"),
										QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes){
				gameController->reset();
				startTime = QTime::currentTime();
			}else{
				close();
			}
		}
	}else if(event->button() == Qt::RightButton){
		ui->lblFlag->setText(QString(tr("标记: %1")).arg(gameController->getRestFlag()));
		if(!gameController->rightClick(x, y)){
			if(QMessageBox::warning(this, tr("游戏失败"), tr("是否重来?"),
										QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes){
				gameController->reset();
				startTime = QTime::currentTime();
			}else{
				close();
			}
		}
	}
	if(gameController->isGameOver()){
		if(QMessageBox::question(this, tr("胜利!"), tr("是否重来?"),
						QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes){
			gameController->reset();
			startTime = QTime::currentTime();
		}else{
			close();
		}
	}
	update();
}

void MainWindow::timerEvent(QTimerEvent *event)
{
	QMainWindow::timerEvent(event);
	if(event->timerId() == countDownTimerID){
		ui->lblTime->setText(QString(tr("时间: %1s")).arg(startTime.secsTo(QTime::currentTime())));
	}
}

void MainWindow::about(){
	QMessageBox::information(NULL, tr("关于"), tr("Made by shwppo!"), QMessageBox::Yes);
}

void MainWindow::on_actionLowLevel_triggered()
{
	gameController->setLevel(LOW);
	ui->lblFlag->setText(tr("标记: %1").arg(gameController->getRestFlag()));
	update();
}

void MainWindow::on_actionMidLevel_triggered()
{
	gameController->setLevel(MIDDLE);
	ui->lblFlag->setText(tr("标记: %1").arg(gameController->getRestFlag()));
	update();
}

void MainWindow::on_actionHighLevel_triggered()
{
	gameController->setLevel(HIGH);
	ui->lblFlag->setText(tr("标记: %1").arg(gameController->getRestFlag()));
	update();
}

void MainWindow::onCustom(int width, int height, int thunder)
{
	gameController->setLevel(width, height, thunder);\
	ui->lblFlag->setText(tr("标记: %1").arg(gameController->getRestFlag()));
	update();
}

void MainWindow::on_actionCustomLevel_triggered()
{
	if(customDialog == NULL){
		customDialog = new CustomThunderDialog(this);
		connect(customDialog, SIGNAL(onCommit(int,int,int)), this, SLOT(onCustom(int,int,int)));
	}
	customDialog->show();
}
