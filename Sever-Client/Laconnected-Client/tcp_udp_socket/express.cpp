/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "express.h"
#include "ui_express.h"

#include <QLabel>
#include <QMovie>
#include <QTextDocument>

Express::Express(Tcpwid *tcpwid,Groupwid *_groupwid) :
    ui(new Ui::Express)
{
    ui->setupUi(this);
    groupwid  = _groupwid;
    tcp = tcpwid;
#if 0
    express_path = ":/express/%1.gif";

    ui->qTableWidget->setColumnCount(5);//设置列数
    ui->qTableWidget->setRowCount(5);//设置行数
    ui->qTableWidget->setWindowTitle("QTableWidget");
    //ui->qTableWidget->setEnabled(false);//禁用编辑
    QStringList m_Header;
    m_Header<<QString(QStringLiteral("表情1"))<<QString(QStringLiteral("表情2"))<<QString(QStringLiteral("表情3"))<<QString(QStringLiteral("表情4"))<<QString(QStringLiteral("表情5"));
    ui->qTableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
    ui->qTableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
    ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化

    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);//设置表格选择方式：设置表格为单个选中
    //ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
    ui->qTableWidget->setStyleSheet("selection-background-color:pink");//设置选中颜色：粉色
    ui->qTableWidget->setIconSize(QSize(24,24));//设置图标的大小

    document=new QTextDocument(this);  //图片容器
    for(int rows=0;rows<11;rows++)
    {
        for(int columns=0;columns<11;columns++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setIcon(QIcon(QPixmap(express_path.arg(columns))));
            ui->qTableWidget->setItem(rows,columns,item);
            url[rows][columns] = QUrl::fromLocalFile(express_path.arg(columns));   //指定Url
            document->addResource(QTextDocument::ImageResource,url[rows][columns],QVariant(url[rows][columns]));  //添加资源到document容器中
        ui->qTableWidget->setColumnWidth(columns, 24);
        }
        ui->qTableWidget->setRowHeight(rows,24);
    }
#endif
    initEmotion();

    //点击表情触发槽函数,发送子项的行号和列号
    connect(ui->qTableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(itempress_signal(int,int)));
}
//添加表情
void Express::addEmotionItem(QString fileName,int row,int column)
{
    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem;

    // 因为表情大部分为gif图片格式，所以这里用QMovie来显示
    QLabel* emotionIcon = new QLabel;
    emotionIcon->setFixedSize(24,24);
    QMovie* movie = new QMovie;
    movie->setScaledSize(QSize(24, 24));

    movie->setFileName(fileName);
    emotionIcon->setMovie(movie);

    ui->qTableWidget->setCellWidget(row, column, emotionIcon);
    movie->start();
}
//初始化表情
void Express::initEmotion()
{
    qDebug()<<QString(QStringLiteral("初始化表情"));
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    ui->qTableWidget->setFocusPolicy(Qt::NoFocus);
    ui->qTableWidget->setColumnCount(11);//设置列数
    ui->qTableWidget->setRowCount(11);//设置行数
    ui->qTableWidget->verticalHeader()->setVisible(false);//纵向表头可视化
    ui->qTableWidget->horizontalHeader()->setVisible(false);//横向表头可视化
    int count = 0;
    QString path = ":/express/%1.gif";
    for (int Row = 0; Row < 11; Row++)
    {
        for(int Column=0;Column<11;Column++)
        {
            qDebug()<<QString(QStringLiteral("添加表情"));
            count++;
            addEmotionItem(path.arg(count),Row,Column);
            ui->qTableWidget->setColumnWidth(Column,24);
            url[Row][Column] = QUrl::fromLocalFile(path.arg(count));   //指定Url
        }
        ui->qTableWidget->setRowHeight(Row,24);
    }

}
Express::~Express()
{
    delete ui;
}

void Express::itempress_signal(int row, int col)
{
    qDebug()<<QString(QStringLiteral("子项表情"));
    if(tcp != nullptr)
    tcp->getitem_expre(url[row][col]);
    else
        groupwid->getitem_expre(url[row][col]);
}
