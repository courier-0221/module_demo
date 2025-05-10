# 自定义一个datasets

import torch
from PIL import Image
from torch.utils.data import Dataset
from torchvision import transforms
from torch.utils.data import DataLoader


class CustomDataset(Dataset):
    def __init__(self, root_dir, transform=None):
        self.root_dir = root_dir
        self.transform = transform
        self.labels = []
        with open(root_dir + '/labels.txt', 'r') as f:
            for line in f:
                self.labels.append(int(line.strip()))

    def __len__(self):
        return len(self.labels)

    def __getitem__(self, idx):
        img_path = self.root_dir + '/images/' + str(idx) + '.jpg'
        image = Image.open(img_path)
        label = self.labels[idx]
        if self.transform:
            image = self.transform(image)
        return image, label


transform = transforms.Compose([
    transforms.Resize((224, 224)),
    transforms.ToTensor(),
    transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))
])

dataset = CustomDataset('data', transform=transform)
dataloader = DataLoader(dataset, batch_size=32, shuffle=True)