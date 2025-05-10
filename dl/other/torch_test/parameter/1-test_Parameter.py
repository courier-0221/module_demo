import torch
import torch.nn as nn

class MyModel(nn.Module):
    def __init__(self):
        super(MyModel, self).__init__()
        self.weight = nn.Parameter(torch.randn(10, 5))
        print(f"weight: {self.weight}")
        self.bias = nn.Parameter(torch.zeros(10))
        print(f"bias: {self.bias}")

    def forward(self, x):
        output = torch.matmul(x, self.weight.t()) + self.bias
        return output

def test_parameter():
    mm = MyModel()
    input = torch.ones(10, 5)
    print(f"input: {input}")
    print(f"result: {mm(input)}")

if __name__ == "__main__":
    test_parameter()