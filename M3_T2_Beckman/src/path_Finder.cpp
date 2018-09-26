#include <cmath>
#include "path_Finder.h"

path_Finder::path_Finder()
{

}

/**
    Using the image height, width, and array of pixels this function will iterate through the columns
    testing the three pixels touching the current pixel to see which is closer.
    The closest pixels value will be changed to 256 which will be made red in the display_image file.
    If the top and bottom pixel are equal the bottom pixel will be chosen.
    If the top or bottom pixel is equal to the forward pixel then the forward pixel will be chosen.
    The first pixel will be half way up the farthest left column of the image.
**/
int** path_Finder::get_Path(int height, int width, int** imgArry){

    int heightOfCurPix = height/2; // starting location will be half way up the image height
    int widthIterate = 1; // the next pixel will be one column to the right of the first which is at 0.

    int currentPix = imgArry[heightOfCurPix][0]; // the value of the first pixel will be half way up the first column of the image.

    // values for the three pixels in the column next to the current pixel
    int pixUp;
    int pixForward;
    int pixDown;

    // values for the difference between the current pixel and each of the three to the right of it.
    int difUp;
    int difForward;
    int difDown;

    // iterate through each column of the image.
    while (widthIterate < width){

        // fill the values of the pixels to the right of the current pixel using the vertical location of the current pixel and the iterated column value.
        pixUp = imgArry[heightOfCurPix-1][widthIterate];
        pixForward = imgArry[heightOfCurPix][widthIterate];
        pixDown = imgArry[heightOfCurPix+1][widthIterate];

        // fill the values of the differences in the current pixel and each of the pixels to the right.
        // I obtained the absolute value because we needed the closest rather than the highest or lowest.
        difUp = abs(currentPix-pixUp);
        difForward = abs(currentPix-pixForward);
        difDown = abs(currentPix-pixDown);

        // if the up pixel is the closest change the current pixel value to that pixel
        // change the value of the pixel at that location to 256 so the drawing file will make it red
        // adjust the height of the current pixel to the hight of the next current pixel
        if(difUp < difForward && difUp < difDown){

            currentPix = imgArry[heightOfCurPix-1][widthIterate];
            imgArry[heightOfCurPix-1][widthIterate] = 256;
            heightOfCurPix = heightOfCurPix-1;
        }
        // if the forward pixel is the closest change the current pixel value to that pixel
        // change the value of the pixel at that location to 256 so the drawing file will make it red
        // adjust the height of the current pixel to the hight of the next current pixel
        else if(difForward < difUp && difForward < difDown){

            currentPix = imgArry[heightOfCurPix][widthIterate];
            imgArry[heightOfCurPix][widthIterate] = 256;
            heightOfCurPix = heightOfCurPix;
        }
        // if the down pixel is the closest change the current pixel value to that pixel
        // change the value of the pixel at that location to 256 so the drawing file will make it red
        // adjust the height of the current pixel to the hight of the next current pixel
        else if(difDown < difUp && difDown < difForward){

            currentPix = imgArry[heightOfCurPix+1][widthIterate];
            imgArry[heightOfCurPix+1][widthIterate] = 256;
            heightOfCurPix = heightOfCurPix+1;

        }
        // If the up and forward pixel distances are the same change the current pixel to the forward pixel
        // change the value of the pixel at that location to 256 so the drawing file will make it red
        // adjust the height of the current pixel to the hight of the next current pixel
        else if(difUp == difForward && difUp < difDown){

            currentPix = imgArry[heightOfCurPix][widthIterate];
            imgArry[heightOfCurPix][widthIterate] = 256;
            heightOfCurPix = heightOfCurPix;

        }
        // If the down and forward pixel distances are the same change the current pixel to the forward pixel
        // change the value of the pixel at that location to 256 so the drawing file will make it red
        // adjust the height of the current pixel to the hight of the next current pixel
        else if(difDown == difForward && difDown < difUp){

            currentPix = imgArry[heightOfCurPix][widthIterate];
            imgArry[heightOfCurPix][widthIterate] = 256;
            heightOfCurPix = heightOfCurPix;

        }
        // If the up and down pixel distances are the same change the current pixel to the down pixel
        // change the value of the pixel at that location to 256 so the drawing file will make it red
        // adjust the height of the current pixel to the hight of the next current pixel
        else if(difUp == difDown && difUp < difForward){

            currentPix = imgArry[heightOfCurPix-1][widthIterate];
            imgArry[heightOfCurPix-1][widthIterate] = 256;
            heightOfCurPix = heightOfCurPix-1;
        }
        // If all pixels are the same change the current pixel to the forward pixel
        // change the value of the pixel at that location to 256 so the drawing file will make it red
        // adjust the height of the current pixel to the hight of the next current pixel
        else if(difUp == difDown && difUp == difForward){

            currentPix = imgArry[heightOfCurPix][widthIterate];
            imgArry[heightOfCurPix][widthIterate] = 256;
            heightOfCurPix = heightOfCurPix;
        }

        // move to the next column
        widthIterate++;
    }

    // return the updated array.
    return imgArry;

}
