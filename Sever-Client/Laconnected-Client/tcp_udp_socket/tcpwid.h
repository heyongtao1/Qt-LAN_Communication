#ifndef TCPWID_H
#define TCPWID_H
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QTableWidget>
#include <QUrl>
#include <QFile>
#include <QUdpSocket>
#include <QHostAddress>
#include <QTreeWidgetItem>

#include <QTextEdit>
#include <QWidget>
#include <QMovie>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStringlist>
namespace Ui {
class Tcpwid;

}
class Communication;
class Express;
class MyThread;
class Tcpwid : public QWidget
{
    Q_OBJECT

public:
    explicit Tcpwid(QString ,int);
    ~Tcpwid();
   void init();
   //获取主机信息
   void gethostifo();

   //获取子项的表情
   void getitem_expre(QUrl);
   //启动发送文件
   //void start_file();
   void addAnimation(const QUrl& url, const QString& fileName);
signals:
   void state_change(QTreeWidgetItem *,bool);
public slots:
   //void on_sendBt_clicked();
   //void on_closeBt_clicked();
   void on_expreBt_pressed();

   void Recv_Send_express_signals();
private slots:
   void on_GIFBt_pressed();
   void on_shotBt_pressed();
   void on_send_fileBt_clicked();
   //发送文件头
   void send_file_head();
   //发送文件内容
   void send_file_text();
   //加入组播成功信号
   //void join_udp_event();

    void subAnimate(int);
public:
    void on_m_editAnimated_clicked(QStringList express_path);
public:
    Ui::Tcpwid *ui;
private:
    //选中的好友
    QTreeWidgetItem *item;
    QTcpSocket *client_socket;
    QUdpSocket *udp_socket;
    MyThread *udp_thread;
    //表情按钮状态
    int expre_stat;
    //表情
    Express *exprewid;
    //将发送的表情
    QUrl express_url;
    //发送文件路径
    QString filepath;
    //发送的文件
    QFile file;
    //发送的文件内容
    QString filetext;
    //实时接收文件的大小
    int recvsize;
    //接收的文件名
    QString recv_filename;
    //接收的文件的大小
    QString recv_filesize;
    QString Friend_name;
    int Friend_ID;
public:
    QList<QString >Send_express_List;

    QList<QUrl> m_lstUrls;

    QHash<QMovie*, QUrl> m_hasUrls;

    int m_count =0;

    int m_curwidth;
};

#endif // TCPWID_H
