#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace cv;
using namespace std;


template <typename T>
void display_image(float** image_array, T rows, T cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			cout << image_array[i][j] << ",";

		}
		cout << endl;
	}
}

template <typename T>
void image_pixel_pickeing(float**& image_array, T rows, T cols, Mat image)
{
	T r, b, g;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			r = image.at<Vec3b>(i, j)[0];//red
			b = image.at<Vec3b>(i, j)[1];//blue
			g = image.at<Vec3b>(i, j)[2];//green

			image_array[i][j] = T(r + b + g) / 3;
		}
	}
}

void lable_marking(float** arr, int rows, int cols)
{
	int lable = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] != 0)
			{
				arr[i][j] = lable;
				if (i > 0) {
					if (arr[i - 1][j] != 0)
					{
						arr[i - 1][j] = min(arr[i][j], arr[i - 1][j]);
						arr[i][j] = min(arr[i][j], arr[i - 1][j]);
					}
					if (j < cols && j > 0) {
						if (arr[i - 1][j + 1] != 0)
						{
							arr[i - 1][j + 1] = min(arr[i][j], arr[i - 1][j + 1]);
							arr[i][j] = min(arr[i][j], arr[i - 1][j + 1]);
						}

						if (arr[i - 1][j - 1] != 0)
						{
							arr[i - 1][j - 1] = min(arr[i][j], arr[i - 1][j - 1]);
							arr[i][j] = min(arr[i][j], arr[i - 1][j - 1]);
						}
					}
				}
				if (arr[i][j - 1] != 0)
				{
					arr[i][j - 1] = min(arr[i][j], arr[i][j - 1]);
					arr[i][j] = min(arr[i][j], arr[i][j - 1]);
				}
			}
			lable++;
		}
	}
	int loop = 0;
	while (loop<200)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] != 0)
				{
					if (i > 0) {
						if (arr[i - 1][j] != 0)
						{
							arr[i - 1][j] = min(arr[i][j], arr[i - 1][j]);
							arr[i][j] = min(arr[i][j], arr[i - 1][j]);
						}
						if (j < cols && j > 0) {
							if (arr[i - 1][j + 1] != 0)
							{
								arr[i - 1][j + 1] = min(arr[i][j], arr[i - 1][j + 1]);
								arr[i][j] = min(arr[i][j], arr[i - 1][j + 1]);
							}

							if (arr[i - 1][j - 1] != 0)
							{
								arr[i - 1][j - 1] = min(arr[i][j], arr[i - 1][j - 1]);
								arr[i][j] = min(arr[i][j], arr[i - 1][j - 1]);
							}
						}
					}
					if (arr[i][j - 1] != 0)
					{
						arr[i][j - 1] = min(arr[i][j], arr[i][j - 1]);
						arr[i][j] = min(arr[i][j], arr[i][j - 1]);
					}
				}
			}
		}
		loop++;
	}

	int* frequency = new int[lable];
	for (int i = 0; i < lable; i++)
	{
		frequency[i] = 0;
	}
	int a;
	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < cols; k++)
		{
			a = int(arr[j][k]);
			frequency[a] += 1;
		}
	}

	int max = frequency[1];
	int index = 1;
	for (int i = 1; i < lable; i++)
	{
		if (max < frequency[i])
		{
			index = i;
			max = frequency[i];
		}
	}

	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < cols; k++)
		{
			if (arr[j][k] != index)
			{
				arr[j][k] = 0;
			}
		}
	}

	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < cols; k++)
		{
			if (arr[j][k] == index)
			{
				arr[j][k] = 255;
			}
		}
	}

	
}

template <typename T>
T min(T a, T b, int* counter_r, int* counter_k)
{
	if (a < b)
	{
		*counter_r = *counter_r + 1;
		return a;
	}
	else
	{
		*counter_k = *counter_k + 1;
		return b;
	}
}

template <typename T>
void display(float** image_array, T rows, T cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << image_array[i][j] << " ";
		}
	}
}

template <typename T>
void allocate(T**& arr, int rows, int cols)
{
	arr = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{0};
	}
}

template <typename T>
void delllocate(T** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template <typename T>
void display_new_image(T** image_array, int rows, int cols, Mat image, string path)
{
	Mat ima = imread(path);
	ima.rows = rows;
	ima.cols = cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			ima.at<Vec3b>(i, j)[2] = image_array[i][j];
			ima.at<Vec3b>(i, j)[1] = image_array[i][j];
			ima.at<Vec3b>(i, j)[0] = image_array[i][j];
		}
	}
	imshow("Window01.bmp", image);
	imshow("Window02.bmp", ima);
	waitKey(0);
}

template <typename T>
void check(string path,int rows,int cols,T**& image_array)
{
	Mat obj = imread(path);
	Mat labelled_img(obj.rows, obj.cols, obj.type());
	int rows2 = obj.rows;
	int cols2 = obj.cols;
	float** image_array_ans = new float* [rows2];
	for (int i = 0; i < rows; i++)
	{
		image_array_ans[i] = new float[cols2] {0};
	}
	image_pixel_pickeing(image_array_ans, rows, cols, obj);

	int flag = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (image_array[i][j] != image_array_ans[i][j])
			{
				flag += 1;
				/*cout << "NOT Equal" << endl;
				break;*/
			}
		}
	}
	cout << "mismatchs = " << flag << " out of = " << rows * cols << endl;
	//}	
}


template <typename T>
T minimun(T a)
{
	if (a < 0)
	{
		a = a * -1;
		return a;
	}
	return a;
}


//template <typename T>
void K_Mean_clustering(float**& image_array, int rows, int cols, int c1, int c2, string path)
{
	int previous_c1 = 0;
	int previous_c2 = 0;
	float** cluster = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		cluster[i] = new float[cols] {0};
	}
	int sum_1 = 0;
	int sum_2 = 0;
	int count_1 = 0;
	int count_2 = 0;
	while (previous_c2 != c2 && previous_c1 != c1)
	{
		previous_c1 = c1;
		previous_c2 = c2;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{

				if (minimun(image_array[i][j] - c1) < minimun(image_array[i][j] - c2))
				{
					count_1++;
					sum_1 += image_array[i][j];
				}
				else
				{
					count_2++;
					sum_2 += image_array[i][j];
				}
			}
		}
		c1 = sum_1 / count_1;
		c2 = sum_2 / count_2;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (minimun(image_array[i][j] - c1) < minimun(image_array[i][j] - c2))
			{
				cluster[i][j] = 255;
			}
			else
			{
				cluster[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			image_array[i][j] = cluster[i][j];
		}
	}
}


