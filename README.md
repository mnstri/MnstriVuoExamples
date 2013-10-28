##compositions
Some example compositions.

## nodes
Some very simple nodes for Vuo.
###Installation instructions
<ol>
  <li>Download the nodes by cloning the repository or downloading the .zip from the sidebar.</li>
  <li>Copy the contents of this folder (nodes/) to: ~/Library/Application Support/Vuo/Modules/</li>
  <li>Launch/relaunch Vuo</li>
</ol>
###List of Nodes
These nodes are very basic but still quite useful. Most of them will probably become obsolete quite soon as Vuo gets updated, but for now they are a good workaround.
####mnstri.glsl.vignette.vuonode
A simple GLSL filter that creates a vignette effect.
####mnstri.math.absolute
Outputs the absolute value of the input value.
####mnstri.math.bpmToSeconds
Converts a BPM (Beats Per Minute) value to a number you can feed to the Fire Periodically node.
####mnstri.math.distanceBetweenPoints3D
Calculates the distance between two points.
####mnstri.math.fpsToSeconds
Converts an FPS (Frames Per Second) value to a number you can feed to the Fire Periodically node.
####mnstri.math.modulo
Modulo. Outputs the remainder of a division between the two input values.
####mnstri.math.sinCosTan
Outputs the sine, cosine and tanget of the input value.
####mnstri.utility.inputSplitter.color
Splits an input value (color) to multiple outputs. Useful for controlling your dataflow. Like the input splitter in QC.
####mnstri.utility.inputSplitter.image
Splits an input value (image) to multiple outputs. Useful for controlling your dataflow. Like the input splitter in QC.
####mnstri.utility.inputSplitter.integer
Splits an input value (integer) to multiple outputs. Useful for controlling your dataflow. Like the input splitter in QC.
####mnstri.utility.inputSplitter.point3d
Splits an input value (3D Point) to multiple outputs. Useful for controlling your dataflow. Like the input splitter in QC.
####mnstri.utility.inputSplitter.real
Splits an input value (real) to multiple outputs. Useful for controlling your dataflow. Like the input splitter in QC.

##source-for-nodes
The source code for the nodes.
