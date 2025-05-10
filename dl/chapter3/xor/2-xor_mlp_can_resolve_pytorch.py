# https://www.cnblogs.com/orion-orion/p/15895136.html


import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np

class Perceptron(nn.Module):
    def __init__(self, input_size, hidden_size):
        super(Perceptron, self).__init__()
        self.fc1 = nn.Linear(input_size, hidden_size)
        self.fc2 = nn.Linear(hidden_size, 1)

    def forward(self, x):
        x = torch.sigmoid(self.fc1(x))
        x = torch.sigmoid(self.fc2(x))
        return x

def train(X, y, n_iter=200, hidden_size=2, eta=0.001):
    X = torch.tensor(X, dtype=torch.float32)
    y = torch.tensor(y, dtype=torch.float32).unsqueeze(1)
    model = Perceptron(X.shape[1], hidden_size)
    criterion = nn.BCELoss()
    optimizer = optim.SGD(model.parameters(), lr=eta)

    for i in range(n_iter):
        optimizer.zero_grad()
        y_pred = model(X)
        loss = criterion(y_pred, y)
        loss.backward()
        optimizer.step()

    return model.fc1.weight.detach(), model.fc2.weight.detach(), model.fc1.bias.detach(), model.fc2.bias.detach()

if __name__ == '__main__':
    X = np.array([
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1]
    ], dtype=np.float64)
    # 标签向量
    y = np.array([0, 1, 1, 0], dtype=np.int64)
    # 迭代次数
    n_iter = 2000
    # 学习率
    eta = 2 #因为每轮所求的梯度太小，这里增大学习率以补偿
    # 隐藏层神经元个数
    hidden_size = 2
    W, w, b1, b2 = train(X, y, n_iter, hidden_size, eta)
    # 代入
    model = Perceptron(X.shape[1], hidden_size)
    model.fc1.weight = nn.Parameter(W)
    model.fc2.weight = nn.Parameter(w)
    model.fc1.bias = nn.Parameter(b1)
    model.fc2.bias = nn.Parameter(b2)
    print(model(torch.tensor(X, dtype=torch.float32)))