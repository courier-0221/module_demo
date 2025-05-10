
# 自定义一个 可迭代对象，并不是迭代器，结合yield无限制的返回

class DaliDataLoader():
    def __init__(self,) -> None:
        self.data = [0,1,2,3,4,5,6,7,8,9]

    # 构造成迭代器
    def __len__(self,):
        return len(self.data)

    def __iter__(self,):
        while True:
            for batch_data in self.data:
                yield batch_data


datasets = DaliDataLoader()
print(len(datasets))

count = 0
for data_unit in datasets:
    count += 1
    if count > 20:
        break
    print(data_unit)
