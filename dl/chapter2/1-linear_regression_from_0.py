import random
import torch

# 这里采用  y=Xw+b+噪声  的形式做例子示范
# 主要出w和b分别是多少

# 生成数据集
def synthetic_data(w, b, num_examples):  #@save
    """生成y=Xw+b+噪声"""
    X = torch.normal(0, 1, (num_examples, len(w)))
    y = torch.matmul(X, w) + b
    # 噪声是标准差为0.01的正态分布值
    y += torch.normal(0, 0.01, y.shape)
    return X, y.reshape((-1, 1))

true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = synthetic_data(true_w, true_b, 1000)
print('features:', features[0],'\nlabel:', labels[0])
print('features.shape:', features.shape,'\nlabel.shape:', labels.shape)

"""
features: tensor([ 0.1294, -0.7884]) 
label: tensor([7.1491])
0.1294*2 + (-0.7884)*(-3.4) + 4.2 = 7.13936(结果里面没有加噪声,噪声可能是0.01)
"""



# 读取数据集
def data_iter(batch_size, features, labels):
    num_examples = len(features)
    indices = list(range(num_examples))
    # 这些样本是随机读取的，没有特定的顺序
    random.shuffle(indices)
    for i in range(0, num_examples, batch_size):
        batch_indices = torch.tensor(
            indices[i: min(i + batch_size, num_examples)])
        yield features[batch_indices], labels[batch_indices]

# 测试读取数据集
batch_size = 10
# for X, y in data_iter(batch_size, features, labels):
#     print(X, '\n', y)
#     break

# 初始化模型参数
# 权重先初始化为w均值是0，标准差是0.01的向量。偏移初始化为0
w = torch.normal(0, 0.01, size=(2,1), requires_grad=True)
b = torch.zeros(1, requires_grad=True)
print('init w:',w, 'b:', b)

# 定义模型
# 返回一个标量
def linreg(X, w, b):  #@save
    # 线性回归模型
    return torch.matmul(X, w) + b

# 测试线性回归接口
# for X, y in data_iter(batch_size, features, labels):
#     print(X, '\n', y)
#     break
# print(linreg(X, torch.tensor([2, -3.4]), 4.2))



# 定义损失函数
# y_hat:预测值，y:真实值
# 对于损失函数来说，w和b是未知变量，要对他们求梯度
def squared_loss(y_hat, y):  #@save
    # 均方损失
    return (y_hat - y.reshape(y_hat.shape)) ** 2 / 2


# 测试损失函数接口
for X, y in data_iter(batch_size, features, labels):
    print(X, '\n', y)
    break
print(squared_loss(linreg(X, torch.tensor([2, -3.4]), 4.2), y))


# 定义优化函数
# params:模型参数集合, [w, b],目的是调整w和b的值
# lr:学习速率
# batch_size:批量大小
def sgd(params, lr, batch_size):  #@save
    # 小批量随机梯度下降
    with torch.no_grad():   # 禁用梯度计算
        for param in params:
            param -= lr * param.grad / batch_size
            param.grad.zero_()

# 训练
lr = 0.03       # 学习率
num_epochs = 3  # 迭代周期个数
net = linreg
loss = squared_loss

for epoch in range(num_epochs):
    for X, y in data_iter(batch_size, features, labels):
        l = loss(net(X, w, b), y)  # X和y的小批量损失
        # 因为l形状是(batch_size,1)，而不是一个标量。l中的所有元素被加到一起，
        # 并以此计算关于[w,b]的梯度
        # print('l:', l, 'l.sum:', l.sum())
        print('l.sum:', l.sum())
        l.sum().backward()
        # print('w.grad:', w.grad, 'X:', X, 'b.grad:', b.grad)
        sgd([w, b], lr, batch_size)  # 使用参数的梯度更新参数
    # print('w:', w, 'b:', b)
    with torch.no_grad():
        train_l = loss(net(features, w, b), labels)
        print(f'epoch {epoch + 1}, loss {float(train_l.mean()):f}')

print(f'w的估计误差: {true_w - w.reshape(true_w.shape)}')
print(f'b的估计误差: {true_b - b}')

"""
"""
