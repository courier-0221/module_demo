import torch

# x = torch.arange(4.0, requires_grad=True)
# y = 2x**2
# y.backword()
# output:
# y: tensor(28., grad_fn=<MulBackward0>)
# x.grad: tensor([ 0.,  4.,  8., 12.])
def func_simple():
    print("*"*60)
    x = torch.arange(4.0, requires_grad=True)
    y = 2 * torch.dot(x, x)
    print('y:', y)
    y.backward()
    print('x.grad:', x.grad)
    print("*"*60)

# x = torch.arange(4.0, requires_grad=True)
# y = x*x
# y.sum().backward()
# output:
# y: tensor([0., 1., 4., 9.], grad_fn=<MulBackward0>)
# y.sum(): tensor(14., grad_fn=<SumBackward0>)
# x.grad: tensor([0., 2., 4., 6.])
def func_xx():
    print("*"*60)
    x = torch.arange(4.0, requires_grad=True)
    # y = 2 * x * x
    y = x * x
    print('y:', y)
    print('y.sum():', y.sum())
    # 等价于y.backward(torch.ones(len(x)))
    y.sum().backward()
    print('x.grad:', x.grad)
    print("*"*60)

# x = torch.arange(4.0, requires_grad=True)
# y = x.sum()
# y.backward()
def func_x_sum():
    print("*"*60)
    x = torch.arange(4.0, requires_grad=True)
    y = x.sum()
    print('y:', y)
    y.backward()
    print('x.grad:', x.grad)
    print("*"*60)


# x = torch.tensor([2.0, 3.0], requires_grad=True)
# y = x**2 + 3x + 1
# y.backward(torch.tensor([1.0, 1.0]))
def func_x23x():
    print("*"*60)
    # 创建一个 Tensor，并设置 requires_grad=True
    x = torch.tensor([2.0, 3.0], requires_grad=True)
    # 定义一个函数 y = x^2 + 3x + 1
    y = x.pow(2) + 3*x + 1
    print('y:', y)
    # 计算 y 相对于 x 的梯度
    y.backward(torch.tensor([2.0, 1.0]))
    # 输出 x 的梯度
    print('x.grad:', x.grad)
    print("*"*60)

# x = torch.tensor([3.0], requires_grad=True)
# y = x**2
# y.backward()
def func_xx2():
    print("*"*60)
    # 创建一个张量并设置 requires_grad=True
    x = torch.tensor([3.0], requires_grad=True)
    # 定义一个函数 y = x^2
    y = x ** 2
    print('y:', y)
    # 计算 y 相对于 x 的梯度
    y.backward()
    # 打印 x 的梯度
    print('x.grad:', x.grad)
    print("*"*60)


func_simple()
func_xx()
func_x_sum()
func_x23x()
func_xx2()
