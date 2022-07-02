#include "game.h"
void Init_source();
int main (){
    SetConsoleOutputCP(65001);
    World world;
    Game game;
    Init_source();
    cout << "1: 新游戏  2: 继续游戏" << endl;
    int choice;
    cin >> choice;
    cin.get();
    if(choice == 1){
        for(int i = 0; start[i].length() > 0; i++){
            cout << start[i] << endl;
            cin.get();
        }
        Role role(players[6]);
        game.run_game(world, role);
    }
    else if(choice == 2){
        Role role;
        if(role.load(players, weapons)){
            cout << "存档读取成功!" << endl;
            system("pause");
            game.run_game(world, role);
        }
    }
}
void Init_source(){
    player_skills.push_back({Skill("普通攻击*淬炼之剑", 0, 1.5, "无", 0, "", 0), 
                    Skill("逆焰之刃", 1, 2, "火", 0, "", 1), 
                    Skill("黎明", 4, 6.4, "火", 1, "将烈焰凝聚在武器上，挥出向前飞行的火之鸟", 2)});
    player_skills.push_back({Skill("普通攻击*神里流*倾", 0, 0.8, "无", 0, "", 0), 
                    Skill("神里流*冰华", 1, 3.8, "冰", 0, "", 1), 
                    Skill("神里流*霜灭", 5, 2.7, "冰", 2, "以倾奇之姿汇聚寒霜，放出持续行进的霜见雪关扉", 2)});
    player_skills.push_back({Skill("普通攻击*古华剑法", 0, 0.8, "无", 0, "", 0), 
                    Skill("古华剑*画雨笼山", 2, 5.7, "水", 0, "", 1), 
                    Skill("古华剑*裁雨留虹", 3, 2.7, "水", 3, "展开虹剑势，驾御幻影剑雨战斗，并生成最大数量的雨帘剑", 2)});
    player_skills.push_back({Skill("普通攻击*西风剑术*宗室", 0, 1.5, "无", 0, "", 0), 
                    Skill("冰潮的涡旋", 1, 2.3, "冰", 0, "", 1), 
                    Skill("凝浪之光剑", 1, 3.9, "冰", 4, "猛烈挥舞大剑，对周围的敌人造成冰元素伤害，并创造一柄跟随自己的光降之剑", 2)});
    player_skills.push_back({Skill("普通攻击*云来剑法", 0, 0.7, "无", 0, "", 0), 
                    Skill("星斗归位", 1, 3.4, "雷", 0, "", 1), 
                    Skill("天街巡游", 3, 7.4, "雷", 0, "", 2)});
    player_skills.push_back({Skill("普通攻击*源流", 0, 0.7, "无", 0, "", 0), 
                    Skill("神变*恶曜开眼", 1, 2.5, "雷", 0, "", 1), 
                    Skill("奥义*梦想真说", 3, 9.0, "雷", 5, "汇聚万千真言，竭尽诸愿百眼之愿力，斩出粉碎一切诅咒的梦想一刀", 2)});
    player_skills.push_back({Skill("普通攻击*神射手", 0, 0.6, "无", 0, "", 0), 
                    Skill("爆弹玩偶", 1, 2, "火", 0, "", 1), 
                    Skill("箭雨", 4, 8, "火", 0, "", 2)});
    player_skills.push_back({Skill("普通攻击*神里流*转", 0, 0.8, "无", 0, "", 0), 
                    Skill("神里流*镜花", 2, 1.7, "水", 6, "进入\"泷廻鉴花\"状态", 1), 
                    Skill("神里流*水囿", 3, 1, "水", 7, "展开清净之园囿，熄灭其中一切嚣闹", 2)});
    
    enemy_skills.push_back({Skill("挥拳", 0, 1, "无", 0, "", 0)});
    enemy_skills.push_back({Skill("火丘丘射击", 0, 1, "火", 0, "", 0)});
    enemy_skills.push_back({Skill("冰丘丘射击", 0, 1, "冰", 0, "", 0)});
    enemy_skills.push_back({Skill("火史莱姆撞击", 0, 1, "火", 0, "", 0)});
    enemy_skills.push_back({Skill("冰史莱姆撞击", 0, 1, "冰", 0, "", 0)});
    enemy_skills.push_back({Skill("水史莱姆撞击", 0, 1, "水", 0, "", 0)});
    enemy_skills.push_back({Skill("雷史莱姆撞击", 0, 1, "雷", 0, "", 0)});
    enemy_skills.push_back({Skill("爪击", 0, 1, "无", 0, "", 0), 
                    Skill("撕咬", 0, 1, "无", 0, "", 0), 
                    Skill("风魔弹", 0, 2, "无", 0, "", 0),
                    Skill("终天闭幕曲", 0, 1, "无", 8, "", 0)});
    enemy_skills.push_back({Skill("鎏金之投", 0, 1, "无", 0, "", 0), 
                    Skill("伏龙之尾", 0, 1, "无", 0, "", 0), 
                    Skill("黑曜之坠", 0, 2, "无", 0, "", 0),
                    Skill("山崩岩殂", 0, 2, "无", 9, "", 0)});
    enemy_skills.push_back({Skill("蓄力冲风", 0, 1, "无", 0, "", 0), 
                    Skill("力引坠风", 0, 1, "无", 0, "", 0), 
                    Skill("飓风领域", 0, 1, "无", 10, "", 0)});
    enemy_skills.push_back({Skill("传动：拍击", 0, 1, "无", 0, "", 0), 
                    Skill("传动：践踏", 0, 1.2, "无", 0, "", 0), 
                    Skill("传动：死亡回转", 0, 1, "无", 11, "", 0)});
    enemy_skills.push_back({Skill("闪现爪击", 0, 1, "无", 12, "", 0)});
    enemy_skills.push_back({Skill("冰之轮", 0, 1, "冰", 0, "", 0), 
                    Skill("极冰天华", 0, 2, "冰", 0, "", 0), 
                    Skill("霜降", 0, 1, "冰", 13, "", 0)});

    weapons.push_back({Weapon("狼的末路", 741, 5), Weapon("松籁响起之时", 741, 5), Weapon("阿莫斯之弓", 741, 5), 
                      Weapon("冬极白星", 741, 5), Weapon("雾切之回光", 741, 5), Weapon("磐岩结绿", 741, 5),
                      Weapon("薙草之稻光", 741, 5), Weapon("护摩之杖", 741, 5)});
    weapons.push_back({Weapon("雨裁", 565, 4), Weapon("无工之剑", 565, 4), Weapon("弓藏", 565, 4), 
                      Weapon("绝弦", 565, 4), Weapon("黎明神剑", 565, 4), Weapon("天目影打刀", 565, 4),
                      Weapon("西风长枪", 565, 4), Weapon("匣里灭辰", 565, 4)});
    weapons.push_back({Weapon("训练大剑", 185, 1), Weapon("猎弓", 185, 1), Weapon("无锋剑", 185, 1), Weapon("新手长枪", 185, 1)});

    Player p1("迪卢克", 1, 311, 12068, "无", weapons[2][0], 5, 1000, player_skills[0]);
    Player p2("神里绫华", 1, 318, 11954, "无", weapons[2][2], 5, 1000, player_skills[1]);
    Player p3("行秋", 1, 188, 9514, "无", weapons[2][2], 5, 1000, player_skills[2]);
    Player p4("优菈", 1, 318, 12296, "无", weapons[2][0], 5, 1000, player_skills[3]);
    Player p5("刻晴", 1, 300, 12182, "无", weapons[2][2], 5, 1000, player_skills[4]);
    Player p6("雷电将军", 1, 314, 12000, "无", weapons[2][3], 5, 1000, player_skills[5]);
    Player p7("安柏", 1, 208, 8806, "无", weapons[2][1], 5, 1000, player_skills[6]);
    Player p8("神里绫人", 1, 278, 12751, "无", weapons[2][2], 5, 1000, player_skills[7]);
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
    players.push_back(p4);
    players.push_back(p5);
    players.push_back(p6);
    players.push_back(p7);
    players.push_back(p8);

    enemies.push_back(Enemy("丘丘人", 1, 300, 13052, "无", enemy_skills[0]));
    enemies.push_back(Enemy("火箭丘丘人", 1, 400, 10442, "无", enemy_skills[1]));
    enemies.push_back(Enemy("冰箭丘丘人", 1, 400, 10442, "无", enemy_skills[2]));
    enemies.push_back(Enemy("火史莱姆", 1, 300, 10442, "无", enemy_skills[3]));
    enemies.push_back(Enemy("冰史莱姆", 1, 300, 10442, "无", enemy_skills[4]));
    enemies.push_back(Enemy("水史莱姆", 1, 300, 10442, "无", enemy_skills[5]));
    enemies.push_back(Enemy("雷史莱姆", 1, 300, 10442, "无", enemy_skills[6]));
    enemies.push_back(Enemy("风魔龙*特瓦林", 1, 600, 117468, "无", enemy_skills[7]));
    enemies.push_back(Enemy("若陀龙王", 1, 700, 179873, "无", enemy_skills[8]));
    enemies.push_back(Enemy("狂风之核", 1, 400, 65260, "无", enemy_skills[9]));
    enemies.push_back(Enemy("遗迹守卫", 1, 450, 91364, "无", enemy_skills[10]));
    enemies.push_back(Enemy("兽境幼兽", 1, 400, 35165, "无", enemy_skills[11]));
    enemies.push_back(Enemy("无相之冰", 1, 500, 91364, "无", enemy_skills[12]));
}
