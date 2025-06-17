#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player{
public:
    QString username;

    Player()=default;
    Player(const QString &name){
        username=name;
    }
};

#endif // PLAYER_H
