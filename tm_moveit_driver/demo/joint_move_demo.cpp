#include "ros/ros.h"
#include "tm_msgs/JointMove.h"
#include "tm_msgs/CartesianMove.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo_joint_move");
  

  ros::NodeHandle n;
  ros::ServiceClient jointMoveClient = n.serviceClient<tm_msgs::JointMove>("joint_move");
  tm_msgs::JointMove jointMoveSrv;
  jointMoveSrv.request.jointTarget.position.push_back(0);
  jointMoveSrv.request.jointTarget.position.push_back(0);
  jointMoveSrv.request.jointTarget.position.push_back(1.57);
  jointMoveSrv.request.jointTarget.position.push_back(0);
  jointMoveSrv.request.jointTarget.position.push_back(0);
  jointMoveSrv.request.jointTarget.position.push_back(1.57);

  if (jointMoveClient.call(jointMoveSrv))
  {
    ROS_INFO("isOk is %d",jointMoveSrv.response.isOK);
  }
  else
  {
    ROS_ERROR("Failed to call service joint_move");
    return 1;
  }

  return 0;
}