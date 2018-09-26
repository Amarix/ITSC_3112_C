#ifndef DISPLAY_IMAGE_H
#define DISPLAY_IMAGE_H


class display_Image
{
    public:
        /**
            This function takes the image height, width, and the array of pixels to display each pixel on a color grid in bridges.
            If the pixel value is below  or equal to 255 the red green and blue values of that spot on the grid are changed to the value of that pixel.
            If the pixel value is above 255 then it has been changed in the path_Finder class and will be made red.
        **/
        display_Image(int height, int width, int** imgArry);

    protected:

    private:
};

#endif // DISPLAY_IMAGE_H
