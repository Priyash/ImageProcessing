#include"DataManager.h"


DataAdapter::DataAdapter()
{

}


DataAdapter::~DataAdapter()
{

}

string DataAdapter::ToString(WCHAR* data)
{
	wstring wstr(data);
	string temp_str(wstr.begin(), wstr.end());
	return temp_str;
}


vector<string> DataAdapter::listFiles(const string& dir_name)
{
	wstring pattern(dir_name.begin(), dir_name.end());
	pattern.append(L"*.*");
	if ((handler = FindFirstFile(pattern.c_str(), &fdata)) != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (fdata.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
			{
				if (wcscmp(fdata.cFileName, L".") != 0 && wcscmp(fdata.cFileName, L"..") != 0)
				{
					//FOUND THE DIRECTORY
					
				}
			}
			else
			{
				//FILES 
				files.push_back(ToString(fdata.cFileName));

			}

		} while (FindNextFile(handler, &fdata));
		
	}
	else
	{
		cout << "Error with handler" << endl;
	}

	return files;
}




DataManager::DataManager()
{
	adapter = new DataAdapter();
}

DataManager::~DataManager()
{

}

void DataManager::listFiles(const string& dir_name)
{
	files = adapter->listFiles(dir_name);
}

vector<string> DataManager::getFiles()
{
	return files;
}

void DataManager::printData()
{
	for (auto i : files)
	{
		cout << i << endl;
	}
}

