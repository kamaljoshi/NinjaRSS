#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
    private:
    int offSet[1000];
    int velocity[1000];
    int positionX[1000];
    int positionY[1000];
    int frame[1000];
    int frame_idle[1000];
    int status[1000];
    bool idle_cond[1000];
    public:
    Enemy(int n);
    int health[1000];
    bool alive[1000];
    int handle_events();
    void move(int i);
    void show();
    void fire();
};


class Enemy2
{
    private:
    int offSet[1000];
    int velocity[1000];
    int positionX[1000];
    int positionY[1000];
    int frame[1000];
    int frame_idle[1000];
    int status[1000];
    bool idle_cond[1000];
    public:
    Enemy2(int n);
    int health[1000];
    bool alive[1000];
    int handle_events();
    void move(int i);
    void show();
    void fire();
};

#endif

