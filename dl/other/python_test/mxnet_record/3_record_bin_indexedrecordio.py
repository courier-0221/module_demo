# 二进制数据的保存和读取

import mxnet as mx

# 字符串数据的读取和保存
#需要保存的字符串数据
data = "data"
#label可以是列表类型的数据
label1 = 1.0#[1.0,2.0,3.0]
#数据的id
id = 1
#打包数据的标签和id
header1 = mx.recordio.IRHeader(flag=0,label=label1,id=id,id2=0)
#将字符串转为二进制数据
s1 = mx.recordio.pack(header1,str.encode(data))
#解压数据
unpack_header1,unpack_s1 = mx.recordio.unpack(s1)
print(unpack_header1)#HEADER(flag=0, label=1.0, id=1, id2=0)
#获取数据的标签和id信息
print(unpack_header1.label,unpack_header1.id)#1.0 1
#获取压缩的数据
print(unpack_s1.decode())#data



# 图片数据的保存和读取
print("-"*20)
# 保存rec文件
write_record = mx.recordio.MXIndexedRecordIO("test.idx","test.rec", 'w')
#读取图片
img_path = "/home/dear/下载/lena.png"
#将图片数据转为Numpy数组
img = mx.image.imread(img_path).asnumpy()
label = 1.0
header = mx.recordio.IRHeader(flag=0,label=label,id=0,id2=0)
s = mx.recordio.pack_img(header, img)
#将数据写入到rec文件中
write_record.write_idx(0,s)
write_record.close()

# 读取rec
read_record = mx.recordio.MXIndexedRecordIO("test.idx","test.rec","r")
#遍历rec文件
for idx in read_record.keys:
    item = read_record.read()
    #解压数据
    header,s = mx.recordio.unpack(item)
    #将图片的bytes数据转换为ndarray
    img = mx.image.imdecode(s)
    print(img.shape)
