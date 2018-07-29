#include "configcpp.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

configCPP::configCPP()
{
}

// public

void configCPP::setAddonTag(QString str)
{
	addonTag = str;
}

void configCPP::setNameSpace(QString str)
{
	cppNameSpace = str;
}

void configCPP::setTerrainName(QString str)
{
	terrainName = str;
}

void configCPP::setClassName(QString str)
{
	className = str;
}

void configCPP::setTerrainSize(QString str)
{
	terrainSize = str;
	bool ok;
	terrainSizeNumber = str.toLong(&ok, 10);
}

void configCPP::setAuthorName(QString str)
{
	authorName = str;
}

void configCPP::saveConfigFile(QString fileName)
{
	readTemplateCPP();
	replaceCppValues();

	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QMessageBox msgBox;
		msgBox.setText("Error writing config file!");
		msgBox.exec();
		return;
	}

	QTextStream out(&file);
	out << cppTemplate;
	file.close();
}


// private

void configCPP::readTemplateCPP()
{
	QString fileName(":/template_configcpp.txt");
	QFile cppTmpFile(fileName);
	cppTmpFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&cppTmpFile);
	cppTemplate = stream.readAll();
	cppTmpFile.close();
}

void configCPP::replaceCppValues()
{
	cppTemplate.replace("TERRAINNAME", terrainName);
	cppTemplate.replace("CLASSNAME", className);
	cppTemplate.replace("NAMESPACE", cppNameSpace);
	cppTemplate.replace("AUTHORNAME", authorName);
	cppTemplate.replace("TERRAINSIZE", terrainSize);
	cppTemplate.replace("TERRAINHALFSIZE", QString::number((terrainSizeNumber / 2)));
}
