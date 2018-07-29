#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "configcpp.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = nullptr);
	~Widget();

private slots:
	void on_checkBox_useAddonTag_stateChanged(int arg1);

	void on_checkBox_fromName_stateChanged(int arg1);

	void on_lineEdit_terrainName_textChanged(const QString &arg1);

	void on_pushButton_createConfig_clicked();

private:
	Ui::Widget *ui;
	QString getClassName(QString terrainName);
	configCPP ccpp = configCPP();
	QString pmcVersion = "v0.0.1";
};

#endif // WIDGET_H
