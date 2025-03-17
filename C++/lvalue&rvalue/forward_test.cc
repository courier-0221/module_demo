#include <iostream>
#include <string>
using namespace std;

void printName(string&& str) {
    cout << "string&& " << str << endl;
}

void printName(string& str) {
    cout << "string& " << str << endl;
}

void test1() {
    string str1 = "zhangsan";
    string str2 = "lisi";
    printName(str1);
    printName(str1+str2);
}

template <typename T>
void call_printfStr(T&& str) {
    printName(forward<T>(str));
}

void test2() {
    string str1 = "zhangsan";
    string str2 = "lisi";
    call_printfStr(str1);
    call_printfStr(str1+str2);
}

int main(void) {
    test1();
    printf("\n");
    test2();
    
    return 0;
}