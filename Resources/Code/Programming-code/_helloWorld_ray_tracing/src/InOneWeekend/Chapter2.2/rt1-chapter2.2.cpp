/**
 * @file rt1-chapter2.2.cpp
 * @brief This file contains the main entry point for a ray tracing program, based on the first book of the series.
* ==============================================================================================
* Originally written in 2016 by Peter Shirley
* You can find it at the regular spot: https://raytracing.github.io
* To the extent possible under law, the author(s) have dedicated all copyright and related and
* neighboring rights to this software to the public domain worldwide. This software is
* distributed without any warranty.
*
* You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication
* along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
* ==============================================================================================
 *
 * @author Dr. George Papagiannakis
 * @date 2024
 */


#include <iostream>

/*

1. **Include the iostream library**: This program starts by including the `<iostream>` library, which is necessary for input and output operations in C++.

2. **Main Function**: The `main()` function is the entry point of any C++ program.

3. **Define Image Dimensions**: 
   - `image_width` and `image_height` are set to 256. These variables define the width and height of the image in pixels.

4. **Start of Image File Output**: 
   - The program prints "P3", followed by the image width and height, and then 255. This is the header for a PPM (Portable Pixmap) file format, which is a simple image format. "P3" means the colors of the pixels are in ASCII, and 255 denotes the maximum color value.

5. **Rendering Loop**:
   - The program uses two nested loops to iterate over each pixel of the image. The outer loop (`j`) goes through each row, and the inner loop (`i`) goes through each column.

6. **Calculate Pixel Colors**:
   - For each pixel, the program calculates color values (red, green, blue). 
   - `r` (red) is calculated as the current column index divided by the width of the image minus one.
   - `g` (green) is calculated as the current row index divided by the height of the image minus one.
   - `b` (blue) is set to 0, so there's no blue component in the colors.

7. **Convert Color Values to Integer**:
   - The program converts these color values to integers ranging from 0 to 255. This is done by multiplying the color value by 255.999 and then casting it to an integer.

8. **Output Pixel Colors**:
   - Finally, the program outputs the color values for each pixel in the image to the standard output (console).

### Pseudocode

```pseudocode
INCLUDE iostream library

FUNCTION main
    SET image_width TO 256
    SET image_height TO 256

    PRINT "P3", image_width, image_height, "255"

    FOR j FROM 0 TO image_height
        FOR i FROM 0 TO image_width
            SET r TO i / (image_width - 1)
            SET g TO j / (image_height - 1)
            SET b TO 0

            SET ir TO CONVERT TO INTEGER(255.999 * r)
            SET ig TO CONVERT TO INTEGER(255.999 * g)
            SET ib TO CONVERT TO INTEGER(255.999 * b)

            PRINT ir, ig, ib
        END FOR
    END FOR
END FUNCTION
```
*/

int main() 
{
    // Image
    int image_width = 256; 
    int image_height = 256;
    
    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    /*
        1. **PPM File Format Header**: 
        - The program first outputs the header for a PPM file. This includes:
            - `"P3"`: Indicates that the file is a PPM file where pixel values are in ASCII.
            - `image_width` and `image_height`: The dimensions of the image, which are both 256 in this case.
            - `255`: The maximum value for any color channel (red, green, or blue).
            e.g. example.PPM
            P3
            # "P3" means this is a RGB color image in ASCII
            # "3 2" is the width and height of the image in pixels
            # "255" is the maximum value for each color
            # This, up through the "255" line below are the header.
            # Everything after that is the image data: RGB triplets.
            # In order: red, green, blue, yellow, white, and black.
            3 2
            255
            255   0   0
            0 255   0
            0   0 255
            255 255   0
            255 255 255
            0   0   0

        2. **Pixel Data**:
        - After the header, the program outputs the color values for each pixel in the image.
        - The image is traversed row by row (top to bottom) and within each row, column by column (left to right).

        3. **Color Calculations**:
        - For each pixel, the program calculates the color values as follows:
            - `r` (red component): Varies horizontally from 0 to 1, as `j` (the column index) varies from 0 to `image_width - 1`.
            - `g` (green component): Varies vertically from 0 to 1, as `i` (the row index) varies from 0 to `image_height - 1`.
            - `b` (blue component): Always 0.

        4. **Color Output**:
        - The calculated `r`, `g`, and `b` values are then converted to integers in the range of 0 to 255 and printed out. Each pixel's color is represented by these three values (red, green, blue).

        ### Visual Result:
        - The resulting image is a 256x256 pixel image with a gradient.
        - The red component of the color increases from left to right.
        - The green component of the color increases from top to bottom.
        - The blue component is always zero, so there is no blue in the image.
        - The top-left corner of the image will be black (0,0,0), as both `r` and `g` are 0 there.
        - The bottom-right corner of the image will be yellow (255,255,0), as both `r` and `g` reach their maximum value there, and `b` is 0.

        This loop below essentially creates a two-dimensional gradient image ranging from: 
            - black at the top-left corner to yellow at the bottom-right corner.
            - red at the top right edge to green at the bottom left edge.
    */

    for (int i = 0; i < image_height; ++i) 
    { 
        for (int j = 0; j < image_width; ++j)
        {
            auto r = double(j) / (image_width-1); 
            auto g = double(i) / (image_height-1); 
            auto b = 0;
            int ir = static_cast<int>(255.999 * r); 
            int ig = static_cast<int>(255.999 * g); 
            int ib = static_cast<int>(255.999 * b);
            
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    return 0;
}
