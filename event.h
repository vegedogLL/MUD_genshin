#ifndef _EVENT_H_
#define _EVENT_H_
#include <string>
#include "map.h"
#include "Role.h"
#include "Fight.h"
#include "source.h"
#include <vector>
using namespace std;
extern const string start[100];
class Event{
    private:
    int certification[100];
    public:
    void judge_event(World& world, Role& role, int index, int x, int show_y, char ch);
    void event_0(World& world, Role& role, int x, int show_y, char ch);
    void event_1(World& world, Role& role, int x, int show_y, char ch);
    void event_2(World& world, Role& role, int x, int show_y, char ch);
    void event_3(World& world, Role& role, int x, int show_y, char ch);
    void event_4(World& world, Role& role, int x, int show_y, char ch);
    void event_5(World& world, Role& role, int x, int show_y, char ch);
    void event_6(World& world, Role& role, int x, int show_y, char ch);
    Event();
};
#endif
//certification
//[0] 0: wendi_0, 1: wendi_1
//[1] 0: kaiselin_0, 1: kaiselin_1
//[2] 深赤之石
//[3] 0: ningguang_0, 1: ningguang_1
//[4] 打败若陀龙王