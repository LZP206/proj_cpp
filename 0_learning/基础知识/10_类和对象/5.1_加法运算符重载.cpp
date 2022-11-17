#include <iostream>
using namespace std;



// 作用：实现两个自定义数据类型相加的运算



class Person {
public:
	Person() {};
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	
	//成员函数实现 + 号运算符重载
	Person operator+(const Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}


public:
	int m_A;
	int m_B;
};


//全局函数实现 + 号运算符重载
Person operator+(const Person& p1, const Person& p2) {
	Person temp(0, 0);
	temp.m_A = p1.m_A + p2.m_A + 5;
	temp.m_B = p1.m_B + p2.m_B + 5;
	return temp;
}


//运算符重载 可以发生函数重载 
Person operator+(const Person& p2, int val)  
{
	Person temp;
	temp.m_A = p2.m_A + val;
	temp.m_B = p2.m_B + val;
	return temp;
}

void test() {

	Person p0(1, 1);
	Person p1(10, 10);
	Person p2(20, 20);

	//成员函数方式或者全局函数方式  (这里可以看到优先使用成员函数？)
	Person p3 = p2 + p1;  //相当于 p2.operaor+(p1)  或  operaor+(p2,p1)
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;

	p3 = p2 + p1 + p0;  
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;


	Person p4 = p3 + 100; //相当于 operator+(p3,10)
	cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;

	p4 = p3 + 100 + p0 + 100; //相当于 operator+(p3,10)
	cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;

}

int main() {

	test();

	return 0;
}