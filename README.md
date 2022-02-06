# sensor_talk_ws
ROS talker listener example but with "sliding window sensor"


git clone https://github.com/juansuerorobotics/sensor_talk_ws.git

cd sensor_talk_ws

catkin_make

vi ~/.bashrc

source devel/setup.bash

open new terminal
roslaunch sensor_talker sensor_talker.launch sensor_numreadings:=10

open new terminal 
roslaunch sensor_listener sensor_listener.launch sensor_span:=10

open new terminal 
rostopic echo /sensor_running_avg

