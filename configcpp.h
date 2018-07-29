#ifndef CONFIGCPP_H
#define CONFIGCPP_H
#include <QString>

class configCPP
{
public:
	configCPP();
	void setAddonTag(QString str);
	void setNameSpace(QString str);
	void setTerrainName(QString str);
	void setClassName(QString str);
	void setTerrainSize(QString str);
	void setAuthorName(QString str);
	void saveConfigFile(QString fileName);

private:
	void readTemplateCPP();
	void replaceCppValues();
	QString cppTemplate, addonTag, cppNameSpace, terrainName, className, terrainSize, authorName;
	long terrainSizeNumber;
};

#endif // CONFIGCPP_H
