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
        cout << "���������ѡ��" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:   // 1.��ʼ�ݽ�����  
                _for_test_Manager.start_Speech();
                break;
            case 2:   // 2.�鿴�����¼
                _for_test_Manager.showRecord();
                break;
            case 3:   // 3.��ձ�����¼
                _for_test_Manager.clearRecord();
                break;
            case 0:   // 0.�˳���������
                _for_test_Manager.exit_Manager();
                break;
            default:
                cout <<  "������ѡ�� ~ ~" << endl;
                break;
        }
    }

    return 0;
}