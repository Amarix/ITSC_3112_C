#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#ifndef IMAGE_FILE_ARRAY_H
#define IMAGE_FILE_ARRAY_H


class image_File_Array
{
    public:
        static int max_Pixel_Value;
        static int min_Pixel_Value;
        static int image_Height;
        static int image_Width;
        static int** image_Array;
        static int counter;
        int** generate(std::string imgLocation);
        image_File_Array();
        void get_Values_For_Scaling(int curVal);
        void fill_Image_Array(int curW, int curH, int curVal);
        static int scale_Pixel_Values(int curPixVal);
    protected:

    private:
};

#endif // IMAGE_FILE_ARRAY_H
