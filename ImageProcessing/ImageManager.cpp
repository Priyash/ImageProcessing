#include"ImageManager.h"

//=================================================IMAGE_MANAGER_CLASS_START==========================================================


ImageManager::ImageManager()
{
	iFact = new ImageFactory();
	dataManager = new DataManager();
}

ImageManager::~ImageManager()
{

}


void ImageManager::start_image_processing()
{	
	dataManager->listFiles(IMAGE_BASE_PATH);
	dataManager->printData();
	iFact->Init_Image_Processing(dataManager->getFiles());
}



//=================================================IMAGE_MANAGER_CLASS_END==========================================================