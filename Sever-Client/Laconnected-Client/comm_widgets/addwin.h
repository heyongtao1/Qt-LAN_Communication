#ifndef ADDWIN_H
#define ADDWIN_H

#include <QSqlDatabase>
#include <QWidget>
namespace Ui {
class Addwin;
}
class Communication;

class Addwin : public QWidget
{
    Q_OBJECT

public:
    explicit Addwin();
    ~Addwin();
signals:

private slots:
    void add_friend_database();
    void add_group_database();
public:
    Ui::Addwin *ui;
private:
    QSqlDatabase friend_db;
    QSqlDatabase group_db;
    int friend_id;
};

#endif // ADDWIN_H
