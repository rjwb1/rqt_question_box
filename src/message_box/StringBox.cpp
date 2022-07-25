#include <rqt_question_box/message_box/StringBox.h>

StringBox::StringBox()
{
    // Create and position the button
    m_button = new QPushButton("Ok", this);
    m_button->setGeometry(350, 250, 200, 100);

    m_textbox = new QLineEdit(this);
    m_textbox->setGeometry(10, 250, 380, 100);

    // NEW : Do the connection
    connect(m_button, &QPushButton::released, this, &StringBox::handleOkButton);
}

StringBox::~StringBox()
{
}

void StringBox::handleOkButton()
{
    result_ = m_textbox->text().toStdString() ;
    QApplication::quit();
}