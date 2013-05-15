/**********************
 * Invert a File
 * OpenCV Demo
 * Cooper Bills (csb8@cornell.edu)
 *********************/

#include <stdio.h>
#include <opencv/highgui.h> // highgui.h contains openCV gui elements

int main(int argc,char *argv[])
{
  IplImage* loadedImg; // where we'll store the current frame
  IplImage* invFrame;

  if(argc < 2) {
    printf("usage: %s image1 [image2] [image3] ...\n", argv[0]);
    return 0;
  }

  for(int i = 1; i < argc; i++) {
    loadedImg = cvLoadImage(argv[i]); // load image

    // check for errors:
    if(!loadedImg)
      continue;

    cvNot(loadedImg, loadedImg); //some funcions can do in-place modification

    char buffer[100];
    sprintf(buffer, "modified-%s", argv[i]); //new filename

    cvSaveImage(buffer, loadedImg); //save the modified image

    cvReleaseImage(&loadedImg); //release it now that we're done
  }

  return 0;
}

