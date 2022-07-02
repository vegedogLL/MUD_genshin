#include "Weapon.h"

Weapon::Weapon(){

}

Weapon::~Weapon(){

}

string Weapon::get_name() const {
    return name;
}

int Weapon::get_ATK(){
    return ATK;
}

void Weapon::show(){
    cout << "--------武器信息--------" << endl;
    cout << "名称：" << get_name() << endl;
    cout << "攻击力：" << get_ATK() << endl;
    cout << endl;
}