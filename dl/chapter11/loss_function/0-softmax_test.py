import torch
import torch.nn.functional as F

# 定义softmax函数
def softmax(X):
    X_exp = torch.exp(X)
    print(f"X_exp: {X_exp}")
    partition = X_exp.sum(0, keepdim=True)
    print(f"partition: {partition}")
    return X_exp / partition  # 这里应用了广播机制



def main():
    print("main")

    x = torch.tensor([1.0, 2.0, 3.0])
    y1 = F.softmax(x, dim=0)
    print(f"y1: {y1}")
    y2 = softmax(x)
    print(f"y2: {y2}")

    # output:
    #     y1: tensor([0.0900, 0.2447, 0.6652])
    #     X_exp: tensor([ 2.7183,  7.3891, 20.0855])
    #     partition: tensor([30.1929])
    #     y2: tensor([0.0900, 0.2447, 0.6652])

if __name__ == "__main__":
    main()