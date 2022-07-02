#include "event.h"
using namespace std;

const string start[100] = {
    "我：我是谁？我在哪？这里是什么地方？",
    "在一旁飞来飞去的小东西：你醒啦。",
    "在一旁飞来飞去的小东西：你好呀，旅行者，欢迎来到提瓦特大陆，这里是蒙德城。我是你的向导，我叫派蒙。",
    "我：哇哇，这是什么生物，能吃吗？",
    "派蒙：派蒙不能吃，派蒙也不是应急食品，别问我为什么说这个。",
    "我：可是，我怎么会在这？我记得我被一辆卡车。。。难道说我转生到了这个世界？",
    "派蒙：派蒙不知道哦。",
    "我：啊啊啊，完了！我的电脑硬盘还没有沉到浴缸里！",
    "我：那么，派蒙为什么会在这呢？",
    "派蒙：根据剧本，我应该在海滩边被你从海里钓起来的。。。",
    "派蒙：但是作者太懒了没有做。",
    "我：既然这个世界呼唤我来到这里，那一定是有拯救世界这种大事需要我来做吧！",
    "派蒙：派蒙不知道哦。",
    "派蒙：或许吧，但只靠你是不够的，你的战斗力也就。。。嗯，五分之一野猪！",
    "派蒙：接下来，你将开展一段神奇的冒险。",
    "派蒙：旅途中，或许你将结识其他的伙伴，一起历练、一起提升。",
    "派蒙：这样，最后说不定真能做出拯救世界一样的大事呢！",
    "派蒙：欸嘿。",
    "这时，一位穿红色衣服的女孩子走了过来。",
    "安柏：可敬的异乡人，你好！我是侦察骑士安柏。欢迎来到蒙德城！",
    "我：啊，我初来乍到什么都不懂，我没有恶意的。",
    "派蒙：对了，要是你不想说话也可以哦，派蒙可以当你的外置发声器官。",
    "我：应急食品闭嘴。",
    "安柏：你误会了，我是来帮忙的，有什么需要都可以找我！",
    "安柏加入队伍。",
    "派蒙：那我们就先在城里随便逛逛吧。",
    "派蒙：我看看，或许我们可以先去冒险家协会，你也想成为冒险家的吧。",
    "tips：使用W、A、S、D键控制人物行走。",
};

const string kaiselin_0[100] = {
    "凯瑟琳：向着星辰与深渊，欢迎来到冒险家协会。",
    "凯瑟琳：两位是来加入冒险家协会的吗。",
    "我：不，是一位，这个是会飞的应急食品。",
    "派蒙：啊，气死我了，我要给你起个难听的绰号，就叫你，黄毛阿姨！",
    "凯瑟琳：好的，冒险家协会需要您这样的新鲜血液。",
    "凯瑟琳：接下来我将教您一些作为冒险家的基本操作，好好看好好学。",
    "凯瑟琳：在不处于战斗和对话状态时，按esc可进入菜单。",
    "凯瑟琳：在菜单中，你可以购买物品，查看队伍、地图、背包等。",
    "凯瑟琳：合理利用元素反应，可以让你的战斗事半功倍哦！",
    "这时，你隐隐约约听到阵阵歌声，似清风般飘渺悠扬。",
    "歌声似乎是从蒙德城的风神像那边传来的。",
};

const string kaiselin_1[10] = {
    "凯瑟琳：向着星辰与。。。",
    "凯瑟琳：感谢你完。。。",
};

const string qin[10] = {
    "愿风神忽悠你!",
};

const string lisha[10] = {
    "你好呀小可爱。",
};

const string diluke[10] = {
    "迪卢克：喝，再喝!",
    "迪卢克：你看这个凯亚就是逊啦，才喝几杯，就醉了。",
};

const string babala[10] = {
    "芭芭拉冲呀！",
};

