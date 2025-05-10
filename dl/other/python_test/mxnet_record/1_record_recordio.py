import mxnet as mx

# 将数据保存为rec文件
write_record = mx.recordio.MXRecordIO("test.rec","w")
for i in range(5):
    #向rec文件中写入数据
    #将字符串数据转换为bytes数据,写入到文件中
    write_record.write(str.encode("record_%d"%i))
write_record.close()


# 读取rec文件的内容
read_record = mx.recordio.MXRecordIO("test.rec","r")
while True:
    item = read_record.read()
    if not item:
        break
    #将bytes数据转换为字符串
    print(item.decode())
read_record.close()

# 重新开始读取rec文件
read_record = mx.recordio.MXRecordIO("test.rec","r")
i = 3
while True:
    item = read_record.read()
    if not item:
        break
    #将bytes数据转换为字符串
    print(item.decode())
#再次读取内容
print(read_record.read())#None
#将指针移到文件的开始位置
read_record.reset()
#读取内容
print(read_record.read())#b'record_0'
read_record.close()
