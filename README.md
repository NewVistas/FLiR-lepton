# FLiR-lepton

To use this code, connect the camera, open the serial monitor and use the following commands for its respective actions:

- To capture Image: captureImage
- Print the image into the serial monitor: transferImage
- To get the temperature of the camera core: getTemperature
- To find the minimum raw value of the captured Image: findMin

In the folder connections there is an image to show how the Arduino Due has to be connected with the PureEngineering Module.

When downloaded, change the folder name from FLiR-lepton-master to FLiR-lepton.

Please, note that the serial monitor has to be setted as to write a new line in the right bottom corner. Moreover, you should know that there is a checkpoint system for the actions, so when an image is captured, you should expect two <OK>, if there is only one, it means that the process was not completed successfully, reset the Arduino and try again.

To visualize the thermal image, what you can do is copy the data from the serial monitor, paste it in an excel sheet and give the data a conditional coloured format.

If you have any issues, please contact me at josepbordesjove@gmail.com and ask.
