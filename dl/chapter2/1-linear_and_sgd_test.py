import torch
from torch import nn
import torch.optim as optim

def line_test():
    line = nn.Linear(2, 4)
    data = torch.tensor([2, -3.4])
    print(line(data))


def sgd_test():
    # 1. 定义模型和损失函数：
    model = torch.nn.Linear(2, 1)  # 定义一个线性模型
    criterion = torch.nn.MSELoss()  # 定义均方误差损失函数

    # # 打印模型参数
    # # 方式1，model.parameters()
    # params = list(model.parameters())
    # for param in params:
    #     print(param)
    # print("\n")
    
    # # 方式2，model.named_parameters()
    # for name, param in model.named_parameters():
    #     print(name, param)
    # print("\n")
    
    # 方式3，state_dict()
    print(model.state_dict())
    print("\n")

    # 2. 定义优化器：
    optimizer = torch.optim.SGD(model.parameters(), lr=0.01)  # 定义随机梯度下降优化器

    # 3. 在训练循环中使用优化器：
    num_epochs = 10
    # 设置x和y
    true_x = torch.randn(10, 2)
    true_y = true_x[:, 0] + true_x[:, 1]
    print(f"true_x {true_x}")
    print(f"true_y {true_y}")
    for epoch in range(num_epochs):
        # 前向传播
        y_pred = model(true_x)
        # print(f"y_pred: {y_pred}")

        # 计算损失
        loss = criterion(y_pred.squeeze(), true_y)

        # 反向传播
        optimizer.zero_grad()
        loss.backward()
        print(f"befor update.param: {model.state_dict()}")

        # 更新参数
        optimizer.step()
        print(f"befor update.param: {model.state_dict()}")

        # 打印损失
        print('Epoch {}, Loss: {:.4f}'.format(epoch, loss.item()))
    
    # 验收下预测结果
    print(f"result = {model(true_x)}")


if __name__ == "__main__":
    # line_test()
    sgd_test()