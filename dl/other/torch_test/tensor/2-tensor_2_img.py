# 将PyTorch的tensor转换为OpenCV的图像格式，并展示出来
# 前提图片是rgb格式的

import cv2
import torch

def cvmat_2_torchtensor():
    # 读取图像并将其转换为OpenCV矩阵
    opencv_mat = cv2.imread('/home/dear/下载/lena.png')
    print("type: ", type(opencv_mat))

    # 将OpenCV矩阵转换为NumPy数组
    numpy_array = cv2.cvtColor(opencv_mat, cv2.COLOR_BGR2RGB).transpose(2, 0, 1)

    # 将NumPy数组转换为PyTorch张量
    tensor = torch.from_numpy(numpy_array)
    print("type: ", type(tensor))
    print("img tensor: ", tensor)
    return tensor



def torchtensor_2_cvmat(tensor):
    # 将张量转换为NumPy数组
    numpy_array = tensor.numpy()

    # 将NumPy数组转换为OpenCV矩阵
    opencv_mat = cv2.cvtColor(numpy_array.transpose(1, 2, 0), cv2.COLOR_RGB2BGR)

    # 展示图像
    cv2.imshow('image', opencv_mat)
    cv2.waitKey(1000)
    cv2.destroyAllWindows()


tensor = cvmat_2_torchtensor()
torchtensor_2_cvmat(tensor)