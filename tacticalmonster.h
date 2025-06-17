#ifndef TACTICALMONSTER_H
#define TACTICALMONSTER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TacticalMonster;
}
QT_END_NAMESPACE

class TacticalMonster : public QMainWindow
{
    Q_OBJECT

public:
    TacticalMonster(QWidget *parent = nullptr);
    ~TacticalMonster();
     void checkNamesFilled();
public slots:
    void showNextPage();

private slots:
    void on_Gallery_clicked();

    void on_startGame_clicked();

    void on_back_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_OKButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_32_clicked();

private:
    Ui::TacticalMonster *ui;

};
#endif // TACTICALMONSTER_H
