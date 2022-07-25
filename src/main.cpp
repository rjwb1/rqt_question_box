#include <iostream>
#include <ros/ros.h>
#include <rqt_question_box/App.h>
#include <rqt_question_box/ServiceHandle.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "gui");
  ros::NodeHandle nh;

  ros::AsyncSpinner spinner(4);
  spinner.start();
  ros::Rate r(5); // 10 hz

  App app(argc, argv);
  ServiceHandle service_handle(&nh, "gui");

  std::cout << "Spinning..." << std::endl;
  while (ros::ok())
  {
    app.update();
    r.sleep();
  }

 return 0;
}