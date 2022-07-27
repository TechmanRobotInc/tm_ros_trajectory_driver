# __TM Trajecotry ROS Driver__


## __1. Overview__
This is Techman Robot Trajecotry ROS Driver<br/>
this package should be used with [TM ROS1 Noetic driver](https://github.com/TechmanRobotInc/tmr_ros1/tree/noetic)

## __2. Install__
1. Type to create a root workspace directory by starting a terminal: For example,  ``tmdriver_ws`` or ``catkin_ws``, then type to change current directory into the workspace directory path.<br/>
``mkdir ~/tmdriver_ws``<br/>
``cd ~/tmdriver_ws``<br/>

2. Download the the TM driver of git repository into the current directory by typing<br/>
``git clone -b noetic https://github.com/TechmanRobotInc/tmr_ros1.git``<br/>

3. Download the the TM Trjectory driver of git repository into the current directory by typing<br/>
``git clone https://github.com/TechmanRobotInc/tm_ros_trajectory_driver.git``<br/>

4. copy all TM Trjectory driver to TM driver and change its name to src<br/>
``cp -R tm_ros_trajectory_driver tmr_ros1``<br/>
``mv ~/tmdriver_ws/tmr_ros1 ~/tmdriver_ws/src``<br/>

4. install the moveit environment, by typing<br/>
``cd ~/tmdriver_ws/src/tm_ros_trajectory_driver``<br/>
``sudo chmod +x install.sh``<br/>
``./install.sh``<br/>

5. Build all source code<br/>
``cd ~/tmdriver_ws``
``catkin_make``
``source devel/setup.bat``

## __3. Running it in simulator__
You can run the TM Trajectory ROS Driver with following command in virtual environment
1. please launch the tm ros driver moveit, we use TM5-900 for example<br/>
``roslaunch tm5-900_moveit_config tm5-900_moveit_planning_execution.launch sim:=True``<br/>
2. please run the TM Trajectory ROS Driver<br/>
``rosrun tm_moveit_driver tm_moveit_driver``

## __4. Running it in real robot__
You can run the TM Trajectory ROS Driver with following command in real robot
1. please launch the tm ros driver moveit, we use TM5-900 for example<br/>
``roslaunch tm5-900_moveit_config tm5-900_moveit_planning_execution.launch sim:=False robot_ip:=<your_ip>``<br/>
2. please run the TM Trajectory ROS Driver<br/>
``rosrun tm_moveit_driver tm_moveit_driver``<br/>

## __5. Use the demo codes to commute with TM Trajectory ROS Driver__
You can run the demo code to send joint target by typing<br/>
`` rosrun tm_moveit_driver joint_move_demo ``<br/>
you can alos run the demo code to send cartesian target by typing<br/>
``rosrun tm_moveit_driver cartisian_move_demo``<br/>
## __6. Get the current robot status__
You can get the current robot joints position by typing<br/>
`` rostopic echo /tm_joint_states ``<br/>
You can get the current robot cartesian position by typing<br/>
`` rostopic echo /tm_tool_pose ``<br/>
