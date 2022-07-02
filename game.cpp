#include "Game.h"

Game::Game(){

}
Game::~Game(){

}
void Game::run_game(World &world, Role &role){
    pair<int, int>trans = run_map(world, role, 0);
    while(1){
        trans = run_map(world, role, trans.second, trans.first);
        if(trans.first == -1){
            break;
        }
    }
}
pair<int, int> Game::run_map(World &world, Role &role, int index, int from){
    string* current_map = world.get_map()[index].get_picture();
    set_position(role, index, from);
    current_map[role.get_x()].replace(role.get_y(), 2, "我");
    system("cls");
    for(int i = 0; current_map[i].length() > 0; i++){
        cout << current_map[i] << endl;
    }
    char ch;
    int x, y, show_y;
    while(1){
        ch = getch();
        x = role.get_x();
        y = role.get_y();
        show_y = role.get_show_y();
        if(ch == 'a'){
            if(y == 0){
                current_map[x].replace(y, 3, "  ");
                pair<int, int>trans(index, get_next_map(index, ch));
                return trans;
            }
            if(current_map[x][y-1] == ' '){
                current_map[x].replace(y, 3, "  ");
                y -= 2;
                show_y--;
                role.set_y(y);
                role.set_show_y(show_y);
                current_map[x].replace(y, 2, "我");
            }
            else{
                event.judge_event(world, role, index, x, show_y-1, ch);
            }
        }
        if(ch == 'd'){
            if(y == current_map[x].length()-3){
                current_map[x].replace(y, 3, "  ");
                pair<int, int>trans(index, get_next_map(index, ch));
                return trans;
            }
            if(current_map[x][y+3] == ' '){
                current_map[x].replace(y, 3, "  ");
                y += 2;
                show_y++;
                role.set_y(y);
                role.set_show_y(show_y);
                current_map[x].replace(y, 2, "我");
            }
            else{
                event.judge_event(world, role, index, x, show_y+1, ch);
            }
        }
        if(ch == 'w'){
            if(x == 0){
                current_map[x].replace(y, 3, "  ");
                pair<int, int>trans(index, get_next_map(index, ch));
                return trans;
            }
            int new_y = 0;
            for(int i = 0; i < show_y; i++){
                if(current_map[x-1][new_y] == ' '){
                    new_y += 2;
                }
                else{
                    new_y += 3;
                }
            }
            if(current_map[x-1][new_y] == ' '){
                current_map[x].replace(y, 3, "  ");
                y = new_y;
                x -= 1;
                role.set_x(x);
                role.set_y(y);
                current_map[x].replace(y, 2, "我");
            }
            else{
                event.judge_event(world, role, index, x-1, show_y, ch);
            }      
        }
        if(ch == 's'){
            if(current_map[x+1].length() == 0){
                current_map[x].replace(y, 3, "  ");
                pair<int, int>trans(index, get_next_map(index, ch));
                return trans;
            }
            int new_y = 0;
            for(int i = 0; i < show_y; i++){
                if(current_map[x+1][new_y] == ' '){
                    new_y += 2;
                }
                else{
                    new_y += 3;
                }
            }
            if(current_map[x+1][new_y] == ' '){
                current_map[x].replace(y, 3, "  ");
                y = new_y;
                x += 1;
                role.set_y(y);
                role.set_x(x);
                current_map[x].replace(y, 2, "我");
            }
            else{
                event.judge_event(world, role, index, x+1, show_y, ch);
            }      
        }
        if(ch == 27){
            cout << "菜单：" << endl;
            cout << "0:商城 1:角色 2:武器 3:更改出场角色 4:更改当前角色武器 5:当前角色信息 6:背包 7:角色祈愿 8:武器祈愿 9:地图 10:退出游戏" << endl;
            int x;
            cin >> x;
            if(x == 0){
                cout << "商城：" << endl;
                cout << "1: 惊雷精油*1--售价1000摩拉" << endl;
                cout << "2: 霜劫精油*1--售价1000摩拉" << endl;
                cout << "3: 烈火精油*1--售价1000摩拉" << endl;
                cout << "4: 激流精油*1--售价1000摩拉" << endl;
                cout << "5: 甜甜花酿鸡*1--售价1000摩拉" << endl;
                cout << "6: 原石*1600--售价10000摩拉" << endl;
                cout << "请输入您要购买的物品编号";
                int buy;
                cin >> buy;
                if(buy == 1){
                    if(role.items[5] >= 1000){
                        cout << "惊雷精油购买成功" << endl;
                        role.items[5] -= 1000;
                        role.items[0] += 1;
                    }
                    else{
                        cout << "摩拉不足" << endl;
                    }
                }
                else if(buy == 2){
                    if(role.items[5] >= 1000){
                        cout << "霜劫精油购买成功" << endl;
                        role.items[5] -= 1000;
                        role.items[1] += 1;
                    }
                    else{
                        cout << "摩拉不足" << endl;
                    }
                }
                else if(buy == 3){
                    if(role.items[5] >= 1000){
                        cout << "烈火精油购买成功" << endl;
                        role.items[5] -= 1000;
                        role.items[2] += 1;
                    }
                    else{
                        cout << "摩拉不足" << endl;
                    }
                }
                else if(buy == 4){
                    if(role.items[5] >= 1000){
                        cout << "激流精油购买成功" << endl;
                        role.items[5] -= 1000;
                        role.items[3] += 1;
                    }
                    else{
                        cout << "摩拉不足" << endl;
                    }
                }
                else if(buy == 5){
                    if(role.items[5] >= 1000){
                        cout << "甜甜花酿鸡购买成功" << endl;
                        role.items[5] -= 1000;
                        role.items[4] += 1;
                    }
                    else{
                        cout << "摩拉不足" << endl;
                    }
                }
                else if(buy == 6){
                    if(role.items[5] >= 1000){
                        cout << "原石购买成功" << endl;
                        role.items[5] -= 1000;
                        role.items[6] += 1600;
                    }
                    else{
                        cout << "摩拉不足" << endl;
                    }
                }
            }
            else if(x == 1){
                role.show_players();
                system("pause");
            }
            else if(x == 2){
                role.show_weapons();
                system("pause");
            }
            else if(x == 3){
                role.change_current_player();
                system("pause");
            }
            else if(x == 4){
                role.change_weapon();
                system("pause");
            }
            else if(x == 5){
                role.get_current_player().show();
                system("pause");
            }
            else if(x == 6){
                role.show_items();
                system("pause");
            }
            else if(x == 7){
                character_wishes(players, role);
                system("pause");
            }
            else if(x == 8){
                weapon_wishes(weapons, role);
                system("pause");
            }
            else if(x == 9){
                world.show_map();
                system("pause");
            }
            else if(x == 10){
                role.save(players, weapons);
                break;
            }
        }
        system("cls");
        for(int i = 0; current_map[i].length() > 0; i++){
            cout << current_map[i] << endl;
        }
    }
    pair<int, int>trans(-1, -1);
    return trans;
}
void set_position(Role& role, int index, int from){
    switch(index){
        case 0:
        role.set_x(32);
        role.set_y(37);
        role.set_show_y(14);
        break;
        case 1:
        if(from == 0){
            role.set_x(0);
            role.set_y(39);
            role.set_show_y(19);
        }
        else if(from == 2){
            role.set_x(13);
            role.set_y(0);
            role.set_show_y(0);
        }
        else if(from == 3){
            role.set_x(16);
            role.set_y(79);
            role.set_show_y(35);
        }
        else if(from == 4){
            role.set_x(24);
            role.set_y(29);
            role.set_show_y(14);
        }
        break;
        case 2:
        role.set_x(19);
        role.set_y(23);
        role.set_show_y(11);
        break;
        case 3:
        role.set_x(0);
        role.set_y(56);
        role.set_show_y(24);
        break;
        case 4:
        if(from == 1){
            role.set_x(0);
            role.set_y(44);
            role.set_show_y(15);
        }
        else if(from == 5){
            role.set_x(18);
            role.set_y(25);
            role.set_show_y(11);
        }
        break;
        case 5:
        if(from == 4){
            role.set_x(0);
            role.set_y(33);
            role.set_show_y(15);
        }
        else if(from == 6){
            role.set_x(26);
            role.set_y(0);
            role.set_show_y(0);
        }
        break;
        default:
        role.set_x(13);
        role.set_y(67);
        role.set_show_y(31);
    }
}

int get_next_map(int index, char ch){
    switch(index){
        case 0:
        return 1;
        case 1:
        if(ch == 'w'){
            return 0;
        }
        else if(ch == 'a'){
            return 2;
        }
        else if(ch == 'd'){
            return 3;
        }
        else{
            return 4;
        }
        case 2:
        return 1;
        case 3:
        return 1;
        case 4:
        if(ch == 'w'){
            return 1;
        }
        else{
            return 5;
        }
        case 5:
        if(ch == 'w'){
            return 4;
        }
        else{
            return 6;
        }
        default:
        return 5;
    }
}