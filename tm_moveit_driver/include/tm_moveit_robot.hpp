#include "move_robot.hpp"
#include <tf/tf.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
class TMMoveItRobot : public MoveRobot{
 private:
  private:
  std::string PLANNING_GROUP = "tmr_arm";
  const double eefStep = 0.01;
  const double jumpThreshold = 0.0; 
  std::unique_ptr<moveit::planning_interface::MoveGroupInterface> moveGroup;
  robot_model::RobotModelPtr kinematicModel;
  robot_state::RobotStatePtr kinematicState;
  std::unique_ptr<robot_model_loader::RobotModelLoader> robotModelLoader;
  const robot_state::JointModelGroup* jointModelGroup;
  ros::Subscriber sub;
  ros::NodeHandle nh_;
  sensor_msgs::JointState currentJoint;
  geometry_msgs::Pose currentPose;
  bool isPlan;
  void joint_states_callback(const sensor_msgs::JointState::ConstPtr& msg);
 public:
  bool set_cartesian_move(geometry_msgs::Pose target) override;
  bool set_joint_move(std::vector<double> target) override;
  sensor_msgs::JointState get_joint() override;
  geometry_msgs::Pose get_pose() override;
  TMMoveItRobot();
} ;