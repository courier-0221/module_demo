#include <string>
#include <iostream>

class Father {
public:
    explicit Father(const std::string &name)
    :name_(name) {}

    virtual void call() const {
        std::cout << "father's name:" << name_ << std::endl;
    }
    
    virtual ~Father() { printf("Father dtor !!!\n"); }

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


int main() {
    
    //情况一：
    Son *s=new Son("111");
    delete s;
    std::cout << "----------" << std::endl;
    //情况二：
    Father *f = new Son("222");
    delete f;

    return 0;
}
