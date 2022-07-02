#ifndef _GAME_H_
#define _GAME_H_
#include "map.h"
#include "Role.h"
#include "event.h"
#include <utility>
class Game{
    private:
    Event event;
    public:
    void run_game(World &world, Role &role);//运行游戏
    pair<int, int> run_map(World &world, Role &role, int index, int from = -1);//加载地图
    Game();
    ~Game();
};

void set_position(Role& role, int index, int from);
int get_next_map(int index, char ch);
#endif