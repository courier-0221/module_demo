import torch
import numpy as np

# 数组的维度，0:第一维度，1：第二维度，2：第三维度
# transpose，就是将维度进行变换

# 初始化tensor
x = torch.arange(24)
x = x.reshape(2,3,4)
print("shape: ", x.shape)
print("type: ", type(x))
print(x)
print('-'*60)

# 转换成numpy的数组
tmp = x.numpy()
print("shape: ", tmp.shape)
print("type: ", type(tmp))
print(tmp)
print('-'*60)

# numpy数组的维度转换
y = tmp.transpose(1,2,0)
# y = tmp.transpose(1,0,2)
print("shape: ", y.shape)
print("type: ", type(y))
print(y)