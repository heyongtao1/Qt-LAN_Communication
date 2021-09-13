#ifndef LOGIN_H
#define LOGIN_H
#include <QSqlDatabase>
#include <QWidget>
#include <QTcpSocket>
#include "myinfo.h"
#include "mycpp.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

    ~Login();

    void login_init();//界面控件图标，样式表初始化

    void Sleep(int msec);

    void Connext_to_Server();

    bool isConnected_Server();

    void Timer_Check_Connected();//定时监测连接服务器

    void Deal_Server_BackLogMsg_Succsee(QJsonValue &);

    void Deal_Server_BackLogMsg_No();
private slots:
    void on_regBt_clicked();

    void on_logonBt_clicked();

    void on_re_password_clicked(bool checked);

    void on_auto_log_clicked(bool checked);

    void on_log_otherBt_activated(const QString &arg1);

    void on_yes_bt_clicked();

    void on_cancel_bt_clicked();

    void Server_Disconnect();

    void Deal_Server_BackLogMsg();

    void setAreaMovable(const QRect rt);//设置鼠标按下可移动窗口的区域，在子窗口中必须设置该区域

    void on_close_bt_clicked();

    void on_log_otherBt_activated(int index);

protected:
    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *);

    void mouseReleaseEvent(QMouseEvent *);

    void closeEvent( QCloseEvent * event );
private:
    Ui::Login *ui;

    QSqlDatabase db;

    //用户六种状态
    enum state{
        online,
        busy,
        leave,
        disturb,
        chat,
        offline,
    };

    //加密状态
    bool passaction;

    //配置服务器的参数保存
    QString server_ip;

    int server_port;

    QTcpSocket *m_socket;

    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口

    bool m_bPressed;//鼠标按下标志（不分左右键）

    QPoint m_ptPress;//鼠标按下的初始位置
};

#endif // LOGIN_H
