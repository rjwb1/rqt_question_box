#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <rqt_question_box/Window.h>
#include <iostream>
#include <rqt_question_box/GetGui.h>
#include <ros/ros.h>

bool gui(rqt_question_box::GetGui::Request  &req,
         rqt_question_box::GetGui::Response &res)
{
  memory::SharedMemory::Ptr shd_mem_;
  shd_mem_ = memory::SharedMemory::getInstance();
  memory::SharedObject<Request> guiReq;
  memory::SharedObject<bool> guiOut;
  memory::SharedObject<bool> guiRes;
  guiReq = shd_mem_->getSharedObject<Request>("_GUI_REQ_");
  guiOut = shd_mem_->getSharedObject<bool>("_GUI_OUT_");
  guiRes = shd_mem_->getSharedObject<bool>("_GUI_RES_");
  Request gui_request;
  gui_request.msg = req.question; 
  gui_request.active = true; 
  guiReq.setObject(gui_request);
  ros::Rate r(10); // 10 hz
  while (ros::ok())
  {
    if (guiOut.getObject())
    {
      guiOut.setObject(false);
      res.result = guiRes.getObject();
      return true;
    } 
    r.sleep();
  }
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "gui");
  ros::NodeHandle n;
  memory::SharedMemory::Ptr shd_mem_;
  memory::SharedObject<bool> guiOut;
  memory::SharedObject<Request> guiReq;
  shd_mem_ = memory::SharedMemory::getInstance();
  QApplication app(argc, argv);
  ros::ServiceServer service = n.advertiseService("gui", gui);
  guiOut = shd_mem_->getSharedObject<bool>("_GUI_OUT_");
  guiReq = shd_mem_->getSharedObject<Request>("_GUI_REQ_");
  ros::AsyncSpinner spinner(4);
  spinner.start();
  ros::Rate r(5); // 10 hz
  while (ros::ok())
  {
    std::cout << "+++++++++" << std::endl;

    if (guiReq.getObject().active)
    {
      std::cout << "Start Gui" << std::endl;
      Window window;
      window.setMsg(guiReq.getObject().msg);
      window.show();
      app.exec();
      Request request;
      request.active = false;
      guiReq.setObject(request);
      guiOut.setObject(true);
    } 
    r.sleep();
  }

 return 0;
}