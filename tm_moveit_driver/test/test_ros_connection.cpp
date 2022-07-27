#include "ros/ros.h"
#include "../include/move_robot.hpp"
#include "tm_msgs/JointMove.h"
#include "tm_msgs/CartesianMove.h"




int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_tm_moveit_driver_node");

  ros::NodeHandle nh_demo; 
  ros::ServiceClient client = nh_demo.serviceClient<tm_msgs::CartesianMove>("cartesian_target_move");
  tm_msgs::CartesianMove srv;

  //Request 
  geometry_msgs::Pose pose;
  pose.position.x = 0.1;
  pose.position.y = 0.2;
  pose.position.z = 0.3;
  srv.request.poseTarget = pose;


  // Wait for the result.
  if (client.call(srv))                             
  {
    if (srv.response.isOK) {
      ROS_INFO_STREAM("cartesian move response is " << srv.response.isOK);
    }    	
    else { 
      ROS_WARN_STREAM("cartesian move response not yet ok ");
    }
  }
  else
  {
    ROS_ERROR_STREAM("Error cartesian move to robot");
    return 1;
  }
  
  ros::ServiceClient jointClient = nh_demo.serviceClient<tm_msgs::JointMove>("joint_move");
  tm_msgs::JointMove jointSrv;

  //Request 
  sensor_msgs::JointState jointTarget;
  jointTarget.position.push_back(0);
  jointTarget.position.push_back(0);
  jointTarget.position.push_back(90);
  jointTarget.position.push_back(0);
  jointTarget.position.push_back(90);
  jointTarget.position.push_back(0);

  jointSrv.request.jointTarget = jointTarget;


  // Wait for the result.
  if (jointClient.call(jointSrv))                             
  {
    if (jointSrv.response.isOK) {
      ROS_INFO_STREAM("joint move response is " << jointSrv.response.isOK);
    }    	
    else { 
      ROS_WARN_STREAM("joint move response not yet ok ");
    }
  }
  else
  {
    ROS_ERROR_STREAM("Error joint move to robot");
    return 1;
  }

  return 0;
}