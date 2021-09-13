/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "treewidget.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlQuery>
#include <mycpp.h>
#include "addwin.h"
#include "myinfo.h"
Treewidget::Treewidget(QWidget *_widget,QRect rect)
{
    widget = _widget;
    _rect = rect;
}
void Treewidget::init(int friend_or_group_widget)
{
        //初始化控件函数
        newTree = new QTreeWidget(widget);	//在当前的类里创建一个树控件
        newTree->headerItem()->setText(0,QString());	//设置表头为空
        newTree->setGeometry(_rect);	//设置起始坐标和大小
        QStringList hraders;
        if(USER_GROUP_WIDGET == friend_or_group_widget)
        hraders<<QStringLiteral("群组");
        else
        hraders<<QStringLiteral("联系人");
        newTree->setHeaderLabels(hraders);		//添加树表的表头

        connect(newTree,SIGNAL(itemClicked(QTreeWidgetItem *, int)),this,SLOT(treeCheck(QTreeWidgetItem *, int)));
        //注意：信号一定只声明变量类型，不要加变量名，是否会报错，找不到该信号
        //关联菜单栏
        newTree->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(newTree, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(ItemMenu(const QPoint&)));
        //双击编辑（重命名）--------未实现
        connect(newTree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*)), this, SLOT(OnItemDoubleClicked(QTreeWidgetItem *)));

        //关联好友状态改变信号
        //connect(tcpwid,SIGNAL(state_change(QTreeWidgetItem*,bool)),this,SLOT(recv_state_signal(QTreeWidgetItem*,bool)));

}
//创建好友列表
QTreeWidgetItem * Treewidget::create_friendlist()
{
    tcp_item1 = new QTreeWidgetItem(newTree);	//创建第一个父节点
    tcp_item1->setText(0,QStringLiteral("好友列表")+QString("                                                         ")+QString(QStringLiteral("[%1/%2]")).arg(Mycpp::FRIEND_ONLINE).arg(Mycpp::FRIEND_NUM));
    //tcp_item1->setCheckState(0,Qt::Unchecked);		//添加复选框，起始为未勾选

    //tcp_item1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
    //Qt::ItemIsSelectable表示可选的
    //Qt::ItemIsUserCheckable项目上是否有复选框
    //Qt::ItemIsEnabled 项目上是否没有被禁用（Enabled可用/Disabled禁用）
    return tcp_item1;
}
//创建讨论组/群聊列表
QTreeWidgetItem * Treewidget::create_grouplist()
{
    UDP_item1 = new QTreeWidgetItem(newTree);	//创建第二个父节点
    UDP_item1->setText(0,QStringLiteral("讨论组/群聊"));
    return UDP_item1;
}

//登陆后初始化显示已存在的好友列表
void Treewidget::show_save_friendlist(QString friend_name)
{
    add_new_friend(tcp_item1,friend_name,nullptr);
}
//登陆后初始化显示已存在的群聊列表
void Treewidget::show_save_grouplist(QString friend_name,QString group_name)
{
    add_new_friend(UDP_item1,friend_name,group_name);
}

void Treewidget::User_Online_Or_Disconnected_Msg(int online_or_num)
{
    qDebug()<<online_or_num;
    if(online_or_num == USER_ONLINE)
    {
        Mycpp::FRIEND_ONLINE++;
        tcp_item1->setText(0,QStringLiteral("好友列表")+QString("                                                         ")+QString(QStringLiteral("[%1/%2]")).arg(Mycpp::FRIEND_ONLINE).arg(Mycpp::FRIEND_NUM));
    }
    if(online_or_num == USER_DISCONNECTED)
    {
        Mycpp::FRIEND_ONLINE--;
        tcp_item1->setText(0,QStringLiteral("好友列表")+QString("                                                         ")+QString(QStringLiteral("[%1/%2]")).arg(Mycpp::FRIEND_ONLINE).arg(Mycpp::FRIEND_NUM));
    }
    if(online_or_num == USER_ADD_FRIEND_NUM)
    {
        Mycpp::FRIEND_NUM++;
        tcp_item1->setText(0,QStringLiteral("好友列表")+QString("                                                         ")+QString(QStringLiteral("[%1/%2]")).arg(Mycpp::FRIEND_ONLINE).arg(Mycpp::FRIEND_NUM));
    }
}

void Treewidget::Updata_Friend_State(QString friend_name,int state)
{
    for(int i=0;i<tcp_item1->childCount();i++)
    {
        if(QString::localeAwareCompare(friend_name,tcp_item1->child(i)->text(0)) == 0)
        {
            if(state == USER_DISCONNECTED)
            {
                tcp_item1->child(i)->setText(2,QString(QStringLiteral("离线")));
            }

            if(state == USER_ONLINE)
            {
                tcp_item1->child(i)->setText(2,QStringLiteral("在线"));
                qDebug()<<tcp_item1->child(i)->text(2);
            }

        }
    }
}

