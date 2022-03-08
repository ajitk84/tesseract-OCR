#include <iostream>
#include <stdio.h>
#include <direct.h>

#include <allheaders.h>
#include <baseapi.h>


void main(int argc, char** argv)
{
	static tesseract::TessBaseAPI api;
	//char* datapath = nullptr;

	api.SetOutputName("D:/OCR_Test/output.txt");

   /* main() calls functions like ParseArgs which call exit().
   * This results in memory leaks if vars_vec and vars_values are
   * declared as auto variables (destructor is not called then). */
	const std::vector<std::string> vars_vec;
	const std::vector<std::string> vars_values;
	const char* datapath = "D:/OCR_Test/OCR/tessdata";
	const char lang[10] = "deu";
	tesseract::OcrEngineMode enginemode = tesseract::OEM_TESSERACT_ONLY;
	const int init_failed = api.Init(datapath, lang);

	// Open input image with leptonica library
	Pix* image = pixRead(argv[1]);
	api.SetImage(image);

	// Get OCR result
	char* outText = api.GetUTF8Text();
	printf("OCR output:\n%s", outText);

	// Destroy used object and release memory
	api.End();
	delete[] outText;
	pixDestroy(&image);

	//return 0;
	/*cv::Mat srcImg = cv::imread("D:/OCR_Test/testImg.JPG", 1);

	cv::Mat grayImg;
	cv::cvtColor(srcImg, grayImg, cv::COLOR_RGB2GRAY);
	cv::imshow("None approximation", grayImg);
	cv::waitKey(0);

	cv::Mat imgBW;
	cv::threshold(grayImg, imgBW, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	cv::imshow("None approximation", imgBW);
	cv::waitKey(0);

	cv::Mat rect_kernal = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(18, 18));

	cv::Mat dilatedImg;
	cv::dilate(imgBW, dilatedImg, rect_kernal);

	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::findContours(dilatedImg, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

	cv::Mat image_copy = srcImg.clone();
    cv::drawContours(image_copy, contours, -1, cv::Scalar(0, 255, 0), 2);
    cv::imshow("None approximation", image_copy);
	cv::waitKey(0);*/

}