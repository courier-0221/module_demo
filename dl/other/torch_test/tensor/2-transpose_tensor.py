import torch

x = torch.arange(2*3*4).reshape(2,3,4)
print(x.shape)  # 输出: torch.Size([2, 3, 4])
print(x)

y = x.transpose(0, 2).transpose(1, 2)
print(y.shape)  # 输出: torch.Size([3, 4, 2])
print(y)