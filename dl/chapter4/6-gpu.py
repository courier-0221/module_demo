import torch
from torch import nn


# 使用计算设备，会返回计算设备
print(torch.device('cpu'), torch.device('cuda'), torch.device('cuda:1'))

# 查询gpu数量
print("-"*60)
print(torch.cuda.device_count())

# 常用获取cpu和gpu的接口
def try_gpu(i=0):  #@save
    """如果存在，则返回gpu(i)，否则返回cpu()"""
    if torch.cuda.device_count() >= i + 1:
        return torch.device(f'cuda:{i}')
    return torch.device('cpu')

def try_all_gpus():  #@save
    """返回所有可用的GPU，如果没有GPU，则返回[cpu(),]"""
    devices = [torch.device(f'cuda:{i}')
             for i in range(torch.cuda.device_count())]
    return devices if devices else [torch.device('cpu')]

print("-"*60)
print(try_gpu(), try_gpu(10), try_all_gpus())



# 张量与GPU
# 默认情况下，张量都是创建在cpu上的
print("-"*60)
x = torch.tensor([1, 2, 3])
print(x.device)

# 存储在gpu上
print("-"*60)
X = torch.ones(2, 3, device=torch.device('cuda'))
print(X)


# 神经网络与GPU
net = nn.Sequential(nn.Linear(3, 1))
net = net.to(device=try_gpu())
print(net(X))

print(net[0].weight.data.device)