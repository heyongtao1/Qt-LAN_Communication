/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "chatcontentcircular.h"
#include <QPainter>
#include <QRect>
#include <QPen>
#include <QTextOption>
#include <QFont>
#include <QColor>
#include <QFontMetricsF>
#include <QDebug>
#include <QPainterPath>

ChatContentCirCular::ChatContentCirCular(QWidget *parent):UserChatContentInterface(parent)
{
    this->setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
    plug_name="circle frame chat content";  //设置插件信息
    plug_version=1.0;

    show_type=SHOW_TYPE_MIN;  //设置变量的初始值
    window_height=10;
    begin_width_spacing=20;
    begin_height_spacing=16;
    icon_width=40;
    icon_height=40;

    text_height_spacing=12;
    triangle_width=10;
    triangle_height=8;
    radius=20;

    text_color=QColor(255,255,255);
    time_color=QColor(153,153,153);

    QFont text_font = this->font();
    text_font.setFamily(QStringLiteral("新宋体"));
    text_font.setPointSize(10);
    this->setFont(text_font);
}

ChatContentCirCular::~ChatContentCirCular()
{

}

QString ChatContentCirCular::getname()
{
    return this->plug_name;
}

qint32 ChatContentCirCular::getverison()
{
    return this->plug_version;
}

qint32 ChatContentCirCular::getwindowHeight()
{
    return this->window_height;
}

QString ChatContentCirCular::getuserIconName()
{
    return this->user_icon_name;
}

QString ChatContentCirCular::getuserChatContent()
{
    return this->user_chat_content;
}

QDateTime ChatContentCirCular::gettalkTime()
{
    return this->talk_time;
}

void ChatContentCirCular::setuserIconName(QString namestr)
{
    this->user_icon_name=namestr;
}

void ChatContentCirCular::setuserChatContent(QString usertext)
{
    this->user_chat_content=usertext;
    this->calc_text_size();
}

void ChatContentCirCular::settalkTime(QDateTime talktime)
{
    this->talk_time=talktime;
}

void ChatContentCirCular::settext_width(qint32 currtext_width)
{

}

void ChatContentCirCular::run(show_type_enum type)
{
    show_type=type;
    this->update();
}

