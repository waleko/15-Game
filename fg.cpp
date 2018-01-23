#include "fg.h"
#include "ui_fg.h"
#include <about.h>
#include <QTime>

FG::FG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FG)
{
    ui->setupUi(this);
    myscene = new myQGraphicsScene();
    gen();
////    debug
////    QVector <int> grid = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, 14, 15};
////    myscene->updateGrid(grid);
    ui->graph->setScene(myscene);
    connect(myscene, SIGNAL(won()), this, SLOT(victory()));
}

FG::~FG()
{
    delete ui;
}
void FG::victory()
{
    QMessageBox o;
    o.setText("Congratulations! You won!");
    o.exec();
    gen();
}
void FG::gen()
{
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
    QVector <int> grid;
    do
    {   grid = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        int sum = 0;
        for(int i = 0; i < 15; i++)
        {
            int pos = -1;
            do {
            pos = qrand() % 16;
            } while(grid[pos] != -1);
            sum += pos;
            grid[pos] = i;
        }
        grid[120 - sum] = 15;
    } while(NotSolvable(grid));
    myscene->updateGrid(grid);
}
bool FG::NotSolvable(QVector<int> grid)
{
    // Algorithm Based on Wikipidea page about this game
    int sum = 0;
    for(int i = 0; i < 16; i++)
    {
        if(grid[i] == 0) {
            sum += (int)(i / 4) + 1;
            continue;
        }
        int k = 0;
        for(int q = i + 1; q < 16; q++)
        {
            if(grid[i] > grid[q] && grid[q] != 0)
                k++;
        }
        sum += k;
    }
    if(sum % 2)
        return true;
    else
        return false;
}
void FG::on_actionAbout_triggered()
{
    About us;
    us.exec();
}

void FG::on_actionRestart_triggered()
{
    gen();
}
