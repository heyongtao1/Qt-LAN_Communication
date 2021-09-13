#ifndef MYINFO_H
#define MYINFO_H

#include <stdint.h>
#include <QString>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

typedef enum{
    M_Lose_TextEdit_Width = 80,

    M_Lose_TextEdit_Higth = 50,

    M_Lose_Showtime_Higth = 10,

}E_ChatContentCirCular;

typedef enum {
   USER_FRIEND_WIDGET = 0,

   USER_GROUP_WIDGET ,

   USER_CHART_WIDGET ,

   USER_MEDIA_WIDGET ,
}E_WIDGET;

typedef enum{
   USER_REGIN  = 0x01,             //用户注册发送的个人信息

   USER_REGIN_SUCCESS,             //返回注册成功信息

   USER_REGIN_NO  ,                //返回注册失败信息

   USER_CHAR_MSG ,                 //用户发送聊天信息

   USER_LOGIN  = 0x05   ,          //用户登录信息

   USER_LOGIN_SUCCESS,             //返回登录成功信息

   USER_LOGIN_NO ,                 //返回登录失败信息

   USER_ADDFRIEND ,                //用户添加好友信息

   USER_ADDFRIEND_SUCCESS ,        //返回添加成功信息

   USER_ADDFRIEND_NO = 0x10,       //返回添加失败信息

   USER_ADDFRIEND_Widget ,         //添加好友的通知窗口

   USER_RECV_FRIEND_MSG,           //好友信息类型

   USER_ONLINE ,                   //用户上线信息

   USER_DISCONNECTED ,             //用户下线信息

   USER_ADD_FRIEND_NUM ,           //用户总人数增加

   USER_GET_FRIEND_STATE = 0x15 ,  //获取用户的状态

   USER_ADDGROUP ,                 //用户添加群聊信息

   USER_ADDGROUP_SUCCESS ,         //返回添加群聊成功信息

   USER_ADDGROUP_NO ,              //返回添加群聊失败信息

   USER_GROUP_MSG ,                //群聊信息类型

   USER_GROUP_ADD_NEWFRIEND = 0x20,//新成员加入群聊

   USER_EXPRESSION_MSG ,           //用户发送表情消息

}E_INFO;


#endif // MYINFO_H
