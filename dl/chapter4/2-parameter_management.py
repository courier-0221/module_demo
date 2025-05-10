import torch
from torch import nn

# 单隐藏层的感知机
# 两个全连接层
net = nn.Sequential(nn.Linear(4, 8), nn.ReLU(), nn.Linear(8, 1))
X = torch.rand(size=(2, 4))
print(net(X))





# 参数访问
print("-"*60)

# 访问某一层
print(net[2].state_dict())

# # 访问某一个参数，访问偏置
# print("-"*60)
# print(type(net[2].bias))
# print(net[2].bias)
# print(net[2].bias.data)

# 一次性访问所有参数
print("-"*60)
# # 访问第0层的参数
# print(*[(name, param.shape) for name, param in net[0].named_parameters()])
# 访问所有层的参数
print(*[(name, param.shape) for name, param in net.named_parameters()])

# print("-"*60)
# for name, value in net.named_parameters():
#     print("name:", name, "value:", value)

# # 多个块的参数
# print("-"*60)
# def block1():
#     return nn.Sequential(nn.Linear(4, 8), nn.ReLU(),
#                          nn.Linear(8, 4), nn.ReLU())

# def block2():
#     net = nn.Sequential()
#     for i in range(4):
#         # 在这里嵌套
#         net.add_module(f'block {i}', block1())
#     return net

# rgnet = nn.Sequential(block2(), nn.Linear(4, 1))
# print(rgnet(X))
# print(rgnet)






# # 参数初始化
# print("-"*60)

# # 将所有参数初始化为给定的常数，比如初始化为1。
# def init_constant(m):
#     if type(m) == nn.Linear:
#         nn.init.constant_(m.weight, 1)
#         nn.init.zeros_(m.bias)
# net.apply(init_constant)
# print(net[0].weight.data[0], net[0].bias.data[0])


# # 对某些块应用不同的初始化方法
# print("-"*60)
# def init_xavier(m):
#     if type(m) == nn.Linear:
#         nn.init.xavier_uniform_(m.weight)
# def init_42(m):
#     if type(m) == nn.Linear:
#         nn.init.constant_(m.weight, 42)

# net[0].apply(init_xavier)
# net[2].apply(init_42)
# print(net[0].weight.data[0])
# print(net[2].weight.data)


# # 自定义初始化
# print("-"*60)
# def my_init(m):
#     if type(m) == nn.Linear:
#         print("Init", *[(name, param.shape)
#                         for name, param in m.named_parameters()][0])
#         nn.init.uniform_(m.weight, -10, 10)
#         m.weight.data *= m.weight.data.abs() >= 5

# net.apply(my_init)
# print(net[0].weight[:2])
