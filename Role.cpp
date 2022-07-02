#include "Role.h"
int Role::get_x(){
    return x;
}
int Role::get_y(){
    return y;
}
int Role::get_show_y(){
    return show_y;
}
void Role::set_x(int a){
    x = a;
}
void Role::set_y(int a){
    y = a;
}
void Role::set_show_y(int a){
    show_y = a;
}
void Role::show_players(){
    cout << "您当前拥有的角色:" << endl;
    int i = 0;
    for(vector<Player>::iterator p = players.begin(); p != players.end(); p++){
        if(p == players.begin()){
            cout << i + 1 << ". " << p->get_name();
        }
        else{
            cout << ", " << i + 1 << ". " << p->get_name();
        }
        i++;
    }
    cout << endl;
}

void Role::change_current_player(){
    show_players();
    cout << "请选择您想要出场的角色:" << endl;
    string choice;
    cin >> choice;
    while(choice.length() > 1|| (choice[0] - 48) > players.size()|| (choice[0] - 48) < 1){
        cout << "你输入了无效的选择，请重新输入！" << endl;
        cin >> choice;
    }
    current_player = players[choice[0] - 48 - 1];
}

vector<Weapon> Role::show_weapons(){
    vector<Weapon> w;
    cout << "您当前拥有的武器:" << endl;
    int i = 0;
    for(vector<Weapon>::iterator p = weapons.begin(); p != weapons.end(); p++){
        if(i == 0){
            cout << i + 1 << ". " << p->get_name();
        }
        else{
            cout << ", " << i + 1 << ". " << p->get_name();
        }
        i++;
        w.push_back(*p);
    }
    cout << endl;
    return w;  
}

void Role::change_weapon(){
    vector<Weapon> w = show_weapons();
    cout << "请选择您想替换的武器:" << endl;
    string choice;
    cin >> choice;
    int flag = 0;
    while(choice.length() > 2){
        cout << "你输入了无效的选择，请重新输入！" << endl;
        cin >> choice;   
    }
    while(!flag){
        if(choice.length() == 1){
            if((choice[0] - 48) <= w.size()&& (choice[0] - 48) >= 1){
                flag = 1;
                current_player.change_weapon(w[choice[0] - 48 -1]);
                break;
            }
        }
        else if(choice.length() == 2){
            if((choice[0] - 48) * 10 + (choice[1] - 48) <= w.size()){
                flag = 1;
                current_player.change_weapon(w[(choice[0] - 48) * 10 + (choice[1] - 48) -1]);
                break;
            }
        }
        cout << "你输入了无效的选择，请重新输入！" << endl;
        cin >> choice;  
    }
}

int Role::add_players(Player player){
    for(vector<Player>::iterator p = players.begin(); p != players.end(); p++){
        if(p->get_name() == player.get_name()){
            return 0;
        }
    }
    players.push_back(player);
    return 1;
}

int Role::add_weapons(Weapon weapon){
    for(vector<Weapon>::iterator p = weapons.begin(); p != weapons.end(); p++){
        if(p->get_name() == weapon.get_name()){
            return 0;
        }
    }
    weapons.push_back(weapon);
    return 1;
}

void Role::show_items(){
    cout << "您背包中有:" << endl;
    cout << "惊雷精油 * " << items[0] << "  霜劫精油 * " << items[1] << endl;
    cout << "烈火精油 * " << items[2] << "  激流精油 * " << items[3] << endl;
    cout << "甜甜花酿鸡 * " << items[4] << endl;
    cout << "摩拉 * " << items[5] << "  原石 * " << items[6] << endl;
}

