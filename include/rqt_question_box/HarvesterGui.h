#ifndef H_GUI_H
#define H_GUI_H

#include <QWidget>
#include <rqt_question_box/Data.h>

class QPushButton;
class Window : public QWidget
{
 Q_OBJECT
public:
 explicit Window(QWidget *parent = 0, std::string question_);
private slots:
 void slotButtonClicked(bool checked);
private:
 QPushButton *m_button;
};

#endif // H_GUI_H
