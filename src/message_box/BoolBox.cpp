#include <rqt_question_box/message_box/BoolBox.h>

BoolBox::BoolBox()
{
    // Create and position the button
    m_yes_button = new QPushButton("Yes", this);
    m_no_button = new QPushButton("No", this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_label, 0, 0, 1, 5);
    layout->addWidget(m_yes_button, 2, 0, 1, 2);
    layout->addWidget(m_no_button, 2, 3, 1, 2);
    setLayout(layout);

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