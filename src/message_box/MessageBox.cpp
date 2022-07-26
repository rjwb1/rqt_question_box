#include <rqt_question_box/message_box/MessageBox.h>

Window::Window(QWidget *parent) :
        QWidget(parent),
        size_h_(config::get<int>(ros::NodeHandle("~"),"~height")),
        size_w_(config::get<int>(ros::NodeHandle("~"),"~width"))
{
    // Set size of the window
    setFixedSize(size_w_, size_h_);

    m_label = new QLabel("", this);
    m_label->setGeometry(10, 50 , 580, 100);
    QFont font = m_label->font();
    m_label->setWordWrap(true);
    font.setPointSize(20);
    font.setBold(true);
    m_label->setFont(font);
}

Window::~Window()
{
}

void Window::moveCentre(int screen_width_, int screen_height_)
{
    move(((screen_width_ - size_w_) / 2), ((screen_height_ - size_h_) / 2));
}


void Window::setSize(int x, int y)
{
    setFixedSize(x, y);
}

void Window::setMsg(std::string message_)
{
    QString text = QString::fromStdString(message_);
    m_label->setText(text);
}

std::string Window::getResult()
{
    return result_;
}