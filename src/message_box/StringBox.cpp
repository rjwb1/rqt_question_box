#include <rqt_question_box/message_box/StringBox.h>

StringBox::StringBox()
{
    // Create and position the button
    m_button = new QPushButton("Ok", this);
    m_textbox = new QLineEdit(this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_label, 0, 0, 1, 5);
    layout->addWidget(m_textbox, 2, 0, 1, 3);
    layout->addWidget(m_button, 2, 3, 1, 2);
    setLayout(layout);

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