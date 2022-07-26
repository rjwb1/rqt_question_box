#include <rqt_question_box/message_box/IntBox.h>

IntBox::IntBox()
{
    // Create and position the button
    m_ok_button = new QPushButton("Ok", this);
    m_clear_button = new QPushButton("Clear", this);
    m_0_button = new QPushButton("0", this);
    m_1_button = new QPushButton("1", this);
    m_2_button = new QPushButton("2", this);
    m_3_button = new QPushButton("3", this);
    m_4_button = new QPushButton("4", this);
    m_5_button = new QPushButton("5", this);
    m_6_button = new QPushButton("6", this);
    m_7_button = new QPushButton("7", this);
    m_8_button = new QPushButton("8", this);
    m_9_button = new QPushButton("9", this);

    m_entry_label = new QLabel("", this);
    m_entry_label->setGeometry(10, 150 , 580, 100);
    QFont font = m_label->font();
    font.setPointSize(20);
    font.setBold(true);
    m_entry_label->setFont(font);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_label, 0, 0, 1, 3);
    layout->addWidget(m_entry_label, 1, 0, 1, 3);
    layout->addWidget(m_1_button, 2, 0);
    layout->addWidget(m_2_button, 2, 1);
    layout->addWidget(m_3_button, 2, 2);
    layout->addWidget(m_4_button, 3, 0);
    layout->addWidget(m_5_button, 3, 1);
    layout->addWidget(m_6_button, 3, 2);
    layout->addWidget(m_7_button, 4, 0);
    layout->addWidget(m_8_button, 4, 1);
    layout->addWidget(m_9_button, 4, 2);
    layout->addWidget(m_clear_button, 5, 0);
    layout->addWidget(m_0_button, 5, 1);
    layout->addWidget(m_ok_button, 5, 2);
    setLayout(layout);
    
    // NEW : Do the connection
    connect(m_ok_button, &QPushButton::released, this, &IntBox::handleOkButton);
    connect(m_clear_button, &QPushButton::released, this, &IntBox::handleClearButton);
    connect(m_1_button, &QPushButton::released, this, &IntBox::handleKeypad);
    connect(m_2_button, &QPushButton::released, this, &IntBox::handleKeypad);
    connect(m_3_button, &QPushButton::released, this, &IntBox::handleKeypad);
    connect(m_4_button, &QPushButton::released, this, &IntBox::handleKeypad);
    connect(m_5_button, &QPushButton::released, this, &IntBox::handleKeypad);
    connect(m_6_button, &QPushButton::released, this, &IntBox::handleKeypad);
    connect(m_7_button, &QPushButton::released, this, &IntBox::handleKeypad);
    connect(m_8_button, &QPushButton::released, this, &IntBox::handleKeypad);
    connect(m_9_button, &QPushButton::released, this, &IntBox::handleKeypad);
    connect(m_0_button, &QPushButton::released, this, &IntBox::handleKeypad);
}

IntBox::~IntBox()
{
}

void IntBox::handleOkButton()
{
    result_ = entry_;
    QApplication::quit();
}

void IntBox::handleClearButton()
{
    entry_ = "";
    setEntryText(entry_);
}

void IntBox::handleKeypad()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text(); // retrive the text from the button clicked
    entry_ = entry_ + buttonText.toStdString();
    setEntryText(entry_);
}

void IntBox::setEntryText(std::string message_)
{
    QString text = QString::fromStdString(message_);
    m_entry_label->setText(text);
}

void IntBox::setEntryText(QString message_)
{
    m_entry_label->setText(message_);
}