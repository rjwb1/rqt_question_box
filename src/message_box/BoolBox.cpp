#include <rqt_question_box/message_box/BoolBox.h>

BoolBox::BoolBox()
{
    // Create and position the button
    m_yes_button = new QPushButton("Yes", this);
    m_yes_button->setGeometry(50, 250, 200, 100);

    m_no_button = new QPushButton("No", this);
    m_no_button->setGeometry(350, 250, 200, 100);

    // NEW : Do the connection
    connect(m_no_button, &QPushButton::released, this, &BoolBox::handleNoButton);
    connect(m_yes_button, &QPushButton::released, this, &BoolBox::handleYesButton);
}

BoolBox::~BoolBox()
{
}

void BoolBox::handleYesButton()
{
    // std::cout << "Yes!" << std::endl;
    result_ = "true";
    QApplication::quit();
}

void BoolBox::handleNoButton()
{
    // std::cout << "No!" << std::endl;
    result_ = "false";
    QApplication::quit();
}