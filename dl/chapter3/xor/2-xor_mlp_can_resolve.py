# https://www.cnblogs.com/orion-orion/p/15895136.html

import numpy as np
import random
import torch
# batch_size表示单批次用于参数估计的样本个数
# y_pred大小为(batch_size, )
# y大小为(batch_size, )，为类别型变量
def log_loss(y_pred, y):
    return -(torch.mul(y, torch.log(y_pred)) + torch.mul(1-y, torch.log(1-y_pred))).sum()/y_pred.shape[0]

# 前向函数
def perceptron_f(X, W, w, b1, b2): 
    z1 = torch.add(torch.matmul(X, W), b1) 
    h = 1/(1+torch.exp(-z1)) 
    z2 = torch.add(torch.matmul(h, w), b2)
    return 1/(1+torch.exp(-z2))

# 之前实现的梯度下降法，做了一些小修改
def gradient_descent(X, W, b1, w, b2, y, n_iter, eta, loss_func, f):
    for i in range(1, n_iter+1):
        y_pred = f(X, W, w, b1, b2)
        loss_v = loss_func(y_pred, y)
        loss_v.backward() 
        with torch.no_grad(): 
            W -= eta*W.grad
            w -= eta*w.grad
            b1 -= eta*b1.grad
            b2 -= eta*b2.grad
        W.grad.zero_()  
        w.grad.zero_()
        b1.grad.zero_()
        b2.grad.zero_()
    W_star = W.detach()
    w_star = w.detach()
    b1_star = b1.detach()
    b2_star = b2.detach()
    return W_star, w_star, b1_star, b2_star

# 本模型按照二分类架构设计
def Perceptron(X, y, n_iter=200, hidden_size=2, eta=0.001, loss_func=log_loss, optimizer=gradient_descent):
    # 初始化模型参数
    # 注意，各权重初始化不能相同
    W = torch.tensor(np.random.random((X.shape[1], hidden_size)), requires_grad=True)
    b1 = torch.tensor(np.random.random((1)), requires_grad=True)
    w = torch.tensor(np.random.random((hidden_size, )), requires_grad=True)
    b2 = torch.tensor(np.random.random((1)), requires_grad=True)
    X, y = torch.tensor(X), torch.tensor(y)
    # 调用梯度下降法对函数进行优化
    # 这里采用单次迭代对所有样本进行估计，后面我们会介绍小批量法
    W_star, w_star, b1_star, b2_star = optimizer(X, W, b1, w, b2, y, n_iter, eta, log_loss, perceptron_f)
    return W_star, w_star, b1_star, b2_star

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
    W, w, b1, b2 = Perceptron(X, y, n_iter, hidden_size, eta, log_loss, gradient_descent)
    # 代入
    print(perceptron_f(torch.tensor(X), W, w, b1, b2))

