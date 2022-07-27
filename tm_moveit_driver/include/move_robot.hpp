#include <sensor_msgs/JointState.h>
#include <geometry_msgs/Pose.h>
#include <thread>
#ifndef MOVE_ROBOT_HPP
#define MOVE_ROBOT_HPP
class MoveRobot{
 public:
  virtual bool set_cartesian_move(geometry_msgs::Pose target)=0;
  virtual bool set_joint_move(std::vector<double> target)=0;
  virtual sensor_msgs::JointState get_joint()=0;
  virtual geometry_msgs::Pose get_pose()=0;
};

class FakeMoveRobot : public MoveRobot{
 public:
  bool set_cartesian_move(geometry_msgs::Pose target) override;
  bool set_joint_move(std::vector<double> target) override;
  sensor_msgs::JointState get_joint() override;
  geometry_msgs::Pose get_pose() override;
} ;
#endif