//双击可编辑
void Treewidget::OnItemDoubleClicked(QTreeWidgetItem *item)
{
    item->setFlags(item->flags() | Qt::ItemIsEditable);
}

//列表里右键菜单
void Treewidget::ItemMenu(const QPoint &pt)
{
    QTreeWidgetItem *selectedItem =newTree->itemAt(pt);
    QMenu menu;//菜单栏
    QAction *addact = new QAction(newTree);//创建添加行为
    addact->setText(QStringLiteral("添加好友/群聊"));
    menu.addAction(addact);
    if (selectedItem) {
        QAction *actionRemove = new QAction(newTree);
        actionRemove->setText(QStringLiteral("删除好友/群聊"));//创建删除行为
        menu.addAction(actionRemove);
        //将删除行为和槽函数关联
        connect(actionRemove, SIGNAL(triggered()), this, SLOT(OnMenuRemove()));
    }
    menu.exec(newTree->mapToGlobal(pt));

    //将添加行为和槽函数关联
    connect(addact, SIGNAL(triggered()), this, SLOT(OnMenuAdd()));
}

//点击添加行为
void Treewidget::OnMenuAdd()
{
#if 0
    qDebug()<<QStringLiteral("添加行为");
    //显示添加好友/讨论组界面进行操作
    Addwin *addwin = new Addwin();
    addwin->setParent(this_win);
    addwin->show();
#endif
}

//点击删除行为，在好友数据库/群聊数据库中一并删除
void Treewidget::OnMenuRemove()
{
    QTreeWidgetItem *item = newTree->currentItem();
    if (item)
    {
        //好友列表
        if(item->parent() == tcp_item1)
        {
            //将数据库的数据一并删除
            QSqlDatabase friend_db = QSqlDatabase::addDatabase("QSQLITE");
            friend_db.setDatabaseName("friend.db");

            if(!friend_db.open())
            {
                qDebug()<<"open sql error";
            }
            else {
                qDebug()<<"open ok";
            }
            //删除
            QString sql = QString("delete from friend where friend_name='%1'").arg(item->text(0));
            qDebug()<<sql;
            QSqlQuery query;
            if(!query.exec(sql))
            {
                qDebug()<<"delete error";
            }
            else
            {
                //删除成功
                qDebug()<<"删除好友成功";
            }
            delete item;
        }
        //讨论组/群聊列表
        if(item->parent() == UDP_item1)
        {
            //将数据库的数据一并删除
            QSqlDatabase udpgroup_db = QSqlDatabase::addDatabase("QSQLITE");
            udpgroup_db.setDatabaseName("udpgroup.db");

            if(!udpgroup_db.open())
            {
                qDebug()<<"open sql error";
            }
            else {
                qDebug()<<"open ok";
            }
            //删除
            QString sql = QString("delete from udpgroup where ip='%1'").arg(item->text(0));
            qDebug()<<sql;
            QSqlQuery query;
            if(!query.exec(sql))
            {
                qDebug()<<"delete error";
            }
            else
            {
                //删除成功
                qDebug()<<"删除好友成功";
            }
            delete item;
        }

    }
}
//接收改变状态信号，进行改变状态---------未实现
void Treewidget::recv_state_signal(QTreeWidgetItem *state_item,bool state_bool)
{
    if(state_bool)
    {
        state_item->setText(2,"在线");
    }
    else
        state_item->setText(2,"离线");
}


