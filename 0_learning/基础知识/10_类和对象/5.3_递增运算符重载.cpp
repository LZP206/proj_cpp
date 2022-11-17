#include <iostream>
using namespace std;

//作用： 通过重载递增运算符，实现自己的整型数据
//总结： 前置递增返回引用，后置递增返回值


class MyInteger {

	friend ostream& operator<<(ostream& out, MyInteger myint);

public:
	MyInteger() {
		m_Num = 0;
	}
	
	//前置++ : 前置递增返回引用，这样可以一直对一个数据进行递增
	MyInteger& operator++() {
		//先++
		this->m_Num++;
		//再返回
		return *this;   //引用接收返回本身
	}

	//后置++ : 其中int是占位参数，用于区分前置和后置
	//这里不能返回引用，因为temp是一个局部变量
	MyInteger operator++(int) {
		//先返回
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		return temp;  
	}

private:
	int m_Num;
};

//关于这里为什么不传入引用: 问题的关键在于后置递增的情况下，重载成员函数返回temp（局部变量）值
ostream& operator<<(ostream& out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}


//前置++ 先++ 再返回 
void test01() {
	MyInteger myInt;
	cout << "前置++的结果为：" << endl;
	cout << ++(++myInt) << endl;
	cout << myInt << endl;
}


//后置++ 先返回 再++ 
void test02() {
	MyInteger myInt;
	cout << "后置++的结果为：" << endl;
	cout << myInt++  << endl;
	cout << myInt << endl;
}


int main() {

	test01();   
	test02();   

	return 0;
}