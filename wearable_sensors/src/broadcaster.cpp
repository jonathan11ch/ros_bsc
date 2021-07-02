#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


int main(int argc, char **argv){
  //initialize ros node
  ros::init(argc, argv, "broadcaster");
  //create the node handler
  ros::NodeHandle n;
  //create the publisher objects
  ros::Publisher pub = n.advertise<std_msgs::String>("broadcast_topic",10);
  ros::Rate loop_rate(1000);

  int count = 0;
  while(ros::ok()){
    std_msgs::String msg;
    std::stringstream ss;
    ss<<"broadcast data: "<< count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
    //publish data
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
 return 0;
}
