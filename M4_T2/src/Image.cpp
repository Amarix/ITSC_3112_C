#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Bridges.h"
#include "ColorGrid.h"
#include "Image.h"

/**
    Class file accepts ppm files edits them and displays them onto Bridges
    @Author Allie Beckman
    ITCS 3112 - 10/1/18
**/

using namespace bridges;

int Image::width;

int Image::height;

int Image::maxValue = 0;

// An array of structs that define red, green, and blue values of a pixel.
rgbValues** Image::image_array;

Image::Image()
{
    //ctor
}

/**
    Reads from ppm file:

    i iterates through the lines of the file.
    The first 3 lines hold information rather than pixels so i starts at -3.

    First line reads P3.
    Second line has width and height of the image.
    Third line has the max scale of the pixel values.

    The value rgb is used to seperate the red green and blue values of the image and use them to populate the rgb struct.
    While the rgb value is 0 the current value is red, rgb = 1 means the current value is green, and 2 means the
    current value is blue.

    Once all three values are inside the struct object, they are added to the array.
    The rgb value is set back to 0.

    The col value keeps track of which column is next to be populated.

    After the struct object is placed in the current column the algorithm moves to the next column. col++
    Once the column number is equal to the width of the image the column value is set back to 0 and the algorithm continues
    to the next row. row++

    Scale value is used to ensure the pixel color values are between 0 and 255.
    If the scale is above 255 the scale method is called to adjust the pixel values.
**/
Image::Image(string input_file)
{
    // input file stream using given file location argument.
    std::ifstream imgFile (input_file);

    // The counter. Represents current row including the header rows.
    int i = -3;

    // The location of the current pixel.
    int row = 0;
    int col = 0;

    // The value that represents the scale of the pixel colors.
    int scaleValue;

    // The current pixel color value.
    int curVal;
    // The current pixel color. 0 = red, 1 = green, 2 = blue
    int rgb = 0;

    // A struct object that is used to populate the array.
    rgbValues curRGB;
    curRGB.red = 0;
    curRGB.green = 0;
    curRGB.blue = 0;

    // If the image file cannot be read send error message else start reading the lines of the file.
    if (!imgFile)
    {
        std::cout << "Failed to open file" << std::endl;
    }
    else for (std::string ln; getline(imgFile, ln); i++)
    {

        // -2 is the second row in the ppm file. This row holds the length and width.
        if (i == -2)
        {
            // delimiter
            int pos = ln.find_first_of(" ");

            // Length and width of image. 0, pos represents the value on the left of the delimiter. pos+1 represents the value on the right.
            Image::width = stoi(ln.substr(0, pos));
            Image::height = stoi(ln.substr(pos+1));

            // The array is populated with null values equal to the height of the image.
            Image::image_array = new rgbValues*[Image::height];
            // The array at location "row" (starting at 0) is populated with null values equal to the width of the image.
            Image::image_array[row] = new rgbValues[Image::width];
        }
        else if (i == -1) // -1 is the third row in the file.
        {
            // Stores the value of the color scale this image uses.
            scaleValue = stoi(ln);
        }
        else if (i > -1)
        {
            // Stream through the values in this row of the ppm file.
            std::istringstream iss(ln);

            // for each value in the ppm file:
            while(iss >> curVal)
            {

                if (rgb == 0) // red value
                {
                    curRGB.red = curVal;
                    rgb++;
                }
                else if (rgb == 1) // green value
                {
                    curRGB.green = curVal;
                    rgb++;
                }
                else if (rgb == 2) // blue value
                {
                    curRGB.blue = curVal;

                    Image::image_array[row][col] = curRGB; // Save struct at current location
                    col++; // next column
                    rgb = 0; // start next struct
                }

                // If current column location is = to the width of the image and there are still rows left to populate:
                if (col == Image::width && row < Image::height-1)
                {
                    col = 0; // first column in the new row
                    row++; // next row
                    // The array at location "row" is populated with null values equal to the width of the image.
                    Image::image_array[row] = new rgbValues[Image::width];
                }

                // Check for a new max pixel value for scaling.
                if (curVal > Image::maxValue)
                {
                    // If the current value is greater than the current max value store the current value as max.
                    Image::maxValue = curVal;
                }
            }
        }
    }

    // close ppm file.
    imgFile.close();

    // If the scale value on the 3rd line of the ppm file is greater than 255 scale the image so that it is between 0-255.
    if (scaleValue > 255)
    {
        // call this classes scale method
        this->scaleArray();
    }
}

