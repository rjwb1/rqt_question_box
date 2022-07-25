#include <rqt_question_box/message_box/MessageBox.h>

Window::Window(QWidget *parent) :
        QWidget(parent)
{
    // Set size of the window
    setFixedSize(600, 400);

    m_label = new QLabel("", this);
    m_label->setGeometry(10, 50 , 580, 100);
    QFont font = m_label->font();
    font.setPointSize(20);
    font.setBold(true);
    m_label->setFont(font);
}

Window::~Window()
{
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