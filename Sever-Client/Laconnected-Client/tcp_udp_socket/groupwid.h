#ifndef GROUPWID_H
#define GROUPWID_H

#include "express.h"

#include <QWidget>

class Express;

namespace Ui {
class Groupwid;
}

class Groupwid : public QWidget
{
    Q_OBJECT

public:
    explicit Groupwid(QWidget *parent = 0);
    ~Groupwid();
    void getitem_expre(QUrl url);
public:
    Ui::Groupwid *ui;
public slots:
    void on_expreBt_2_clicked();

    void Recv_Send_Group_express_signals();

private:
    int expre_stat;
    Express *exprewid;
public:
    int m_curwidth;

    QList<QString >Send_express_List;
};

#endif // GROUPWID_H
