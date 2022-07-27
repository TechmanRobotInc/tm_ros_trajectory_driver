#include "../include/tm_moveit_robot.hpp"

TMMoveItRobot::TMMoveItRobot(){
  moveGroup = std::make_unique<moveit::planning_interface::MoveGroupInterface>(PLANNING_GROUP);
  robotModelLoader = std::make_unique<robot_model_loader::RobotModelLoader>("robot_description");
  kinematicModel = robotModelLoader->getModel();
  kinematicState = robot_state::RobotStatePtr(new robot_state::RobotState(kinematicModel));
  jointModelGroup = kinematicModel->getJointModelGroup(PLANNING_GROUP);
  isPlan = false;
  sub = nh_.subscribe("joint_states", 1000, &TMMoveItRobot::joint_states_callback, this);
  
}
void TMMoveItRobot::joint_states_callback(const sensor_msgs::JointState::ConstPtr& msg){
  currentJoint = *msg;
  kinematicState->setJointGroupPositions(jointModelGroup,currentJoint.position);

  const Eigen::Isometry3d& endEffectorState = kinematicState->getGlobalLinkTransform("flange_link");

  auto tmp = endEffectorState.rotation();

  Eigen::Matrix3f roatationMatrix;
  roatationMatrix(0,0)=tmp(0,0);
  roatationMatrix(1,0)=tmp(1,0);
  roatationMatrix(2,0)=tmp(2,0);
  roatationMatrix(0,1)=tmp(0,1);
  roatationMatrix(1,1)=tmp(1,1);
  roatationMatrix(2,1)=tmp(2,1);
  roatationMatrix(0,2)=tmp(0,2);
  roatationMatrix(1,2)=tmp(1,2);
  roatationMatrix(2,2)=tmp(2,2);

  Eigen::Quaternionf q(roatationMatrix);

  currentPose.position.x = endEffectorState.translation()(0,0);
  currentPose.position.y = endEffectorState.translation()(1,0);
  currentPose.position.z = endEffectorState.translation()(2,0);

  currentPose.orientation.x = q.x();
  currentPose.orientation.y = q.y();
  currentPose.orientation.z = q.z();
  currentPose.orientation.w = q.w();
}
bool TMMoveItRobot::set_cartesian_move(geometry_msgs::Pose target){
  moveit::planning_interface::MoveGroupInterface::Plan myPlan;

  moveGroup->setPoseTarget(target);

  moveGroup->asyncMove();
  return true;
}
bool TMMoveItRobot::set_joint_move(std::vector<double> target){
  moveGroup->setJointValueTarget(target);
  bool success;
  if(isPlan){
    moveit::planning_interface::MoveGroupInterface::Plan myPlan;
    success = (moveGroup->plan(myPlan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);            
  } else {
    moveGroup->asyncMove();
    success = true;
  }
  return success;
}
sensor_msgs::JointState TMMoveItRobot::get_joint(){
  return currentJoint;
}
geometry_msgs::Pose TMMoveItRobot::get_pose(){
  return currentPose;
}