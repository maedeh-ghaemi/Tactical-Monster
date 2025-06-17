#include "tacticalmonster.h"
#include "GamePage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TacticalMonster w;
    GamePage g;
    w.show();
    return a.exec();
}
