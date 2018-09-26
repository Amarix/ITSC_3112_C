#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "image_File_Array.h"

// The largest and smallest pixel values in the image file.
// These will be changed as the array of pixels is populated.
// These are used to scale the pixel values to a number between 0 and 255
// so that the image can be displayed in a color grid in bridges.
int image_File_Array::max_Pixel_Value = 0;
int image_File_Array::min_Pixel_Value = 10000;

// values for the height and width of the array that will hold the pixel values.
// they will be changed after the array has been built.
int image_File_Array::image_Height = 0;
int image_File_Array::image_Width = 0;

int** image_File_Array::image_Array;  // array that will hold the image values

int image_File_Array::counter = 0; // a counter to ensure the array is initalized only once.

image_File_Array::image_File_Array()
{

}

/**
    This method uses in input file stream to read the list of values from an image.dat file.
**/
int** image_File_Array::generate(std::string imgLocation)
{
    std::ifstream imgFile (imgLocation); // read from file at location

    int i = -1;
    int k = 0;

    int intVal; // a value for each pixel in the array

    if (!imgFile){ // test to make sure the file is available

        std::cout << "Failed to open file" << std::endl; // print this if file was not found

    }
    else for (std::string ln; getline(imgFile, ln); i++){ // iterate through each line of the file. The lines become rows in the array. Add one to the number of lines in the array.

        std::istringstream iss(ln); // input stream for each row

        if (i == -1){ // the first line will not be added to the array. It is broken down to find the width and height of the array.

            int pos = ln.find_first_of("x"); // split the demensions of the image by the x. IE 844x480 w = 844 h = 480

            int imgHeight = stoi(ln.substr(0, pos)); // value before the delimiter
            int imgWidth = stoi(ln.substr(pos+1)); // value after the delimiter

            image_File_Array::image_Height = imgHeight; // subtract one for the first line (signature line of a .dat file)
            image_File_Array::image_Width = imgWidth; // the width of the image based on the longest row to avoid out of bounds exceptions.

        }
        else{

            while (iss >> intVal){ // iterate through the row and separate the values for the columns of the array.

                if (intVal > image_File_Array::max_Pixel_Value){ // if the current value being passed is greater than the saved max value
                    image_File_Array::max_Pixel_Value = intVal; // the new max value is the current value
                }
                else if (intVal < image_File_Array::min_Pixel_Value){ // if the current value being passed is less than the saved min value
                    image_File_Array::min_Pixel_Value = intVal; // the new min value is the current value
                }

                this->image_File_Array::fill_Image_Array(i, k, intVal); // call the fill image array function with the current location of the pixel and the pixels value.
                k++;
            }
            k = 0; // prepare for next row
        }
    }

    return image_File_Array::image_Array; // return the array once it has been filled and scaled
}

/**
    This method will initalize the main array by its size the first time it is called.
    It will use the curent location of the pixel and the pixel value to fill the array once it has been initalized.
    It will also send the value to the scale method to fill the array with values between 0 and 255.

**/
void image_File_Array::fill_Image_Array(int curWidth, int curHeight, int curVal)
{

    if (image_File_Array::counter == 0){// first time it is called.

        // height and width obtained by the generate method
        int h = image_File_Array::image_Height;
        int w = image_File_Array::image_Width;

        // initalize the hight
        image_File_Array::image_Array = new int*[h];

        // fill in the width
        for (int i = 0; i < h; i++){
            image_File_Array::image_Array[i] = new int[w];
            for (int j = 0; j < w; j++){
                // set all values at 0 for now.
                image_File_Array::image_Array[i][j] = 0;
            }
        }
        // change the counter so this wont run again.
        image_File_Array::counter = 1;
    }

    // a value for the scaled pixel
    int scaledPixVal;

    scaledPixVal = image_File_Array::scale_Pixel_Values(curVal); // call the scale method using the current pixel value as an argument to received the scaled pixel.
    image_File_Array::image_Array[curWidth][curHeight] = scaledPixVal; // add in the scaled pixel to the array.

}

/**
    This method is called during the fill_Image_Array() method in order to scale each pixel as it's being added to the final image array.
**/
int image_File_Array::scale_Pixel_Values(int curPixel)
{
    double maxVal = image_File_Array::max_Pixel_Value; // largest pixel value
    double minVal = image_File_Array::min_Pixel_Value; // smallest pixel value

    // The formula for scaling numbers given the min and max range of numbers, the desired min and max values, and the number to be scaled
    // Subtract the number to be scaled from the min value of all numbers to be scaled.
    double scaleStepOne = curPixel-minVal;
    // Subtract the max value of all numbers to be scaled by all min numbers to be scaled.
    double scaleStepTwo = maxVal-minVal;
    // Divide the first answer by the second.
    double scaleStepThree = scaleStepOne/scaleStepTwo;
    // Multiply that answer by the max scaled value minus the min scaled value.
    // In this case the number needs to be between 255 and 0 so I multiplied by 255.
    int scaleStepFour = scaleStepThree*255;

    // return scaled pixel.
    return scaleStepFour;

}
