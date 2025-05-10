import torch
import torchvision.models as models
import torch.quantization
import os
import onnx
import onnxsim

resnet18_no_quant_onnx = r"./resnet18_no_quant.onnx"
resnet18_has_quant_onnx = r"./resnet18_has_quant.onnx"

def export_norm_onnx(input, model, onnx_path):
    # current_path = os.path.dirname(__file__)
    # file = current_path + "/../../models/onnx/sample_customScalar.onnx"
    torch.onnx.export(
        model         = model, 
        args          = (input,),
        f             = onnx_path,
        input_names   = ["input0"],
        output_names  = ["output0"],
        opset_version = 11)
    print("Finished normal onnx export")

    # check the exported onnx model
    model_onnx = onnx.load(onnx_path)
    onnx.checker.check_model(model_onnx)

    # use onnx-simplifier to simplify the onnx
    print(f"Simplifying with onnx-simplifier {onnxsim.__version__}...")
    model_onnx, check = onnxsim.simplify(model_onnx)
    assert check, "assert check failed"
    onnx.save(model_onnx, onnx_path)

# 加载ResNet18模型
model = models.resnet18(pretrained=True)

# 将模型设置为训练模式
model.train()

# 创建一个数据批次用于量化
data = torch.randn(1, 3, 224, 224)

# 对模型进行动态量化
quantized_model = torch.quantization.quantize_dynamic(
    model, {torch.nn.Conv2d, torch.nn.Linear}, dtype=torch.qint8
)

export_norm_onnx(data, model, resnet18_no_quant_onnx)
export_norm_onnx(data, quantized_model, resnet18_has_quant_onnx)