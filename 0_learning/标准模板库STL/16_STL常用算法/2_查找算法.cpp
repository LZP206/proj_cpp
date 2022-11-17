/*
常用查找算法：           
-find(iterator beg, iterator end, value); 
    - 按值查找元素，找到返回第一次出现的位置迭代器，找不到返回结束迭代器位置end()
    - beg 开始迭代器
    - end 结束迭代器
    - value 查找的元素

- find_if(iterator beg, iterator end, _Pred);  
    - 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    - beg 开始迭代器
    - end 结束迭代器
    - _Pred 函数或者谓词（返回bool类型的仿函数）

- adjacent_find(iterator beg, iterator end);  
    - 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
    - beg 开始迭代器
    - end 结束迭代器

- bool binary_search(iterator beg, iterator end, value);  
    - 查找指定的元素，查到返回true,否则false
    - 注意: 在**无序序列中不可用**
    - beg 开始迭代器
    - end 结束迭代器
    - value 查找的元素

- count(iterator beg, iterator end, value);  
    - 统计元素出现次数
    - beg 开始迭代器
    - end 结束迭代器
    - value 统计的元素

- count_if(iterator beg, iterator end, _Pred);  
    - 按条件统计元素出现次数
    - beg 开始迭代器
    - end 结束迭代器
    - _Pred 谓词
*/




#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>


class Person
{
    public:
    Person(string NAME_IN, int AGE_IN)
    {
        this->m_Name = NAME_IN;
        this->m_Age = AGE_IN;
    }
    bool operator==(const Person & PERSON_IN)
    {
        if (this->m_Age == PERSON_IN.m_Age && this->m_Name == PERSON_IN.m_Name){
            return true;
        }
        return false;
    }

    string m_Name;
    int m_Age;
};


// 重载<<需要全局函数来实现
ostream& operator<<(ostream & DATA,Person & PERSON_IN)
{
    DATA << "Name is " << PERSON_IN.m_Name << "\tAge is " << PERSON_IN.m_Age;
    return DATA;
}





//---------------------------------------------------------------------------
// 1.find
void test01()
{   
    // 内置数据类型
    vector<int> VEC_TEST;
    for (int i = 0; i < 10; i++){VEC_TEST.push_back(i+1);}
    vector<int>::iterator it = find(VEC_TEST.begin(),VEC_TEST.end(),5);
    if (it == VEC_TEST.end()){
        cout << "element not found" << endl;
    }
    else{
        cout << "element found is " << *it << endl;
    }

    cout << "----------------------------" << endl;

    // 自定义数据类型(find需要比较元素是否相等，因此需重载==)
    vector<Person> VEC_PERSON;
    VEC_PERSON.push_back(Person("aaa",10));
    VEC_PERSON.push_back(Person("bbb",20));
    VEC_PERSON.push_back(Person("ccc",30));
    VEC_PERSON.push_back(Person("ddd",40));
    Person TAGET = Person("bbb",20);
    vector<Person>::iterator it_Person = find(VEC_PERSON.begin(),VEC_PERSON.end(),TAGET);
    if (it_Person == VEC_PERSON.end()){
        cout << "element not found" << endl;
    }
    else{
        cout << "element found: " << *it_Person << endl;
    }
}



//---------------------------------------------------------------------------
// 2.find_if
class is_Greater_than_Five
{
    public:
    bool operator()(const int & VAL_COMPARE){
        return VAL_COMPARE > 5;
    }
};
class is_Age_Greater20
{
    public:
    bool operator()(const Person & PER_COMPARE){
        return PER_COMPARE.m_Age > 20;
    }
};

void test02()
{
    // 内置数据类型
    vector<int> VEC_INT;
    for (int i = 0; i < 10; i++){VEC_INT.push_back(i);}
    vector<int>::iterator it = find_if(VEC_INT.begin(),VEC_INT.end(),is_Greater_than_Five());
    if (it == VEC_INT.end()){
        cout << "element not found" << endl;
    }
    else{
        cout << "element found: " << *it << endl;
    }

    cout << "----------------------------" << endl;

    // 自定义数据类型
    vector<Person> VEC_PERSON;
    VEC_PERSON.push_back(Person("aaa",10));
    VEC_PERSON.push_back(Person("bbb",20));
    VEC_PERSON.push_back(Person("ccc",30));
    VEC_PERSON.push_back(Person("ddd",40));
    vector<Person>::iterator it_Person = find_if(VEC_PERSON.begin(),VEC_PERSON.end(),is_Age_Greater20());
    if (it_Person == VEC_PERSON.end()){
        cout << "element not found" << endl;
    }
    else{
        while (it_Person != VEC_PERSON.end()){
            cout << "element found: " << *it_Person << endl;
            it_Person++;
        }
    }
}




//---------------------------------------------------------------------------
// 3.adjacent_find 
class is_Age_Adjacent
{
    public:
    bool operator()(const Person& p1, const Person& p2)
    {
        return p1.m_Age == p2.m_Age;
    }
};

