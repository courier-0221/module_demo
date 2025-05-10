import torch
from torch import nn
from torch.nn import functional as F


# 加载和保存张量到文件


# 加载和保存单个张量到文件
x = torch.arange(4)
torch.save(x, 'x-file')
x2 = torch.load('x-file')
print(x2)

# 加载和保存张量列表到文件
print("-"*60)
y = torch.zeros(4)
torch.save([x, y],'x-files')
x2, y2 = torch.load('x-files')
print(x2, y2)

# 加载和保存张量字典到文件
print("-"*60)
mydict = {'x': x, 'y': y}
torch.save(mydict, 'mydict')
mydict2 = torch.load('mydict')
print(mydict2)



# 加载和保存模型参数
print("-"*60)
class MLP(nn.Module):
    def __init__(self):
        super().__init__()
        self.hidden = nn.Linear(20, 256)
        self.output = nn.Linear(256, 10)

    def forward(self, x):
        return self.output(F.relu(self.hidden(x)))

net = MLP()
X = torch.randn(size=(2, 20))
Y = net(X)

# 保存模型参数
torch.save(net.state_dict(), 'mlp.params')

# 加载模型参数
clone = MLP()
clone.load_state_dict(torch.load('mlp.params'))
clone.eval()
Y_clone = clone(X)

# 对比
print(Y_clone == Y)