#pragma once
#include <iostream>
using namespace std;

// ������ģ��Ҫ��
// * ���Զ��������������Լ��Զ����������͵����ݽ��д洢
// * �������е����ݴ洢������
// * ���캯���п��Դ������������
// * �ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
// * �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
// * ����ͨ���±�ķ�ʽ���������е�Ԫ��
// * ���Ի�ȡ�����е�ǰԪ�ظ��������������




template<typename T>
class MyArray
{
private:
    T * pAddress;
    int m_Capacity;
    int m_Size;
public:
    MyArray(int capacity);
    MyArray(const MyArray & arr);
    ~MyArray();

    // ���� = 
    MyArray & operator=(const MyArray & arr)
    {
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Size = 0;
            this->m_Capacity = 0;
        }
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Size];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        cout << "�����=����" << endl;
        return *this;
    }

    // ����[]
    T & operator[](int index)
    {
        cout << "�����[]����" << endl;
        return this->pAddress[index];
    }

    // β�巨
    void push_Back(const T & val)
    {
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
        cout << "β�巨ʵ��" << endl;
    }

    // βɾ��
    void pop_Back()
    {
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
        cout << "βɾ��ʵ��" << endl;
    }

    // ��ȡ�����С
    int getArrSize()
    {
        return this->m_Size;
        cout << "��ȡ�����Сʵ��" << endl;
    }
    
    // ��ȡ��������
    int getArrCapacity()
    {
        return this->m_Capacity;
        cout << "��ȡ��������ʵ��" << endl;
    }


};



// �вι���
template<typename T>
MyArray<T>::MyArray(int capacity)
{
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new T[this->m_Capacity];
    cout << "�вι������" << endl;
}

// ��������
template<typename T>
MyArray<T>::MyArray(const MyArray & arr)
{
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    this->pAddress = new T[arr.m_Capacity];
    for (int i = 0; i < this->m_Size; i++)
    {
        this->pAddress[i] = arr.pAddress[i];
        // =��  ��ͨ�������ݿ���ֱ��=��ֵ   ָ��������Ҫ���
        // ���TΪ���󣬶��һ�����ָ�룬������Ҫ���� = ����������Ϊ����ȺŲ��� ���� ���Ǹ�ֵ��
    }
    cout << "�����������" << endl;
}


// ��������
template<typename T>
MyArray<T>::~MyArray()
{
    if (this->pAddress != NULL)
    {
        delete[] this->pAddress;
        this->pAddress = NULL;
        this->m_Size = 0;
        this->m_Capacity = 0;
        cout << "������������" << endl;
    }
    
}