void ChatContentCirCular::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);//消锯齿
    painter.setFont(this->font());

    if(this->show_type==SHOW_TYPE_LEFT)//左边的图像和内容显示
    {
        //画图像
        text_color=QColor(255,255,255);
        this->calc_text_size();
        QRect icon_rect=QRect(begin_width_spacing,begin_height_spacing,icon_width,icon_height);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(Qt::gray));
        painter.drawPixmap(icon_rect,QPixmap(user_icon_name));

        //画框架
        QPainterPath bubble_path;
        bubble_path.moveTo(begin_width_spacing+icon_width+triangle_width+radius,begin_height_spacing);

        bubble_path.arcTo(begin_width_spacing+icon_width+triangle_width, begin_height_spacing, radius*2, radius*2, 90.0f, 90.0f);

        bubble_path.lineTo(begin_width_spacing+icon_width+triangle_width,begin_height_spacing+text_height_spacing+text_height+text_height_spacing-triangle_height);

        bubble_path.lineTo(begin_width_spacing+icon_width,begin_height_spacing+text_height_spacing+text_height+text_height_spacing+2);

        bubble_path.lineTo(begin_width_spacing+icon_width+triangle_width,begin_height_spacing+text_height_spacing+text_height+text_height_spacing);

        bubble_path.lineTo(begin_width_spacing+icon_width+triangle_width+radius+text_max_width,begin_height_spacing+text_height_spacing+text_height+text_height_spacing);

        bubble_path.arcTo(begin_width_spacing+icon_width+triangle_width+radius+text_max_width - radius, begin_height_spacing+text_height_spacing+text_height+text_height_spacing - radius*2, radius*2, radius*2, 270.0f, 90.0f);

        bubble_path.lineTo(begin_width_spacing+icon_width+triangle_width+radius+text_max_width+radius,begin_height_spacing+radius);

        bubble_path.arcTo(begin_width_spacing+icon_width+triangle_width+radius+text_max_width - radius, begin_height_spacing, radius*2, radius*2, 0.0f, 90.0f);

        bubble_path.lineTo(begin_width_spacing+icon_width+triangle_width+radius,begin_height_spacing);
        QPen pen(QColor(255,255,255));
        pen.setWidth(2);
        painter.setPen(pen);
        painter.setBrush(QBrush(QColor(0,0,0)));
        painter.drawPath(bubble_path);

        painter.setPen(QColor(255,255,255));
        painter.setBrush(QBrush(QColor(255,255,255)));

        painter.drawChord(QRectF(begin_width_spacing+icon_width+triangle_width+radius/4,begin_height_spacing+radius/4,radius*2*3/4,radius*2*3/4), 140*16, 30*16);
        painter.drawChord(QRectF(begin_width_spacing+icon_width+triangle_width+radius/4,begin_height_spacing+radius/4,radius*2*3/4,radius*2*3/4), 100*16, 20*16);

        painter.drawChord(QRectF(begin_width_spacing+icon_width+triangle_width+radius+text_max_width-radius*3/4,begin_height_spacing+radius/4,radius*2*3/4,radius*2*3/4), 0*16, 30*16);
        painter.drawChord(QRectF(begin_width_spacing+icon_width+triangle_width+radius+text_max_width-radius*3/4,begin_height_spacing+radius/4,radius*2*3/4,radius*2*3/4), 50*16, 30*16);

        painter.drawChord(QRectF(begin_width_spacing+icon_width+triangle_width+radius+text_max_width-radius*3/4,begin_height_spacing+text_height_spacing+text_height+text_height_spacing-radius*7/4,radius*2*3/4,radius*2*3/4), 270*16, 30*16);
        painter.drawChord(QRectF(begin_width_spacing+icon_width+triangle_width+radius+text_max_width-radius*3/4,begin_height_spacing+text_height_spacing+text_height+text_height_spacing-radius*7/4,radius*2*3/4,radius*2*3/4), 320*16, 20*16);

        //画文字
        QPen penText;
        penText.setColor(text_color);
        painter.setPen(penText);
        QTextOption option(Qt::AlignLeft | Qt::AlignVCenter);
        option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
        painter.drawText(QRect(begin_width_spacing+icon_width+triangle_width+radius,begin_height_spacing+text_height_spacing,text_max_width,text_height), user_chat_content,option);
    }
    else if(this->show_type==SHOW_TYPE_RIGHT)//右边的图像和内容显示
    {
        //画图像
        text_color=QColor(202,202,202);
        int window_current_width=this->width();
        this->calc_text_size();
        QRect icon_rect=QRect(window_current_width-begin_width_spacing-icon_width,begin_height_spacing,icon_width,icon_height);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(Qt::gray));
        painter.drawPixmap(icon_rect,QPixmap(user_icon_name));

        //画框架
        QPainterPath bubble_path;
        bubble_path.moveTo(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius),begin_height_spacing);

        bubble_path.arcTo(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+radius), begin_height_spacing, radius*2, radius*2, 90.0f, -90.0f);

        bubble_path.lineTo(window_current_width-(begin_width_spacing+icon_width+triangle_width),begin_height_spacing+text_height_spacing+text_height+text_height_spacing-triangle_height);

        bubble_path.lineTo(window_current_width-(begin_width_spacing+icon_width),begin_height_spacing+text_height_spacing+text_height+text_height_spacing+2);

        bubble_path.lineTo(window_current_width-(begin_width_spacing+icon_width+triangle_width),begin_height_spacing+text_height_spacing+text_height+text_height_spacing);

        bubble_path.lineTo(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+text_max_width),begin_height_spacing+text_height_spacing+text_height+text_height_spacing);

        bubble_path.arcTo(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+text_max_width+radius), begin_height_spacing+text_height_spacing+text_height+text_height_spacing - radius*2, radius*2, radius*2, 270.0f, -90.0f);

        bubble_path.lineTo(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+text_max_width+radius),begin_height_spacing+radius);

        bubble_path.arcTo(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+text_max_width+radius), begin_height_spacing, radius*2, radius*2,180.0f, -90.0f);

        bubble_path.lineTo(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius),begin_height_spacing);
        QPen pen(QColor(255,255,255));
        pen.setWidth(2);
        painter.setPen(pen);
        painter.setBrush(QBrush(QColor(0,0,0)));
        painter.drawPath(bubble_path);

        painter.setPen(QColor(255,255,255));

        painter.drawChord(QRectF(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius*7/4),begin_height_spacing+radius/4,radius*2*3/4,radius*2*3/4), 90*16, -30*16);
        painter.drawChord(QRectF(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius*7/4),begin_height_spacing+radius/4,radius*2*3/4,radius*2*3/4), 40*16, -20*16);

        painter.drawChord(QRectF(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+text_max_width+radius*3/4),begin_height_spacing+text_height_spacing+text_height+text_height_spacing-radius*7/4,radius*2*3/4,radius*2*3/4), 270*16, -30*16);
        painter.drawChord(QRectF(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+text_max_width+radius*3/4),begin_height_spacing+text_height_spacing+text_height+text_height_spacing-radius*7/4,radius*2*3/4,radius*2*3/4), 220*16, -30*16);

        painter.drawChord(QRectF(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+text_max_width+radius*3/4),begin_height_spacing+radius/4,radius*2*3/4,radius*2*3/4), 180*16, -30*16);
        painter.drawChord(QRectF(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+text_max_width+radius*3/4),begin_height_spacing+radius/4,radius*2*3/4,radius*2*3/4), 120*16, -20*16);


        //画文字
        QPen penText;
        penText.setColor(text_color);
        painter.setPen(penText);
        QTextOption option(Qt::AlignLeft | Qt::AlignVCenter);
        option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
        painter.drawText(QRect(window_current_width-(begin_width_spacing+icon_width+triangle_width+radius+text_max_width),begin_height_spacing+text_height_spacing,text_max_width,text_height), user_chat_content,option);

    }
    else if(this->show_type==SHOW_TYPE_TIME)//时间显示
    {
        QPen time_pen;
        time_pen.setColor(time_color);
        painter.setPen(time_pen);

        QTextOption time_option(Qt::AlignCenter);
        time_option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);

        QFont time_font = painter.font();
        time_font.setFamily("MicrosoftYaHei");
        time_font.setPointSize(9);
        painter.setFont(time_font);

        painter.drawText(this->rect(),talk_time.toString("yyyy-MM-dd HH:mm:ss"),time_option);
    }
}

