#include <rqt_question_box/ServiceHandle.h>

ServiceHandle::ServiceHandle(ros::NodeHandle* nodehandle, std::string service_name_) :
    nh_(*nodehandle),
    service_name(service_name_)
{
    shd_mem_    = memory::SharedMemory::getInstance();
    guiReq_ = shd_mem_->getSharedObject<std::vector<Request>>("_GUI_REQ_");
    ROS_INFO("Initializing Service");
    service_ = nh_.advertiseService(service_name, &ServiceHandle::serviceCallback, this);  
}

ServiceHandle::~ServiceHandle()
{
    std::cout << "~" << typeid ( this ).name() << std::endl;
}

bool ServiceHandle::serviceCallback(rqt_question_box::GetGuiRequest& req, rqt_question_box::GetGuiResponse& res) {
    
    ROS_INFO("Got New Request: [%s]", req.question.c_str());
    std::vector<Request> gui_request_vec;
    Request gui_request;
    gui_request.question = req.question;
    int req_id = ServiceHandle::getId();
    gui_request.id = req_id;
    gui_request.type = req.type;;
    gui_request_vec = guiReq_.getObject();
    gui_request_vec.push_back(gui_request);
    guiReq_.setObject(gui_request_vec);
    ros::Rate r(3); // 10 hz
    while (ros::ok())
    {
        gui_request_vec = guiReq_.getObject();
        if (!gui_request_vec.empty())
        {
            if (gui_request_vec[0].id == req_id && gui_request_vec[0].result)
            {
                res.response = gui_request_vec[0].response;
                gui_request_vec.erase(gui_request_vec.begin());
                guiReq_.setObject(gui_request_vec);
                return true;
            }
        }
        r.sleep();
    }
    return true;    
}

int ServiceHandle::getId()
{
    id_++;
    if (id_ == 50)
    {
        id_ = 0;
    }
    return id_;
}