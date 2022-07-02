#ifndef _ROLE_H_
#define _ROLE_H_
#include <iostream>
#include <fstream>
#include "Character.h"
#include "Weapon.h"
#include <time.h>
#include <windows.h>
using namespace std;

class Role{
//设置友元类方便修改各类信息
friend class Event;
friend class Game;
friend int fight(Player &P, Enemy E, Role &R);
friend void character_wishes(vector<Player> player, Role &R);
friend void weapon_wishes(vector<vector<Weapon>> weapon, Role &R);
private:
    vector<Player> players;//玩家所拥有的角色
    Player current_player;//玩家当前操控的角色
    vector<Weapon> weapons;//玩家所拥有的武器
    map<int, int> items;//玩家所拥有的道具
    int x;//人物x坐标
    int y;//人物y坐标
    int show_y;//人物显示的y坐标
public:
    //含参构造,仅在开始新游戏时使用
    Role(Player _player): current_player(_player) {
        players.push_back(_player);
        weapons.push_back(_player.get_weapon());
        for(int i = 0; i < 7; i++){
            if(i < 5){
                items[i] = 5;
            }
            else if(i == 5){
                items[i] = 10000;
            }
            else{
                items[i] = 160000;
            }
        }
    }
    Role(){}
    ~Role(){}
    int get_x();//返回人物x坐标
    int get_y();//返回人物y坐标
    int get_show_y();
    void set_x(int a);//设置人物x坐标
    void set_y(int a);//设置人物y坐标
    void set_show_y(int a);
    //显示,修改各类信息
    void show_players();
    vector<Weapon> show_weapons();
    void show_items();
    void change_current_player();
    void change_weapon();
    int add_players(Player player);
    int add_weapons(Weapon weapon);
    Player &get_current_player(){ return current_player; }
    //存档,保存游戏进度
    void save(vector<Player> player, vector<vector<Weapon>> weapon);
    //读取存档,恢复游戏进度
    int load(vector<Player> player, vector<vector<Weapon>> weapon);
};

void character_wishes(vector<Player> player, Role &R);
void weapon_wishes(vector<vector<Weapon>> weapon, Role &R);

#endif