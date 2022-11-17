#include <iostream>
using namespace std;

struct AAA{
    int a1;
    int a2;
    double d1;
};
struct  BBB{
    int a1;
    double d1;
    int a2;
};
struct CCC{
    short a;
    int b;
    char c;
};

struct DDD{
    short a;
    char c;
    int b;
};



class AA {
    public:
    int a;
    AA(){}
    virtual ~AA(){}
};
class BB {
    public:
    int a;
    double d;
    BB(){}
    virtual ~BB(){}
};










int main() {
    int (*A)[5]; 
    cout << sizeof(A) << endl; // 8
    cout << sizeof(*(A+1)) << endl; // 20
    cout << *(A+1) << " == " << A[1] << endl; // 0x14 == 0x14
    cout << *A << " == " << A << " != " << &A << endl; // 0x0 == 0x0 != 0x7ffeefbff4e0

    int a[5] = {1,2,3,4,5};
    cout << sizeof(a) << endl;  // 20
    cout << sizeof(*a) << endl; // 4
    cout << *(a+1) << " == " << a[1] << endl; // 2 == 2
    cout << &a << " == " << a << endl; // 0x7ffeefbff4f0 == 0x7ffeefbff4f0
    cout << &a+1 << " != " << a+1 << endl; // 0x7ffeefbff504 != 0x7ffeefbff4f4

    AAA aaa; cout << sizeof(aaa) << endl;  // 16 = 4+4+8 
    BBB bbb; cout << sizeof(bbb) << endl;  // 24 = 8+8+8
    CCC ccc; cout << sizeof(ccc) << endl;  // 12 = 4+4+4 
    DDD ddd; cout << sizeof(ddd) << endl;  // 8 = 2+2+4

    AA aa; cout << sizeof(aa) << endl;  // 16
    BB bb; cout << sizeof(bb) << endl;  //24
    return 0;
}
