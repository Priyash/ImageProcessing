#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H
#include"Image.h"
#include"DataManager.h"

using namespace std;

class ImageManager
{

	IImageFactory* iFact;
	DataManager* dataManager;
	const string& IMAGE_BASE_PATH = "Image_Input_Data\\";
public:
	ImageManager();
	~ImageManager();
	void start_image_processing();
};



#endif