# Choi-et-al-Nature2020
Code repository for Choi et al. nature. 2020 paper "Parallel ascending spinal pathways for affective touch and pain"

1) In Bonsai codes, 
   - Select the region of interest in the Crop node.
   - Adjust "ThresholdValue" in the Threshold node and "MinArea" in the FindContours node depending on video capturing setup/conditions. 
   
2) For RTTA and opto_RTPP Bonsai codes, 
   - Use the Image Process_ROI node to select a ROI (Crop node) for one side of the chamber, and the downstream nodes will generate a csv file with timestamps and x coordinate          (positive) values (when a mouse is present in that side of the chamber) (or "NaN" when a mouse is not present in that side of the chamber). In the excel, use Data --> Text to      Columns--> Delimited --> space to transfer the data into separate columns. Simply calculate the % of frames with positive values.  
   - Use the Image Process_Raw node to select a ROI (Crop node) for the entire chamber including both sides, and the downstream nodes will generate a csv file with timestamps and      x, y coordinates you can use to plot a mouse tracking trace.  
   - Change the running time in the Timer node if desired.
   
3) For opto_chamber Bonsai code,
   - In the second timer node, you can change the DueTime (set with 1 min for baseline period before the trigger of opto stimulation protocol)
   - In the video analys Bonsai code, you can change the frame rate for the analysis by changing the number of frames that are skipped (Skip node). It will generate a csv file          with Euclidean distance for each frame analyzed. 
   
4) For opto_pupil video analysis Bonsai code, 
   - You can change the frame rate for the analysis by changing the number of frames that are skipped (Skip node).
   - Adjust "ThresholdValue" in the Threshold node and "MinArea" in the FindContours node to capture and track the pupil, depending on video capturing setup/conditions. 
   - It will generate a csv file with two data sets for each fram analyzed. Use the first one (diameter value) for calculation. 
   
5) For opto_lever Bonsai code,
   - Change the running time in the last Timer node if desired.
   - It will generate two csv files per lever (duration and count) with timestamps when the lever was pressed. Use the values in the levercount file, and simply add up the number    of timestamp values to caculate the total number of lever presses during the session.
