import torch
import torch.nn as nn
import torch.optim as optim

"""
定义了一个包含一个隐藏层的多层感知机模型，隐藏层包含两个神经元。
我们使用sigmoid作为激活函数，并使用均方误差作为损失函数，使用随机梯度下降作为优化器。
在训练过程中，我们迭代10000次，并在每1000次迭代后输出损失值。
最后，我们使用训练好的模型对输入进行预测，并将输出结果与真实结果进行比较。
"""

# 定义输入和输出
inputs = torch.tensor([[0, 0], [0, 1], [1, 0], [1, 1]], dtype=torch.float32)
outputs = torch.tensor([[0], [1], [1], [0]], dtype=torch.float32)

# 定义多层感知机模型
class MLP(nn.Module):
    def __init__(self):
        super(MLP, self).__init__()
        self.fc1 = nn.Linear(2, 2)
        self.fc2 = nn.Linear(2, 1)
        
    def forward(self, x):
        x = torch.sigmoid(self.fc1(x))
        # x = torch.sigmoid(self.fc2(x))
        x = self.fc2(x)
        return x

# 定义模型、损失函数和优化器
model = MLP()
loss = nn.MSELoss()
optimizer = optim.SGD(model.parameters(), lr=0.1)

# 训练模型
for epoch in range(10000):
    optimizer.zero_grad()
    outputs_pred = model(inputs)
    l = loss(outputs_pred, outputs)
    l.backward()
    optimizer.step()
    if epoch % 1000 == 0:
        print('Epoch [{}/{}], Loss: {:.4f}'.format(epoch+1, 10000, l.item()))

# 测试模型
with torch.no_grad():
    outputs_pred = model(inputs)
    predicted = (outputs_pred > 0.5).float()
    print('Predicted XOR values: {}'.format(predicted))