//树列表的鼠标点击信号
void Treewidget::treeCheck(QTreeWidgetItem *item, int column)
{
    if(Qt::Checked == item->checkState(0))		//若被选中
    {
        int count = item->childCount();			//得到选中的子节点个数
        if(count>0)								//若大于0，说明选中的是父节点，则将全部的子节点选中
        {
            for (int i = 0;i<count;i++) {
                //item->child(i)->setCheckState(0,Qt::Checked);
            }
        }
        else {								//否则选中的是子节点
            PartiallyCheck(item);			//将节点传到函数中进行其他操作
        }
    }
    else if(Qt::Unchecked == item->checkState(0)){	//没有被选中
        int count = item->childCount();
        if(count>0)
        {
            for (int i = 0;i<count;i++) {
                //item->child(i)->setCheckState(0,Qt::Unchecked);
            }
        }
        else {
            PartiallyCheck(item);
        }
    }

}
//鼠标选择哪个子项则进行操作
void Treewidget::PartiallyCheck(QTreeWidgetItem *item)
{
    qDebug()<<item->text(0);//鼠标位置的好友的账号/名字
    qDebug()<<item->text(1);//好友的状态
    if(item->parent() == tcp_item1)
    {
        //向主界面发射开始通信信号
        /*信号解释：当鼠标选择某个好友时，则发射信号转到聊天窗口*/
                emit tcpstart(item->text(0));
    }
    else
        emit udpstart(item ->text(0));
    //判断是否已经被选中过,选过则设置为禁用该项
    item->setFlags(Qt::ItemIsEnabled);
#if 0
    //得到节点的父节点，首先判断是否为空，为空说明是父节点，则直接退出，若不加判断会造成程序异常退出。
    QTreeWidgetItem *parent = item->parent();
    if(parent==nullptr)
        return;
    int selectedCount = 0;		//记录被选中的子节点个数
    int count = parent->childCount();		//记录子节点个数
    for (int i = 0;i<count ;i++) {			//父节点下的所有子节点，记录选中的子节点个数
        if(parent->child(i)->checkState(0)==Qt::Checked)
            selectedCount++;
    }
    if(selectedCount<=0)					//等于0说明没有子节点被选中，则将父节点取消选中
        parent->setCheckState(0,Qt::Unchecked);
    else if(selectedCount>0&&selectedCount<count)	//若大于0且小于总的子节点数，说明选中了一部分，则将父节点设置为半选中
        parent->setCheckState(0,Qt::PartiallyChecked);
    else {
        //否则，全选中
        parent->setCheckState(0,Qt::Checked);
    }
#endif
}
/**@添加新好友到好友列表
 * 头像和呢称
 * 状态布局
 * */
void Treewidget::add_new_friend(QTreeWidgetItem *item1,QString friend_name,QString udpname)
{
    QTreeWidgetItem *item1_1 = new QTreeWidgetItem(item1);		//添加子节点
    //设置好友的默认状态：离线
    QString friend_state = "0";//0->离线 1->在线

    //item1_1->setCheckState(0,Qt::Unchecked);
    //item1_1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
    item1_1->setSizeHint(0,QSize(350,60));//设置好友在好友列表显示的大小
    /*保存好友的信息，设置文本模式*/

    if(item1 == tcp_item1)
    {
        item1_1->setText(0,friend_name);
        //将布尔类型的状态强转为QString
        item1_1->setText(2,friend_state);
    }
    else if(item1 == UDP_item1)
    {
        item1_1->setText(0,udpname);
    }


    QVBoxLayout *VB = new QVBoxLayout;//垂直布局

    QLabel *text_friend_name = new QLabel;
    QLabel *text_state_or_name = new QLabel;

    text_friend_name->setFixedSize(QSize(260,20));
    text_state_or_name->setFixedSize(QSize(260,20));

    text_friend_name->setMinimumSize(QSize(260,20));
    text_state_or_name->setMinimumSize(QSize(260,20));

    text_friend_name->setText(friend_name);
    //当好友列表时，显示呢称、在线离线状态
    if(item1 == tcp_item1)
    {
        text_friend_name->setText(friend_name);
        text_state_or_name->setText(QString(QStringLiteral("用户当前状态：")) +QString( QStringLiteral("离线")));

    }
    //当讨论组/群聊时，没有状态显示，显示呢称、讨论组/群聊公告显示
    if(item1 == UDP_item1)
    {
        text_friend_name->setText(udpname);
        text_state_or_name->setText(QString(QStringLiteral("公告：我的群,我做主...")));
    }
    VB->addWidget(text_friend_name);
    VB->addWidget(text_state_or_name);

    QLabel *text3 = new QLabel;
    text3->setFixedSize(QSize(260,50));
    text3->setMinimumSize(QSize(260,50));
    text3->setLayout(VB);

    //头像
    QLabel *head = new QLabel();
    head->setFixedSize(QSize(40,40));
    head->setPixmap(QPixmap(":/resource/0.bmp"));
    head->setMinimumSize(QSize(40,40));

    QHBoxLayout *ph = new QHBoxLayout();
    ph->addWidget(head);
    ph->addWidget(text3);

    QLabel *text4 = new QLabel;
    text4->setFixedSize(QSize(350,60));
    text4->setLayout(ph);
    text4->move(QPoint(0,0));
    //布局的重点，在子项中添加所需要显示的控件
    newTree->setItemWidget(item1_1,0,text4);//在子项里添加控件，0代表为在item1_1的第1列
    //主界面刷新
    widget->update();

}

void Treewidget::add_action()
{
}
