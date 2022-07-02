
#include "Character.h"

Character::Character(){

}

Character::Character(string _name, int _level, int _ATK, int _HP_upperbound, string _state)
: name(_name), level(_level), ATK(_ATK), HP_upperbound(_HP_upperbound), state(_state){
    HP = HP_upperbound;
}

Character::~Character(){

}

string Character::get_name() const{
    return name;
}

int Character::get_level() const{
    return level;
}

int Character::get_ATK() const{
    return ATK;
}

int Character::get_HP() const{
    return HP;
}

int Character::get_HP_upperbound() const{
    return HP_upperbound;
}

string Character::get_state() const{
    return state;
}

void Character::add_HP(int add_num){
    int upperbound = get_HP_upperbound();
    if(HP + add_num <= upperbound){
        HP += add_num;
    }
    else{
        HP = upperbound;
    }
}

int Character::sub_HP(int sub_num){
    if(HP <= sub_num){
        HP = 0;
        return 0;
    }
    else{
        HP -= sub_num;
        return 1;
    }
}
void Character::set_HP(int hp){
    HP = hp;
}
void Character::set_ATK(int value){
    ATK = value;
}

void Character::set_state(string state){
    //设置元素附着
    state = state;
}

float Character::reaction(const string element, int &type){
    float rate = 1;
    if(state == "无"){
        state = element;
        type = 0;
    }
    else if(state == "火"){
        if(element == "水"){
            state = "无";
            rate *= 2;
            type = 1;
        }
        else if(element == "冰"){
            state = "无";
            rate *= 1.5;
            type = 2;
        }
        else if(element == "雷"){
            state = "无";
            rate *= 1.5;
            type = 4;
        }
    }
    else if(state == "水"){
        if(element == "火"){
            state = "无";
            rate *= 1.5;
            type = 1;
        }
        else if(element == "冰"){
            state = "无";
            type = 3;
        }
        else if(element == "雷"){
            state = "无";
            rate *= 1.5;
            type = 5;
        }
    }
    else if(state == "冰"){
        if(element == "火"){
            state = "无";
            rate *= 2;
            type = 2;
        }
        else if(element == "水"){
            state = "无";
            type = 3;
        }
        else if(element == "雷"){
            state = "无";
            rate *= 1.5;
            type = 6;
        }
    }
    else if(state == "雷"){
        if(element == "火"){
            state = "无";
            rate *= 1.5;
            type = 4;
        }
        else if(element == "水"){
            state = "无";
            rate *= 1.5;
            type = 5;
        }
        else if(element == "冰"){
            state = "无";
            rate *= 1.5;
            type = 6;
        }
    }
    return rate;
}

//Enemy

Enemy::Enemy(){

}

Enemy::Enemy(string _name, int _level, int _ATK, int _HP_upperbound, string _state, vector<Skill> _skill)
: Character(_name, _level, _ATK, _HP_upperbound, _state), skill(_skill){
    if(name.find("史莱姆") != string::npos|| name == "无相之冰"){
        condition = 1;
    }
    else{
        condition = 0;
    }
}

int Enemy::drop_EXP() const{
    return level;
}

void Enemy::show(){
    cout << "--------敌人信息--------" << endl;
    cout << "名称：" << get_name() << endl;
    cout << "等级：" << get_level() << endl;
    cout << "攻击力：" << get_ATK() << endl;
    cout << "当前HP值：" << get_HP() << endl;
    cout << "身上的元素附着："  << get_state() << endl;
    cout << endl;
}

void Enemy::set_condition(int event){
    condition = event;
}

int Enemy::get_condition(){
    return condition;
}

Enemy::~Enemy(){

}

vector<Skill> Enemy::get_skill(){
    return skill;    
}

