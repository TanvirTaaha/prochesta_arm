#include <ros/ros.h>
#include <std_msgs/String.h>
#include <cstdio>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);
    
    int count = 0;
    while (ros::ok())
    {
        std_msgs::String msg;
        char str[100];
        snprintf(str, 100, "%d, %d, %d, %d, %d, %d, %d", 10, 20, 30, 40, 50, 60, 70);
        msg.data = str;
        ROS_INFO("%d:Message is:%s", count, str);
        pub.publish(msg);
        loop_rate.sleep();
        count++;
    }
    return 0;
}