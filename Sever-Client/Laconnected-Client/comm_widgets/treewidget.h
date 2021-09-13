#ifndef TREEWIDGET_H
#define TREEWIDGET_H
#include <QTreeWidget>
#include "communication.h"
class Treewidget:public QObject
{
    Q_OBJECT
public:
    Treewidget(QWidget *,QRect);

    void init(int );

    void PartiallyCheck(QTreeWidgetItem *item);

    void add_new_friend(QTreeWidgetItem *item1,QString friend_name,QString udpname);

    void add_action();

    QTreeWidgetItem * create_friendlist();

    QTreeWidgetItem * create_grouplist();

    void show_save_friendlist(QString);

    void show_save_grouplist(QString,QString);

    void User_Online_Or_Disconnected_Msg(int);

    void Updata_Friend_State(QString friend_name,int state);
public slots:
    void treeCheck(QTreeWidgetItem *item, int column);

    void ItemMenu(const QPoint &pt);

    void OnItemDoubleClicked(QTreeWidgetItem *item);

    void OnMenuAdd();

    void OnMenuRemove();

    void recv_state_signal(QTreeWidgetItem *,bool);
signals:
    void tcpstart(QString);

    void udpstart(QString);
private:
    QWidget *widget;

    QTreeWidget *newTree;

    QRect _rect;

    QTreeWidgetItem *tcp_item1;

    QTreeWidgetItem *UDP_item1;
};

#endif // TREEWIDGET_H
