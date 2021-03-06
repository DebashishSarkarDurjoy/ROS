#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "topic_publisher");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

  ros::Rate loop_rate(2);

  geometry_msgs::Twist var;
  var.linear.x = 2;
  var.angular.z = 2;

  while (ros::ok()) {
    pub.publish(var);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
