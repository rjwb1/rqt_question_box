#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <QLabel>
#include <QApplication>
#include <QFont>
#include <QString>
#include <QWidget>

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
    protected:
        std::string result_;
        QLabel *m_label;
};

#endif // MESSAGE_BOX_H
