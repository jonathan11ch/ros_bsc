#include "ros/ros.h"
#include <vectornav/Ins.h>

float angle = 0;
//Reader callback
void readerCallback(const vectornav::Ins::ConstPtr& msg)
{
  ROS_INFO("ddd");
  angle = msg->yaw;
  //ROS_INFO("Read data: [%f]", msg->yaw);
}

//Main entry point
int main(int argc, char **argv)
{
  ros::init(argc, argv, "sensor_reader");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/vectornav/INS", 1000 , readerCallback);
  ROS_INFO("Before Spin");
while (ros::ok()) {
  /* code */
  ROS_INFO("Spinning: [%f]", angle);
  ros::spinOnce();
}

  return 0;
}
