#include "ros/ros.h"
#include "../include/move_robot.hpp"
#include "tm_msgs/JointMove.h"
#include "tm_msgs/CartesianMove.h"
#include "../include/tm_moveit_robot.hpp"

class TmMoveDriver{
 private:
  bool isRun = true; 
  ros::NodeHandle nh_;
  ros::ServiceServer cartesianMoveCmd;
  ros::ServiceServer jointMoveCmd;
  ros::Publisher jointStatePublisher;
  ros::Publisher cartesianPublisher;
  std::thread popDataThread;
  void initial_moveit_driver_service();
  void initial_publisher();
  void pop_data_thread();
  bool cartesian_target_move(tm_msgs::CartesianMoveRequest &req, tm_msgs::CartesianMoveResponse &res);
  bool joint_move(tm_msgs::JointMoveRequest &req, tm_msgs::JointMoveResponse &res);
  std::unique_ptr<MoveRobot> moveRobot;
 public:
  TmMoveDriver();
};
bool TmMoveDriver::cartesian_target_move(tm_msgs::CartesianMoveRequest &req, tm_msgs::CartesianMoveResponse &res){
  std::cout<<"cartesian_target_move is called"<<std::endl;
  bool ok =  moveRobot->set_cartesian_move(req.poseTarget);
  res.isOK = ok;
  return ok;
}
bool TmMoveDriver::joint_move(tm_msgs::JointMoveRequest &req, tm_msgs::JointMoveResponse &res){
  bool ok =  moveRobot->set_joint_move(req.jointTarget.position);
  res.isOK = ok;
  return ok;
}
void TmMoveDriver::initial_moveit_driver_service(){
  cartesianMoveCmd = nh_.advertiseService("cartesian_target_move", &TmMoveDriver::cartesian_target_move, this);
  jointMoveCmd = nh_.advertiseService("joint_move", &TmMoveDriver::joint_move, this);
}
void TmMoveDriver::initial_publisher(){
  jointStatePublisher = nh_.advertise<sensor_msgs::JointState>("tm_joint_states", 10);
  cartesianPublisher = nh_.advertise<geometry_msgs::Pose>("tm_tool_pose", 10);
}
void TmMoveDriver::pop_data_thread(){
  while (isRun){
    jointStatePublisher.publish(moveRobot->get_joint());
    cartesianPublisher.publish(moveRobot->get_pose());
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
TmMoveDriver::TmMoveDriver(){
  //moveRobot = std::make_unique<FakeMoveRobot>();
  moveRobot = std::make_unique<TMMoveItRobot>();
  initial_moveit_driver_service();
  initial_publisher();
  popDataThread = std::thread(std::bind(&TmMoveDriver::pop_data_thread, this));
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "tm_moveit_driver_node");
  std::unique_ptr<TmMoveDriver> tmMoveDriver;
  tmMoveDriver = std::make_unique<TmMoveDriver>();

  ros::spin();

  return 0;
}