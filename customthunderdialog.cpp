#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "customthunderdialog.h"
#include <QDebug>

CustomThunderDialog::CustomThunderDialog(QWidget *parent) : QDialog(parent)
{
	lblWidth.setText(tr("列数(1-50)"));
	editWidth.setValidator(new QIntValidator(1, 60, this));
	latWidth.addWidget(&lblWidth);
	latWidth.addWidget(&editWidth);
	latMain.addLayout(&latWidth);

	lblHeight.setText(tr("行数(1-30)"));
	editHeight.setValidator(new QIntValidator(1, 30, this));
	latHeight.addWidget(&lblHeight);
	latHeight.addWidget(&editHeight);
	latMain.addLayout(&latHeight);

	lblThunder.setText(tr("雷数(1-1000)"));
	editThunder.setValidator(new QIntValidator(1, 1000, this));
	latThunder.addWidget(&lblThunder);
	latThunder.addWidget(&editThunder);
	latMain.addLayout(&latThunder);

	btnOk.setText(tr("确定"));
	connect(&btnOk, SIGNAL(clicked(bool)), this, SLOT(onOkClick()));
	latMain.addWidget(&btnOk);

	setWindowTitle(tr("Custom"));
	setLayout(&latMain);
}

CustomThunderDialog::~CustomThunderDialog()
{
}

void CustomThunderDialog::onOkClick()
{
	int width = editWidth.text().toInt();
	int height = editHeight.text().toInt();
	int thunder = editThunder.text().toInt();
	emit onCommit(width, height, thunder);
	close();
}
