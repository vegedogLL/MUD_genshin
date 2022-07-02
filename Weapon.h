#ifndef _WEAPON_H_
#define _WEAPON_H_
#include <iostream>
#include <string>
using namespace std;

class Weapon{
private:
    string name; //名称
    int ATK; //攻击力
    int star; //稀有度
public:
    Weapon();
    Weapon(string _name, int _ATK, int _star):name(_name), ATK(_ATK), star(_star){}; //含参构造函数
    ~Weapon(); 
    string get_name() const; //返回武器名称
    int get_ATK(); //返回攻击力
    int get_star(){ return star; }// 返回稀有度
    void show(); //显示武器的信息
};

#endif