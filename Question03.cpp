#include"Header.h"
#include <iostream>

using namespace std;

int main()
{
	string path= "D:/Data Structures/Assignments/Assignment 1/Segmented Outputs/mIMD002.bmp";
	string patr = "D:/Data Structures/Assignments/Assignment 1/Ground Truths/IMD002_lesion.bmp";

	int Tp = 0;
	int FP = 0;
	int FN = 0;

	Mat img = imread(path);
	Mat img2 = imread(patr);
	float** image;
	float** check;
	allocate(image, img.rows, img.cols);
	image_pixel_pickeing(image, img.rows, img.cols, img);
	allocate(check, img2.rows, img2.cols);
	image_pixel_pickeing(check, img2.rows, img2.cols, img2);
	float** image2;
	allocate(image2, img.rows, img.cols);
	K_Mean_clustering(image2, img.rows, img.cols, 0, 255, path);
	
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			if (image[i][j] == 255 && check[i][j] == 255)
			{
				Tp++;
			}
			else if(image[i][j]==255 && check[i][j]==0)
			{
				FP++;
			}
			else if (image[i][j] == 0 && check[i][j] == 255)
			{
				FN++;
			}
		}
	}


	float dice_cofficcient = float(2 * Tp) / (FN + (2 * Tp) + FP);
	cout << "Total number of pixels             = " << img.rows * img.cols << endl;
	cout << "---------------------------------------------------------------------------------\n";
	cout << "Number of False Negative are       = " << FN << endl;
	cout << "Number of False positive are       = " << FP << endl;
	cout << "Number if matched lables are       = " << Tp << endl;
	cout <<"The dice coefficent is             = " << dice_cofficcient<<endl;
	cout << "---------------------------------------------------------------------------------\n";
	FN = FP = Tp = 0;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			if (image2[i][j] == 255 && check[i][j] == 255)
			{
				Tp++;
			}
			else if (image2[i][j] == 255 && check[i][j] == 0)
			{
				FP++;
			}
			else if (image2[i][j] == 0 && check[i][j] == 255)
			{
				FN++;
			}
		}
	}
	dice_cofficcient = float(2 * Tp) / (FN + (2 * Tp) + FP);
	cout << "Number of False Negative are       = " << FN << endl;
	cout << "Number of False positive are       = " << FP << endl;
	cout << "Number if matched lables are       = " << Tp << endl;
	cout << "The dice coefficent is             = " << dice_cofficcient << endl;
	cout << "---------------------------------------------------------------------------------\n";
	return 0;
}