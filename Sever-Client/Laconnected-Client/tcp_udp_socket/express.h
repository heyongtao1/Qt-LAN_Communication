#ifndef EXPRESS_H
#define EXPRESS_H


#include "tcpwid.h"
#include "groupwid.h"
#include <QTextDocument>
#include <QWidget>

#define PIC_MAX 11
namespace Ui {
class Express;
}
class Groupwid;
class Express : public QWidget
{
    Q_OBJECT

public:
    Express(Tcpwid *tcp,Groupwid *growid);
    ~Express();
    void initEmotion();
    void addEmotionItem(QString fileName,int,int);
public slots:
    void itempress_signal(int ,int );

private:
    Ui::Express *ui;

    Tcpwid *tcp;

    Groupwid *groupwid;

    QUrl url[PIC_MAX][PIC_MAX];
};

#endif // EXPRESS_H
