# Image-Processing-in-C--suing-OpenCV

This C++ code includes a set of functions that process images. The code can read an image file, apply a thresholding function, perform k-means clustering, and compare two images to check for discrepancies. The code is designed to be versatile and easy to modify.

### _Functions_
image_pixel_pickeing

### _Copy code_
![image](https://user-images.githubusercontent.com/115175167/229116687-9964f61c-7847-49a8-af6a-fe2cd394f1b2.png)

This function takes in a 2D array, a row and column size, and an image file. It reads the image and stores the pixel values in the 2D array.

### _thresholding_

![image](https://user-images.githubusercontent.com/115175167/229117047-75b6b469-637d-408f-a187-7b15691376c8.png)


This function takes in a 2D array, a row and column size, and a threshold value. It compares each pixel value to the threshold value and sets it to either 0 or 255.

### _labeling_

![image](https://user-images.githubusercontent.com/115175167/229117108-345010dc-508d-4da4-94f1-22e004eb4f42.png)

This function takes in a 2D array, a row and column size. It applies a labeling algorithm to the array, assigning each group of adjacent pixels with the same value a unique label.

### _min_

![image](https://user-images.githubusercontent.com/115175167/229117160-2e49b1d7-64f7-4bdc-94d6-ee373e5c2170.png)

This function takes in two values and two integer pointers. It returns the smaller of the two values and increments the appropriate counter based on which value was returned.

### _display_

![image](https://user-images.githubusercontent.com/115175167/229117558-6a8cb24a-25c1-4f6d-ac6a-b4d457302881.png)

This function takes in a 2D array and its row and column size. It displays the array.

### _allocate_

![image](https://user-images.githubusercontent.com/115175167/229117617-1a03f9d1-b023-4eed-b55a-cbd00b37d883.png)

This function takes in a 2D array, a row and column size. It allocates memory for the array.

### _delllocate_

![image](https://user-images.githubusercontent.com/115175167/229117670-e4e4a47f-188f-4f3d-88b2-ad33b80f9e07.png)

This function takes in a 2D array and its row and column size. It deallocates the memory for the array.

### _display_new_image_

  ![image](https://user-images.githubusercontent.com/115175167/229117236-0c3026e5-10e0-4dc2-b89f-94ede567c1a2.png)

This function takes in a 2D array, its row and column size, an image file, and a file path. It creates a new image file with the pixel values from the array and displays it.

### _check_

![image](https://user-images.githubusercontent.com/115175167/229117276-fddd5a5a-f683-404f-abbf-789e789119b5.png)
  
This function takes in an image file path, the row and column size of a 2D array, and the array itself. It compares the pixel values of the image file with the pixel values of the array and prints the number of discrepancies.

### _minimun_

  ![image](https://user-images.githubusercontent.com/115175167/229117443-83b713e0-d01f-4e6e-9838-b097673a1850.png)

This function takes in a value and returns its absolute value.

### _K_Mean_clustering_

  ![image](https://user-images.githubusercontent.com/115175167/229117391-9c96259c-77c9-4e51-9bf0-e00e1bbd2c8f.png)
  
This function takes in a 2D array, its row and column size, two integer values for the initial centroids, and a file path. It applies a k-means clustering algorithm to the array, replacing the pixel values with either
