#include <iostream>
#include"Header.h"

using namespace std;


int main()
{
	string path;
	float** image_array;
	int rows, cols;

		path = "D:/Data Structures/Assignments/Assignment 1/Segmented Outputs/mIMD002.bmp";
		Mat image = imread(path);
		rows = image.rows;
		cols = image.cols;
		allocate(image_array, rows, cols);
		image_pixel_pickeing(image_array, rows, cols, image);
		lable_marking(image_array, rows, cols);

		display_new_image(image_array, rows, cols, image, path);
		delllocate(image_array, rows, cols);
	
	return 0;
}