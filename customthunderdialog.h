#ifndef CUSTOMTHUNDERDIALOG_H
#define CUSTOMTHUNDERDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>
#include <QValidator>

class CustomThunderDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CustomThunderDialog(QWidget *parent = 0);
	~CustomThunderDialog();

public slots:
	void onOkClick();

signals:
	void onCommit(int, int, int);

private:
	QLabel lblWidth, lblHeight, lblThunder;
	QLineEdit editWidth, editHeight, editThunder;
	QHBoxLayout latWidth, latHeight, latThunder;
	QVBoxLayout latMain;
	QPushButton btnOk;

};

#endif // CUSTOMTHUNDERDIALOG_H
