# Image-Processing-in-C--suing-OpenCV

This C++ code includes a set of functions that process images. The code can read an image file, apply a thresholding function, perform k-means clustering, and compare two images to check for discrepancies. The code is designed to be versatile and easy to modify.

### _Functions_
image_pixel_pickeing

### _Copy code_
![image](https://user-images.githubusercontent.com/115175167/229116687-9964f61c-7847-49a8-af6a-fe2cd394f1b2.png)

This function takes in a 2D array, a row and column size, and an image file. It reads the image and stores the pixel values in the 2D array.

### _thresholding_

template <typename T>
void thresholding(T**& arr, int rows, int cols, int threshold);
This function takes in a 2D array, a row and column size, and a threshold value. It compares each pixel value to the threshold value and sets it to either 0 or 255.

### _labeling_

template <typename T>
void labeling(T**& arr, int rows, int cols);
This function takes in a 2D array, a row and column size. It applies a labeling algorithm to the array, assigning each group of adjacent pixels with the same value a unique label.

### _min_

template <typename T>
T min(T a, T b, int* counter_r, int* counter_k);
This function takes in two values and two integer pointers. It returns the smaller of the two values and increments the appropriate counter based on which value was returned.

### _display_

template <typename T>
void display(float** image_array, T rows, T cols);
This function takes in a 2D array and its row and column size. It displays the array.

### _allocate_

template <typename T>
void allocate(T**& arr, int rows, int cols);
This function takes in a 2D array, a row and column size. It allocates memory for the array.

### _delllocate_

template <typename T>
void delllocate(T** arr, int rows, int cols);
This function takes in a 2D array and its row and column size. It deallocates the memory for the array.

### _display_new_image_

template <typename T>
void display_new_image(T** image_array, int rows, int cols, Mat image, string path);
This function takes in a 2D array, its row and column size, an image file, and a file path. It creates a new image file with the pixel values from the array and displays it.

### _check_

template <typename T>
void check(string path,int rows,int cols,T**& image_array);
This function takes in an image file path, the row and column size of a 2D array, and the array itself. It compares the pixel values of the image file with the pixel values of the array and prints the number of discrepancies.

### _minimun_

template <typename T>
T minimun(T a);
This function takes in a value and returns its absolute value.

### _K_Mean_clustering_

void K_Mean_clustering(float**& image_array, int rows, int cols, int c1, int c2, string path);
This function takes in a 2D array, its row and column size, two integer values for the initial centroids, and a file path. It applies a k-means clustering algorithm to the array, replacing the pixel values with either
