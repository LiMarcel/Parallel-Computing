#include <iostream>

using namespace std;

typedef struct
{
    double d;
    char c1;
    char c2;
} CS;

typedef struct
{
    char c1;
    double d;
    char c2;
} CS1;

int main()
{
    CS a;

    cout << "sizeof(CS): " << sizeof(a) << endl;
    cout << (char*)&a.d - (char*)&a << endl;
    cout << (char*)&a.c1 - (char*)&a << endl;

    CS1 b;

    cout << "sizeof(CS): " << sizeof(b) << endl;
    cout << (char*)&b.c1 - (char*)&b << endl;
    cout << (char*)&b.d - (char*)&b << endl;
    cout << (char*)&b.c2 - (char*)&b << endl;

    return 0;
}
