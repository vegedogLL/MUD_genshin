#ifndef _FIGHT_H
#define _FIGHT_H
#include "Character.h"
#include "Role.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define MAXROUND 4

const void show(Player P, Enemy E);
int fight(Player &P, Enemy E, Role &R);

//这个类帮助处理战斗中的情况
class Processer{
private:
    map<int, int> rounds;//保存特殊技能效果持续回合
    float rate;
    int freeze;//是否发生冻结反应
    Skill skill;//本回合使用的技能
    int whose;//玩家还是敌人的回合
    int damage;//特殊技能效果的伤害
public:
    Processer(){ damage = 0; }
    ~Processer(){}
    float get_rate(){ return rate; }
    int get_freeze(){ return freeze; }
    void set_skill(Skill _skill){ skill = _skill; }
    void set_whose(int _whose){ whose = _whose; }
    void set_rate(float _rate){ rate = _rate; }
    int get_damage(){ return damage; }
    void process(Player &P, Enemy &E);//处理战斗
    void reaction(int type);
};

#endif