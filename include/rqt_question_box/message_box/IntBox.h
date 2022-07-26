#ifndef INT_BOX_H
#define INT_BOX_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <rqt_question_box/message_box/MessageBox.h>

class QPushButton;

class IntBox : public Window
{
    public:
        explicit IntBox();
        ~IntBox();
    private:
        void handleOkButton();
        void handleClearButton();
        void handleKeypad();
        void setEntryText(QString message_);
        void setEntryText(std::string message_);

        QPushButton *m_ok_button;
        QPushButton *m_clear_button;
        std::string entry_;
        QLabel *m_entry_label;

        // Keypad
        QPushButton *m_0_button;
        QPushButton *m_1_button;
        QPushButton *m_2_button;
        QPushButton *m_3_button;
        QPushButton *m_4_button;
        QPushButton *m_5_button;
        QPushButton *m_6_button;
        QPushButton *m_7_button;
        QPushButton *m_8_button;
        QPushButton *m_9_button;
};
#endif // INT_BOX_H
