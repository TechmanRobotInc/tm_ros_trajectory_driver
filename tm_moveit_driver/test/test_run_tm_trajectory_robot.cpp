#include "../include/tm_moveit_robot.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "tm_moveit_driver_node");
  std::unique_ptr<TMMoveItRobot> tmMoveItRobot;
  tmMoveItRobot = std::make_unique<TMMoveItRobot>();
  geometry_msgs::Pose target;
  target.position.x = 0.5174654328489118;
  target.position.y = -0.12230975732453687;
  target.position.z = 0.461063498777877;
  target.orientation.x = 0.7071235179901123;
  target.orientation.y = 0.7070900201797485;
  target.orientation.z = 0;
  target.orientation.w = 0;
  tmMoveItRobot->set_cartesian_move(target);

  return 0;
}