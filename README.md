# FLiR-lepton

To use this code, connect the camera, open the serial monitor and use the following commands for its respective actions:

- To capture Image: captureIma
- Print the image into the serial monitor: transferIm
- To get the temperature of the camera core: getTemperature
- To find the minimum raw value of the captured Image: getTemperature

In the folder connections there is an image to show how the Arduino Due has to be connected with the PureEngineering Module.

Please, note that the serial monitor has to be setted as to write a new line in the right bottom corner. Moreover, you should know that there is a checkpoint system for the actions, so when an image is captured, you should expect two <OK>, if there is only one, it means that the process was not completed successfully, reset the Arduino and try again.

If you have any issues, please contact me at josepbordesjove@gmail.com and ask.
