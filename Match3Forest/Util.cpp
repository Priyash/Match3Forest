#include "Util.h"



Utility::Utility(string name)
{
	this->name = name;
}


Utility::~Utility()
{

}

string Utility::getUtilType()
{
	return name;
}

void Utility::openConfigFile(string file)
{
	ifstream json_reader;
	json_reader.open(file.c_str(), ios::in);
	IStreamWrapper wrapper_stream(json_reader);

	doc.ParseStream(wrapper_stream);

}

void Utility::readConfigFile()
{

}


//==============================================================UTIL_MANAGER===========================================


UtilManager::UtilManager()
{

}


UtilManager::~UtilManager()
{

}


IUtil* UtilManager::createUtilObject(string util_object_name)
{
	IUtil* utility = new Utility(util_object_name);
	return utility;
}

void UtilManager::add(IUtil* util)
{
	if (util != nullptr)
	{
		util_list.insert(pair<string, IUtil*>(util->getUtilType(), util));
	}
}