void Role::save(vector<Player> player, vector<vector<Weapon>> weapon){
    ofstream fout;
    fout.open("data.txt", ios::out);
    fout << players.size() << endl;
    for(vector<Player>::iterator p = players.begin(); p != players.end(); p++){
        int i = 0;
        for(vector<Player>::iterator q = player.begin(); q != player.end(); q++){
            if(p->get_name() == q->get_name()){
                fout << i << endl;
                break;
            }
            i++;
        }
    }
    fout << weapons.size() << endl;
    for(vector<Weapon>::iterator p = weapons.begin(); p != weapons.end(); p++){
        int i = 0;
        if(p->get_star() == 1){
            for(vector<Weapon>::iterator q = weapon[2].begin(); q != weapon[2].end(); q++){
                if(p->get_name() == q->get_name()){
                    fout << 2 << i << endl;
                    break;
                }
                i++;
            }
        }
        else if(p->get_star() == 4){
            for(vector<Weapon>::iterator q = weapon[1].begin(); q != weapon[1].end(); q++){
                if(p->get_name() == q->get_name()){
                    fout << 1 << i << endl;
                    break;
                }
                i++;
            }
        }
        else{
            for(vector<Weapon>::iterator q = weapon[0].begin(); q != weapon[0].end(); q++){
                if(p->get_name() == q->get_name()){
                    fout << 0 << i << endl;
                    break;
                }
                i++;
            }
        }
    }
    for(map<int, int>::iterator p = items.begin(); p != items.end(); p++){
        fout << p->second << endl;
    }
    fout.close();
}

int Role::load(vector<Player> player, vector<vector<Weapon>> weapon){
    ifstream fin;
    fin.open("data.txt", ios::in);
    if(!fin.is_open()){
        cout << "无法打开存档文件!" << endl;
        return 0;
    }
    else{
        int number;
        fin >> number;
        for(int i = 0; i < number; i++){
            int player_id;
            fin >> player_id;
            players.push_back(player[player_id]);
        }
        fin >> number;
        for(int i = 0; i < number; i++){
            string weapon_id;
            fin >> weapon_id;
            weapons.push_back(weapon[weapon_id[0] - 48][weapon_id[1] - 48]);
        }
        for(int i = 0; i < 7; i++){
            int item_num;
            fin >> item_num;
            items[i] = item_num;
        }
    }
    current_player = players[0];
    fin.close();
    return 1;
}