// Create a new image_array with given length and width.
Image::Image(int width, int height)
{
    Image::image_array[width][height];
}

// return current width of the image.
int Image::getWidth()
{
    return Image::width;
}

// set width of this objects image to given int.
void Image::setWidth(int w)
{
    Image::width = w;
}

// return current height of the image.
int Image::getHeight()
{
    return Image::height;
}

// set height of this objects image to given int.
void Image::setHeight(int h)
{
    Image::height = h;
}

// given the row and column location of a pixel return its value.
rgbValues Image::getImagePixel (int col, int row)
{
    return Image::image_array[row][col];
}

// given the row and column and value of a pixel place it into the array.
void Image::setImagePixel (int col, int row, rgbValues pixel)
{
    Image::image_array[row][col] = pixel;
}

// given a pixel value return a value scaled so that it is between 0 and 255.
int Image::scalePixel(int pix)
{
    int minRange = 0; // minimum value of current range
    int maxRange = Image::maxValue; // max value of current range
    int targetMin = 0; // min value of target range
    int targetMax = 255; // max value of target range
    int pixVal = pix; // current value of pixel
    int scaledVal; // new value of pixel

    // formula to scale a number
    scaledVal = ((pixVal-minRange)/(maxRange-minRange))*(targetMax-targetMin)+targetMin;

    return scaledVal; // return new value
}

/**
    Iterates through current array calling the scale pixel method for each pixel color value.
**/
void Image::scaleArray()
{
    for (int j = 0; j < Image::height; j++)
    {
        for (int k = 0; k < Image::width; k++)
        {
            // current value = new scaled value for each color at a single location.
            Image::image_array[j][k].red = Image::scalePixel(Image::image_array[j][k].red);
            Image::image_array[j][k].green = Image::scalePixel(Image::image_array[j][k].green);
            Image::image_array[j][k].blue = Image::scalePixel(Image::image_array[j][k].blue);
        }
    }
}

/**
    Display the image onto bridges.

    Creates a new color grid object using the length and width of this object.
    Populates color grid with a given array argument.
**/
void Image::display(int height, int width, rgbValues** ima)
{
    Bridges::initialize(4, "Allie_Beckman", "1078037612459");
    Bridges::setTitle("PPM editor");

    ColorGrid *cg = new ColorGrid(height, width, Color("red"));

    for (int j = 0; j < height; j++)
    {
        for (int k = 0; k < width; k++)
        {
            cg->set(j, k, Color(ima[j][k].red, ima[j][k].green, ima[j][k].blue));
        }
    }

    Bridges::setDataStructure(cg);

    Bridges::visualize();
}

// Returns this objects array.
rgbValues** Image::getImageArray()
{
    return Image::image_array;
}

