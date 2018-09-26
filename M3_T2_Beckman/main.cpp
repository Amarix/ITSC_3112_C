#include <iostream>
#include "image_File_Array.h"
#include "display_Image.h"
#include "path_Finder.h"

using namespace std;

int main()
{

    int** vlus; // array for the image files original pixel values
    int** vlusWithPath; // array for the image files scaled pixel values

    string locationOne = "/home/user/M3_T2_Beckman/image_files/Colorado_480x480.dat";
    string locationTwo = "/home/user/M3_T2_Beckman/image_files/Colorado_844x480.dat";

    image_File_Array iFA; // create the image file object

    path_Finder pthFind; // create the pathfinder object

    vlus = iFA.generate(locationTwo); // fill the array using the image file object

    vlusWithPath = pthFind.get_Path(iFA.image_Height, iFA.image_Width, vlus); // create the new array with the path values added using the path finder object

    display_Image dI(iFA.image_Height, iFA.image_Width, vlusWithPath); // display the image using the array holding the path to bridges
}
