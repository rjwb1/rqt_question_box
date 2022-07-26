#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <QLabel>
#include <QApplication>
#include <QFont>
#include <QString>
#include <QWidget>
#include <rqt_question_box/Config.h>

class QPushButton;
class QLabel;

class Window : public QWidget
{
    public:
        explicit Window(QWidget *parent = 0);
        ~Window();
        void setMsg(std::string message_);
        std::string getResult();
        void setSize(int x, int y);
        void moveCentre(int screen_width_, int screen_height_);
    protected:
        std::string result_;
        QLabel *m_label;
        int size_h_;
        int size_w_;
};

#endif // MESSAGE_BOX_H
