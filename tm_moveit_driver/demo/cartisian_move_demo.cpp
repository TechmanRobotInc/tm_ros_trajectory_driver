#include "ros/ros.h"
#include "tm_msgs/JointMove.h"
#include "tm_msgs/CartesianMove.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo_cartesian_move");
  

  ros::NodeHandle n;
  ros::ServiceClient cartesianMoveClient = n.serviceClient<tm_msgs::CartesianMove>("cartesian_target_move");
  tm_msgs::CartesianMove cartesianMoveSrv;
  cartesianMoveSrv.request.poseTarget.position.x = 0.5173971834076588;
  cartesianMoveSrv.request.poseTarget.position.y = -0.12227435655083664;
  cartesianMoveSrv.request.poseTarget.position.z = 0.4610696619406722;
  cartesianMoveSrv.request.poseTarget.orientation.x = 0.7072787284851074;
  cartesianMoveSrv.request.poseTarget.orientation.y = 0.7069346308708191;
  cartesianMoveSrv.request.poseTarget.orientation.z = 0.00019281297863926739;
  cartesianMoveSrv.request.poseTarget.orientation.w = 0.0003879592986777425;

  if (cartesianMoveClient.call(cartesianMoveSrv))
  {
    ROS_INFO("isOk is %d",cartesianMoveSrv.response.isOK);
  }
  else
  {
    ROS_ERROR("Failed to call service cartesian_target_move");
    return 1;
  }

  return 0;
}