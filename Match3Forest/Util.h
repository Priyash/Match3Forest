#ifndef UTIL_H
#define UTIL_H
#include<map>
#include <rapidjson\document.h>
#include <rapidjson\writer.h>
#include <rapidjson\stringbuffer.h>
#include <rapidjson\istreamwrapper.h>
#include<fstream>

using namespace std;
using namespace rapidjson;


class IUtil
{
public:
	IUtil() {}
	~IUtil() {}
	virtual void openConfigFile(string) = 0;
	virtual void readConfigFile() = 0;
	virtual string getUtilType() = 0;
};


class Utility : public IUtil
{
	map<string, string>resource_list;
	Document doc;
	string name;
public:
	Utility(string name);
	~Utility();

	void openConfigFile(string file);
	void readConfigFile();
	string getUtilType();
};


class UtilManager
{
	map<string, IUtil*>util_list;
	UtilManager();
	static UtilManager* instance;
public:
	~UtilManager();

	static UtilManager* getInstance();

	IUtil* createUtilObject(string);
	void add(IUtil*);
};


#endif

