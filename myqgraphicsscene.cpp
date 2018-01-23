#include "myqgraphicsscene.h"

myQGraphicsScene::myQGraphicsScene()
{
    lastOp = QTime::currentTime();
    for(int i = 1; i < 16; i++)
    {
        Tile * t = new Tile(i, i - 1);
        this->addItem(t);
        _g.push_back(t);
    }
}

void myQGraphicsScene::updateGrid(QVector<int> grid)
{
    for(int i = 0; i < 16; i++)
    {
        if(grid[i] == 0)
            continue;
        _g[grid[i] - 1]->setI(i);
    }
    _grid = grid;
}
void myQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QTime curTime = QTime::currentTime();
    if((curTime.msecsSinceStartOfDay() - lastOp.msecsSinceStartOfDay()) % 86400000 < 100)
        return;
    lastOp = curTime;
    QGraphicsItem * pr = this->itemAt(event->scenePos(), QTransform());
    h = _grid.indexOf(0); // hole index
    for(int q = 0; q < 15; q++)
    {
        if(pr == _g[q])
        {
            int i = _grid.indexOf(q + 1);
            if(h % 4 == i % 4)
            {
                if(h > i)
                {

                    if(h / 4 - i / 4 > 2)
                        me(i + 8, 2);
                    if(h / 4 - i / 4 > 1)
                        me(i + 4, 2);
                    me(i, 2);
                }
                else
                {
                    if(i / 4 - h / 4 > 2)
                        me(i - 8, 0);
                    if(i / 4 - h / 4 > 1)
                        me(i - 4, 0);
                    me(i, 0);
                }
            }
            else if(h / 4 == i / 4)
            {
                if(h > i)
                {
                    if(h - i > 2)
                        me(i + 2, 1);
                    if(h - i > 1)
                        me(i + 1, 1);
                    me(i, 1);
                }
                else
                {
                    if(i - h > 2)
                        me(i - 2, 3);
                    if(i - h > 1)
                        me(i - 1, 3);
                    me(i, 3);
                }
            }
        }
    }
}

void myQGraphicsScene::me(int i, int dir)
{
    _g[_grid[i] - 1]->move(dir);
    switch(dir)
    {
    case 2:
        _grid[i + 4] = _grid[i];
        _grid[i] = 0;
        break;
    case 0:
        _grid[i - 4] = _grid[i];
        _grid[i] = 0;
        break;
    case 1:
        _grid[i + 1] = _grid[i];
        _grid[i] = 0;
        break;
    case 3:
        _grid[i - 1] = _grid[i];
        _grid[i] = 0;
        break;
    }
    QVector <int> standard = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    if(_grid == standard)
        emit won();
}
