#include "../include/move_robot.hpp"

bool FakeMoveRobot::set_cartesian_move(geometry_msgs::Pose target){
  std::cout<<"target is "<<target.position.x<<","<<target.position.y<<","<<target.position.z<<std::endl;
  return true;
}
bool FakeMoveRobot::set_joint_move(std::vector<double> target) {
  std::cout<<"target is ";
  for(int i =0; i<target.size();i++){
    std::cout<<target[i]<<",";
  }
  std::cout<<std::endl;
  return true;
}
sensor_msgs::JointState FakeMoveRobot::get_joint() {
  sensor_msgs::JointState re;
  re.position.push_back(0);
  re.position.push_back(0);
  re.position.push_back(90);
  re.position.push_back(0);
  re.position.push_back(90);
  re.position.push_back(0);
  return re;
}
geometry_msgs::Pose FakeMoveRobot::get_pose(){
  geometry_msgs::Pose pose;
  pose.position.x = 1; 
  pose.position.x = 2; 
  pose.position.x = 3;
  pose.orientation.x = 56;
  pose.orientation.y = 57;
  pose.orientation.z = 58;
  pose.orientation.w = 60;
  return pose;
}
