import torch


# tensor按列访问
def test1():
    a = torch.rand(8, 5)
    print(f"origin: {a}")
 
    for idx in range(a.size()[-1]):
        print(f"a[..., {idx}]: {a[..., idx]}")


# bool类型索引
# https://blog.csdn.net/mch2869253130/article/details/118088278
def test2():
    t1 = torch.rand(4, 2)
    b1 = torch.tensor([True, False, True, True])
    print(f"t1: {t1}")
    print(f"t1[b1]: {t1[b1]}")

# bool类型索引
# https://blog.csdn.net/mch2869253130/article/details/118088278
def test3():
    target = torch.tensor([[0.],
        [1.],
        [0.],
        [1.],
        [0.],
        [1.],
        [0.],
        [1.]])
    predict = torch.tensor([[-4.1484],
        [4.0117],
        [-3.7285],
        [4.3164],
        [-5.6211],
        [5.7930],
        [-6.1406],
        [4.5977]])

    com = predict[target == 1].view(-1, 1)
    print(f"com: {com}")


# bool类型索引
# https://blog.csdn.net/mch2869253130/article/details/118088278
def test4():
    targets_weather = torch.tensor([[0., 0., 0., 1., 0.],
        [0., 0., 0., 0., 1.],
        [0., 0., 0., 0., 1.],
        [0., 0., 0., 0., 1.],
        [0., 0., 0., 1., 0.],
        [0., 0., 0., 1., 0.],
        [0., 0., 0., 1., 0.],
        [0., 1., 0., 0., 0.]])
    predict_weather = torch.tensor([[-4.1484, -5.0664, -2.8848,  3.1016, -4.3516],
        [-4.0117, -4.8906, -3.4414, -3.6660,  3.9316],
        [-3.7285, -4.0430, -3.2148, -3.6406,  3.2168],
        [-4.3164, -4.1797, -3.2832, -3.3008,  3.9043],
        [-5.6211, -5.8047, -3.7070,  3.2441, -5.2891],
        [-5.7930, -5.8633, -3.0215,  3.4824, -4.2891],
        [-6.1406, -6.5469, -2.9980,  3.5391, -5.6797],
        [-4.5977,  3.1875, -2.7852, -3.2715, -4.3125]])
    print(f"targets_weather: {targets_weather}")
    print(f"predict_weather: {predict_weather}")    

    for idx in range(targets_weather.size(-1)):
        predict_positive = predict_weather[..., idx][targets_weather[..., idx] == 1].view(-1, 1)
        predict_negative = predict_weather[..., idx][targets_weather[..., idx] == 0].view(-1, 1)
        targets_positive = targets_weather[..., idx][targets_weather[..., idx] == 1].view(-1, 1)
        targets_negative = targets_weather[..., idx][targets_weather[..., idx] == 0].view(-1, 1)
        predict_stack = torch.cat([predict_positive, predict_negative], dim=0)
        targets_stack = torch.cat([targets_positive, targets_negative], dim=0)
        print(f"predict_weather[..., {idx}]: {predict_weather[..., idx]}")
        print(f"targets_weather[..., {idx}]: {targets_weather[..., idx]}")
        print(f"predict_positive: {predict_positive}")
        print(f"predict_negative: {predict_negative}")
        print(f"targets_positive: {targets_positive}")
        print(f"targets_negative: {targets_negative}")
        print(f"predict_stack: {predict_stack}")
        print(f"targets_stack: {targets_stack}")


if __name__ == "__main__":
    # test1()
    # test2()
    # test3()
    test4()