float Enemy::reaction(const string element, int &type){
    float rate = 1;
    if(state == "无"){
        state = element;
        type = 0;
    }
    else if(state == "火"){
        if(element == "水"){
            if(!condition){
                state = "无";
            }
            rate *= 2;
            type = 1;
        }
        else if(element == "冰"){
            if(!condition){
                state = "无";
            }
            rate *= 1.5;
            type = 2;
        }
        else if(element == "雷"){
            if(!condition){
                state = "无";
            }
            rate *= 1.5;
            type = 4;
        }
    }
    else if(state == "水"){
        if(element == "火"){
            if(!condition){
                state = "无";
            }
            rate *= 1.5;
            type = 1;
        }
        else if(element == "冰"){
            if(!condition){
                state = "无";
            }
            type = 3;
        }
        else if(element == "雷"){
            if(!condition){
                state = "无";
            }
            rate *= 1.5;
            type = 5;
        }
    }
    else if(state == "冰"){
        if(element == "火"){
            if(!condition){
                state = "无";
            }
            rate *= 2;
            type = 2;
        }
        else if(element == "水"){
            if(!condition){
                state = "无";
            }
            type = 3;
        }
        else if(element == "雷"){
            if(!condition){
                state = "无";
            }
            rate *= 1.5;
            type = 6;
        }
    }
    else if(state == "雷"){
        if(element == "火"){
            if(!condition){
                state = "无";
            }
            rate *= 1.5;
            type = 4;
        }
        else if(element == "水"){
            if(!condition){
                state = "无";
            }
            rate *= 1.5;
            type = 5;
        }
        else if(element == "冰"){
            if(!condition){
                state = "无";
            }
            rate *= 1.5;
            type = 6;
        }
    }
    return rate;
}

//Player

Player::Player(){

}

Player::Player(string _name, int _level, int _ATK, int _HP_upperbound, string _state, Weapon _weapon, 
int _BP_upperbound, int _EXP_upperbound, vector<Skill> _skill)
:Character(_name, _level, _ATK, _HP_upperbound, _state), 
weapon(_weapon), BP_upperbound(_BP_upperbound), EXP_upperbound(_EXP_upperbound){
    BP = 0;
    EXP = 0;
    ATK = ATK + weapon.get_ATK();
    int i = 0;
    for(vector<Skill>::iterator p = _skill.begin(); p != _skill.end(); p++){
        if(i < 3){
            skill[*p] = 1;
        }
        else{
            skill[*p] = 0;
        }
        i++;
    }
}

Player::~Player(){

}

Weapon Player::get_weapon() const{
    return weapon;
}

int Player::get_BP() const{
    return BP;
}

int Player::get_EXP() const{
    return EXP;
}

int Player::get_BP_upperbound() const{
    return BP_upperbound;
}

int Player::get_EXP_upperbound() const{
    return EXP_upperbound;
}

void Player::level_up(){
    level += 1;
    HP_upperbound += 50;
    ATK += 10;
    EXP_upperbound += 20;
    HP = HP_upperbound;
    cout << get_name() <<"升级了！" << endl;
    cout << endl;
}

void Player::add_BP(int add_num){
    int upperbound = get_BP_upperbound();
    if(BP + add_num <= upperbound){
        BP += add_num;
    }
    else{
        BP = upperbound;
    }
}

int Player::sub_BP(int sub_num){
    if(BP < sub_num){
        return 0;
    }
    else{
        BP -= sub_num;
        return 1;
    }
}

void Player::add_EXP(int add_num){
    cout << get_name() << "获得了" << add_num << "EXP!" << endl;
    cout << endl;
    EXP += add_num;
    while(EXP >= get_EXP_upperbound()){
        EXP -= get_EXP_upperbound();
        level_up();
    }
}

void Player::show(){
    cout << "--------角色信息--------" << endl;
    cout << "名称：" << get_name() << endl;
    cout << "等级：" << get_level() << endl;
    cout << "攻击力：" << get_ATK() << endl;
    cout << "HP：" << get_HP() << " / " << get_HP_upperbound() << endl;
    cout << "BP：" << get_BP() << " / " << get_BP_upperbound() << endl;
    cout << "EXP：" << get_EXP() << " / " << get_EXP_upperbound() << endl;
    cout << "装备的武器：" << weapon.get_name() << endl;
    cout << "身上的元素附着："  << get_state() << endl;
    cout << endl;
}

void Player::change_weapon(Weapon W){
    weapon = W;
}

vector<Skill> Player::get_skill(){
    vector<Skill> learned_skill;
    for(map<Skill, int>::iterator p = skill.begin(); p != skill.end(); p++){
        if(p->second == 1){
            learned_skill.push_back(p->first);
        }
    }
    return learned_skill;
}

Skill::Skill(){}

Skill::Skill(string name, int cost, float rate, string element, int type, string description, int rank)
:name(name), cost(cost), rate(rate), element(element), type(type), description(description), rank(rank){}

Skill::~Skill(){}

string Skill::get_name() const{
    return name;
}

int Skill::get_cost() const{
    return cost;
}

float Skill::get_rate() const{
    return rate;
}

string Skill::get_element() const{
    return element;
}

bool Skill::operator<(const Skill &that)const{
    return this->rank < that.rank;
}

int Skill::get_type() const{
    return type;
}

string Skill::get_description() const{
    return description;
}