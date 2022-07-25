#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <QWidget>
#include <rqt_question_box/shared_memory/SharedMemory.h>
#include <rqt_question_box/Data.h>

class QPushButton;
class QLabel;

class Window : public QWidget
{
    public:
        explicit Window(QWidget *parent = 0);
        void setMsg(std::string message_);
        std::string getResult();

    private:
        void handleYesButton();
        void handleNoButton();
        QPushButton *m_yes_button;
        QPushButton *m_no_button;
        QLabel *m_label;
        std::string result_;
};

#endif // MESSAGE_BOX_H
