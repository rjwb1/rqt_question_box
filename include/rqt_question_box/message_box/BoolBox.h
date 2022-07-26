#ifndef BOOL_BOX_H
#define BOOL_BOX_H

#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <rqt_question_box/message_box/MessageBox.h>

class QPushButton;

class BoolBox : public Window
{
    public:
        explicit BoolBox();
        ~BoolBox();
    private:
        void handleYesButton();
        void handleNoButton();
        QPushButton *m_yes_button;
        QPushButton *m_no_button;
};

#endif // BOOL_BOX_H