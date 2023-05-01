#include <iostream>
#include "BMP.h"
#include <cmath>

int main() {
    //setting height and weight 
    BMP bmpNew(2000, 800, false);
    bmpNew.fill_region(0, 0, 2000, 800, 0, 0, 0, 0);
    
    for (int i = 0; i < bmpNew.bmp_info_header.width; i++) {
        bmpNew.set_pixel(i, 0, 255, 255, 255, 0);
    }
    
    //for each pixel: 
    for (int i = 0; i < bmpNew.bmp_info_header.width; i++)
    {
        //Check that pixel is withing ellipse
        if ((i >= 232) && (i <= 1768)) {
            //Compute the correct x value to calculate y
            int x = i - 1000;
            //Rearrange ellipse equation to compute y
            int y = (int)(sqrt((768 + x) * (768 - x)) / 2);	
            //show the pixels screen 
            bmpNew.set_pixel(i, y, 255, 255, 255, 0);
        }
    }

    bmpNew.write("output.bmp");
}
