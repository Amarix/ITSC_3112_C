#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Image.h"

/**
    @Author Allie Beckman
    ITCS 3112 - 10/1/18
**/

using namespace std;

int main()
{
    // I added images files to a folder within the project.
    string ppmFileOne = "/home/user/M4_T2/PPM_Files/yosemite.ppm";
    string ppmFileTwo = "/home/user/M4_T2/PPM_Files/pony_image.ppm";
    string ppmFileThree = "/home/user/M4_T2/PPM_Files/puppy_image.ppm";
    string ppmFileFour = "/home/user/M4_T2/PPM_Files/kitten_image.ppm";

    /**
        Image One Object:
    **/
    Image image_One = Image(ppmFileOne);

    rgbValues** image_One_Array = image_One.getImageArray();

    int arOneWidth = image_One.getWidth();
    int arOneHeight = image_One.getHeight();

    /**
        Image Two Object:
    **/
    Image image_Two = Image(ppmFileTwo);

    rgbValues** image_Two_Array = image_Two.getImageArray();

    int arTwoWidth = image_Two.getWidth();
    int arTwoHeight = image_Two.getHeight();

    /**
        Image Three Object:
    **/
    Image image_Three = Image(ppmFileThree);

    rgbValues** image_Three_Array = image_Three.getImageArray();

    int arThreeWidth = image_Three.getWidth();
    int arThreeHeight = image_Three.getHeight();

    /**
        Image Four Object:
    **/
    Image image_Four = Image(ppmFileFour);

    rgbValues** image_Four_Array = image_Four.getImageArray();

    int arFourWidth = image_Four.getWidth();
    int arFourHeight = image_Four.getHeight();

    /**
        Image One Grayscale:
    **/
    image_One_Array = image_One.toGrayScale(arOneWidth, arOneHeight, image_One_Array);

    /**
        Image Two Flip Horizontal:
    **/
    image_Two_Array = image_Two.flipHorizontal(arTwoWidth, arTwoHeight, image_Two_Array);

    /**
        Image Three Flatten Red:
    **/
    image_Three_Array = image_Three.flattenRed(arThreeWidth, arThreeHeight, image_Three_Array);

    /**
        Image Four Negate Blue:
    **/
    image_Four_Array = image_Four.negateBlue(arFourWidth, arFourHeight, image_Four_Array);

    /**
        Combine first two images:
    **/
    rgbValues** combo_One = image_One.combineArrays(arOneHeight, arOneWidth, image_One_Array, arTwoHeight, arTwoWidth, image_Two_Array);

    int cmOneW = image_One.getWidth();
    int cmOneH = image_One.getHeight();

    /**
        Combine next image:
    **/
    rgbValues** combo_Two = image_One.combineArrays(arThreeHeight, arThreeWidth, image_Three_Array, cmOneH, cmOneW, combo_One);

    int cmTwoW = image_One.getWidth();
    int cmTwoH = image_One.getHeight();

    /**
        Combine next image:
    **/
    rgbValues** combo_Three = image_One.combineArrays(arFourHeight, arFourWidth, image_Four_Array, cmTwoH, cmTwoW, combo_Two);

    int cmThreeW = image_One.getWidth();
    int cmThreeH = image_One.getHeight();

    /**
        Display all edited and combined images:
    **/
    image_One.display(cmThreeH, cmThreeW, combo_Three);
    Image createImage;
}