/**
    Combines two arrays.

    Uses the width and height of both arrays to determine which is the biggest.

    Populates the first half of the new combination array with the larger of the two arrays.

    Populates the second half of the new combination array with the smaller array and fills in the excess width with black pixels.

    Returns new combination of the two arrays.
**/
rgbValues** Image::combineArrays(int arOneR, int arOneC, rgbValues** arOne, int arTwoR, int arTwoC, rgbValues** arTwo)
{
    // Initalize the new array.
    rgbValues** combAry;

    // An array to hold the larger of the two initial arrays and an array to hold the smaller array.
    rgbValues** lgAry;
    rgbValues** smAry;

    // Counter for rows of smaller array.
    int i = 0;

    // Height of the new combination array.
    int newH = arOneR + arTwoR;

    // Holds the height of the array with the most rows. (out of the two initial arrays)
    int lgH;
    // Holds the height of the array with fewer rows. (out of the two initial arrays)
    int smH;

    // Holds the width of the new combination array. The width will equal the width of the argument array with the most columns.
    int newW;

    // Holds the width of the argument array with the fewest columns.
    int smW;

    // If array one is greater than array two
    if (arOneC > arTwoC)
    {
        // Fill in corresponding values
        newW = arOneC;
        smW = arTwoC;
        lgH = arOneR;
        smH = arTwoR;
        lgAry = arOne;
        smAry = arTwo;
    }
    else
    {
        // Fill in corresponding values
        newW = arTwoC;
        smW = arOneC;
        lgH = arTwoR;
        smH = arOneR;
        lgAry = arTwo;
        smAry = arOne;
    }

    // set new default width and height.
    Image::height = newH;
    Image::width = newW;

    // Initalize the first dimension of the new combination array
    combAry = new rgbValues*[newH];
    // Populate the first half of the new array with the larger of the two argument arrays.
    // The larger argument array will fill the dsiplay width.
    // *Notice this loop stopping at the larger arrays height.
    for (int j = 0; j < lgH; j++)
    {
        // Initalize the second dimension(columns) for each row.
        combAry[j] = new rgbValues[newW];
        // Iterate through the width/columns and populate the first half of the new array.
        for (int k = 0; k < newW; k++)
        {
            combAry[j][k].red = lgAry[j][k].red;
            combAry[j][k].green = lgAry[j][k].green;
            combAry[j][k].blue = lgAry[j][k].blue;
        }
    }
    // Populate the second half of the new array with the smaller of the two argument arrays.
    // *Notice the height loop starts where the last loop left off and runs to the new height of the combination array.
    for (int j = lgH; j < newH; j++)
    {
        // Initalize the second dimension(columns) for each row.
        combAry[j] = new rgbValues[newW];
        // Iterate through the width/columns and populate the second half of the new array.
        for (int m = 0; m < newW; m++)
        {
            // This if statement is a paramater check for the smaller array.
            // The values of the new array that are out of bounds of the smaller array will be filled with black pixels.
            // The variable i is used to start from the first row of the smaller array while j is continuing through the new array.
            if (m < smW)
            {
                combAry[j][m].red = smAry[i][m].red;
                combAry[j][m].green = smAry[i][m].green;
                combAry[j][m].blue = smAry[i][m].blue;
            }
            else
            {
                combAry[j][m].red = 0;
                combAry[j][m].green = 0;
                combAry[j][m].blue = 0;
            }
        }
        i++;
    }

    return combAry;
}

/**
    Takes an array and its width and height.
    Iterates through each value and replaces it with the result of the grayscale equation.
**/
rgbValues** Image::toGrayScale(int width, int height, rgbValues** ary)
{
    int grayVal;

    for (int j = 0; j < height; j++)
    {
        for (int k = 0; k < width; k++)
        {
            grayVal = (ary[j][k].red*0.299)+(ary[j][k].green*0.587)+(0.114*ary[j][k].blue);
            ary[j][k].red = grayVal;
            ary[j][k].green = grayVal;
            ary[j][k].blue = grayVal;
        }
    }

    return ary;
}

/**
    Takes an array and its width and height.
    Creates a new array.
    Fills the new array with the values from the initial array in reverse order.
**/
rgbValues** Image::flipHorizontal(int width, int height, rgbValues** ary)
{
    rgbValues** newAry = new rgbValues*[height];
    int rev;

    for (int j = 0; j < height; j++)
    {
        newAry[j] = new rgbValues[width];
        for (int k = 0; k < width; k++)
        {
            rev = width - k -1;

            newAry[j][k] = ary[j][rev];
        }
    }

    return newAry;
}

/**
    Takes an array and its width and height.
    Iterates through and turns all red values of each pixel in the array to 0
**/
rgbValues** Image::flattenRed(int width, int height, rgbValues** ary)
{
    for (int j = 0; j < height; j++)
    {
        for (int k = 0; k < width; k++)
        {
            ary[j][k].red = 0;
        }
    }

    return ary;
}

/**
    Takes an array and its width and height.
    Iterates through and subtracts the blue value in each pixel from 255.
    Places the new blue value into the array.
**/
rgbValues** Image::negateBlue(int width, int height, rgbValues** ary)
{
    for (int j = 0; j < height; j++)
    {
        for (int k = 0; k < width; k++)
        {
            ary[j][k].blue = 255-ary[j][k].blue;
        }
    }

    return ary;
}
