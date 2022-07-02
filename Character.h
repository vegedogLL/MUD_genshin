#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Weapon.h"
using namespace std;

class Skill{
private:
    string name;//技能名称
    int cost;//技能花费
    float rate;//技能倍率
    string element;//元素属性
    int type;//技能类型,用于识别特殊技能
    string description;//特殊技能的描述
    int rank;//方便类对象在map容器中排序
public:
    Skill();
    Skill(string name, int cost, float rate, string element, int type, string description, int rank);
    ~Skill();
    string get_name() const;
    int get_cost() const;
    float get_rate() const;
    string get_element() const;
    int get_type() const;
    string get_description() const;
    void set_rate(float _rate){ rate = _rate; }
    void set_element(string _element){ element = _element; }
    int get_rank(){ return rank; }
    bool operator<(const Skill &that) const;//重载<号使得能存放在map容器中
};

class Character{
protected:
    string name; //名称
    int level; //等级
    int ATK; //攻击力
    int HP;
    int HP_upperbound;
    string state; //元素附着
public:
    Character();
    Character(string _name, int _level, int _ATK, int _HP_upperbound, string _state);
    ~Character();
    // 返回相关信息
    string get_name() const;
    int get_level() const;
    int get_ATK() const;
    int get_HP() const;
    string get_state() const;
    void add_HP(int add_num); //增加HP
    int sub_HP(int sub_num); //减少HP
    void set_HP(int hp);
    void set_ATK(int value); //设置攻击力
    void set_state(string state); //设置元素附着状态
    virtual void show() = 0; //纯虚函数show()显示相关信息
    int get_HP_upperbound() const; //返回HP上限
    float reaction(const string element, int &type);//元素反应
};

//公有继承Character类
class Enemy :public Character{
friend class Processer;
public:
    Enemy();
    Enemy(string _name, int _level, int _ATK, int _HP_upperbound, string _state, vector<Skill> _skill);
    ~Enemy();
    int drop_EXP() const; //返回掉落的EXP
    void show(); //显示相关信息
    void set_condition(int event);
    int get_condition();
    vector<Skill> get_skill();
    float reaction(const string element, int &type);//元素反应
private:
    int condition;
    vector<Skill> skill;//敌人拥有的技能
};

//公有继承Character类
class Player :public Character{
friend class Processer;//设置友元类方便战斗时修改角色相关数值
private:
    Weapon weapon; //持有的武器
    map<Skill, int> skill; //技能 <技能, 能否使用>
    int BP;
    int EXP;
    int BP_upperbound; //BP上限
    int EXP_upperbound; //EXP上限
public:
    Player();
    //含参构造函数
    Player(string _name, int _level, int _ATK, int _HP_upperbound, string _state, Weapon _weapon, 
    int _BP_upperbound, int _EXP_upperbound, vector<Skill> _skill);
    ~Player();
    //返回各类信息
    Weapon get_weapon() const;
    int get_BP() const;
    int get_EXP() const;
    int get_BP_upperbound() const;
    int get_EXP_upperbound() const;
    //升级
    void level_up();
    //增加或减少各类属性
    void add_BP(int add_num);
    int sub_BP(int sub_num);
    void add_EXP(int add_num);
    //显示各类信息
    void show();
    //更改持有的武器
    void change_weapon(Weapon W);
    vector<Skill> get_skill(); //获取技能
};

#endif