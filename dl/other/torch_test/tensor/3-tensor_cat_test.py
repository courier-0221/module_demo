import torch

def test1():
    # 创建两个张量
    x = torch.tensor([[1, 2], [3, 4]])
    y = torch.tensor([[5, 6]])

    # 沿着第0维拼接
    z = torch.cat((x, y), dim=0)
    print(z)
    # 输出：
    # tensor([[1, 2],
    #         [3, 4],
    #         [5, 6]])

    # 沿着第1维拼接
    w = torch.cat((x, y.T), dim=1)
    print(w)
    # 输出：
    # tensor([[1, 2, 5],
    #         [3, 4, 6]])

def test2():
    x = torch.tensor([1, 2])
    y = torch.tensor([5, 6])
    z = torch.cat((x, y), dim=0)
    print(z)

    z2 = torch.cat([x, y], dim=0)
    print(z2)


def main():
    # test1()
    test2()


if __name__ == "__main__":
    main()