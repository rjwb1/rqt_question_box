#ifndef SERVICE_HANDLE_H
#define SERVICE_HANDLE_H

#include <ros/ros.h>
#include <rqt_question_box/GetGui.h>
#include <rqt_question_box/shared_memory/SharedMemory.h>
#include <rqt_question_box/Data.h>

class ServiceHandle 
{
public:
    ServiceHandle(ros::NodeHandle* nodehandle, std::string service_name_);
    ~ServiceHandle();

private:
    ros::NodeHandle nh_;
    memory::SharedMemory::Ptr shd_mem_;
    memory::SharedObject<std::vector<Request>>  guiReq_;
    ros::ServiceServer service_;
    std::string service_name;
    int id_ = 0;

    int getId();

    bool serviceCallback(rqt_question_box::GetGuiRequest& req, rqt_question_box::GetGuiResponse& res);
};

#endif // SERVICE_HANDLE_H
