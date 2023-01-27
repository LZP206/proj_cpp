#include <iostream>
using namespace std;
#include "speechManager.h"



int main()
{
    speechManager _for_test_Manager;
    int choice = 0;
    while (true)
    {
        _for_test_Manager.show_Menu();
        cout << "请输入你的选择：" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:   // 1.开始演讲比赛  
                _for_test_Manager.start_Speech();
                break;
            case 2:   // 2.查看往届记录
                _for_test_Manager.showRecord();
                break;
            case 3:   // 3.清空比赛记录
                _for_test_Manager.clearRecord();
                break;
            case 0:   // 0.退出比赛程序
                _for_test_Manager.exit_Manager();
                break;
            default:
                cout <<  "请重新选择 ~ ~" << endl;
                break;
        }
    }

    return 0;
}