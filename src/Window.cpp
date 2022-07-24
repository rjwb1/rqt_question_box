#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QFont>
#include <QString>
#include <rqt_question_box/Window.h>
#include <ros/ros.h>

Window::Window(QWidget *parent) :
        QWidget(parent)
{

    shd_mem_    = memory::SharedMemory::getInstance();
    guiOut = shd_mem_->getSharedObject<bool>("_GUI_OUT_");
    guiRes = shd_mem_->getSharedObject<bool>("_GUI_RES_");

    // Set size of the window
    setFixedSize(600, 400);

    m_label = new QLabel("", this);
    m_label->setGeometry(10, 50 , 400, 100);
    QFont font = m_label->font();
    font.setPointSize(12);
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
    guiRes.setObject(true);
    QApplication::quit();
}

void Window::handleNoButton()
{
    // std::cout << "No!" << std::endl;
    guiRes.setObject(false);
    QApplication::quit();
}