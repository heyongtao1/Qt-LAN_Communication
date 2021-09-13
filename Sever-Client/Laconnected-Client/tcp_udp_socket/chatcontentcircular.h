
#include "userchatcontentinterface.h"

#include <QWidget>
#include <QPaintEvent>
#include <QColor>
#include <QString>
#include <QDateTime>
class ChatContentCirCular:public UserChatContentInterface
{
     Q_OBJECT
public:
    explicit ChatContentCirCular(QWidget *parent = 0);
    ~ChatContentCirCular();

    QString getname();//插件类型名称
    qint32 getverison();//插件版本号

    qint32 getwindowHeight();
    QString getuserIconName();//返回登录用户的图像名称
    QString getuserChatContent();//返回登录用户聊天内容
    QDateTime gettalkTime();//返回聊天时间

    void setuserIconName(QString namestr);//设置登录用户的图像名称
    void setuserChatContent(QString usertext);//设置登录用户聊天内容
    void settalkTime(QDateTime talktime);//设置聊天时间
    void settext_width(qint32 currtext_width);
    void run(show_type_enum type);//开始运行，需要绘制，即开始绘制
protected:

    void paintEvent(QPaintEvent *event); //重写QWidget的重绘时间
    void calc_text_size(); //计算文字的实际高度

signals:

public slots:

private:
    QString plug_name;  //插件名称
    qint32  plug_version;//插件版本号

    QString user_icon_name;//用户图像地址
    QString user_chat_content;//用户聊天内容
    QDateTime talk_time;//用户聊天时间

    show_type_enum show_type; //显示类型

    qint32 window_height;//实际的窗口高度

    qint32 text_max_width; //文字的最大宽度
    qint32 text_min_width;//文字的最小宽度
    qint32 text_height;//文字的实际高度

    qint32 begin_width_spacing;//起始点距边框的宽度
    qint32 begin_height_spacing;//起始点距边框的高度
    qint32 icon_width;//图像宽度
    qint32 icon_height;//图像高度

    qint32 text_height_spacing;//文字距矩形气泡边框的高度
    qint32 triangle_width;//横向三角形的宽度
    qint32 triangle_height;//横向三角形的高度
    qint32 radius; //圆角的半径


    QColor framework_border_color;//气泡样式的边框颜色
    QColor framework_background_color;//气泡样式的背景颜色
    QColor text_color;//文字颜色
    QColor time_color;//时间颜色
};
