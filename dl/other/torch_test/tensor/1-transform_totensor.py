import torch
import numpy as np
from torchvision import transforms

# https://pytorch.org/vision/stable/generated/torchvision.transforms.ToTensor.html


data = np.random.randint(0, 255, size=300).astype(np.uint8)
img = data.reshape(10,10,3)
print(img.shape)
print(img)

# [-1,1]区间
# transform = transforms.Compose([
#     transforms.ToTensor(),
#     transforms.Normalize(mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5])
# ])
# img_tensor = transform(img)

# [0, 1]区间
img_tensor = transforms.ToTensor()(img) # 转换成tensor

print(img_tensor.shape)
print(img_tensor)