#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include<iostream>
#include<vector>
#include<Windows.h>
#include<string>
#include<algorithm>
#include<assert.h>
#include<cstdlib>
#include<array>
#include<ctime>
#include<ratio>
#include<chrono>


using namespace std;
using namespace chrono;


class IDataAdapter
{

public:
	virtual vector<string> listFiles(const string& dir_name) = 0;
};


class DataAdapter : public IDataAdapter
{
	HANDLE handler;
	WIN32_FIND_DATA fdata;
	vector<string>files;
	
private:
	string ToString(WCHAR* text);
public:
	DataAdapter();
	~DataAdapter();
	vector<string> listFiles(const string& dir_name);
};


class DataManager
{
	IDataAdapter* adapter;
	vector<string>files;
public:
	DataManager();
	~DataManager();
	void listFiles(const string& dir_name);
	vector<string> getFiles();
	void printData();


};

#endif