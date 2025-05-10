import torch


# https://blog.csdn.net/weicao1990/article/details/93599947

# 选择维度
def test1():
    a = torch.rand(4, 3, 28, 28)
 
    # 等与a
    print(a[...].shape)
    
    # 第一张图片的所有维度
    print(a[0, ...].shape)
    
    # 所有图片第二通道的所有维度
    print(a[:, 1, ...].shape)
    
    # 所有图像所有通道所有行的第一、第二列
    print(a[..., :2].shape)

    # output:
    # torch.Size([4, 3, 28, 28])
    # torch.Size([3, 28, 28])
    # torch.Size([4, 28, 28])
    # torch.Size([4, 3, 28, 2])


# 插入新维度
def test2():
    # 创建一个 3 维张量
    x = torch.randn(3, 28, 28)

    # 使用 ... 插入一个新的维度
    y = x[..., None]

    # 打印 y 的形状
    print(y.shape)

    # output:
    # torch.Size([3, 28, 28, 1])


# 选取指定维度
def test3():
    # 创建一个5维张量
    x = torch.randn(2, 4, 3, 28, 28)

    # 选取所有的第0、1维，第2维选第3个通道，第3维选第4个通道
    y = x[..., 2, 3, :]
    print(y.shape)
    # outpyt:
    #     [2,4,28]

    y2 = x[..., 2, 3, ...]
    print(y2.shape)
    # outpyt:
    #     [2,4,3]


if __name__ == "__main__":
    # test1()
    # test2()
    test3()