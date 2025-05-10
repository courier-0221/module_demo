import numpy as np
from PIL import Image
import torchvision

img_path = r"/home/dear/下载/R2.jpeg"

def show_img():
    # 读取图像
    img = Image.open(img_path)

    width, height = img.size
    print("图像宽度为：", width)
    print("图像高度为：", height)

    # 展示图像
    img.show()

def resize_img():
    # 读取图像
    img = Image.open(img_path)

    # 调整图像大小
    new_size = (500, 500)  # 新的图像大小
    resized_img = img.resize(new_size)

    # 展示调整后的图像
    resized_img.show()

def pil_img_to_tensor():
    img = Image.open(img_path)

    transform = torchvision.transforms.ToTensor()
    img_tensor = transform(img)
    print(img_tensor)

def ndarray_to_tensor():
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
    img_tensor = torchvision.transforms.ToTensor()(img) # 转换成tensor

    print(img_tensor.shape)
    print(img_tensor)


if __name__ == "__main__":
    # show_img()
    # resize_img()
    # pil_img_to_tensor()
    ndarray_to_tensor()