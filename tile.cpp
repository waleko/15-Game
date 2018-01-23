#include "tile.h"
#include <QTimer>
Tile::Tile(int value, int i)
{
    this->setPixmap(getP(value));
    this->setPos(QPoint((i % 4) * 100 - 200, ((int) (i / 4)) * -100 + 200));
    _i = i;
    tmr = new QTimer();
    connect(tmr, SIGNAL(timeout()), this, SLOT(abit()));
    ops = 0;
}
// 0 - up, 1 - right, 2 - down, 3 - left


int Tile::i()
{
    return _i;
}

void Tile::setI(int i)
{
    this->setPos(QPoint((i % 4) * 100 - 200, ((int) (i / 4)) * 100 - 200));
    _i = i;
}
void Tile::move(int direction)
{
    _dir = direction;
    tmr->start(5);
}

void Tile::abit()
{
    if(ops >= 25)
    {
        ops = 0;
        tmr->stop();
        return;
    }
    switch(_dir)
    {
    case 0:
        this->moveBy(0, -4);
        break;
    case 1:
        this->moveBy(4, 0);
        break;
    case 2:
        this->moveBy(0, 4);
        break;
    case 3:
        this->moveBy(-4, 0);
        break;
    }
    ops++;
}

QPixmap Tile::getP(int value)
{
    QPixmap e;
    e.load(":/tiles/" + QString::number(value) + ".png");
    return e.scaled(100, 100);
}

