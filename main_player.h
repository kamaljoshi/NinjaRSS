#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

class Player
{
    private:
    int offSet;
    int velocity;
    int frame;
    int frame_idle;
    int status;
    bool idle_cond;
    public:
    Player();
    int health;
    void handle_events();
    void move(int health_t1,int health_t2);
    void show();
    void fire();
};

#endif
