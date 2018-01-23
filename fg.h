#ifndef FG_H
#define FG_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <QString>
#include <QGraphicsView>
#include <QDebug>
#include <QMessageBox>

#include <myqgraphicsscene.h>


namespace Ui {
class FG;
}

class FG : public QMainWindow
{
    Q_OBJECT

public:
    explicit FG(QWidget *parent = 0);
    ~FG();
    void gen();
public slots:
    void victory();
private slots:
    void on_actionAbout_triggered();

    void on_actionRestart_triggered();

private:
    Ui::FG *ui;
    myQGraphicsScene * myscene;
    bool NotSolvable(QVector <int> grid);
};

#endif // FG_H
