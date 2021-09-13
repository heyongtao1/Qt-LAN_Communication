 #ifndef LOG_TABEL_H
#define LOG_TABEL_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonValue>
#include <myinfo.h>
#include "mycpp.h"
namespace Ui {
class Log_tabel;
}

class Log_tabel : public QWidget
{
    Q_OBJECT

public:
    explicit Log_tabel(QTcpSocket *);

    ~Log_tabel();

    void SendMsg_to_Server();

    //处理返回的注册信息，分配的ID
    void Deal_regMsg_SUCCESS(QJsonValue &);

    void Deal_regMsg_NO(QJsonValue &);
private slots:
    void on_logbt_clicked();

    void Deal_typeMsg();

    void Deal_typeMsg_Switch(int State_type,QJsonValue &);
signals:
    void Deal_typeMsg_Signals(int State_type,QJsonValue &);
private:
    Ui::Log_tabel *ui;

    QTcpSocket *write_socket;
};

#endif // LOG_TABEL_H