const string wendi_0[100] = {
    "温迪：你好呀，旅行者，想不想欣赏一曲高天之歌呢？",
    "我：你是谁？是个卖唱的？",
    "温迪：我可是提瓦特最有名的吟游诗人温迪，你这么说我，人家好生气啊。",
    "派蒙：卖唱的，我们对你没兴趣。",
    "温迪：诶诶，别走啊，实在不想听，也可以直接一点嘛。",
    "温迪：v我50，今天是天使的馈赠疯狂星期四，怎么样？",
    "温迪：可以吗，可以吗可以吗？",
    "我：？",
    "温迪：欸嘿。",
    "温迪：可是，来自异乡的旅人啊，蒙德即将面临一场危机，你真的想要转身离去隔岸观火吗？",
    "派蒙：咦？这里明明很平静啊？",
    "温迪：平静只是表象，无处不在的流风却早已向我揭示了一切。",
    "温迪：守护蒙德千年的巨龙特瓦林，如今受到了深渊教团的控制。",
    "温迪：如果不及时处理掉它身上的污秽，恐怕对蒙德城来说是一场灭顶之灾。",
    "派蒙：可是，蒙德不是处在自由之神巴巴托斯的庇护之下吗？",
    "温迪：嗯，如果我没猜错的话，他可能在摸鱼吧。",
    "我：？",
    "派蒙：？",
    "温迪：等你们的好消息哦！欸嘿。",
};

const string wendi_1[10] = {
    "当你的天空突然下起了暴雨~",
    "那是我在为你炸乌云。。。",
};

const string fengqiang[10] = {
    "派蒙：危险！不要靠近！",
    "派蒙：如果击败那边的狂风之核的话，不知道有没有什么作用。",
};

const string jianbing[10] = {
    "派蒙：咦，派蒙撞不开呢，派蒙头好痛。",
    "派蒙：想想别的办法吧。",
    "派蒙：如果有深赤之石的话，或许就可以很容易地融化坚冰了吧。",
};

const string xiao[10] = {
    "魈：有杏仁豆腐吗？没有就别来扰我清净。",
};

const string shibing[10] = {
    "千岩军士兵：听说凝光大人在玉京台募集勇者，也不知道发生了什么事",
};

const string ganyu[10] = {
    "甘雨：有工作上的事吗？",
};

const string hutao[10] = {
    "胡桃：往生堂大酬宾！几位有什么需要吗？",
};

const string zhongli[10] = {
    "钟离：听戏、遛鸟，退休生活甚好。",
    "钟离：听闻今日层岩巨渊发生异象，以普遍理性而论，确实需要有人去处理。",
};

const string xianglin[10] = {
    "香菱：啊哈哈，鸡汤来咯！咦，这菜都上齐了怎么还不吃啊。",
};

const string ningguang_0[100] = {
    "凝光：旅者，我听闻过你的事迹，你是击败了蒙德地风魔龙的英雄。",
    "派蒙：嘿嘿，也没有那么厉害啦。",
    "凝光：我们现在也遇到了一点麻烦，不知你是否愿意出手相助呢？",
    "派蒙：发生甚么事了。",
    "凝光：层岩巨渊一带是璃月重地，最近，巨渊底下却有异常活动。",
    "凝光：相传岩王帝君曾与若陀龙王在巨渊之底战斗，把失控的龙王封印在了下面。",
    "凝光：如今封印似乎松动，若陀龙王或许将冲出巨渊。",
    "凝光：这种层次的大事，本该由岩王爷出面解决。",
    "凝光：可上次请仙典仪，岩王帝君却迟迟未出现，此后便再未现身。",
    "凝光：看来这次危机，或许只能靠我们凡人的力量了。",
    "派蒙：我相信旅行者一定不会袖手旁观的吧。",
};

const string ningguang_1[10] = {
    "你好。"
};