void character_wishes(vector<Player> player, Role &R){
    while(1){
        cout << "你拥有的原石:" << R.items[6] << endl;
        cout << "请做出你的选择:" << endl;
        cout << "1.抽一次   2.抽十次   3.退出" << endl;
        string choice;
        cin >> choice;
        while(choice != "1"&& choice != "2"&& choice != "3"){
            cout << "你输入了无效的选择，请重新输入！" << endl;
            cin >> choice;
        }
        if(choice == "1"){
            if(R.items[6] < 160){
                cout << "原石数量不足!" << endl;
                continue;
            }
            else{
                R.items[6] -= 160;
            }
        }
        else if(choice == "2"){
            if(R.items[6] < 1600){
                cout << "原石数量不足!" << endl;
                continue;
            }
            else{
                R.items[6] -= 1600;
            }
        }
        else{
            break;
        }
        if(choice == "1"){
            cout << "恭喜你获得了:" << endl;
            srand((unsigned) time(NULL) + R.items[5] + R.items[6]);
            int number = rand()%100 + 1;
            if(number < 50){
                if(number < 25){
                    cout << "摩拉 * 1000" << endl;
                    R.items[5] += 1000;
                }
                else if(number < 40){
                    cout << "摩拉 * 5000" << endl;
                    R.items[5] += 5000;
                }
                else if(number < 46){
                    cout << "摩拉 * 10000" << endl;
                    R.items[5] += 10000;
                }
                else if(number < 50){
                    cout << "摩拉 * 100000" << endl;
                    R.items[5] += 100000;
                }
            }
            else if(number < 80){
                if(number < 55){
                    cout << "惊雷精油 * 10" << endl;
                    R.items[0] += 10;
                }
                else if(number < 60){
                    cout << "霜劫精油 * 10" << endl;
                    R.items[1] += 10;
                }
                else if(number < 65){
                    cout << "烈火精油 * 10" << endl;
                    R.items[2] += 10;
                }
                else if(number < 70){
                    cout << "激流精油 * 10" << endl;
                    R.items[3] += 10;
                }
                else if(number < 75){
                    cout << "甜甜花酿鸡 * 10" << endl;
                    R.items[4] += 10;
                }
                else if(number < 80){
                    cout << "惊雷精油 * 10, 霜劫精油 * 10, 烈火精油 * 10, 激流精油 * 10, 甜甜花酿鸡 * 10" << endl;
                    for(int i = 0; i < 5; i++){
                        R.items[i] += 10;
                    }
                }
            }
            else if(number < 90){
                if(number < 85){
                    cout << "原石 * 20" << endl;
                    R.items[6] += 20;
                }
                else if(number < 89){
                    cout << "原石 * 60" << endl;
                    R.items[6] += 60;
                }
                else if(number < 90){
                    cout << "原石 * 1600" << endl;
                    R.items[6] += 1600;
                }
            }
            else{
                if(number < 92){
                    cout << "飞行冠军*安柏" << endl;
                    if(!R.add_players(player[6])){
                        cout << "重复角色已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 94){
                    cout << "霆霓快雨*刻晴" << endl;
                    if(!R.add_players(player[4])){
                        cout << "重复角色已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 95){
                    cout << "晨曦的暗面*迪卢克" << endl;
                    if(!R.add_players(player[0])){
                        cout << "重复角色已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 96){
                    cout << "白鹭霜华*神里绫华" << endl;
                    if(!R.add_players(player[1])){
                        cout << "重复角色已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 97){
                    cout << "少年春衫薄*行秋" << endl;
                    if(!R.add_players(player[2])){
                        cout << "重复角色已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 98){
                    cout << "浪沫的旋舞*优菈" << endl;
                    if(!R.add_players(player[3])){
                        cout << "重复角色已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 99){
                    cout << "一心净土*雷电将军" << endl;
                    if(!R.add_players(player[5])){
                        cout << "重复角色已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 100){
                    cout << "磐祭叶守*神里绫人" << endl;
                    if(!R.add_players(player[7])){
                        cout << "重复角色已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
            }
        }
        else{
            cout << "恭喜你获得了:" << endl;
            srand((unsigned) time(NULL) + R.items[5] + R.items[6]);
            for(int i = 0; i < 10; i++){
                int number = rand()%100 + 1;
                if(number < 50){
                    if(number < 25){
                        cout << "摩拉 * 1000" << endl;
                        R.items[5] += 1000;
                    }
                    else if(number < 40){
                        cout << "摩拉 * 5000" << endl;
                        R.items[5] += 5000;
                    }
                    else if(number < 46){
                        cout << "摩拉 * 10000" << endl;
                        R.items[5] += 10000;
                    }
                    else if(number < 50){
                        cout << "摩拉 * 100000" << endl;
                        R.items[5] += 100000;
                    }
                }
                else if(number < 80){
                    if(number < 55){
                        cout << "惊雷精油 * 10" << endl;
                        R.items[0] += 10;
                    }
                    else if(number < 60){
                        cout << "霜劫精油 * 10" << endl;
                        R.items[1] += 10;
                    }
                    else if(number < 65){
                        cout << "烈火精油 * 10" << endl;
                        R.items[2] += 10;
                    }
                    else if(number < 70){
                        cout << "激流精油 * 10" << endl;
                        R.items[3] += 10;
                    }
                    else if(number < 75){
                        cout << "甜甜花酿鸡 * 10" << endl;
                        R.items[4] += 10;
                    }
                    else if(number < 80){
                        cout << "惊雷精油 * 10, 霜劫精油 * 10, 烈火精油 * 10, 激流精油 * 10, 甜甜花酿鸡 * 10" << endl;
                        for(int i = 0; i < 5; i++){
                            R.items[i] += 10;
                        }
                    }
                }
                else if(number < 90){
                    if(number < 85){
                        cout << "原石 * 20" << endl;
                        R.items[6] += 20;
                    }
                    else if(number < 89){
                        cout << "原石 * 60" << endl;
                        R.items[6] += 60;
                    }
                    else if(number < 90){
                        cout << "原石 * 1600" << endl;
                        R.items[6] += 1600;
                    }
                }
                else{
                    if(number < 92){
                        cout << "飞行冠军*安柏" << endl;
                        if(!R.add_players(player[6])){
                            cout << "重复角色已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 94){
                        cout << "霆霓快雨*刻晴" << endl;
                        if(!R.add_players(player[4])){
                            cout << "重复角色已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 95){
                        cout << "晨曦的暗面*迪卢克" << endl;
                        if(!R.add_players(player[0])){
                            cout << "重复角色已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 96){
                        cout << "白鹭霜华*神里绫华" << endl;
                        if(!R.add_players(player[1])){
                            cout << "重复角色已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 97){
                        cout << "少年春衫薄*行秋" << endl;
                        if(!R.add_players(player[2])){
                            cout << "重复角色已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 98){
                        cout << "浪沫的旋舞*优菈" << endl;
                        if(!R.add_players(player[3])){
                            cout << "重复角色已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 99){
                        cout << "一心净土*雷电将军" << endl;
                        if(!R.add_players(player[5])){
                            cout << "重复角色已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 100){
                        cout << "磐祭叶守*神里绫人" << endl;
                        if(!R.add_players(player[7])){
                            cout << "重复角色已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                }
            }
        }
    }
}

void weapon_wishes(vector<vector<Weapon>> weapon, Role &R){
    while(1){
        cout << "你拥有的原石:" << R.items[6] << endl;
        cout << "请做出你的选择:" << endl;
        cout << "1.抽一次   2.抽十次   3.退出" << endl;
        string choice;
        cin >> choice;
        while(choice != "1"&& choice != "2"&& choice != "3"){
            cout << "你输入了无效的选择，请重新输入！" << endl;
            cin >> choice;
        }
        if(choice == "1"){
            if(R.items[6] < 160){
                cout << "原石数量不足!" << endl;
                continue;
            }
            else{
                R.items[6] -= 160;
            }
        }
        else if(choice == "2"){
            if(R.items[6] < 1600){
                cout << "原石数量不足!" << endl;
                continue;
            }
            else{
                R.items[6] -= 1600;
            }
        }
        else{
            break;
        }
        if(choice == "1"){
            cout << "恭喜你获得了:" << endl;
            srand((unsigned) time(NULL) + R.items[5] + R.items[6]);
            int number = rand()%100 + 1;
            if(number < 50){
                if(number < 25){
                    cout << "摩拉 * 1000" << endl;
                    R.items[5] += 1000;
                }
                else if(number < 40){
                    cout << "摩拉 * 5000" << endl;
                    R.items[5] += 5000;
                }
                else if(number < 46){
                    cout << "摩拉 * 10000" << endl;
                    R.items[5] += 10000;
                }
                else if(number < 50){
                    cout << "摩拉 * 100000" << endl;
                    R.items[5] += 100000;
                }
            }
            else if(number < 76){
                if(number < 55){
                    cout << "惊雷精油 * 10" << endl;
                    R.items[0] += 10;
                }
                else if(number < 60){
                    cout << "霜劫精油 * 10" << endl;
                    R.items[1] += 10;
                }
                else if(number < 65){
                    cout << "烈火精油 * 10" << endl;
                    R.items[2] += 10;
                }
                else if(number < 70){
                    cout << "激流精油 * 10" << endl;
                    R.items[3] += 10;
                }
                else if(number < 75){
                    cout << "甜甜花酿鸡 * 10" << endl;
                    R.items[4] += 10;
                }
                else if(number < 76){
                    cout << "惊雷精油 * 10, 霜劫精油 * 10, 烈火精油 * 10, 激流精油 * 10, 甜甜花酿鸡 * 10" << endl;
                    for(int i = 0; i < 5; i++){
                        R.items[i] += 10;
                    }
                }
            }
            else{
                if(number < 77){
                    cout << "狼的末路" << endl;
                    if(!R.add_weapons(weapon[0][0])){
                        cout << "重复武器已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 78){
                    cout << "松籁响起之时" << endl;
                    if(!R.add_weapons(weapon[0][1])){
                        cout << "重复武器已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 79){
                    cout << "阿莫斯之弓" << endl;
                    if(!R.add_weapons(weapon[0][2])){
                        cout << "重复武器已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 80){
                    cout << "冬极白星" << endl;
                    if(!R.add_weapons(weapon[0][3])){
                        cout << "重复武器已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 81){
                    cout << "雾切之回光" << endl;
                    if(!R.add_weapons(weapon[0][4])){
                        cout << "重复武器已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 82){
                    cout << "磐岩结绿" << endl;
                    if(!R.add_weapons(weapon[0][5])){
                        cout << "重复武器已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 83){
                    cout << "薙草之稻光" << endl;
                    if(!R.add_weapons(weapon[0][6])){
                        cout << "重复武器已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 84){
                    cout << "护摩之杖" << endl;
                    if(!R.add_weapons(weapon[0][7])){
                        cout << "重复武器已转换成原石 * 400" << endl;
                        R.items[6] += 400;
                    }
                }
                else if(number < 86){
                    cout << "雨裁" << endl;
                    if(!R.add_weapons(weapon[1][0])){
                        cout << "重复武器已转换成原石 * 100" << endl;
                        R.items[6] += 100;
                    }
                }
                else if(number < 88){
                    cout << "无工之剑" << endl;
                    if(!R.add_weapons(weapon[1][1])){
                        cout << "重复武器已转换成原石 * 100" << endl;
                        R.items[6] += 100;
                    }
                }
                else if(number < 90){
                    cout << "弓藏" << endl;
                    if(!R.add_weapons(weapon[1][2])){
                        cout << "重复武器已转换成原石 * 100" << endl;
                        R.items[6] += 100;
                    }
                }
                else if(number < 92){
                    cout << "绝弦" << endl;
                    if(!R.add_weapons(weapon[1][3])){
                        cout << "重复武器已转换成原石 * 100" << endl;
                        R.items[6] += 100;
                    }
                }
                else if(number < 94){
                    cout << "黎明神剑" << endl;
                    if(!R.add_weapons(weapon[1][4])){
                        cout << "重复武器已转换成原石 * 100" << endl;
                        R.items[6] += 100;
                    }
                }
                else if(number < 96){
                    cout << "天目影打刀" << endl;
                    if(!R.add_weapons(weapon[1][5])){
                        cout << "重复武器已转换成原石 * 100" << endl;
                        R.items[6] += 100;
                    }
                }
                else if(number < 98){
                    cout << "西风长枪" << endl;
                    if(!R.add_weapons(weapon[1][6])){
                        cout << "重复武器已转换成原石 * 100" << endl;
                        R.items[6] += 100;
                    }
                }
                else if(number < 100){
                    cout << "匣里灭辰" << endl;
                    if(!R.add_weapons(weapon[1][7])){
                        cout << "重复武器已转换成原石 * 100" << endl;
                        R.items[6] += 100;
                    }
                }
            }
        }
        else{
            cout << "恭喜你获得了:" << endl;
            srand((unsigned) time(NULL) + R.items[5] + R.items[6]);
            for(int i = 0; i < 10; i++){
                int number = rand()%100 + 1;
                if(number < 50){
                    if(number < 25){
                        cout << "摩拉 * 1000" << endl;
                        R.items[5] += 1000;
                    }
                    else if(number < 40){
                        cout << "摩拉 * 5000" << endl;
                        R.items[5] += 5000;
                    }
                    else if(number < 46){
                        cout << "摩拉 * 10000" << endl;
                        R.items[5] += 10000;
                    }
                    else if(number < 50){
                        cout << "摩拉 * 100000" << endl;
                        R.items[5] += 100000;
                    }
                }
                else if(number < 76){
                    if(number < 55){
                        cout << "惊雷精油 * 10" << endl;
                        R.items[0] += 10;
                    }
                    else if(number < 60){
                        cout << "霜劫精油 * 10" << endl;
                        R.items[1] += 10;
                    }
                    else if(number < 65){
                        cout << "烈火精油 * 10" << endl;
                        R.items[2] += 10;
                    }
                    else if(number < 70){
                        cout << "激流精油 * 10" << endl;
                        R.items[3] += 10;
                    }
                    else if(number < 75){
                        cout << "甜甜花酿鸡 * 10" << endl;
                        R.items[4] += 10;
                    }
                    else if(number < 76){
                        cout << "惊雷精油 * 10, 霜劫精油 * 10, 烈火精油 * 10, 激流精油 * 10, 甜甜花酿鸡 * 10" << endl;
                        for(int i = 0; i < 5; i++){
                            R.items[i] += 10;
                        }
                    }
                }
                else{
                    if(number < 77){
                        cout << "狼的末路" << endl;
                        if(!R.add_weapons(weapon[0][0])){
                            cout << "重复武器已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 78){
                        cout << "松籁响起之时" << endl;
                        if(!R.add_weapons(weapon[0][1])){
                            cout << "重复武器已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 79){
                        cout << "阿莫斯之弓" << endl;
                        if(!R.add_weapons(weapon[0][2])){
                            cout << "重复武器已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 80){
                        cout << "冬极白星" << endl;
                        if(!R.add_weapons(weapon[0][3])){
                            cout << "重复武器已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 81){
                        cout << "雾切之回光" << endl;
                        if(!R.add_weapons(weapon[0][4])){
                            cout << "重复武器已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 82){
                        cout << "磐岩结绿" << endl;
                        if(!R.add_weapons(weapon[0][5])){
                            cout << "重复武器已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 83){
                        cout << "薙草之稻光" << endl;
                        if(!R.add_weapons(weapon[0][6])){
                            cout << "重复武器已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 84){
                        cout << "护摩之杖" << endl;
                        if(!R.add_weapons(weapon[0][7])){
                            cout << "重复武器已转换成原石 * 400" << endl;
                            R.items[6] += 400;
                        }
                    }
                    else if(number < 86){
                        cout << "雨裁" << endl;
                        if(!R.add_weapons(weapon[1][0])){
                            cout << "重复武器已转换成原石 * 100" << endl;
                            R.items[6] += 100;
                        }
                    }
                    else if(number < 88){
                        cout << "无工之剑" << endl;
                        if(!R.add_weapons(weapon[1][1])){
                            cout << "重复武器已转换成原石 * 100" << endl;
                            R.items[6] += 100;
                        }
                    }
                    else if(number < 90){
                        cout << "弓藏" << endl;
                        if(!R.add_weapons(weapon[1][2])){
                            cout << "重复武器已转换成原石 * 100" << endl;
                            R.items[6] += 100;
                        }
                    }
                    else if(number < 92){
                        cout << "绝弦" << endl;
                        if(!R.add_weapons(weapon[1][3])){
                            cout << "重复武器已转换成原石 * 100" << endl;
                            R.items[6] += 100;
                        }
                    }
                    else if(number < 94){
                        cout << "黎明神剑" << endl;
                        if(!R.add_weapons(weapon[1][4])){
                            cout << "重复武器已转换成原石 * 100" << endl;
                            R.items[6] += 100;
                        }
                    }
                    else if(number < 96){
                        cout << "天目影打刀" << endl;
                        if(!R.add_weapons(weapon[1][5])){
                            cout << "重复武器已转换成原石 * 100" << endl;
                            R.items[6] += 100;
                        }
                    }
                    else if(number < 98){
                        cout << "西风长枪" << endl;
                        if(!R.add_weapons(weapon[1][6])){
                            cout << "重复武器已转换成原石 * 100" << endl;
                            R.items[6] += 100;
                        }
                    }
                    else if(number < 100){
                        cout << "匣里灭辰" << endl;
                        if(!R.add_weapons(weapon[1][7])){
                            cout << "重复武器已转换成原石 * 100" << endl;
                            R.items[6] += 100;
                        }
                    }
                }
            }
        }
    }
}