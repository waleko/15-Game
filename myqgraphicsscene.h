#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <QString>
#include <QGraphicsView>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QTime>
#include <tile.h>

class myQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    myQGraphicsScene();
    void updateGrid(QVector <int> grid);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void won();
private:
    QVector <int> _grid;
    QVector <Tile*> _g;
    void me(int i, int dir);
    int h;
    QTime lastOp;
};

#endif // MYQGRAPHICSSCENE_H
