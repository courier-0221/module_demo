import torch


# 基础入门
def func_introduction():
    print("*"*60)

    x = torch.arange(12)
    print(x)

    # 通过张量的shape属性来访问张量（沿每个轴的长度）的形状 。
    print(x.shape)
    # 想知道张量中元素的总数，即形状的所有元素乘积，可以检查它的大小（size）
    print(x.numel())

    print("-"*60)

    # 想改变一个张量的形状而不改变元素数量和元素值，可以调用reshape函数
    x1 = x.reshape(3, 4)
    print(x1)
    print(x1.shape)
    print(x1.numel())

    print("-"*60)

    # 可以用x.reshape(-1,4)或x.reshape(3,-1)来取代x.reshape(3,4)，来做到自动计算另一个维度
    x2 = x.reshape(-1, 4)
    print(x2)
    print(x2.shape)
    print(x2.numel())

    print("-"*60)

    # 可以使用zeros、ones、以及randn来初始化张量
    x3 = torch.zeros((2, 3, 4))
    print(x3)
    print(x3.shape)
    print(x3.numel())

    x4 = torch.ones((2, 3, 4))
    print(x4)
    print(x4.shape)
    print(x4.numel())

    x5 = torch.randn((2, 3, 4))
    print(x5)
    print(x5.shape)
    print(x5.numel())

    print("-"*60)

    # 可以通过提供包含数值的Python列表（或嵌套列表），来为所需张量中的每个元素赋予确定值。
    x6 = torch.tensor([[2, 1, 4, 3], [1, 2, 3, 4], [4, 3, 2, 1]])
    print(x6)
    print(x6.shape)
    print(x6.numel())

    print("*"*60)


# tensor的size方法测试
# size()方法的参数是dim，如果不指定dim则返回张量的完整形状，如果是-1则获取最后一维上的元素大小
def func_tensor_size():
    x = torch.randn(3, 4, 5)
    print(x.size())
    print(x.size(-1))
    print(x.size()[0])
    print(x.size()[1])
    print(x.size()[2])



# 运算符
def func_operator():
    print("*"*60)

    # 加减乘除， **运算符是求幂运算
    x = torch.tensor([1.0, 2, 4, 8])
    y = torch.tensor([2, 2, 2, 2])
    print(x)
    print(y)
    print(x + y)
    print(x - y) 
    print(x * y)
    print(x / y)
    print(x ** y)

    print("-"*60)

    # 按元素操作，像求幂这样的一元函数
    print(torch.exp(x))
    # 除了按元素计算外，还可以执行线性代数运算，包括向量点积和矩阵乘法。后面介绍

    print("-"*60)
    
    # 也可以把多个张量连结（concatenate）在一起， 把它们端对端地叠起来形成一个更大的张量。 我们只需要提供张量列表，并给出沿哪个轴连结。
    X = torch.arange(12, dtype=torch.float32).reshape((3,4))
    Y = torch.tensor([[2.0, 1, 4, 3], [1, 2, 3, 4], [4, 3, 2, 1]])
    print(torch.cat((X, Y), dim=0))
    print(torch.cat((X, Y), dim=1))

    print("-"*60)

    # 通过逻辑运算符构建二元张量。 以X == Y为例： 对于每个位置，如果X和Y在该位置相等，则新张量中相应项的值为1。 这意味着逻辑语句X == Y在该位置处为真，否则该位置为0。
    print(X == Y)

    print("-"*60)

    # 对张量中的所有元素进行求和，会产生一个单元素张量。
    print(X.sum())

    print("*"*60)

# 广播机制
def func_broadcasting_mechanism():
    print("*"*60)
    # 由于a和b分别是3*1和1*2矩阵，如果让它们相加，它们的形状不匹配。 
    # 我们将两个矩阵广播为一个更大的3*2矩阵，如下所示：矩阵a将复制列， 矩阵b将复制行，然后再按元素相加。
    a = torch.arange(3).reshape((3, 1))
    b = torch.arange(2).reshape((1, 2))
    print(a)
    print(b)
    print("-"*60)
    print(a+b)

    print("*"*60)

# 切片和索引
def func_index_slice():
    print("*"*60)
    
    #  与任何Python数组一样：第一个元素的索引是0，最后一个元素索引是-1； 可以指定范围以包含第一个元素和最后一个之前的元素。
    X = torch.arange(12, dtype=torch.float32).reshape((3,4))
    print(X)
    print(X[-1])
    print(X[1:3])

    print("-"*60)

    # 可以通过指定索引来将元素写入矩阵
    X[1, 2] = 9
    print(X)

    print("-"*60)

    # 为多个元素赋值相同的值，我们只需要索引所有元素，然后为它们赋值。 
    # 例如，[0:2, :]访问第1行和第2行，其中“:”代表沿轴1（列）的所有元素。 
    # 虽然我们讨论的是矩阵的索引，但这也适用于向量和超过2个维度的张量。
    X[0:2, :] = 12
    print(X)

    print("*"*60)



# func_introduction()
# func_operator()
# func_broadcasting_mechanism()
# func_index_slice()
func_tensor_size()