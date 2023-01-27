#include "speechManager.h"

speechManager::speechManager()
{
    this->init_Speech();    // ��һ������ʼ������
    this->create_Speaker(); // �ڶ���������12��ѡ��
    this->loadRecord();     // ����������ȡ�����¼
}

speechManager::~speechManager()
{
}


// ------------------------------ ��ʼ������ ------------------------------
void speechManager::init_Speech()
{
    // ������֤Ϊ��
    this->v_round01.clear();
    this->v_round02.clear();
    this->v_final.clear();
    this->m_Speaker.clear();
    // ��ʼ����������
    this->m_Index = 1;
    // ��ʼ����¼����
    this->m_Record.clear();
}


// ------------------------------ ����12��ѡ�� ------------------------------
void speechManager::create_Speaker()
{
    string nameseed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameseed.size(); i++)
    {
        string name_temp = "ѡ��";
        name_temp += nameseed[i];
        Speaker speaker_temp;
        speaker_temp.m_Name = name_temp;
        for (int Index = 0; Index < 2; Index++){speaker_temp.m_Score[Index] = 0;}

        this->v_round01.push_back(10001 + i);
        this->m_Speaker.insert(make_pair( 10001 + i , speaker_temp));
    }
}



// ------------------------------ 1.��ʼ�ݽ����� ------------------------------
void speechManager::start_Speech()
{
    srand((unsigned int)time(NULL));
    // ��һ�ֱ���
    this->start_Speech_Draw();   // 1.��ǩ
    this->start_Speech_Contest();// 2.�������
    this->show_Score();          // 3.��ʾ�������

    cout << "���������س�����...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");

    // �ڶ��ֱ���
    this->m_Index++;
    this->start_Speech_Draw();   // 1.��ǩ
    this->start_Speech_Contest();// 2.�������
    this->show_Score();          // 3.��ʾ�������
    this->saveRecord();          // 4.�������
    cout << "��¼�Ա��棬�������������" << endl;

    // ���ñ���
    this->init_Speech();
    this->create_Speaker();
    this->loadRecord();

    cout << "���������س�����...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}



