#include <stdio.h>
#include <malloc.h>
#include "BMP.h"

BITMAPFILEHEADER fileHeader;
BITMAPINFOHEADER infoHeader;

void showBmpHead(BITMAPFILEHEADER pBmpHead)
{  //Define the function of displaying information, pass in the file header structure
    printf("BMP file size: %dkb\n", fileHeader.bfSize/1024);
    printf("Reserved words must be 0: %d\n",  fileHeader.bfReserved1);
    printf("Reserved words must be 0: %d\n",  fileHeader.bfReserved2);
    printf("Offset bytes of actual bitmap data: %d\n",  fileHeader.bfOffBits);
}
void showBmpInfoHead(BITMAPINFOHEADER pBmpinfoHead)
{//Define the function to display the information, and the information header structure is passed in
    printf("Bitmap Information Header:\n" );
    printf("The size of the message header: %d\n" ,infoHeader.biSize);
    printf("Bitmap width: %d\n" ,infoHeader.biWidth);
    printf("Bitmap height: %d\n" ,infoHeader.biHeight);
    printf("The number of planes of the image (the number of planes is the number of palettes, the default is 1 palette): %d\n" ,infoHeader.biPlanes);
    printf("Number of bits per pixel: %d\n" ,infoHeader.biBitCount);
    printf("Compression method:%d\n" ,infoHeader.biCompression);
    printf("Image size: %d\n" ,infoHeader.biSizeImage);
    printf("Horizontal resolution: %d\n" ,infoHeader.biXPelsPerMeter);
    printf("Vertical resolution: %d\n" ,infoHeader.biYPelsPerMeter);
    printf("Number of colors used: %d\n" ,infoHeader.biClrUsed);
    printf("Number of important colors: %d\n" ,infoHeader.biClrImportant);
}

int loadBMP(char* filename){
    FILE* fp;
    fp = fopen(filename, "rb");//Read the image.bmp file in the same directory.
    if(fp == NULL){
        printf("Failed to open'image.bmp'!\n");
        return -1;
    }
    //If you do not read the bifType first, according to the C language structure Sizeof operation rule-the whole is greater than the sum of the parts, resulting in misalignment of the read file
    unsigned short  fileType;
    fread(&fileType,1,sizeof (unsigned short), fp);
    if (fileType = 0x4d42){
        printf("The file type identification is correct!" );
        printf("\nFile identifier: %d\n", fileType);
        fread(&fileHeader, 1, sizeof(BITMAPFILEHEADER), fp);
        showBmpHead(fileHeader);
        fread(&infoHeader, 1, sizeof(BITMAPINFOHEADER), fp);
        showBmpInfoHead(infoHeader);
        fclose(fp);
    }
    return 1;
}
int main(){
    char* fileTest = "test1.bmp";
    loadBMP(fileTest);
}