void ChatContentCirCular::calc_text_size()
{
    QFontMetrics metrics = QFontMetrics(this->font());

    text_min_width=metrics.width("A")*2;

    qint32 min_width=begin_width_spacing+icon_width+triangle_width+radius+icon_width+begin_width_spacing;

    if(this->width()<min_width+text_min_width)//最小显示即一行只显示一个汉字
    {
        this->setMinimumWidth(min_width+text_min_width);
    }

    text_max_width=this->width()-min_width;//框架的最大文字宽度

    qint32 real_width=metrics.width(this->user_chat_content);

    if(real_width<text_max_width)
    {
        text_max_width=real_width;
        text_height=text_height_spacing+metrics.height()+text_height_spacing>radius*2? metrics.height(): radius*2-text_height_spacing-text_height_spacing ;
    }
    else
    {
        QRect textRect=QRect(0,0,text_max_width,0);
        int flags = Qt::TextWordWrap; // 自动换行
        textRect=metrics.boundingRect(textRect, flags, user_chat_content);
        text_height=text_height_spacing+textRect.height()+text_height_spacing>radius*2? textRect.height(): radius*2-text_height_spacing-text_height_spacing ;
    }

    window_height=text_height_spacing+text_height+text_height_spacing>icon_height? text_height_spacing+text_height+text_height_spacing: icon_height;
    window_height=begin_height_spacing+window_height+begin_height_spacing;
}
