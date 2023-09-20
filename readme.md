# __TM Trajectory ROS Driver__


## __1. Overview__
This is Techman Robot Trajectory ROS Driver.<br/>
This package should be used with [TM ROS1 Noetic driver](https://github.com/TechmanRobotInc/tmr_ros1/tree/noetic).

## __2. Install__
1. Type to create a root workspace directory by starting a terminal:<br/>
For example, ``tmdriver_ws`` or ``catkin_ws``, then type to change the current directory into the workspace directory path.<br/>
``mkdir ~/tmdriver_ws``<br/>
``cd ~/tmdriver_ws``<br/>

2. Download the TM driver of the git repository into the current directory by typing<br/>
``git clone -b noetic https://github.com/TechmanRobotInc/tmr_ros1.git``<br/>

3. Download the TM Trajectory driver of the git repository into the current directory by typing<br/>
``git clone https://github.com/TechmanRobotInc/tm_ros_trajectory_driver.git``<br/>

4. Copy the TM Trajectory driver to TM driver and change its name to src<br/>
``cp -R tm_ros_trajectory_driver tmr_ros1``<br/>
``mv ~/tmdriver_ws/tmr_ros1 ~/tmdriver_ws/src``<br/>

5. Install the MoveIt environment, by typing<br/>
``cd ~/tmdriver_ws/src/tm_ros_trajectory_driver``<br/>
``sudo chmod +x install.sh``<br/>
``./install.sh``<br/>
**Note**: The _install.sh_ installation will only need to be built once, unless it needs to be updated.

6. Build all source code<br/>
``cd ~/tmdriver_ws``<br/>
``catkin_make``<br/>
``source ./devel/setup.bash``<br/>

## __3. Running it in simulator__
You can run the TM Trajectory ROS Driver with the following command in the virtual environment
1. Please launch the TM ros driver with MoveIt, we use TM5-900 for example<br/>
``roslaunch tm5-900-moveit_config tm5-900_moveit_planning_execution.launch sim:=True``<br/>
2. Please run the TM Trajectory ROS Driver<br/>
``rosrun tm_trajectory_driver tm_trajectory_driver``

## __4. Running it in real robot__
You can run the TM Trajectory ROS Driver with the following command in a real robot
1. Please launch the TM ros driver with MoveIt, we use TM5-900 for example<br/>
``roslaunch tm5-900-moveit_config tm5-900_moveit_planning_execution.launch sim:=False robot_ip:=<your_ip>``<br/>
2. Please run the TM Trajectory ROS Driver<br/>
``rosrun tm_trajectory_driver tm_trajectory_driver``<br/>

## __5. Use the demo codes to commute with TM Trajectory ROS Driver__
You can run the demo code to send joint target by typing<br/>
`` rosrun tm_trajectory_driver joint_move_demo ``<br/>
you can also run the demo code to send a cartesian target by typing<br/>
``rosrun tm_trajectory_driver cartisian_move_demo``<br/>
## __6. Get the current robot status__
You can get the current robot joints position by typing<br/>
`` rostopic echo /tm_joint_states ``<br/>
You can get the current robot cartesian position by typing<br/>
`` rostopic echo /tm_tool_pose ``<br/>
