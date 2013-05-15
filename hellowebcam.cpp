/**********************
 * Hello Webcam
 * OpenCV Demo
 * Cooper Bills (csb88@cornell.edu)
 *********************/

#include <stdio.h>
#include <opencv/highgui.h> // highgui.h contains OpenCV gui elements

int main()
{
  CvCapture* captureDevice; // our webcam handler
  IplImage* currentFrame; // where we'll store the current frame
  IplImage* modifiedFrame; // where we'll store the current frame

  // now get webcam handler.  0 is the camera index.  If your computer
  // has more than one capture device, the index chooses the camera.
  captureDevice = cvCaptureFromCAM(0); 

  // check to make sure there are no problems
  if(!captureDevice) {
    printf("Error opening webcam. Exiting. \n");
    return -1;
  }

  // Create a window to display our webcam in, The handler for this
  // window is also the name, in this case "myWindow"
  cvNamedWindow("myWindow", CV_WINDOW_AUTOSIZE);

  int key = -1;
  int i=0;
  // while there is no key press by the user,
  //while(key == -1) {
  while(i<3) {
    i++;
    printf("%d\r\n",i);

    currentFrame = cvQueryFrame(captureDevice); // get current frame
						// from camera
    // check for errors:
    if(!currentFrame)
      break;

    // Start Modify image
    /////////////////////
  
    modifiedFrame=cvCloneImage(currentFrame);

    // Invert the frame
    for(int x = 0; x < currentFrame->width; x++) {
       for(int y = 0; y < currentFrame->height; y++) {
          int B = 255 - CV_IMAGE_ELEM( currentFrame, uchar, y, x*3); 
	  int G = 255 - CV_IMAGE_ELEM( currentFrame, uchar, y, x*3+1); 
	  int R = 255 - CV_IMAGE_ELEM( currentFrame, uchar, y, x*3+2);
          CV_IMAGE_ELEM( modifiedFrame, uchar, y, x*3) = B; 
	  CV_IMAGE_ELEM( modifiedFrame, uchar, y, x*3+1) = G; 
	  CV_IMAGE_ELEM( modifiedFrame, uchar, y, x*3+2) = R;
       }
    }

    // End Modify image
    /////////////////////

    // Display the current frame in the window we created earlier
    cvShowImage("myWindow", modifiedFrame);

    // Release frame
    cvReleaseImage(&modifiedFrame);
    
    // Wait for user input for 30ms, cvWaitKey return the user's
    // keypress, or -1 if time limit is reached. (0 = wait forever)
    key = cvWaitKey(30);
  }

  // Appropreate Cleanup
  cvReleaseCapture(&captureDevice);
  cvDestroyWindow("myWindow");

  return 0;
}

