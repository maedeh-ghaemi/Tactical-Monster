#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QComboBox>
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>
#include <QList>
#include <QPushButton>
#include <QPointF>
#include <QVector>

struct Cell {
    QGraphicsPolygonItem* item;
    QPointF center;
    QString type;
    int row;
    int col;

};        //هر خونه شش ضلعی

class GamePage : public QWidget {
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent = nullptr);

private slots:
    void loadSelectedMap(const QString &mapName);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QComboBox *mapSelector;
    QVector<Cell> cells;
    QGraphicsEllipseItem *agent1 = nullptr;
    QGraphicsEllipseItem *agent2 = nullptr;
    bool isPlayer1Turn = true;

    void loadMap(const QString &path);
    void createCell(int row, int col, const QString &type);
    void handleClick(const QPointF &clickedPos);
    //void move(QGraphicsEllipseItem *agent,const QPointF& destination);
};


#endif // GAMEPAGE_H
