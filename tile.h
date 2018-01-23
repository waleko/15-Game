#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <QString>
#include <QGraphicsView>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>


class Tile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tile(int value, int i);
    void move(int direction); // 0 - up, 1 - right, 2 - down, 3 - left
    int i();
    void setI(int i);
public slots:
    void abit();
private:
    QPixmap getP(int value);
    int _i;
    int _dir;
    QTimer * tmr;
    int ops;

};

#endif // TILE_H
