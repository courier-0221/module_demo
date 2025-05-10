import torch
import torch.nn as nn
import torch.nn.functional as F

def test1():
    inputs = torch.randn(2, 1)
    labels = torch.tensor([0, 1]).view(-1, 1)
    print(f"inputs: {inputs}")
    print(f"labels: {labels}")

    loss = F.binary_cross_entropy_with_logits(inputs, labels.float())
    print(loss)

def sigmoid_focal_loss(pred, target, gamma=2.0, alpha=0.25, reduction='mean'):

    assert pred.shape == target.shape, 'pred and target should be in the same shape.'
    pred_sigmoid = pred.sigmoid()
    target = target.type_as(pred)
    print(f"pred_sigmoid: {pred_sigmoid}")
    print(f"target: {target}")

    pt = (1 - pred_sigmoid) * target + pred_sigmoid * (1 - target)
    print(f"pt: {pt}")
    print(f"math.factorial: {(alpha * target + (1 - alpha) * (1 - target))}")
    print(f"math.factorial2: {pt.pow(gamma)}")
    focal_weight = (alpha * target + (1 - alpha) * (1 - target)) * pt.pow(gamma)
    print(f"focal_weight: {focal_weight}")
    loss = F.binary_cross_entropy_with_logits(pred, target, reduction='none') * focal_weight
    print(f"loss: {loss}")
    loss = loss.mean()
    return loss

# 1和0的组合
def test2():
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

    idx = 3
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

    loss_weather = sigmoid_focal_loss(predict_stack, targets_stack, gamma=2, alpha=0.25, reduction='mean')
    print(f"loss_weather: {loss_weather:.8f}")

# -1和0的组合
def test3():
    targets_weather = torch.tensor([[0., 0., 0., 1., 0.],
        [-1., 0., 0., 0., 1.],
        [0., 0., 0., 0., 1.],
        [-1., 0., 0., 0., 1.],
        [0., 0., 0., 1., 0.],
        [-1., 0., 0., 1., 0.],
        [0., 0., 0., 1., 0.],
        [-1., 1., 0., 0., 0.]])
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

    idx = 0
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

    loss_weather = sigmoid_focal_loss(predict_stack, targets_stack, gamma=2, alpha=0.25, reduction='mean')
    print(f"loss_weather: {loss_weather:.8f}")

if __name__ == "__main__":
    # test1()
    # test2()
    test3()