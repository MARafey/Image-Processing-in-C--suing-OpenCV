#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include"Header.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int r = 0;
	int k = 255;
	float** image_array;
	string path;
	int rows, cols;

	path = "D:\IMD002.bmp";
	Mat image = imread(path);
	rows = image.rows;
	cols = image.cols;
	allocate(image_array, rows, cols);
	image_pixel_pickeing(image_array, rows, cols, image);

	K_Mean_clustering(image_array, rows, cols, r, k, path);
	Mat img = imread(path);
	
	//lable_marking(image_array, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			img.at<Vec3b>(i, j)[0] = image_array[i][j];
			img.at<Vec3b>(i, j)[1] = image_array[i][j];
			img.at<Vec3b>(i, j)[2] = image_array[i][j];
		}
	}
	imshow("Window01.bmp", image);
	imshow("Window02.bmp", img);
	waitKey(0);

	imwrite("D:\IMD002_copy_Question02.bmp", img);
	delllocate(image_array, rows, cols);

	return 0;
}

