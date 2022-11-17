#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "Worker.h"
#include "Boss.h"
#include "Manager.h"
#include "Employee.h"
#define Filename "wokerInfo"


class workerManager
{
public:
    workerManager();
    ~workerManager();

    void Show_Menu();         //显示菜单
    void exitSystem();        //0-退出管理程序
    void addWorker();         //1-增加职工信息
	void show_WorkerInfo();   //2-显示职工信息
    void delete_WorkerInfo(); //3-删除离职职工
    void modify_WorkerInfo(); //4-修改职工信息
    void find_WorkerInfo();   //5-查找职工信息
	void sort_WorkerInfo();   //6-按照编号排序
    void clearInfo();         //7-清空所有文档

    void saveInfo();            //写文件-保存信息
    int getInfo_workerNum();    //读文件-读取人数
    void initial_workerArray(); //读文件-初始化数组
    int DeptNametoID(string temp_DeptName);//读文件-根据部门名称对应部门代码
    int isexist_ID(int input_ID);//根据员工编号判断是否已存在范围数组索引值

    int m_workerNum;
    Worker ** m_workerArray;
    bool m_FileisEmpty;
};


