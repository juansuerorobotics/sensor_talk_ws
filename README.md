# sensor_talk_ws
ROS talker listener example but with "sliding window sensor"

I ran these on ROS1 Noetic on Ubuntu 20.04  
Long story short it streamlines the sensor example instead of looping through the queue everytime.

cd <directory where you will perform the git clone>
  
git clone https://github.com/juansuerorobotics/sensor_talk_ws.git

cd sensor_talk_ws

catkin_make

-------------
vi ~/.bashrc

add the following lines to the end of ~/.bashrc

source /opt/ros/noetic/setup.bash

source <directory where you performed the git clone>/sensor_talk_ws/devel/setup.bash

-------------
  
cd <directory where you will perform the git clone>
  
cd sensor_talk_ws
  
source devel/setup.bash

-------------
  
open new terminal
roslaunch sensor_talker sensor_talker.launch sensor_numreadings:=10

open new terminal 
roslaunch sensor_listener sensor_listener.launch sensor_span:=10

open new terminal 
rostopic echo /sensor_running_avg

