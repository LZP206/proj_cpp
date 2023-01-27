#include "speechManager.h"

speechManager::speechManager()
{
    this->init_Speech();    // 第一步：初始化属性
    this->create_Speaker(); // 第二步：创建12名选手
    this->loadRecord();     // 第三步：获取往届记录
}

speechManager::~speechManager()
{
}


// ------------------------------ 初始化属性 ------------------------------
void speechManager::init_Speech()
{
    // 容器保证为空
    this->v_round01.clear();
    this->v_round02.clear();
    this->v_final.clear();
    this->m_Speaker.clear();
    // 初始化比赛轮数
    this->m_Index = 1;
    // 初始化记录容器
    this->m_Record.clear();
}


// ------------------------------ 创建12名选手 ------------------------------
void speechManager::create_Speaker()
{
    string nameseed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameseed.size(); i++)
    {
        string name_temp = "选手";
        name_temp += nameseed[i];
        Speaker speaker_temp;
        speaker_temp.m_Name = name_temp;
        for (int Index = 0; Index < 2; Index++){speaker_temp.m_Score[Index] = 0;}

        this->v_round01.push_back(10001 + i);
        this->m_Speaker.insert(make_pair( 10001 + i , speaker_temp));
    }
}



// ------------------------------ 1.开始演讲比赛 ------------------------------
void speechManager::start_Speech()
{
    srand((unsigned int)time(NULL));
    // 第一轮比赛
    this->start_Speech_Draw();   // 1.抽签
    this->start_Speech_Contest();// 2.打分排名
    this->show_Score();          // 3.显示晋级结果

    cout << "按任意键后回车继续...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");

    // 第二轮比赛
    this->m_Index++;
    this->start_Speech_Draw();   // 1.抽签
    this->start_Speech_Contest();// 2.打分排名
    this->show_Score();          // 3.显示晋级结果
    this->saveRecord();          // 4.保存分数
    cout << "记录以保存，本届比赛结束！" << endl;

    // 重置比赛
    this->init_Speech();
    this->create_Speaker();
    this->loadRecord();

    cout << "按任意键后回车继续...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}



