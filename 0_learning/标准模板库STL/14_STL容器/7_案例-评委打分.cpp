#include <iostream>
using namespace std;

#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>

/*
* 案例描述
* 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

* 实现步骤
* 1. 创建五名选手，放到vector中
* 2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
* 3. sort算法对deque容器中分数排序，去除最高和最低分
* 4. deque容器遍历一遍，累加总分
* 5. 获取平均分
*/

class Person
{
    public:
    Person(string name, int score_ave)
    {
        this->m_Name = name;
        this->m_Score_ave = score_ave;
    }

    public:
    string m_Name;
    int m_Score_ave;
};



// --------------------- 创建选手 ----------------------
void createPerson(vector<Person> & input_array)
{
    string nameseed = "ABCDE";
    for (int i = 0; i < nameseed.size(); i++)
    {
        string name = "选手";
        name += nameseed[i];

        int score_init = 0;
        Person person_temp(name, score_init);

        input_array.push_back(person_temp);
    }
    // cout << "--------------" << endl;
    // cout << input_array.size() <<endl;        // 5
    // cout << input_array.capacity() << endl;   // 8
}



// --------------------- 给选手打分 ----------------------
void setScore(vector<Person> & input_array)
{
    for (vector<Person>::iterator it = input_array.begin(); it != input_array.end(); it++)
    {
        deque<int> _set_score_array;
        for (int i = 0; i < 10; i++)
        {
            int _temp_score = rand() % 41 + 60;
            _set_score_array.push_back(_temp_score);
        }

        sort(_set_score_array.begin(),_set_score_array.end());
        _set_score_array.pop_front();
        _set_score_array.pop_back();

        int sum_score = 0;
        for (deque<int>::iterator dit = _set_score_array.begin(); dit != _set_score_array.end(); dit++)
		{
			sum_score += *dit; 
		}

		int avg_score = sum_score / _set_score_array.size();
		it->m_Score_ave = avg_score;
    }
}



// --------------------- 显示最后得分 ----------------------
void showScore(vector<Person>& input_array)
{
	for (vector<Person>::iterator it = input_array.begin(); it != input_array.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "\t平均分：" << it->m_Score_ave << endl;
	}
}





// --------------------- main() ----------------------
int main()
{
    vector<Person> person_array;
    createPerson(person_array);
    // 测试
	// for (vector<Person>::iterator it = person_array.begin(); it != person_array.end(); it++)
	// {
	// 	cout << "姓名： " << it->m_Name << " 分数： " << it->m_Score_ave << endl;
	// }

	srand((unsigned int)time(NULL));
    setScore(person_array);

    showScore(person_array);

    return 0;
}