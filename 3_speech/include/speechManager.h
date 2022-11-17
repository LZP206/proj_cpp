#pragma once
#include <iostream>
using namespace std;
#include "Speaker.h"
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>


class speechManager
{
public:
    speechManager();
    ~speechManager();

    void show_Menu();     // 显示功能选项
    void exit_Manager();  // 功能 0.退出比赛程序

    void init_Speech();   // 初始化属性
    void create_Speaker();// 创建选手
    void loadRecord();    // 加载往届记录

    void start_Speech();            // 功能 1.开始演讲比赛
    void start_Speech_Draw();       // 抽签
    void start_Speech_Contest();    // 打分
    void show_Score();              // 结果
    void saveRecord();              // 保存结果
    void showRecord();              // 功能 2.显示往届记录
    void clearRecord();             // 功能 3.清空比赛记录


    vector<int> v_round01;       // 第一轮12人的编号
    vector<int> v_round02;       // 第二轮6人的编号
    vector<int> v_final;         // 最终获奖3人的编号
    map<int,Speaker> m_Speaker;  // 存放编号以及对应的具体选手
    int m_Index;                 // 记录当前比赛轮数
    bool fileIsEmpty;            // 文件为空的标志
    map<int, vector<string> > m_Record;// 往届记录
};