// ------------------------------ 抽签 ------------------------------
void speechManager::start_Speech_Draw()
{
    cout << "开始第" << this->m_Index << "轮比赛抽签" << endl;
    cout << "------------------------------------------" << endl;
    cout << "第" << this->m_Index << "轮比赛抽签结果如下：" << endl;
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




// ------------------------------ 打分排名 ------------------------------
void speechManager::start_Speech_Contest()
{
    cout << "开\n始\n打\n分\n.\n.\n.\n" << endl;
    vector<int> v_temp;
    if (this->m_Index == 1){v_temp = v_round01;}
    else{v_temp = v_round02;}
    
    int num = 0; // 记录人数
    multimap<double,int,greater<double> > ranker_temp;  // 按照打分降序排列
    for (vector<int>::iterator it = v_temp.begin(); it !=v_temp.end(); it++)
    {
        num++;
        deque<double> d_Score;
        for (int i = 0; i < 10; i++)   // 1.遍历10个评委对每一个选手打分
        {
            double score_temp = ( rand()%501 + 500 ) / 10.0;  // 500 ~ 1000
            d_Score.push_back(score_temp);
        }
        sort(d_Score.begin(),d_Score.end(),greater<double>());
        d_Score.pop_front(); d_Score.pop_back();   // 2.去掉一个最高分一个最低分
        double sum = accumulate(d_Score.begin(),d_Score.end(),0.0);
        double avg = sum / d_Score.size();         // 3.取平均值作为最终打分
        ranker_temp.insert(make_pair(avg, *it));   // 4.存入临时容器
        this->m_Speaker[*it].m_Score[this->m_Index -1] = avg;

        if (num % 6 == 0)
        {
            cout<< "第" << this->m_Index << "轮比赛" << "第" << num / 6 << "小组名次" << endl;
            cout << "------------------------------------------" << endl;
            for (multimap<double,int,greater<double> >::iterator it2 = ranker_temp.begin(); it2 != ranker_temp.end(); it2++)
            {
                cout << " 编号： " << it2->second << " 姓名： " << this->m_Speaker[it2->second].m_Name 
                     << " 成绩： " << this->m_Speaker[it2->second].m_Score[this->m_Index - 1] << endl;
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




// ------------------------------ 显示晋级结果 ------------------------------
void speechManager::show_Score()
{
    cout << "第" << this->m_Index << "轮晋级选手信息如下" << endl;
    cout << "------------------------------------------" << endl;
    if (this->m_Index == 1)
    {
        for (vector<int>::iterator it = v_round02.begin(); it != v_round02.end(); it++)
        {
            cout << " 编号： " << *it << " 姓名： " << this->m_Speaker[*it].m_Name 
                 << " 成绩： " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
        }
    }
    else
    {
        for (vector<int>::iterator it = v_final.begin(); it != v_final.end(); it++)
        {
            cout << " 编号： " << *it << " 姓名： " << this->m_Speaker[*it].m_Name 
                 << " 成绩： " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
        }
    }
    cout << "------------------------------------------" << endl;
    cout << endl;
}




// ------------------------------ 保存结果 ------------------------------
void speechManager::saveRecord()
{
    ofstream record_output;
    record_output.open("speech.csv", ios::out | ios::app); // 以追加方式写文件

    for (vector<int>::iterator it = v_final.begin(); it != v_final.end(); it++)
    {
        record_output << *it << "," << m_Speaker[*it].m_Score[1] << ",";
    }
    record_output << endl;

    record_output.close();
    cout << "记录已经保存" << endl;
    this->fileIsEmpty = false;
}




// ------------------------------ 加载往届记录 ------------------------------
void speechManager::loadRecord()
{
    ifstream record_input;
    record_input.open("speech.csv", ios::in);
    if (!record_input.is_open())
    {
        this->fileIsEmpty = true;
        cout << "文件不存在！" << endl;
        record_input.close();
        return;
    }
    char temp_ch;
    record_input >> temp_ch;
    if (record_input.eof())
    {
        this->fileIsEmpty = true;
        cout << "文件为空！" << endl;
        record_input.close();
        return;
    }

    this->fileIsEmpty = false;
    record_input.putback(temp_ch); //读取的单个字符放回去

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
            pos = data.find(",", start); //从0开始查找 ','
            if (pos == -1){break;}
            string tmp = data.substr(start, pos - start); //找到了,进行分割 参数1 起始位置，参数2 截取长度
            vec.push_back(tmp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, vec));
        index++;
    }
    record_input.close();
}




// ------------------------------ 2.显示往届记录 ------------------------------
void speechManager::showRecord()
{
    if (this->fileIsEmpty)
    {
        cout << "文件不存在或文件为空！" << endl;
    }
    for (int i = 0; i < this->m_Record.size(); i++)
    {
        cout << "第" << i + 1 << "届 " <<
        "冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
        "亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
        "季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
    }
    cout << "按任意键后回车继续...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}



// ------------------------------ 3.清空往届记录 ------------------------------
void speechManager::clearRecord()
{
    cout << "确认清空？" << endl;
    cout << "1.确认" << endl;
    cout << "2.返回" << endl;
    int select = 0;
    cin >> select;
    if (select == 1)
    {
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        this->init_Speech();
        this->create_Speaker();
        this->loadRecord();
        cout << "清空成功！" << endl;

        cout << "按任意键后回车继续...";
        cin.ignore(1024, '\n'); cin.get();
    }
    system("clear");
}












// ------------------------------ 显示功能选项 ------------------------------
void speechManager::show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*************  欢迎参加演讲比赛 ************" << endl;
    cout << "*************  1.开始演讲比赛  *************" << endl;
    cout << "*************  2.查看往届记录  *************" << endl;
    cout << "*************  3.清空比赛记录  *************" << endl;
    cout << "*************  0.退出比赛程序  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

// ------------------------------ 功能 0.退出比赛程序 ------------------------------
void speechManager::exit_Manager()
{
    cout << "欢迎下次使用 ~ ~" << endl;
    exit(0);
}

