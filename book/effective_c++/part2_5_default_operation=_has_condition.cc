#include <iostream>

// 默认构造函数中的赋值运算符生成是有条件的，对于const及引用操作则不会生成。
template<typename T>
class A{
  public:
    A(std::string& _name, const T& value);
  private:
    std::string& name;
    const T value;
};

int main(void)
{
    std::string s1("hello");
    std::string s2("hi");

    A<int> a1(s1,3);
    A<int> a2(s2,6);
    a1=a2;      // 操作失败
    return 0;
}