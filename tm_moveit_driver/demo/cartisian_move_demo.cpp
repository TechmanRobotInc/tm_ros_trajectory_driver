#include "ros/ros.h"
#include "tm_msgs/JointMove.h"
#include "tm_msgs/CartesianMove.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo_cartesian_move");
  

  ros::NodeHandle n;
  ros::ServiceClient cartesianMoveClient = n.serviceClient<tm_msgs::CartesianMove>("cartesian_target_move");
  tm_msgs::CartesianMove cartesianMoveSrv;
  cartesianMoveSrv.request.poseTarget.position.x = 0.5174654328489118;
  cartesianMoveSrv.request.poseTarget.position.y = -0.12230975732453687;
  cartesianMoveSrv.request.poseTarget.position.z = 0.461063498777877;
  cartesianMoveSrv.request.poseTarget.orientation.x = 0.7071235179901123;
  cartesianMoveSrv.request.poseTarget.orientation.y = 0.7070900201797485;
  cartesianMoveSrv.request.poseTarget.orientation.z = 0;
  cartesianMoveSrv.request.poseTarget.orientation.w = 0;
/*
position: 
  x: 0.5174654328489118
  y: -0.12230975732453687
  z: 0.461063498777877
orientation: 
  x: 0.7071235179901123
  y: 0.7070900201797485
  z: 2.1351197574404068e-05
  w: 2.7723019229597412e-05

*/

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