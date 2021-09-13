#include <QWidget>
#include <QString>
#include <QDateTime>
#include <QSize>

typedef enum {
    SHOW_TYPE_MIN=1,
    SHOW_TYPE_LEFT,//窗口从左到右显示
    SHOW_TYPE_RIGHT,//窗口从右到左显示
    SHOW_TYPE_TIME //时间显示
}show_type_enum;

class UserChatContentInterface:public QWidget
{
public:
    UserChatContentInterface(QWidget *parent = 0):QWidget(parent){}

    virtual QString getname()=0;//插件类型名称
    virtual qint32 getverison()=0;//插件版本号

    virtual qint32 getwindowHeight()=0;//返回窗口的实际合适高度
    virtual QString getuserIconName()=0;//返回用户的图像名称
    virtual QString getuserChatContent()=0;//返回用户聊天内容
    virtual QDateTime gettalkTime()=0;//返回聊天时间

    virtual void setuserIconName(QString namestr)=0;//设置用户的图像名称
    virtual void setuserChatContent(QString usertext)=0;//设置用户聊天内容
    virtual void settalkTime(QDateTime talktime)=0;//设置聊天时间
    virtual void run(show_type_enum type)=0;//开始运行，需要绘制，即开始绘制
};
