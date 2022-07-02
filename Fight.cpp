#include "Fight.h"

void Processer::reaction(int type){
    if(type == 1){
        cout << "触发了蒸发反应!" << endl;
    }
    else if(type == 2){
        cout << "触发了融化反应!" << endl;
    }
    else if(type == 3){
        freeze = 1;
        cout << "触发了冻结反应!" << endl;
    }
    else if(type == 4){
        cout << "触发了超载反应!" << endl;
    }
    else if(type == 5){
        cout << "触发了感电反应!" << endl;
    }
    else if(type == 6){
        cout << "触发了超导反应!" << endl;
    }
}

void Processer::process(Player &P, Enemy &E){
    freeze = 0;
    int reaction_type = 0;
    if(skill.get_type()){
        rounds[skill.get_type()] = MAXROUND;
    }
    if(skill.get_element() != "无"){
        if(whose){
            rate *= P.reaction(skill.get_element(), reaction_type);
        }
        else{
            rate *= E.reaction(skill.get_element(), reaction_type);
        }
        reaction(reaction_type);
    }
    rate *= skill.get_rate();
    for(map<int, int>::iterator p = rounds.begin(); p != rounds.end(); p++){
        if(!whose){
            if(p->first == 1){
                if(p->second == MAXROUND){
                    P.skill.erase(P.skill.begin());
                    Skill s("普通攻击*淬炼之剑", 0, 1.8, "火", 0, "", 0);
                    P.skill[s] = 1;
                    cout << P.name << skill.get_description() << endl;
                }
                if(--p->second == 0){
                    P.skill.erase(P.skill.begin());
                    Skill s("普通攻击*淬炼之剑", 0, 1.5, "无", 0, "", 0);
                    P.skill[s] = 1;
                }
            }
            else if(p->first == 2){
                if(p->second == MAXROUND){
                    cout << P.name << skill.get_description() << endl;
                }
                if(p->second > 0&& p->second < MAXROUND){
                    damage = P.get_ATK() * 1.8 * E.reaction("冰", reaction_type);
                    reaction(reaction_type);
                    cout << "霜见雪关扉以刀锋般尖锐的霜风持续切割" << E.name << ",造成了" << damage << "点伤害!" << endl;
                    E.sub_HP(damage);
                }
                if(p->second != 0){
                    --p->second;
                }
            }
            else if(p->first == 3){
                if(p->second == MAXROUND){
                    cout << P.name << skill.get_description() << endl;
                }
                if(p->second > 0&& p->second < MAXROUND&& skill.get_rank() == 0){
                    damage = P.get_ATK() * 2.5 * E.reaction("水", reaction_type);
                    reaction(reaction_type);
                    cout << P.name << "进行普通攻击，产生剑雨连携攻击,对" << E.name << "造成了" << damage << "点伤害!" << endl;
                    E.sub_HP(damage);
                }
                if(p->second != 0){
                    --p->second;
                }
            }
            else if(p->first == 4){
                if(p->second == MAXROUND){
                    damage = 0;
                    cout << P.name << skill.get_description() << endl;
                }
                if(p->second > 0&& p->second < MAXROUND){
                    damage += P.get_ATK() *rate;
                }
                if(p->second != 0){
                    --p->second;
                }
                else{
                    damage += P.get_ATK() * 6.3;
                    cout << "光降之剑降下并猛烈爆发，对" << E.name << "造成了" << damage << "点伤害!" << endl;
                    E.sub_HP(damage);
                }
            }
            else if(p->first == 5){
                if(p->second == MAXROUND){
                    P.skill.erase(P.skill.begin());
                    Skill s("普通攻击*源流", 0, 0.9, "雷", 0, "", 0);
                    P.skill[s] = 1;
                    cout << P.name << skill.get_description() << endl;
                }
                if(--p->second == 0){
                    P.skill.erase(P.skill.begin());
                    Skill s("普通攻击*源流", 0, 0.7, "无", 0, "", 0);
                    P.skill[s] = 1;
                }
            }
            else if(p->first == 6){
                if(p->second == MAXROUND){
                    P.skill.erase(P.skill.begin());
                    Skill s("瞬水剑", 0, 1.2, "水", 0, "", 0);
                    P.skill[s] = 1;
                    cout << P.name << skill.get_description() << endl;
                }
                if(--p->second == 0){
                    P.skill.erase(P.skill.begin());
                    Skill s("普通攻击*神里流*转", 0, 0.8, "无", 0, "", 0);
                    P.skill[s] = 1;
                }
            }
            else if(p->first == 7){
                if(p->second == MAXROUND){
                    cout << P.name << skill.get_description() << endl;
                }
                if(p->second > 0&& p->second < MAXROUND){
                    damage = P.get_ATK() * 1 * E.reaction("水", reaction_type);
                    reaction(reaction_type);
                    cout << "园囿中持续降下水花剑,对" << E.name << "造成了" << damage << "点伤害!" << endl;
                    E.sub_HP(damage);
                }
                if(p->second != 0){
                    --p->second;
                }
            }
        }
        else{
            if(p->first == 8){
                if(p->second > 0&& p->second < MAXROUND){
                    damage = E.get_ATK() * 1;
                    cout << "地面开裂涌出能量,对" << P.name << "造成了" << damage << "点伤害!" << endl;
                    P.sub_HP(damage);
                }
                if(p->second != 0){
                    --p->second;
                }
            }
            else if(p->first == 9){
                if(p->second > 0&& p->second < MAXROUND){
                    damage = E.get_ATK() * 2;
                    cout << "若陀龙王踩踏引发地震波,对" << P.name << "造成了" << damage << "点伤害!" << endl;
                    P.sub_HP(damage);
                }
                if(p->second != 0){
                    --p->second;
                }
            }
            else if(p->first == 10){
                if(p->second > 0&& p->second < MAXROUND){
                    damage = E.get_ATK() * 1;
                    cout << P.name << "在飓风领域中受到了" << damage << "点伤害!" << endl;
                    P.sub_HP(damage);
                }
                if(p->second != 0){
                    --p->second;
                }
            }
            else if(p->first == 11){
                if(p->second > 0&& p->second < MAXROUND){
                    damage = E.get_ATK() * 5;
                    cout << P.name << "受到了" << damage << "点伤害!" << endl;
                    P.sub_HP(damage);
                }
                if(p->second != 0){
                    --p->second;
                }
            }
            else if(p->first == 12){
                if(p->second > 0){
                    damage = P.get_HP_upperbound() * 0.05;
                    cout << P.name << "由于侵蚀效果,受到了" << damage << "点伤害!" << endl;
                    P.sub_HP(damage);
                }
                if(p->second != 0){
                    --p->second;
                }
            }
            else if(p->first == 13){
                if(p->second > 0&& p->second < MAXROUND){
                    damage = E.get_ATK() * 1;
                    cout << E.name << "发射追踪冰刺,对" << P.name << "造成了" << damage << "点伤害!" << endl;
                    P.sub_HP(damage);
                }
                if(p->second != 0){
                    --p->second;
                }
            }
        }
    }
}

