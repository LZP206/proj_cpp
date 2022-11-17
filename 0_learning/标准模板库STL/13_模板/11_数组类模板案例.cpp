#include <iostream>
using namespace std;
#include "MyArray.hpp"


// --------------------------------------------------------------------------------------------------
//测试内置数据类型


void printIntArray(MyArray<int> & input_arr)   // 不能加const！！  原因：传入为const常对象，常对象只能调用常函数
{
    for (int i = 0; i < input_arr.getArrSize(); i++)
    {
        cout << input_arr[i] << endl;
    }
}

void test01()
{
    MyArray<int> arr1(10);
    for (int i = 0; i < 10; i++)
    {
        arr1.push_Back(i);
    }
    printIntArray(arr1);
    cout << "Capacity: " << arr1.getArrCapacity() << "  Size: "  << arr1.getArrSize() << endl;
    
    cout << "----------------------------" << endl;

    MyArray<int> arr2(arr1);
    arr2.pop_Back();
    printIntArray(arr2);
    cout << "Capacity: " << arr2.getArrCapacity() << "  Size: "  << arr2.getArrSize() << endl;

    cout << "----------------------------" << endl;

    MyArray<int> arr3(1);
    cout << "Capacity: " << arr3.getArrCapacity() << "  Size: "  << arr3.getArrSize() << endl;
    arr3 = arr1;
    cout << "Capacity: " << arr3.getArrCapacity() << "  Size: "  << arr3.getArrSize() << endl;
}



// --------------------------------------------------------------------------------------------------
//测试自定义数据类型


class Person {
public:
	Person() {} 
	Person(string name, int age) 
    {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};


void printPersonArray(MyArray<Person> & input_arr)
{
    for (int i = 0; i < input_arr.getArrSize(); i++)
    {
        cout << "Name: " << input_arr[i].m_Name << "  Age: " << input_arr[i].m_Age << endl;
    }   
}


void test02()
{
    MyArray<Person> arr1(10);
    Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
    arr1.push_Back(p1);
    arr1.push_Back(p2);
    arr1.push_Back(p3);
    printPersonArray(arr1);
    cout << "Capacity: " << arr1.getArrCapacity() << "  Size: "  << arr1.getArrSize() << endl;
    
}







// --------------------------------------------------------------------------------------------------

int main()
{
    test01();

    system("pause");
    return 0;
}