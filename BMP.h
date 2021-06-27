# ifndef BMP_H
# define BMP_H
/*
 BMP format
 The data in this format is divided into three to four parts, in order:
 File information header (14 bytes) stores file type, file size and other information
 The picture information header (40 bytes) stores the picture size, color index, bit plane number and other information
 Palette (determined by the number of color indexes) [may not have this information]
 Bitmap data (determined by the image size) information for each pixel is stored here

 The general bmp image is 24 bits, which is true color. Every 8 bits is a byte, and 24 bits use three bytes to store the information of each pixel. The three bytes correspond to the data of the three primary colors of r, g, and b.
 The storage range of each byte is 0-255. Then by analogy, a 32-bit image stores four data of r, g, b, a (Alpha channel, storage transparency) per pixel. 8-bit image is only the grayscale information,
 There is also a binary image, which has only two colors, black or white.
*/
// File information header structure
typedef struct tagBITMAPFILEHEADER
{
    //unsigned short bfType; // 19778, must be a BM string, the corresponding hexadecimal is 0x4d42, and the decimal is 19778, otherwise it is not a bmp format file
    unsigned int   bfSize;        // File size in bytes (2-5 bytes)
    unsigned short bfReserved1;   // Reserved, must be set to 0 (6-7 bytes)
    unsigned short bfReserved2;   // Reserved, must be set to 0 (8-9 bytes)
    unsigned int   bfOffBits;     // Offset from file header to pixel data (10-13 bytes)
} BITMAPFILEHEADER;

//Image information header structure
typedef struct tagBITMAPINFOHEADER
{
    unsigned int    biSize;          // The size of this structure (14-17 bytes)
    long            biWidth;         // The width of the image (18-21 bytes)
    long            biHeight;        // The height of the image (22-25 bytes)
    unsigned short  biPlanes;        // Indicates the plane attribute of the bmp picture, obviously the display has only one plane, so it is always equal to 1 (26-27 bytes)
    unsigned short  biBitCount;      // The number of bits occupied by a pixel, generally 24 (28-29 bytes)
    unsigned int    biCompression;   // Describe the type of image data compression, 0 means no compression. (30-33 bytes)
    unsigned int    biSizeImage;     // The size of pixel data, this value should be equal to bfSize-bfOffBits (34-37 bytes) in the file header structure above
    long            biXPelsPerMeter; // Describe the horizontal resolution, expressed in pixels/meter. Generally 0 (38-41 bytes)
    long            biYPelsPerMeter; // Describe the vertical resolution, expressed in pixels/meter. Generally 0 (42-45 bytes)
    unsigned int    biClrUsed;       // Describe the number of color indexes in the color table actually used by the bitmap (if set to 0, all palette items are used). (46-49 bytes)
    unsigned int    biClrImportant;  // Explain the number of color indexes that have an important influence on the image display. If it is 0, it means all are important. (50-53 bytes)
} BITMAPINFOHEADER;

//24 bitmap pixel information structure, namely palette
typedef struct _PixelInfo {
    unsigned char rgbBlue;   //The blue component of the color (value range is 0-255)
    unsigned char rgbGreen;  //The green component of the color (value range is 0-255)
    unsigned char rgbRed;    //The red component of the color (value range is 0-255)
    unsigned char rgbReserved;// reserved, must be 0
} PixelInfo;

#endif
