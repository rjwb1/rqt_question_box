#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QFont>
#include <QString>
#include <rqt_question_box/message_box/MessageBox.h>
#include <ros/ros.h>
#include <QDesktopWidget>

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

    // Create and position the button
    m_yes_button = new QPushButton("Yes", this);
    m_yes_button->setGeometry(50, 250, 200, 100);

    m_no_button = new QPushButton("No", this);
    m_no_button->setGeometry(350, 250, 200, 100);

    // NEW : Do the connection
    connect(m_no_button, &QPushButton::released, this, &Window::handleNoButton);
    connect(m_yes_button, &QPushButton::released, this, &Window::handleYesButton);
}

void Window::setMsg(std::string message_)
{
    QString text = QString::fromStdString(message_);
    m_label->setText(text);
}

void Window::handleYesButton()
{
    // std::cout << "Yes!" << std::endl;
    result_ = "true";
    QApplication::quit();
}

void Window::handleNoButton()
{
    // std::cout << "No!" << std::endl;
    result_ = "false";
    QApplication::quit();
}

std::string Window::getResult()
{
    return result_;
}