const void show(Player P, Enemy E){
    cout << "----------------------------------------" << endl;
    cout << left;
    cout << "名称:" << setw(13) << P.get_name() << " 元素附着:" << setw(6) << P.get_state() << " 等级:" << setw(4) << P.get_level();
    cout << endl;
    cout << "HP: " << P.get_HP() << " / " << P.get_HP_upperbound() << "   BP: " << P.get_BP() << " / " << P.get_BP_upperbound();
    cout << "   EXP: " << P.get_EXP() << " / " << P.get_EXP_upperbound() << endl;
    cout << "----------------------------------------" << endl;
    cout << "名称:" << setw(13) << E.get_name() << " 元素附着:" << setw(6) << E.get_state() << " 等级:" << setw(4) << E.get_level() << endl;
    cout << "HP: " << E.get_HP() << " / " << E.get_HP_upperbound() << endl;
    cout << "----------------------------------------" << endl << endl;
}

int fight(Player &P, Enemy E, Role &R){
    cout << "遭遇了" << E.get_name() << ',' << "进入战斗!" << endl;
    Processer processer;
    while(1){
        //玩家的回合
        processer.set_whose(0);
        processer.set_rate(1);
        P.add_BP(1);
        show(P, E);
        //记录战斗结果 1:敌人阵亡，战斗胜利 0:战斗继续 -1:敌人被冻结,跳过它的回合
        // 3:逃跑成功 4:逃跑失败
        int flag; 
        string choice;
        cout << "现在是你的回合" << endl;
        cout << "请做出你的选择：" << endl;
        cout << "1.使用技能" << " 2.使用道具" << " 3.逃跑" << endl;
        cin >> choice;
        while(choice != "1"&& choice != "2"&& choice != "3"){
            cout << "你输入了无效的选择，请重新输入！" << endl;
            cin >> choice;
        }
        if(choice == "1"){
            vector<Skill> learned_skill = P.get_skill();
            map<string, Skill> m;
            string s;
            string b;
            int index = 48;
            cout << "你可以选择消耗至多" << P.get_BP() << "点BP值以使用强化技能" << endl;
            cin >> b;
            while((!(b[0] >= 48&& b[0] <= P.get_BP() + 48))&& b.length() > 1){
                cout << "你输入了无效的选择，请重新输入！" << endl;
                cin >> b;
            }
            cout << "请选择你要使用的技能：" << endl;
            for(vector<Skill>::iterator p = learned_skill.begin(); p != learned_skill.end(); p++){
                if(b[0] - 48 >= (*p).get_cost()){
                    index++;
                    s = index;
                    m[s] = *p;
                    cout << s << '.' << (*p).get_name() << ' ';
                }
            }
            cout << endl;
            cin >> s;
            while(m.count(s) != 1){
                cout << "你输入了无效的选择，请重新输入！" << endl;
                cin >> s;
            }
            P.sub_BP(m[s].get_cost());
            processer.set_skill(m[s]);
            cout << P.get_name() << "使用了" << m[s].get_name() << endl;
            processer.process(P, E);
            int damage = P.get_ATK() * processer.get_rate();
            cout << "对" << E.get_name() << "造成了" << damage << "点伤害!" << endl;
            if(E.sub_HP(damage) == 0){
                flag = 1;
            }
            else{
                if(processer.get_freeze() == 1){
                    flag = -1;
                }
                else{
                    flag = 0;
                }
            }
        }
        else if(choice == "2"){
            R.show_items();
            cout << "请选择你要使用的道具:" << endl;
            cout << "1.惊雷精油" << "  2.霜劫精油";
            cout << "  3.烈火精油" << "  4.激流精油";
            cout << "  5.甜甜花酿鸡" << endl;
            cin >> choice;
            while(choice != "1"&& choice != "2"&& choice != "3"&& choice != "4"&& choice != "5"){
                cout << "你输入了无效的选择，请重新输入！" << endl;
                cin >> choice;
            }
            if(choice == "1"){
                int type;
                int damage = P.get_ATK() * 0.5 * E.reaction("雷", type);
                cout << "你使用了惊雷精油，对" << E.get_name() << "造成了" << damage << "点伤害!" << endl;
                processer.reaction(type);
                R.items[0]--;
                if(E.sub_HP(damage) == 0){
                    flag = 1;
                }
                else{
                    if(processer.get_freeze() == 1){
                        flag = -1;
                    }
                    else{
                        flag = 0;
                    }
                }
            }
            else if(choice == "2"){
                int type;
                int damage = P.get_ATK() * 0.5 * E.reaction("冰", type);
                cout << "你使用了霜劫精油，对" << E.get_name() << "造成了" << damage << "点伤害!" << endl;
                processer.reaction(type);
                R.items[1]--;
                if(E.sub_HP(damage) == 0){
                    flag = 1;
                }
                else{
                    if(processer.get_freeze() == 1){
                        flag = -1;
                    }
                    else{
                        flag = 0;
                    }
                }
            }
            else if(choice == "3"){
                int type;
                int damage = P.get_ATK() * 0.5 * E.reaction("火", type);
                cout << "你使用了烈火精油，对" << E.get_name() << "造成了" << damage << "点伤害!" << endl;
                processer.reaction(type);
                R.items[2]--;
                if(E.sub_HP(damage) == 0){
                    flag = 1;
                }
                else{
                    if(processer.get_freeze() == 1){
                        flag = -1;
                    }
                    else{
                        flag = 0;
                    }
                }
            }
            else if(choice == "4"){
                int type;
                int damage = P.get_ATK() * 0.5 * E.reaction("水", type);
                cout << "你使用了激流精油，对" << E.get_name() << "造成了" << damage << "点伤害!" << endl;
                processer.reaction(type);
                R.items[3]--;
                if(E.sub_HP(damage) == 0){
                    flag = 1;
                }
                else{
                    if(processer.get_freeze() == 1){
                        flag = -1;
                    }
                    else{
                        flag = 0;
                    }
                }
            }
            else if(choice == "5"){
                R.items[4]--;
                cout << "你使用了甜甜花酿鸡,恢复了3000点HP!" << endl;
                P.add_HP(3000);
                flag = 0; 
            }
        }
        else if(choice == "3"){
            srand((unsigned) time(NULL));
            if(rand()%2 == 1){
                flag = 3;
            }
            else{
                flag = 4;
            }
        }
        if(flag == 1){
            cout << "你成功击败了" << E.get_name() << '!' << endl;
            int reward;
            reward = E.drop_EXP();
            cout << "你获得了" << reward << "点EXP值!" << endl;
            P.add_EXP(reward);
            system("pause");
            return 1;
        }
        else if(flag == 3){
            cout << "你成功逃脱了!" << endl;
            break;
        }
        else if(flag == 4){
            cout << "逃跑失败!你的回合结束了!" << endl;
        }
        else if(flag == -1){
            cout << "敌人被冻结了,无法行动!" << endl;
            continue;
        }
        //敌人的回合
        processer.set_whose(1);
        processer.set_rate(1);
        cout << "现在是敌人的回合" << endl;
        vector<Skill> skill = E.get_skill();
        Skill chosen_skill;
        for(vector<Skill>::iterator p = skill.begin(); ; p++){
            if(p == skill.end()){
                p = skill.begin();
            }
            srand((unsigned) time(NULL));
            if(rand()%2 == 1){
                chosen_skill = *p;
                break;
            }
        }
        processer.set_skill(chosen_skill);
        processer.process(P, E);
        int damage = E.get_ATK() * processer.get_rate();
        cout << E.get_name() << "使用" << chosen_skill.get_name() << "对你造成了" << damage << "点伤害!" << endl;
        if(P.sub_HP(damage) == 0){
            flag = 1;
        }
        else{
            flag = 0;
        }
        if(flag == 1){
            cout << "你被" << E.get_name() << "打败了!" << endl;
            break;
        }
    }
    P.sub_BP(P.get_BP());
    system("pause");
    return 0;
}
