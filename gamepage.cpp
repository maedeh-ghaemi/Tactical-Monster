#include "gamepage.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QPen>
#include <QBrush>
#include <QtMath>
#include <QDebug>
#include <QPixmap>
#include <QLabel>

GamePage::GamePage(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mapSelector = new QComboBox(this);
    mapSelector->addItems({
        "grid1.txt", "grid2.txt", "grid3.txt", "grid4.txt",
        "grid5.txt", "grid6.txt", "grid7.txt", "grid8.txt"
    });
    mainLayout->addWidget(mapSelector);

    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    mainLayout->addWidget(view);

    setLayout(mainLayout);

    connect(mapSelector, &QComboBox::currentTextChanged, this, &GamePage::loadSelectedMap);
    connect(scene, &QGraphicsScene::selectionChanged, this, [this]() {
        auto items = scene->selectedItems();
        if (!items.isEmpty()) {
            QPointF clickPos = items.first()->boundingRect().center() + items.first()->pos();
            handleClick(clickPos);
            items.first()->setSelected(false);
        }
    });


}

void GamePage::loadSelectedMap(const QString &mapName) {
    scene->clear();
    cells.clear();
    agent1 = agent2 = nullptr;
    isPlayer1Turn = true;
    loadMap(":/new/prefix1/" + mapName);
}

//void GamePage::loadMap(const QString &path) {
    //QFile file(path);
    //if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
       // qDebug() << "cannot open thr file" << path;
        //return;
    //}

    //QTextStream in(&file);
    //int numhex;
    //int row = 1;
    //for (numhex=0;numhex<41;) {
        //QString line = in.readLine();
        //QStringList items = line.split(" ", Qt::SkipEmptyParts);
        //int col=0;
        //for (int i=0;i<line.length();i++) {
           // if (!line.isEmpty()) {
                //if(line[i]=='/'){
                    //createCell(row, col, line[i+1]);
                   // numhex++;
                    // col++;

               // }



           // }

     //}

       // ++row;
   // }
//}

void GamePage::loadMap(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file:" << path;
        return;
    }

    QTextStream in(&file);
    int row = 1;
    int haxnum=0;
    while (haxnum<41) {
        QString line = in.readLine();
        for (int col = 0; col + 1 < line.length(); col += 3) {
            QString cell = line.mid(col, 2);
            if (!cell.isEmpty() && line[col]=="/") {
                    createCell(row, col / 3, cell);
                    haxnum++;
            }
        }
        row++;
    }
    file.close();
}

void GamePage::createCell(int row, int col, const QString &type) {
    const int size = 30;
    const double w = size * 2;
    const double h = qSqrt(3) * size;

    double x = col * (0.75 * w);
    double y = (row) * h + (col % 2) * (h / 2);
    QPointF center(x, y);

    QPolygonF hex;
    for (int i = 0; i < 6; ++i) {
        double angle_deg = 60 * i + 30;
        double angle_rad = M_PI / 180 * angle_deg;
        hex << QPointF(center.x() + size * qCos(angle_rad), center.y() + size * qSin(angle_rad));
    }

    QBrush brush(Qt::white);
    if (type.contains("/#")) brush = Qt::green;
    else if (type.contains("/~")) brush = Qt::blue;

    auto *item = scene->addPolygon(hex, QPen(Qt::gray), brush);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setToolTip(type);

    cells.append({item, center, type, row, col});

    if (type.contains("1") && !agent1) {
        agent1 = scene->addEllipse(center.x()-10, center.y()-10, 20, 20, QPen(Qt::darkBlue), QBrush(Qt::blue));
    }
    if (type.contains("2") && !agent2) {
        agent2 = scene->addEllipse(center.x()-10, center.y()-10, 20, 20, QPen(Qt::darkRed), QBrush(Qt::red));
    }
}

void GamePage::handleClick(const QPointF &clickedPos) {
    for (const Cell &cell : cells) {
        if (QLineF(cell.center, clickedPos).length() < 30 && !cell.type.contains("#")) {
            if (isPlayer1Turn && agent1) {
                agent1->setRect(cell.center.x()-10, cell.center.y()-10, 20, 20);
                isPlayer1Turn = false;
            } else if (!isPlayer1Turn && agent2) {
                agent2->setRect(cell.center.x()-10, cell.center.y()-10, 20, 20);
                isPlayer1Turn = true;
            }
            break;
        }
    }
}
