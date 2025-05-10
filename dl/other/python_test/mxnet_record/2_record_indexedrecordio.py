import mxnet as mx

# 保存数据
write_record = mx.recordio.MXIndexedRecordIO('test.idx', 'test.rec', 'w')
for i in range(5):
    write_record.write_idx(i, str.encode('record_%d'%i))
write_record.close()


# 读取数据
read_record = mx.recordio.MXIndexedRecordIO('test.idx', 'test.rec', 'r')
for i in range(5):
    item = read_record.read()
    if item is None:
        break
    print(item.decode())
read_record.close()


# 获取随机顺序的数据
print("-"*20)
import random

idx_list = [i for i in range(0,4)]
#打乱idx的顺序
random.shuffle(idx_list)
read_record = mx.recordio.MXIndexedRecordIO('test.idx', 'test.rec', 'r')
for i in idx_list:
    #获取指定idx的数据
    read_record.read_idx(i)
    item = read_record.read()
    if item is None:
        break
    print(item.decode())
read_record.close()



# 获取文件中的idx
print("-"*20)
read_record = mx.recordio.MXIndexedRecordIO('test.idx', 'test.rec', 'r')
#通过items来获取idx
for key,_ in read_record.idx.items():
    #key就是文件中的idx
    print(key)
#获取文件的idx
print(read_record.keys)
