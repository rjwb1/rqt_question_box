#include <rqt_question_box/App.h>

App::App(int argc, char **argv) :
    app(argc, argv)
{
    shd_mem_    = memory::SharedMemory::getInstance();
    guiReq_ = shd_mem_->getSharedObject<std::vector<Request>>("_GUI_REQ_");
    desktop = QApplication::desktop();
    int screenWidth;
    int screenHeight;
    int x, y;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth - 600) / 2;
    y = (screenHeight - 400) / 2;
}

App::~App()
{
    std::cout << "~" << typeid ( this ).name() << std::endl;
}

void App::update()
{
    request_vec = guiReq_.getObject();
    if (! request_vec.empty())
    {
      if (! request_vec[0].result)
        {
            if(request_vec[0].type == "bool")
            {
                BoolBox window;
                window.setMsg(request_vec[0].question);
                //window.move( x, y );
                window.show();
                app.exec();
                request_vec = guiReq_.getObject();
                request_vec[0].response = window.getResult();
                request_vec[0].result = true; 
                guiReq_.setObject(request_vec);
            }
            else if (request_vec[0].type == "string")
            {
                StringBox window;
                window.setMsg(request_vec[0].question);
                //window.move( x, y );
                window.show();
                app.exec();
                request_vec = guiReq_.getObject();
                request_vec[0].response = window.getResult();
                request_vec[0].result = true; 
                guiReq_.setObject(request_vec);
            }
            else
            {
                request_vec = guiReq_.getObject();
                request_vec[0].result = true; 
                guiReq_.setObject(request_vec);
            }


        }
    }
}