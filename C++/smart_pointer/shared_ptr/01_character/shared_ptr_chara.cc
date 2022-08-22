#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Father {
public:
    explicit Father(const std::string &name)
    :name_(name) {}

    virtual void call() const {
        std::cout << "father's name:" << name_ << std::endl;
    }
    
    //virtual ~Father() { printf("Father dtor !!!\n"); }  //virtual 不使用智能指针的话是必须的
    ~Father() { printf("Father dtor !!!\n"); }  //virtual 不使用智能指针的话是必须的

private:
    const std::string name_;
};

class Son : public Father {
public:
    explicit Son(const std::string &name)
    : Father(name + "'s father")
    , name_(name) {}

    void call() const override {
        std::cout << "son's name:" << name_ << std::endl;
    }

    ~Son() { printf("Son dtor !!!\n"); }

private:
    const std::string name_;
};

// g++ shared_ptr_chara.cc

// 在创建时捕获析构函数，析构函数不用是虚析构的

int main() {

    shared_ptr<Father> p(new Son("1111"));

    return 0;
}