// ------------------------------ ��ǩ ------------------------------
void speechManager::start_Speech_Draw()
{
    cout << "��ʼ��" << this->m_Index << "�ֱ�����ǩ" << endl;
    cout << "------------------------------------------" << endl;
    cout << "��" << this->m_Index << "�ֱ�����ǩ������£�" << endl;
    if (this->m_Index == 1)
    {
        random_shuffle(this->v_round01.begin(),this->v_round01.end());
        for (vector<int>::iterator it = this->v_round01.begin(); it != this->v_round01.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(this->v_round02.begin(),this->v_round02.end());
        for (vector<int>::iterator it = this->v_round02.begin(); it != this->v_round02.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------------" << endl;
    cout << endl;
}




// ------------------------------ ������� ------------------------------
void speechManager::start_Speech_Contest()
{
    cout << "��\nʼ\n��\n��\n.\n.\n.\n" << endl;
    vector<int> v_temp;
    if (this->m_Index == 1){v_temp = v_round01;}
    else{v_temp = v_round02;}
    
    int num = 0; // ��¼����
    multimap<double,int,greater<double> > ranker_temp;  // ���մ�ֽ�������
    for (vector<int>::iterator it = v_temp.begin(); it !=v_temp.end(); it++)
    {
        num++;
        deque<double> d_Score;
        for (int i = 0; i < 10; i++)   // 1.����10����ί��ÿһ��ѡ�ִ��
        {
            double score_temp = ( rand()%501 + 500 ) / 10.0;  // 500 ~ 1000
            d_Score.push_back(score_temp);
        }
        sort(d_Score.begin(),d_Score.end(),greater<double>());
        d_Score.pop_front(); d_Score.pop_back();   // 2.ȥ��һ����߷�һ����ͷ�
        double sum = accumulate(d_Score.begin(),d_Score.end(),0.0);
        double avg = sum / d_Score.size();         // 3.ȡƽ��ֵ��Ϊ���մ��
        ranker_temp.insert(make_pair(avg, *it));   // 4.������ʱ����
        this->m_Speaker[*it].m_Score[this->m_Index -1] = avg;

        if (num % 6 == 0)
        {
            cout<< "��" << this->m_Index << "�ֱ���" << "��" << num / 6 << "С������" << endl;
            cout << "------------------------------------------" << endl;
            for (multimap<double,int,greater<double> >::iterator it2 = ranker_temp.begin(); it2 != ranker_temp.end(); it2++)
            {
                cout << " ��ţ� " << it2->second << " ������ " << this->m_Speaker[it2->second].m_Name 
                     << " �ɼ��� " << this->m_Speaker[it2->second].m_Score[this->m_Index - 1] << endl;
            }
            cout << "------------------------------------------" << endl;
            int count = 0;
            for (multimap<double,int,greater<double> >::iterator it2 = ranker_temp.begin(); it2 != ranker_temp.end() && count < 3; it2++, count++)
            {
                if (this->m_Index == 1) {v_round02.push_back((*it2).second);}
                else {v_final.push_back((*it2).second);}
            }
            ranker_temp.clear();
        }
    }
    cout << endl;
}




// ------------------------------ ��ʾ������� ------------------------------
void speechManager::show_Score()
{
    cout << "��" << this->m_Index << "�ֽ���ѡ����Ϣ����" << endl;
    cout << "------------------------------------------" << endl;
    if (this->m_Index == 1)
    {
        for (vector<int>::iterator it = v_round02.begin(); it != v_round02.end(); it++)
        {
            cout << " ��ţ� " << *it << " ������ " << this->m_Speaker[*it].m_Name 
                 << " �ɼ��� " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
        }
    }
    else
    {
        for (vector<int>::iterator it = v_final.begin(); it != v_final.end(); it++)
        {
            cout << " ��ţ� " << *it << " ������ " << this->m_Speaker[*it].m_Name 
                 << " �ɼ��� " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
        }
    }
    cout << "------------------------------------------" << endl;
    cout << endl;
}




// ------------------------------ ������ ------------------------------
void speechManager::saveRecord()
{
    ofstream record_output;
    record_output.open("speech.csv", ios::out | ios::app); // ��׷�ӷ�ʽд�ļ�

    for (vector<int>::iterator it = v_final.begin(); it != v_final.end(); it++)
    {
        record_output << *it << "," << m_Speaker[*it].m_Score[1] << ",";
    }
    record_output << endl;

    record_output.close();
    cout << "��¼�Ѿ�����" << endl;
    this->fileIsEmpty = false;
}




// ------------------------------ ���������¼ ------------------------------
void speechManager::loadRecord()
{
    ifstream record_input;
    record_input.open("speech.csv", ios::in);
    if (!record_input.is_open())
    {
        this->fileIsEmpty = true;
        cout << "�ļ������ڣ�" << endl;
        record_input.close();
        return;
    }
    char temp_ch;
    record_input >> temp_ch;
    if (record_input.eof())
    {
        this->fileIsEmpty = true;
        cout << "�ļ�Ϊ�գ�" << endl;
        record_input.close();
        return;
    }

    this->fileIsEmpty = false;
    record_input.putback(temp_ch); //��ȡ�ĵ����ַ��Ż�ȥ

    string data;
    int index = 0;
    while (record_input >> data)
    {
        // cout << data << endl;
        vector<string> vec;
        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start); //��0��ʼ���� ','
            if (pos == -1){break;}
            string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
            vec.push_back(tmp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, vec));
        index++;
    }
    record_input.close();
}




// ------------------------------ 2.��ʾ�����¼ ------------------------------
void speechManager::showRecord()
{
    if (this->fileIsEmpty)
    {
        cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
    }
    for (int i = 0; i < this->m_Record.size(); i++)
    {
        cout << "��" << i + 1 << "�� " <<
        "�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
        "�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
        "������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
    }
    cout << "���������س�����...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}



// ------------------------------ 3.��������¼ ------------------------------
void speechManager::clearRecord()
{
    cout << "ȷ����գ�" << endl;
    cout << "1.ȷ��" << endl;
    cout << "2.����" << endl;
    int select = 0;
    cin >> select;
    if (select == 1)
    {
        //��ģʽ ios::trunc �������ɾ���ļ������´���
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        this->init_Speech();
        this->create_Speaker();
        this->loadRecord();
        cout << "��ճɹ���" << endl;

        cout << "���������س�����...";
        cin.ignore(1024, '\n'); cin.get();
    }
    system("clear");
}












// ------------------------------ ��ʾ����ѡ�� ------------------------------
void speechManager::show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
    cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
    cout << "*************  2.�鿴�����¼  *************" << endl;
    cout << "*************  3.��ձ�����¼  *************" << endl;
    cout << "*************  0.�˳���������  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

// ------------------------------ ���� 0.�˳��������� ------------------------------
void speechManager::exit_Manager()
{
    cout << "��ӭ�´�ʹ�� ~ ~" << endl;
    exit(0);
}

