#include <iostream>
using namespace std;

namespace novirtualVer
{
class Entity
{
public:
    void printName(void) { cout << "Entity ptintName" << endl; }
};

class Player : public Entity
{
};

class Enemy : public Entity
{
};

void test(void)
{
    Player* player = new Player();
    Entity* actuallyEnemy = new Enemy();
    Entity* actuallyPlayer = player;    // 隐式类型转换，派生类可以转换成基类

    //Player* p0 = dynamic_cast<Player*>(actuallyEnemy);  //err 编译报错 提示运行时 dynamic_cast的操作数必须包含多态类型
    //Player* p1 = dynamic_cast<Player*>(actuallyPlayer); //err 编译报错 提示运行时 dynamic_cast的操作数必须包含多态类型
}
}

namespace hasvirtualVer
{
class Entity
{
public:
    virtual void printName(void) { cout << "Entity ptintName" << endl; }
};

class Player : public Entity
{
};

class Enemy : public Entity
{
};

void test(void)
{
    Player* player = new Player();
    Entity* actuallyEnemy = new Enemy();
    Entity* actuallyPlayer = player;    // 隐式类型转换，派生类可以转换成基类

    Player* p0 = dynamic_cast<Player*>(actuallyEnemy);  //不会报错，但是这里不会转换成功，因为基类相同但是派生类之间转换不成功
    if (p0 == nullptr)
        printf("Enemy* --> Player* err \n");
    Player* p1 = dynamic_cast<Player*>(actuallyPlayer); //不会报错
}
}

int main(void)
{
    hasvirtualVer::test();
    return 0;
}