#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
	setWindowTitle("Terrain Config Creator " + pmcVersion + " (c) PMC");
}

Widget::~Widget()
{
	delete ui;
}

// namespace tickbox
void Widget::on_checkBox_useAddonTag_stateChanged(int arg1)
{
	if (arg1)
	{
		ui->lineEdit_nameSpace->setText(ui->lineEdit_addonTag->text());
		ui->lineEdit_nameSpace->setDisabled(true);
	}
	else
	{
		ui->lineEdit_nameSpace->setEnabled(true);
	}
}

// class name tickbox
void Widget::on_checkBox_fromName_stateChanged(int arg1)
{
	if (arg1)
	{
		ui->lineEdit_terrainClassName->setText(ui->lineEdit_addonTag->text() + "_" + getClassName(ui->lineEdit_terrainName->text()));
		ui->lineEdit_terrainClassName->setDisabled(true);
	}
	else
	{
		ui->lineEdit_terrainClassName->setEnabled(true);
	}
}


QString Widget::getClassName(QString terrainName)
{
	terrainName.replace(" ", "_");
	terrainName = terrainName.toLower();

	return terrainName;
}

// terrain name changed
void Widget::on_lineEdit_terrainName_textChanged(const QString &arg1)
{
	if (ui->checkBox_fromName->isChecked())
	{
		ui->lineEdit_terrainClassName->setText(getClassName(arg1));
	}
}

// save
void Widget::on_pushButton_createConfig_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this,
	tr("Save new config.cpp"), "",
	tr("ArmA Config (*.cpp);;All Files (*)"));

	if (fileName.isEmpty())
		return;
	else
	{
		ccpp.setAddonTag(ui->lineEdit_addonTag->text());
		ccpp.setAuthorName(ui->lineEdit_author->text());
		ccpp.setClassName(getClassName(ui->lineEdit_terrainClassName->text()));
		ccpp.setNameSpace(ui->lineEdit_nameSpace->text());
		ccpp.setTerrainName(ui->lineEdit_terrainName->text());
		ccpp.setTerrainSize(ui->spinBox_terrainSize->text());

		// send file name to ccpp
		ccpp.saveConfigFile(fileName);
	}
}
