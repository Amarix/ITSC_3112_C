#ifndef PATH_FINDER_H
#define PATH_FINDER_H


class path_Finder
{
    public:
        /**
            Using the image height, width, and array of pixels this function will iterate through the columns
            testing the three pixels touching the current pixel to see which is closer.
            The closest pixels value will be changed to 256 which will be made red in the display_image file.
            If the top and bottom pixel are equal the bottom pixel will be chosen.
            If the top or bottom pixel is equal to the forward pixel then the forward pixel will be chosen.
            The first pixel will be half way up the farthest left column of the image.
        **/
        int** get_Path(int height, int width, int** imgArry);
        path_Finder();

    protected:

    private:
};

#endif // PATH_FINDER_H
