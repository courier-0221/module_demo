import torch
from PIL import Image
import numpy as np
import torchvision.transforms as transforms


def test1_no_totensor():
    # 创建一个张量
    channel = torch.tensor([[1, 2, 3], [4, 5, 6], [7, 8, 9]], dtype=torch.float32)

    # 将三个相同的tensor沿着第0维度堆叠起来，形成一个三通道的tensor
    tensor = torch.stack([channel, channel, channel], dim=0)
    print(tensor)

    # 创建一个 Normalize 转换方法
    normalize = transforms.Normalize(mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5])

    # 对张量进行标准化
    normalized_tensor = normalize(tensor)

    print(normalized_tensor)

def test2_yes_totensor():
    # 创建一个张量
    channel = torch.tensor([[1, 2, 3], [4, 5, 6], [7, 8, 9]], dtype=torch.float32)
    # 将三个相同的tensor沿着第0维度堆叠起来，形成一个三通道的tensor
    tensor = torch.stack([channel, channel, channel], dim=0)
    print(tensor)


    # 将tensor转换成numpy数组
    array = tensor.numpy()
    # 将numpy数组转换成PIL图像
    # 维度从(3, 256, 256)转换成(256, 256, 3)
    pil_image = Image.fromarray(np.uint8(array.transpose((1, 2, 0))))
    print(f"pil_image {pil_image}")
    # 显示图像
    # pil_image.show()

    # 创建一个toTensor 转换方法
    totensor = transforms.ToTensor()
    # 对张量进行归一化
    totensor_tensor = totensor(pil_image)
    print(f"totensor_tensor {totensor_tensor}")
    
    # 创建一个 Normalize 转换方法
    normalize = transforms.Normalize(mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5])
    # 对张量进行标准化
    normalized_tensor = normalize(totensor_tensor)
    print(f"normalized_tensor {normalized_tensor}")

def test3_compose():
    # 创建一个张量
    channel = torch.tensor([[1, 2, 3], [4, 5, 6], [7, 8, 9]], dtype=torch.float32)
    # 将三个相同的tensor沿着第0维度堆叠起来，形成一个三通道的tensor
    tensor = torch.stack([channel, channel, channel], dim=0)
    print(tensor)

    array = tensor.numpy()
    pil_image = Image.fromarray(np.uint8(array.transpose((1, 2, 0))))

    # 定义transforms
    transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize(mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5])
    ])

    # 应用transforms
    result = transform(pil_image)
    print(result)

if __name__ == "__main__":
    # test1_no_totensor()
    # test2_yes_totensor()
    test3_compose()