#ifndef OTHEROPERATIONS_H
#define OTHEROPERATIONS_H

#include <QWidget>

namespace Ui {
class OtherOperations;
}

class OtherOperations : public QWidget
{
    Q_OBJECT

public:
    explicit OtherOperations(QWidget *parent = 0);
    ~OtherOperations();

private slots:
    void on_exit_login_bt_clicked();
signals:
    void exit_login_signal();
private:
    Ui::OtherOperations *ui;
};

#endif
