from nvidia.dali.pipeline import Pipeline, pipeline_def
import nvidia.dali.fn as fn
import nvidia.dali.types as types
import cv2
import numpy as np
from nvidia.dali.plugin.pytorch import DALIGenericIterator

def common_pipeline(jpegs, labels):
    images = fn.decoders.image(jpegs, device='mixed')

    images = fn.crop_mirror_normalize(
        images,
        dtype=types.FLOAT,
        mean=[128., 128., 128.],
        std=[128., 128., 128.])
        #device="gpu"
        #output_layout="CHW"
    return images, labels

@pipeline_def
def mxnet_reader_pipeline(rec_file_path, idx_file_path, rank, world_size):
    jpegs, labels = fn.readers.mxnet(
        path=rec_file_path,
        index_path=idx_file_path,
        random_shuffle=True,
        pad_last_batch=True,
        shard_id=rank,
        num_shards=world_size,
        name='Reader'
    )
    return common_pipeline(jpegs, labels)

# 可迭代对象，可以使用for等便利
class DaliDataLoader():
    def __init__(self, rec_path, idx_path, batch_size, num_workers) -> None:
        self.rec_path = rec_path
        self.idx_path = idx_path
        self.batch_size = batch_size # batch_size per gpu
        self.num_workers = num_workers
        self.rank = 0 #torch.distributed.get_rank() # global gpu idx
        self.world_size = 1 #torch.distributed.get_world_size() # global num gpus

        self.dali_iter = self.build_dali_iter()
        self.num_batches = len(self.dali_iter) # num batches per gpu

    def build_dali_iter(self):
        pipes = mxnet_reader_pipeline(rec_file_path=self.rec_path, idx_file_path=self.idx_path, rank=self.rank, world_size=self.world_size, batch_size=self.batch_size, num_threads=self.num_workers, device_id=self.rank)
        dali_iter = DALIGenericIterator(pipes, ['data', 'label'], reader_name='Reader')
        return dali_iter

    # 构造成迭代器
    def __len__(self,):
        return self.num_batches

    def __iter__(self,):
        while True:
            for batch_data in self.dali_iter:
                batch_image = batch_data[0]["data"]
                batch_labels = batch_data[0]["label"]
                yield (batch_image, batch_labels)

def BaseDataLoader():
    batch_size = 128 # batch_size per gpu
    num_workers = 8

    data_list = [
        ['/mnt/work/project/model/perception_wk/transfer_from_nc4/weather', 'weather'],
        ['/mnt/work/project/model/perception_wk/transfer_from_nc4/scene', 'scene'],
        ['/mnt/work/project/model/perception_wk/transfer_from_nc4/time', 'time'],
        ['/mnt/work/project/model/perception_wk/transfer_from_nc4/light', 'light'],
    ]

    dataloader_dict = {}
    for (base_path, base_category) in data_list:
        rec_path = base_path + '.rec'
        idx_path = base_path + '.idx'
        dataloader = DaliDataLoader(rec_path=rec_path, idx_path=idx_path, batch_size=batch_size, num_workers=num_workers)
        dataloader_dict[base_category] = dataloader

    return dataloader_dict['weather'], dataloader_dict['scene'], dataloader_dict['time'], dataloader_dict['light']

def torchtensor_2_cvmat(tensor):
    # 将张量转换为NumPy数组
    numpy_array = tensor.numpy()

    # 将NumPy数组转换为OpenCV矩阵
    opencv_mat = cv2.cvtColor(numpy_array.transpose(1, 2, 0), cv2.COLOR_RGB2BGR)

    # 展示图像
    cv2.imshow('image', opencv_mat)
    cv2.waitKey(5000)
    cv2.destroyAllWindows()


dataloader_weather, dataloader_scene, dataloader_time, dataloader_light = BaseDataLoader()

for data_scene in dataloader_scene:
    images_scene, labels_scene = data_scene[0], data_scene[1]
    # 将tensor从cuda拷贝到cpu上
    img = images_scene[0].cpu()
    print(images_scene.shape, images_scene.shape)
    print("label:", img)
    torchtensor_2_cvmat(img)
    break