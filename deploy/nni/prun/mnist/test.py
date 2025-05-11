import torch
import torch.nn.functional as F
from torch.optim import SGD

from nni_assets.compression.mnist_model import TorchModel, trainer, evaluator, device

# define the model
model = TorchModel().to(device)

# show the model structure, note that pruner will wrap the model layer.
print(model)



# define the optimizer and criterion for pre-training

optimizer = SGD(model.parameters(), 1e-2)
criterion = F.nll_loss

# pre-train and evaluate the model on MNIST dataset
for epoch in range(3):
    trainer(model, optimizer, criterion)
    evaluator(model)




# Pruning Model
config_list = [{
    'op_types': ['Linear', 'Conv2d'],
    'exclude_op_names': ['fc3'],
    'sparse_ratio': 0.5
}]


from nni.compression.pruning import L1NormPruner
pruner = L1NormPruner(model, config_list)

# show the wrapped model structure, `PrunerModuleWrapper` have wrapped the layers that configured in the config_list.
print(model)

# compress the model and generate the masks
_, masks = pruner.compress()
# show the masks sparsity
for name, mask in masks.items():
    print(name, ' sparsity : ', '{:.2}'.format(mask['weight'].sum() / mask['weight'].numel()))


# need to unwrap the model, if the model is wrapped before speedup
pruner.unwrap_model()

# speedup the model, for more information about speedup, please refer :doc:`pruning_speedup`.
from nni.compression.speedup import ModelSpeedup

ModelSpeedup(model, torch.rand(3, 1, 28, 28).to(device), masks).speedup_model()