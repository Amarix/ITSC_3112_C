#include "display_Image.h"
#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace bridges;

/**
    This function takes the image height, width, and the array of pixels to display each pixel on a color grid in bridges.
    If the pixel value is below  or equal to 255 the red green and blue values of that spot on the grid are changed to the value of that pixel.
    If the pixel value is above 255 then it has been changed in the path_Finder class and will be made red.
**/
display_Image::display_Image(int imgHeight, int imgWidth, int** imgArry)
{
    // This example illustrates using the Bridges color grid
    // We will build a checker grid using two different colors
                                            // initialize BRIDGES
    Bridges::initialize(3, "Allie_Beckman", "1078037612459");
                                            // set title for visualization
    Bridges::setTitle("Greedy Algorithm");

    ColorGrid *cg  = new ColorGrid(imgWidth, imgHeight, Color("white"));

    int curColor; // value of the pixel that will fill the red blue and green spaces in the Color function.

    for (int j = 0; j < imgWidth;  j++)
    for (int k = 0; k < imgHeight;  k++) {

        // if the pixel at each location is less than 256 its values are used to fill the red blue and green spaces.
        if (imgArry[j][k] < 256){

            // get the pixel value
            curColor = imgArry[j][k];

            // set the color of this spot on the grid to the pixel value.
            cg->set(j, k, Color(curColor, curColor, curColor));
        }
        else{
            // if the value of the current pixel is greater than 255 then it is one of the
            // pixels on the path and is turned red.
            cg->set(j, k, Color("red"));
        }

    }

    Bridges::setDataStructure(cg);

    Bridges::visualize();
}
