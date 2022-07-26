#ifndef APP_H
#define APP_H

#include <rqt_question_box/shared_memory/SharedMemory.h>
#include <rqt_question_box/Data.h>
#include <rqt_question_box/message_box/MessageBox.h>
#include <rqt_question_box/message_box/BoolBox.h>
#include <rqt_question_box/message_box/StringBox.h>
#include <rqt_question_box/message_box/IntBox.h>
#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <QDesktopWidget>
class App 
{
public:
    App(int argc, char **argv);
    ~App();
    void update();

private:
    memory::SharedMemory::Ptr shd_mem_;
    memory::SharedObject<std::vector<Request>>  guiReq_;
    std::vector<Request> request_vec;  
    QApplication app;
    QDesktopWidget *desktop;
    int x, y;
};

#endif // APP_H
