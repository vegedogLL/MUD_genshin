#ifndef _MAP_H_
#define _MAP_H_

#include<iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

class Map{
    private:
    int index;//地图编号
    string name;//地图名称
    string picture[100];//地图的画面本身
    bool found;//该地图是否被开辟
    public:
    string* get_picture();//返回地图图像数组
    string get_map_name();//返回地图名称
    bool get_found();//返回地图是否被开辟
    void remove_a_character(int x, int y);//删除一个汉字
    Map(int i);
    ~Map();
};

class World{
    private:
    Map *maps;
    int map_num;//地图数量
    public:
    void show_map();
    int get_adjacent(int a, int b);//输入两个地图编号，返回是否邻接 1或0
    Map* get_map();//返回成员maps
    World();
    ~World();
};

#endif