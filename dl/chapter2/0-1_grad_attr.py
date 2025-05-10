import torch
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np


# b站 cc

# 1.可微分性相关属性
def part1():
    x1 = torch.tensor(1.0)
    print(x1)

    # 只有float和复合类型才可以进行微分计算
    x2 = torch.tensor(1.0, requires_grad=True)
    print(x2)

    y = x2 ** 2
    print(y.requires_grad)
    print(y)

    z = y + 1
    print(z.requires_grad)
    print(z)


# 反向传播的基本过程
def part2():
    x = torch.tensor(1.0, requires_grad=True)
    y = x ** 2
    z = y + 1
    print("befor z.backward()  x.grad ", x.grad, "x ", x)
    print('z: ', z)
    z.backward()
    print("after z.backward()  x.grad ", x.grad, "x ", x)

    # z.backward()    # 在执行一次backward会报错

# 阻止计算图追踪
def part3_method1():
    x = torch.tensor(1.,requires_grad = True)
    y = x ** 2

    with torch.no_grad():
        z = y ** 2
    print(z)
    print(z.requires_grad)

def part3_method2():
    x = torch.tensor(1.,requires_grad = True)
    y = x ** 2
    y1 = y.detach()
    z = y1 ** 2
    print("y: ", y)
    print("y1: ", y1)
    print("z: ", z)


# 梯度下降的核心思想 sse演示
def part4():
    x = np.arange(-1,3,0.05)
    y = np.arange(-1,3,0.05)
    a, b = np.meshgrid(x, y)
    SSE = (2 - a - b) ** 2 + (4 - 3 * a - b) ** 2
    fig = plt.figure()  
    ax = plt.axes(projection='3d')

    ax.plot_surface(a, b, SSE, cmap='rainbow')
    ax.contour(a, b, SSE, zdir='z', offset=0, cmap="rainbow")  #生成z方向投影，投到x-y平面
    plt.show()

# 导数和梯度
# 梯度的值（grad）和导数相同
def part5():
    x = np.arange(-10,10,0.1)
    y = x ** 2                          # y = 2x
    z = 2 * x - 1                       # 在（1，1）点的切线方程
    plt.plot(x, y, '-')
    plt.plot(x, z, 'r-')
    plt.plot(1, 1, 'bo')
    plt.show()

    x = torch.tensor(1., requires_grad = True)
    y = x ** 2
    y.backward()
    print(x.grad)

# 梯度与方向
# a、b是权重是损失函数中的变量需要学习出来的内容，step是学习率，梯度乘以学习率就是权重需要更新的量
def part6():
    step = 0.01
    # 第一次尝试在(a, b) = (0, 0)点看是不是最小值
    a = torch.tensor(0., requires_grad = True)
    b = torch.tensor(0., requires_grad = True)
    s0 = torch.pow((2 - a - b), 2) + torch.pow((4 - 3 * a - b), 2)
    s0.backward()
    print("frist s0:", s0)
    print(f"a.grad: {a.grad}, b.grad: {b.grad}")

    # 第二次尝试在(a, b) = (-0.28, -0.12)点看是不是最小值
    a_next = a.grad * step + 0.
    b_next = b.grad * step + 0.
    print(f"a_next: {a_next}, b_next: {b_next}")
    a = torch.tensor(-a_next.item(), requires_grad = True)
    b = torch.tensor(-b_next.item(), requires_grad = True)
    s0 = torch.pow((2 - a - b), 2) + torch.pow((4 - 3 * a - b), 2)
    s0.backward()
    print("second s0:", s0)
    print(f"a.grad: {a.grad}, b.grad: {b.grad}")

    # 第三次尝试在(a, b) = (-0.49, -0.21)点看是不是最小值
    a_next = a.grad * step + a_next
    b_next = b.grad * step + b_next
    print(f"a_next: {a_next}, b_next: {b_next}")
    a = torch.tensor(-a_next.item(), requires_grad = True)
    b = torch.tensor(-b_next.item(), requires_grad = True)
    s0 = torch.pow((2 - a - b), 2) + torch.pow((4 - 3 * a - b), 2)
    s0.backward()
    print("thrid s0:", s0)
    print(f"a.grad: {a.grad}, b.grad: {b.grad}")



if __name__ == "__main__":
    # part1()
    # part2()
    # part3_method1()
    # part3_method2()
    # part4()
    # part5()
    part6()