void test03()
{
    // 内置数据类型
	vector<int> VEC_INT;
	VEC_INT.push_back(1);
	VEC_INT.push_back(2);
	VEC_INT.push_back(5);
	VEC_INT.push_back(2);
	VEC_INT.push_back(4);
	VEC_INT.push_back(4);
	VEC_INT.push_back(3);

	//查找相邻重复元素
	vector<int>::iterator it = adjacent_find(VEC_INT.begin(), VEC_INT.end());
	if (it == VEC_INT.end()) {
		cout << "element not found" << endl;
	}
	else {
		cout << "element found: " << *it << endl;
	}

    cout << "----------------------------" << endl;

    // 自定义数据类型
    vector<Person> VEC_PERSON;
    VEC_PERSON.push_back(Person("aaa",10));
    VEC_PERSON.push_back(Person("bbb",20));
    VEC_PERSON.push_back(Person("ccc",20));
    VEC_PERSON.push_back(Person("ddd",40));
    vector<Person>::iterator it_Person = adjacent_find(VEC_PERSON.begin(),VEC_PERSON.end(),is_Age_Adjacent());
    if (it_Person == VEC_PERSON.end()) {
		cout << "element not found" << endl;
	}
	else {
		cout << "element found: " << *it_Person << endl;
	}
}





//---------------------------------------------------------------------------
// 4.binary_search
bool operator<(const Person & PERSON_IN1,const Person & PERSON_IN2)
{
    return PERSON_IN1.m_Age < PERSON_IN2.m_Age;
}
class Binary_Compare
{
    public:
    bool operator()(const Person & VAL_COM,const Person & INTERATOR)
    {
        return VAL_COM.m_Age < INTERATOR.m_Age;
    }
};

void test04()
{
    // 内置数据类型
	vector<int> VEC_INT;
	for (int i = 0; i < 10; i++){VEC_INT.push_back(i);}
	bool ret = binary_search(VEC_INT.begin(), VEC_INT.end(),2);
	if (ret){
		cout << "element is found" << endl;
	}
	else{
		cout << "element not found" << endl;
	}

    cout << "----------------------------" << endl;

    // 自定义数据类型 
    // binary_search本质上判断 输入数据<*iterator？ 因此需重载 < 关系符
    vector<Person> VEC_PERSON;
    VEC_PERSON.push_back(Person("aaa",10));
    VEC_PERSON.push_back(Person("bbb",20));
    VEC_PERSON.push_back(Person("ccc",20));
    VEC_PERSON.push_back(Person("ddd",40));
    Person TAGET = Person("eee",20);

    // 方法一：重载 operator<
    // ret = binary_search(VEC_PERSON.begin(),VEC_PERSON.end(),TAGET);

    // 方法二：自定义比较函数
    ret = binary_search(VEC_PERSON.begin(),VEC_PERSON.end(),TAGET,Binary_Compare());
    if (ret){
		cout << "element is found" << endl;
	}
	else{
		cout << "element not found" << endl;
	}
}







//---------------------------------------------------------------------------
// 5.count
void test05()
{
    // 内置数据类型
	vector<int> VEC_INT;
	VEC_INT.push_back(1);
	VEC_INT.push_back(2);
	VEC_INT.push_back(4);
	VEC_INT.push_back(5);
	VEC_INT.push_back(3);
	VEC_INT.push_back(4);
	VEC_INT.push_back(4);

	int num = count(VEC_INT.begin(), VEC_INT.end(), 4);
	cout << "the number of 4: " << num << endl;

    cout << "----------------------------" << endl;

    // 自定义数据类型 (需要重载==运算符)
    vector<Person> VEC_PER;
    Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);
	VEC_PER.push_back(p1);
	VEC_PER.push_back(p2);
	VEC_PER.push_back(p3);
	VEC_PER.push_back(p4);
	VEC_PER.push_back(p5);
    
    Person p_target("张飞",35);
	int num2 = count(VEC_PER.begin(), VEC_PER.end(), p_target);
	cout << "number = " << num2 << endl;
}






//---------------------------------------------------------------------------
// 6.count_if
class Greater4
{
    public:
	bool operator()(int val){return val >= 4;}
};
class AgeLess35
{
    public:
	bool operator()(const Person &p){return p.m_Age < 35;}
};


void test06()
{
    vector<int> VEC_int;
	VEC_int.push_back(1);
	VEC_int.push_back(2);
	VEC_int.push_back(4);
	VEC_int.push_back(5);
	VEC_int.push_back(3);
	VEC_int.push_back(4);
	VEC_int.push_back(4);

	int num_int = count_if(VEC_int.begin(), VEC_int.end(), Greater4());
	cout << "the number >= 4: " << num_int << endl;

    cout << "----------------------------" << endl;

    vector<Person> VEC_Person;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);

	VEC_Person.push_back(p1);
	VEC_Person.push_back(p2);
	VEC_Person.push_back(p3);
	VEC_Person.push_back(p4);
	VEC_Person.push_back(p5);

	int num_Person = count_if(VEC_Person.begin(), VEC_Person.end(), AgeLess35());
	cout << "the number of age < 35: " << num_Person << endl;
}








//---------------------------------------------------------------------------
int main()
{
    test06();
    system("pause");
    return 0;
}