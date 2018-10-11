#include <string>
#ifndef IMAGE_H
#define IMAGE_H

/**
    @Author Allie Beckman
    ITCS 3112 - 10/1/18
**/

using namespace std;

struct rgbValues
{
    int red;
    int green;
    int blue;
};

class Image
{
    private:
        // image dimensions
        static int width, height, maxValue;

        // pointer to the dynamically allocated image array
        static rgbValues** image_array;

    protected:

    public:

        Image();     // constructor - creates an empty image object,
               // creates an image object by reading the input file
        Image(string input_file);
               //creates an image object using the given dimensions
        Image (int width, int height);

               // accessors/mutators
        int getWidth();
        void setWidth(int w);
        int getHeight();
        void setHeight(int h);

               // set/get an image pixel given row and column addresses
               // pixel is a 3 element r,g,b triple
        rgbValues getImagePixel (int col, int row);
        void setImagePixel (int col, int row, rgbValues pixel);

                // called by the scale array method to adjust a single pixel
        int scalePixel(int pix);

                // called while the array is being populated if the scale
                // of the ppm values are higher than 255.
        void scaleArray();

               // writes image to file
        void display (int height, int width, rgbValues** image_array);

                // Returns current array value.
        rgbValues** getImageArray();

        rgbValues** combineArrays(int arOneR, int arOneC, rgbValues** arOne, int arTwoR, int arTwoC, rgbValues** arTwo);

               // Converts RGB to grayscale
        rgbValues** toGrayScale (int width, int height, rgbValues** ary);

               // flips the image  horizontally each row of pixesl
        rgbValues** flipHorizontal(int width, int height, rgbValues** ary);

               // sets the red component of each pixel to zero
        rgbValues** flattenRed(int width, int height, rgbValues** ary);

               // flips the blue component of image about 255
        rgbValues** negateBlue(int width, int height, rgbValues** ary);

};

#endif // IMAGE_H
