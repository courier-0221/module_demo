import torch

# 定义输入和标签
inputs = torch.tensor([[0, 0], [0, 1], [1, 0], [1, 1]], dtype=torch.float32)
outputs = torch.tensor([[0], [1], [1], [0]], dtype=torch.float32)

# 定义感知机模型
class Perceptron(torch.nn.Module):
    def __init__(self):
        super(Perceptron, self).__init__()
        self.fc = torch.nn.Linear(2, 1)
        
    def forward(self, x):
        x = self.fc(x)
        return torch.sigmoid(x)

# 训练模型
model = Perceptron()
criterion = torch.nn.BCELoss()
optimizer = torch.optim.SGD(model.parameters(), lr=0.1)

for epoch in range(1000):
    optimizer.zero_grad()
    y_pred = model(inputs)
    loss = criterion(y_pred, outputs)
    loss.backward()
    optimizer.step()

# 测试模型
with torch.no_grad():
    y_pred = model(inputs)
    y_pred = torch.round(y_pred)
    print(y_pred)