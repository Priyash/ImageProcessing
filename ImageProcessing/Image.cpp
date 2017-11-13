#include "Image.h"

using namespace cv;

//=================================================IMAGE_CLASS_START=======================================================

ImageAdapter::ImageAdapter()
{
	FULL_CLASSIFIER_PATH = CLASSIFIER_BASE_PATH + CLASSIFIER_XML_PATH;
}

ImageAdapter::~ImageAdapter()
{

}


void ImageAdapter::loadImageData(vector<string>images)
{
	Mat img;
	for (auto i : images)
	{
		cout << "Transforming image to image matrix " + i << endl;
		img = imread(IMAGE_BASE_PATH + i);
		face_images_mat.push_back(img);

		break;
	}
}


void ImageAdapter::detectFrontalFaces(vector<Mat>& img, vector<Rect_<int> >& faces, string cascade_path)
{
	cout << "Detecting frontal face in the image . . ." << endl;
	cout << "Cascade Path " << cascade_path << endl;
	for (auto i : img)
	{
		CascadeClassifier face_cascade;
		face_cascade.load(cascade_path);
		cout << "Loaded cascade classifier " << endl;
		face_cascade.detectMultiScale(i, faces, 1.15, 3, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
		cout << "Detecting multiscale successfull " << endl;
		detectFacialFeatures(i, faces);
		break;
	}
	
	return;
}

void ImageAdapter::detectFrontalFaces()
{
	detectFrontalFaces(face_images_mat, rect_faces, FULL_CLASSIFIER_PATH);
}


void ImageAdapter::detectFacialFeatures(Mat& img, const vector<Rect_<int>> faces)
{
	cout << "Detecting facial features in the image . . ." << endl;
	Rect face;
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		face = faces[i];
		rectangle(img, Point(face.x, face.y), Point(face.x + face.width, face.y + face.height), Scalar(255, 0, 0), 1, 4);
		//Mat ROI = img(Rect(face.x, face.y, face.width, face.height));
		break;
	}
}

void ImageAdapter::showDetectedFaces()
{

	for (auto i : face_images_mat)
	{
		imshow(CLASSIFIER_NAME, i);
		waitKey(0);
	}
}

//=================================================IMAGE_CLASS_END==========================================================



//=================================================IMAGE_FACTORY_CLASS_START==========================================================



ImageFactory::ImageFactory()
{
	image = new ImageAdapter();
}

ImageFactory::~ImageFactory()
{

}

void ImageFactory::Init_Image_Processing(vector<string>images_list)
{
	image->loadImageData(images_list);
	image->detectFrontalFaces();
}


void ImageFactory::show_detected_faces()
{
	image->showDetectedFaces();
}

//=================================================IMAGE_FACTORY_CLASS_END==========================================================
