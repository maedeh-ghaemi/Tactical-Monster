#include "tacticalmonster.h"
#include "./ui_tacticalmonster.h"
#include <QMovie>
#include <QPixmap>
#include <QLabel>
#include "player.h"
#include "GamePage.h"
#include <QMessageBox>
#include <QPalette>
#include <QGraphicsView>
#include <QGraphicsScene>
TacticalMonster::TacticalMonster(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TacticalMonster)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->startpage);  //namayeshh page1
    QMovie *movie=new QMovie(":/new/prefix1/animation.gif");
    ui->backgerandLabel->setMovie(movie);
    ui->backgerandLabel->setScaledContents(true);
    movie->start();

    QLabel *welcomLabel=new QLabel;
    QFont Font("Versatylo Rounded",33);
    ui->welcomeLabel->setFont(Font);

    QLabel *nameLabel=new QLabel;
    QFont font("Shabina",45);
    ui->nameLabel->setFont(font);
    ui->nameLabel->setStyleSheet("color:blue");

    connect(ui->startbutton,&QPushButton::clicked,this,&TacticalMonster::showNextPage);


    QLabel *label=new QLabel;
    QPixmap pixmap(":/new/prefix1/page2Background.jpg");
    QPixmap scaledPixmap=pixmap.scaled(861,741);
    ui->label->setPixmap(scaledPixmap);
    ui->label->resize(scaledPixmap.size());
    ui->label->lower();
    ui->label->show();

    QLabel *nameLabel_2=new QLabel;
    QFont font1("Rollete Qaku",30);
    ui->nameLabel_2->setFont(font1);

    QLabel *markLabel=new QLabel;
    QPixmap Pixmap(":/new/prefix1/markGame2.jpg");
    QPixmap scaledpixmap=Pixmap.scaled(70,70);
    ui->markLabel->setPixmap(scaledpixmap);
    ui->markLabel->resize(scaledpixmap.size());
    ui->markLabel->show();

    QLabel *label_2=new QLabel;
    QPixmap Pixmap2(":/new/prefix1/Background3.jpg");
    QPixmap scaledPixmap2=Pixmap2.scaled(861,741);
    ui->label_2->setPixmap(scaledPixmap2);
    ui->label_2->resize(scaledPixmap2.size());
    ui->label_2->lower();
    ui->label_2->show();

    QLabel *markLabel2=new QLabel;
    QPixmap Pixmap3(":/new/prefix1/markGame2.jpg");
    QPixmap scaledpixmap3=Pixmap3.scaled(70,70);
    ui->markLabel2->setPixmap(scaledpixmap3);
    ui->markLabel2->resize(scaledpixmap3.size());
    ui->markLabel2->show();

    QLabel *nameGame=new QLabel;
    QFont font2("Rollete Qaku",30);
    ui->nameGame->setFont(font2);

    QLabel *label_3=new QLabel;
    QFont Font1("Versatylo Rounded",17);
    ui->label_3->setFont(Font1);

    QLabel *label_4=new QLabel;
    QFont Font2("Versatylo Rounded",17);
    ui->label_4->setFont(Font2);

    QLabel *label_7=new QLabel;
    QPixmap Pixmap4(":/new/prefix1/page2Background.jpg");
    QPixmap scaledPixmap4=Pixmap4.scaled(861,741);
    ui->label_7->setPixmap(scaledPixmap4);
    ui->label_7->resize(scaledPixmap4.size());
    ui->label_7->lower();
    ui->label_7->show();

    QLabel *label_9=new QLabel;
    ui->label_9->setPixmap(scaledPixmap4);
    ui->label_9->resize(scaledPixmap4.size());
    ui->label_9->lower();
    ui->label_9->show();

    QLabel *label_10=new QLabel;
    ui->label_10->setPixmap(scaledPixmap4);
    ui->label_10->resize(scaledPixmap4.size());
    ui->label_10->lower();
    ui->label_10->show();

    QLabel *label_11=new QLabel;
    ui->label_11->setPixmap(scaledPixmap4);
    ui->label_11->resize(scaledPixmap4.size());
    ui->label_11->lower();
    ui->label_11->show();



}

TacticalMonster::~TacticalMonster()
{
    delete ui;
}

void TacticalMonster::showNextPage(){
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void TacticalMonster::on_Gallery_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page3);
}


void TacticalMonster::on_startGame_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page4);
}


void TacticalMonster::on_back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->startpage);
}


void TacticalMonster::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}


void TacticalMonster::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void TacticalMonster::checkNamesFilled(){
    bool filled=! ui->lineEdit->text().isEmpty() && ! ui->lineEdit_2->text().isEmpty();
    ui->OKButton->setEnabled(filled);
}



void TacticalMonster::on_OKButton_clicked()
{
    QString name1 = ui->lineEdit->text();
    QString name2 = ui->lineEdit_2->text();

    if (name1.isEmpty() || name2.isEmpty()) {
        QMessageBox::warning(this, "warrning","please enter the player name!");
        return;
    }

    ui->stackedWidget->setCurrentWidget(ui->page);
    QLabel *label_12=new QLabel();
    QPixmap Pixmap4(":/new/prefix1/Background3.jpg");
    QPixmap scaledpixmap4=Pixmap4.scaled(900,800);
    ui->label_12->setPixmap(scaledpixmap4);
    ui->label_12->resize(scaledpixmap4.size());
    ui->label_12->lower();
    ui->label_12->show();
    QGraphicsView *graphicsView=new QGraphicsView();
    QGraphicsScene *scane=new QGraphicsScene();
    GamePage *game = new GamePage();
    game->setMinimumSize(421,660);
    QGraphicsProxyWidget *proxy=scane->addWidget(game);
    graphicsView->setScene(scane);
    setCentralWidget(graphicsView);
    //ui->stackedWidget->addWidget(game);
    //ui->stackedWidget->setCurrentWidget(game);



}


void TacticalMonster::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page4);
}


void TacticalMonster::on_pushButton_5_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox { messagebox-icon: none; }"); // غیرفعال کردن آیکون (و صدا)
    msgBox.setText("");
    msgBox.exec();
}


void TacticalMonster::on_pushButton_39_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page3);
}


void TacticalMonster::on_pushButton_29_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page3);
}


void TacticalMonster::on_pushButton_34_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page3);
}


void TacticalMonster::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}


void TacticalMonster::on_pushButton_9_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_4);
}


void TacticalMonster::on_pushButton_10_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_5);
}


void TacticalMonster::on_pushButton_4_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_6);
}


void TacticalMonster::on_pushButton_32_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page3);
}

