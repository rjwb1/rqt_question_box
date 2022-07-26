#ifndef STRING_BOX_H
#define STRING_BOX_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <rqt_question_box/message_box/MessageBox.h>

class QPushButton;

class StringBox : public Window
{
    public:
        explicit StringBox();
        ~StringBox();
    private:
        void handleOkButton();
        QPushButton *m_button;
        QLineEdit *m_textbox;
};
#endif // STRING_BOX_H
