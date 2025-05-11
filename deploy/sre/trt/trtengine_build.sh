# 查看info
# trtexec --onnx=/home/dear/code/VoiceprintRecognition-Pytorch/models/Res2Net_pt_onnx/inference.onnx --verbose

# 动态input，最小、最优、最大，无量化
trtexec --onnx=/home/dear/code/VoiceprintRecognition-Pytorch/models/Res2Net_pt_onnx/inference.onnx \
        --saveEngine=sre.plan \
        --minShapes=feature:1x1x80 \
        --optShapes=feature:1x512x80 \
        --maxShapes=feature:1x1024x80
