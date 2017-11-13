#ifndef IMAGE_H
#define IMAGE_H

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<vector>
#include<string>

using namespace std;



class IImageAdapter
{

public:
	virtual void loadImageData(vector<string>images_list) = 0;
	virtual void detectFrontalFaces() = 0;
	virtual void showDetectedFaces() = 0;
};


class ImageAdapter :public IImageAdapter
{
	string FULL_CLASSIFIER_PATH;
	const string CLASSIFIER_BASE_PATH = "C:\\Users\\PRIYASH_11\\Documents\\Softwares\\opencv\\sources\\data\\haarcascades\\";
	const string CLASSIFIER_XML_PATH = "haarcascade_frontalface_alt.xml";
	const string CLASSIFIER_NAME = "Harcascade";
	const string IMAGE_BASE_PATH = "Image_Input_Data\\";
	const string IMAGE_FILE_NAME = "";
	const string FULL_IMAGE_PATH;
	//vector<string>images_list;

	vector<cv::Mat>face_images_mat;
	vector<cv::Rect_<int>>rect_faces;
public:
	ImageAdapter();
	~ImageAdapter();
	void loadImageData(vector<string>images_list);
	void detectFrontalFaces();
	void showDetectedFaces();

private:
	void detectFrontalFaces(vector<cv::Mat>&img, vector<cv::Rect_<int> >& faces, string cascade_path);
	void detectFacialFeatures(cv::Mat& img, const vector<cv::Rect_<int>> faces);

private:

};





class IImageFactory
{
	
public:
	virtual void Init_Image_Processing(vector<string>images_list) = 0;
	virtual void show_detected_faces() = 0;
};


class ImageFactory : public IImageFactory
{
	
	IImageAdapter* image;
public:
	ImageFactory();
	~ImageFactory();
	void Init_Image_Processing(vector<string>images_list);
	void show_detected_faces();
};



#endif