Event::Event(){
    for(int i = 0; i < 100; i++){
        certification[i] = 0;
    }
}
void Event::event_0(World& world, Role& role, int x, int y, char ch){
    if(x == 4 && y == 14){
        for(int i = 0; babala[i].length() > 0; i++){
            cout << babala[i] << endl;
            cin.get();
        }
    }
    else if(x == 15 && y == 17){
        if(certification[0] == 0){
            for(int i = 0; wendi_0[i].length() > 0; i++){
                cout << wendi_0[i] << endl;
                cin.get();
            }
            certification[0] = 1;
        }
        else{
            for(int i = 0; wendi_1[i].length() > 0; i++){
                cout << wendi_1[i] << endl;
                cin.get();
            }
        }
    }
    else if(x == 19 && y == 7){
        for(int i = 0; qin[i].length() > 0; i++){
            cout << qin[i] << endl;
            cin.get();
        }
    }
    else if(x == 21 && y == 6){
        for(int i = 0; lisha[i].length() > 0; i++){
            cout << lisha[i] << endl;
            cin.get();
        }
    }
    else if(x == 22 && y == 23){
        for(int i = 0; diluke[i].length() > 0; i++){
            cout << diluke[i] << endl;
            cin.get();
        }
    }
    else if(x == 28 && y == 9){
        if(certification[1] == 0){
            for(int i = 0; kaiselin_0[i].length() > 0; i++){
                cout << kaiselin_0[i] << endl;
                cin.get();
            }
            certification[1] = 1;
        }
        else{
            for(int i = 0; kaiselin_1[i].length() > 0; i++){
                cout << kaiselin_1[i] << endl;
                cin.get();
            }
        }
    }
    else if((x == 2 && y == 16) || (x == 12 && y == 7) || (x == 28 && y == 23) || (x == 31 && y == 4)){
        cout << "开启宝箱：" << endl;
        cout << "获得摩拉*10000，原石*1600！" << endl;
        role.items[5] += 10000;
        role.items[6] += 1600;
        world.get_map()[0].remove_a_character(x, y);
        if(ch == 'a'){
            role.set_y(role.get_y()-1);
        }
        system("pause");
    }
}
void Event::event_1(World& world, Role& role, int x, int y, char ch){
    string* current_map = world.get_map()[1].get_picture();
    if((x == 13 && y == 13)||(x == 13 && y == 14)||(x == 14 && y == 13)||(x == 14 && y == 14)){
        cout << "神像的恩泽：" << endl;
        cout << "所有角色生命值恢复！" << endl;
        system("pause");
        for(vector<Player>::iterator p = role.players.begin(); p != role.players.end(); p++){
            int hp_max = p->get_HP_upperbound();
            p->set_HP(hp_max);
        }
        int hp_max = role.current_player.get_HP_upperbound();
        role.current_player.set_HP(hp_max);
    }
    else if((x == 6 && y == 16)||(x == 9 && y == 25)||(x == 15 && y == 9)){
        Enemy qiuqiuren = enemies[0];
        int res = fight(role.current_player, qiuqiuren, role);
        if(res){
            world.get_map()[1].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 13 && y == 17){
        Enemy huoqiuqiuren = enemies[1];
        int res = fight(role.current_player, huoqiuqiuren, role);
        if(res){
            world.get_map()[1].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 19 && y == 20){
        Enemy bingqiuqiuren = enemies[2];
        int res = fight(role.current_player, bingqiuqiuren, role);
        if(res){
            world.get_map()[1].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 10 && y == 30){
        Enemy huoshilaimu = enemies[3];
        int res = fight(role.current_player, huoshilaimu, role);
        if(res){
            world.get_map()[1].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 21 && y == 15){
        Enemy shuishilaimu = enemies[5];
        int res = fight(role.current_player, shuishilaimu, role);
        if(res){
            world.get_map()[1].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 10 && y == 7){
        Enemy leishilaimu = enemies[6];
        int res = fight(role.current_player, leishilaimu, role);
        if(res){
            world.get_map()[1].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 19 && y == 22) || (x == 10 && y == 10) || (x == 7 && y == 28)){
        cout << "开启宝箱：" << endl;
        cout << "获得摩拉*10000，原石*1600！" << endl;
        role.items[5] += 10000;
        role.items[6] += 1600;
        world.get_map()[1].remove_a_character(x, y);
        if(ch == 'a'){
            role.set_y(role.get_y()-1);
        }
        system("pause");
    }
}
void Event::event_2(World& world, Role& role, int x, int y, char ch){
    string* current_map = world.get_map()[2].get_picture();
    if(x == 9 && y == 10){
        Enemy fengmolong = enemies[7];
        int res = fight(role.current_player, fengmolong, role);
        if(res){
            world.get_map()[2].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 7 && y == 19){
        Enemy fenghe = enemies[9];
        int res = fight(role.current_player, fenghe, role);
        if(res){
            world.get_map()[2].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
            world.get_map()[2].remove_a_character(5, 8);
            world.get_map()[2].remove_a_character(5, 9);
            world.get_map()[2].remove_a_character(5, 10);
            world.get_map()[2].remove_a_character(5, 11);
            world.get_map()[2].remove_a_character(5, 12);
            world.get_map()[2].remove_a_character(6, 7);
            if(ch == 's'){
                role.set_y(role.get_y()-1);
            }
            world.get_map()[2].remove_a_character(6, 13);
            if(ch == 's'){
                role.set_y(role.get_y()-1);
            }
            world.get_map()[2].remove_a_character(7, 6);
            if(ch == 'a' || ch == 'd'){
                role.set_y(role.get_y()-1);
            }
            world.get_map()[2].remove_a_character(7, 14);
            if(ch == 'a' || ch == 'd'){
                role.set_y(role.get_y()-1);
            }
            world.get_map()[2].remove_a_character(8, 6);
            if(ch == 'w'){
                role.set_y(role.get_y()-1);
            }
            world.get_map()[2].remove_a_character(8, 14);
            if(ch == 'w'){
                role.set_y(role.get_y()-1);
            }
            world.get_map()[2].remove_a_character(9, 6);
            world.get_map()[2].remove_a_character(9, 14);
            world.get_map()[2].remove_a_character(10, 6);
            world.get_map()[2].remove_a_character(10, 14);
            world.get_map()[2].remove_a_character(11, 6);
            world.get_map()[2].remove_a_character(11, 14);
            world.get_map()[2].remove_a_character(12, 7);
            world.get_map()[2].remove_a_character(12, 13);
            world.get_map()[2].remove_a_character(13, 8);
            world.get_map()[2].remove_a_character(13, 9);
            world.get_map()[2].remove_a_character(13, 10);
            world.get_map()[2].remove_a_character(13, 11);
            world.get_map()[2].remove_a_character(13, 12);
            cout << "风墙竟消散了！" << endl;
            system("pause");
        }
    }
    else if(x == 3 && y == 18){
        Enemy qiuqiuren = enemies[0];
        int res = fight(role.current_player, qiuqiuren, role);
        if(res){
            world.get_map()[2].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 11 && y == 3){
        Enemy huoqiuqiuren = enemies[1];
        int res = fight(role.current_player, huoqiuqiuren, role);
        if(res){
            world.get_map()[2].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 4 && y == 5){
        Enemy bingshilaimu = enemies[4];
        int res = fight(role.current_player, bingshilaimu, role);
        if(res){
            world.get_map()[2].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 15 && y == 17)||(x == 15 && y == 18)||(x == 16 && y == 17)||(x == 16 && y == 18)){
        Enemy yijishouwei = enemies[10];
        int res = fight(role.current_player, yijishouwei, role);
        if(res){
            world.get_map()[2].remove_a_character(15, 17);
            world.get_map()[2].remove_a_character(16, 17);
            world.get_map()[2].remove_a_character(15, 18);
            world.get_map()[2].remove_a_character(16, 18);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 1 && y == 15) || (x == 15 && y == 6)){
        cout << "开启宝箱：" << endl;
        cout << "获得摩拉*10000，原石*1600！" << endl;
        role.items[5] += 10000;
        role.items[6] += 1600;
        world.get_map()[2].remove_a_character(x, y);
        if(ch == 'a'){
            role.set_y(role.get_y()-1);
        }
        system("pause");
    }
    else if((x == 5 && y == 8)||(x == 5 && y == 9)||(x == 5 && y == 10)||(x == 5 && y == 11)||
    (x == 5 && y == 12)||(x == 6 && y == 7)||(x == 6 && y == 13)||(x == 7 && y == 6)||
    (x == 7 && y == 14)||(x == 8 && y == 6)||(x == 8 && y == 14)||(x == 9 && y == 6)||
    (x == 9 && y == 14)||(x == 10 && y == 6)||(x == 10 && y == 14)||(x == 11 && y == 6)||
    (x == 11 && y == 14)||(x == 12 && y == 7)||(x == 12 && y == 13)||(x == 13 && y == 8)||
    (x == 13 && y == 9)||(x == 13 && y == 10)||(x == 13 && y == 11)||(x == 13 && y == 12)){
        for(int i = 0; fengqiang[i].length() > 0; i++){
            cout << fengqiang[i] << endl;
        }
        system("pause");
    }
}
void Event::event_3(World& world, Role& role, int x, int y, char ch){
    string* current_map = world.get_map()[3].get_picture();
    if((x == 4 && y == 15)||(x == 10 && y == 2)||(x == 16 && y == 30)){
        Enemy bingqiuqiuren = enemies[2];
        int res = fight(role.current_player, bingqiuqiuren, role);
        if(res){
            world.get_map()[3].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 7 && y == 28)||(x == 9 && y == 14)||(x == 19 && y == 18)||(x == 12 && y == 9)){
        Enemy bingshilaimu = enemies[4];
        int res = fight(role.current_player, bingshilaimu, role);
        if(res){
            world.get_map()[3].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 19 && y == 5)||(x == 19 && y == 6)||(x == 20 && y == 5)||(x == 20 && y == 6)){
        Enemy yijishouwei = enemies[10];
        int res = fight(role.current_player, yijishouwei, role);
        if(res){
            world.get_map()[3].remove_a_character(19, 5);
            world.get_map()[3].remove_a_character(19, 6);
            world.get_map()[3].remove_a_character(20, 5);
            world.get_map()[3].remove_a_character(20, 6);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 20 && y == 34)||(x == 20 && y == 35)||(x == 21 && y == 34)||(x == 21 && y == 35)){
        Enemy yijishouwei = enemies[10];
        int res = fight(role.current_player, yijishouwei, role);
        if(res){
            world.get_map()[3].remove_a_character(20, 34);
            world.get_map()[3].remove_a_character(20, 35);
            world.get_map()[3].remove_a_character(21, 34);
            world.get_map()[3].remove_a_character(21, 35);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 8 && y == 1){
        cout << "获得了深赤之石！" << endl;
        certification[2] = 1;
        world.get_map()[3].remove_a_character(x, y);
        system("pause");
    }
    else if((x == 15 && y == 12)||(x == 16 && y == 12)){
        if(certification[2] == 0){
            for(int i = 0; jianbing[i].length() > 0; i++){
                cout << jianbing[i] << endl;
                cin.get();
            }
        }
        else{
            cout << "使用深赤之石融化了坚冰！" << endl;
            world.get_map()[3].remove_a_character(15, 12);
            world.get_map()[3].remove_a_character(16, 12);
            system("pause");
        }
    }
    else if((x == 13 && y == 19)||(x == 13 && y == 20)||(x == 14 && y == 19)||(x == 14 && y == 20)){
        Enemy wuxiangbing = enemies[12];
        int res = fight(role.current_player, wuxiangbing, role);
        if(res){
            world.get_map()[3].remove_a_character(13, 19);
            world.get_map()[3].remove_a_character(13, 20);
            world.get_map()[3].remove_a_character(14, 19);
            world.get_map()[3].remove_a_character(14, 20);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 3 && y == 26) || (x == 14 && y == 33) || (x == 18 && y == 1)){
        cout << "开启宝箱：" << endl;
        cout << "获得摩拉*10000，原石*1600！" << endl;
        role.items[5] += 10000;
        role.items[6] += 1600;
        world.get_map()[3].remove_a_character(x, y);
        if(ch == 'a'){
            role.set_y(role.get_y()-1);
        }
        system("pause");
    }
}
void Event::event_4(World& world, Role& role, int x, int y, char ch){
    if(x == 13 && y == 4){
        for(int i = 0; xiao[i].length() > 0; i++){
            cout << xiao[i] << endl;
            cin.get();
        }
    }
    else if((x == 5 && y == 13)||(x == 12 && y == 14)){
        Enemy qiuqiuren = enemies[0];
        int res = fight(role.current_player, qiuqiuren, role);
        if(res){
            world.get_map()[4].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 4 && y == 15){
        Enemy leishilaimu = enemies[6];
        int res = fight(role.current_player, leishilaimu, role);
        if(res){
            world.get_map()[4].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 17 && y == 12)){
        Enemy shoujingliequan = enemies[11];
        int res = fight(role.current_player, shoujingliequan, role);
        if(res){
            world.get_map()[4].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 9 && y == 15)){
        Enemy shuishilaimu = enemies[5];
        int res = fight(role.current_player, shuishilaimu, role);
        if(res){
            world.get_map()[4].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 10 && y == 4) || (x == 9 && y == 17)){
        cout << "开启宝箱：" << endl;
        cout << "获得摩拉*10000，原石*1600！" << endl;
        role.items[5] += 10000;
        role.items[6] += 1600;
        world.get_map()[4].remove_a_character(x, y);
        if(ch == 'a'){
            role.set_y(role.get_y()-1);
        }
        system("pause");
    }
}
void Event::event_5(World& world, Role& role, int x, int y, char ch){
    if(x == 4 && y == 14){
        for(int i = 0; shibing[i].length() > 0; i++){
            cout << shibing[i] << endl;
            cin.get();
        }
    }
    else if(x == 8 && y == 15){
        for(int i = 0; zhongli[i].length() > 0; i++){
            cout << zhongli[i] << endl;
            cin.get();
        }
    }
    else if(x == 20 && y == 5){
        if(certification[3] == 0){
            for(int i = 0; ningguang_0[i].length() > 0; i++){
                cout << ningguang_0[i] << endl;
                cin.get();
            }
            certification[3] = 1;
        }
        else{
            for(int i = 0; ningguang_1[i].length() > 0; i++){
                cout << ningguang_1[i] << endl;
                cin.get();
            }
        }
    }
    else if(x == 18 && y == 10){
        for(int i = 0; hutao[i].length() > 0; i++){
            cout << hutao[i] << endl;
            cin.get();
        }
    }
    else if(x == 12 && y == 7){
        for(int i = 0; ganyu[i].length() > 0; i++){
            cout << ganyu[i] << endl;
            cin.get();
        }
    }
    else if(x == 31 && y == 12){
        for(int i = 0; xianglin[i].length() > 0; i++){
            cout << xianglin[i] << endl;
            cin.get();
        }
    }
    else if((x == 25 && y == 10)||(x == 25 && y == 11)||(x == 26 && y == 10)||(x == 26 && y == 11)){
        cout << "神像的恩泽：" << endl;
        cout << "所有角色生命值恢复！" << endl;
        system("pause");
        for(auto it : role.players){
            int hp_max = it.get_HP_upperbound();
            it.set_HP(hp_max);
        }
    }
    else if((x == 14 && y == 30) || (x == 8 && y == 28) || (x == 16 && y == 15) || (x == 31 && y == 27)){
        cout << "开启宝箱：" << endl;
        cout << "获得摩拉*10000，原石*1600！" << endl;
        role.items[5] += 10000;
        role.items[6] += 1600;
        world.get_map()[5].remove_a_character(x, y);
        if(ch == 'a'){
            role.set_y(role.get_y()-1);
        }
        system("pause");
    }
}
void Event::event_6(World& world, Role& role, int x, int y, char ch){
    if((x == 7 && y == 13)||(x == 7 && y == 14)||(x == 8 && y == 12)||(x == 8 && y == 15)||
    (x == 9 && y == 11)||(x == 9 && y == 16)||(x == 10 && y == 11)||(x == 10 && y == 16)||
    (x == 11 && y == 12)||(x == 11 && y == 15)||(x == 12 && y == 13)||(x == 12 && y == 14)){
        if(certification[4] == 0){
            Enemy retuolongwang = enemies[8];
            int res = fight(role.current_player, retuolongwang, role);
            if(res){
                certification[4] = 1;
            }
        }
        else{
            cout << "深不见底的巨渊，如今再没有活动的痕迹。" << endl;
            system("pause");
        }
    }
    else if((x == 8 && y == 24)||(x == 15 && y == 6)||(x == 6 && y == 10)){
        Enemy shoujingliequan = enemies[11];
        int res = fight(role.current_player, shoujingliequan, role);
        if(res){
            world.get_map()[6].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 12 && y == 23){
        Enemy qiuqiuren = enemies[0];
        int res = fight(role.current_player, qiuqiuren, role);
        if(res){
            world.get_map()[6].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 1 && y == 12){
        Enemy bingqiuqiuren = enemies[2];
        int res = fight(role.current_player, bingqiuqiuren, role);
        if(res){
            world.get_map()[6].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if(x == 17 && y == 22){
        Enemy huoshilaimu = enemies[3];
        int res = fight(role.current_player, huoshilaimu, role);
        if(res){
            world.get_map()[6].remove_a_character(x, y);
            if(ch == 'a'){
                role.set_y(role.get_y()-1);
            }
        }
    }
    else if((x == 7 && y == 1) || (x == 14 && y == 25) || (x == 5 && y == 22)){
        cout << "开启宝箱：" << endl;
        cout << "获得摩拉*10000，原石*1600！" << endl;
        role.items[5] += 10000;
        role.items[6] += 1600;
        world.get_map()[6].remove_a_character(x, y);
        if(ch == 'a'){
            role.set_y(role.get_y()-1);
        }
        system("pause");
    }
}
void Event::judge_event(World& world, Role& role, int index, int x, int y, char ch){
    string* current_map = world.get_map()[index].get_picture();
    switch(index){
        case 0:
            event_0(world, role, x, y, ch);
        break;
        case 1:
            event_1(world, role, x, y, ch);
        break;
        case 2:
            event_2(world, role, x, y, ch);
        break;
        case 3:
            event_3(world, role, x, y, ch);
        break;
        case 4:
            event_4(world, role, x, y, ch);
        break;
        case 5:
            event_5(world, role, x, y, ch);
        break;
        case 6:
            event_6(world, role, x, y, ch);
        break;

    }
}