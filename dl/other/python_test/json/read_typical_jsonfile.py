import json

# 读取 简单.json 中的内容，统计个数

demo_json_path = r"./demo_1.json"
demo_gts = json.load(open(demo_json_path, 'r'))
print("type: ", type(demo_gts))     # dict
print("count:", len(demo_gts))

print("-"*80)


# 读取demo2.json中的内容
with open('demo_2.json', 'r') as f:
    data = json.load(f)

# 遍历 frames 数组，打印出每个元素的 imageUrl 和 road conditions 字段
print("type: ", type(data))             # dict
print("type: ", type(data['frames']))   # list
for frame in data['frames']:
    print('imageUrl:', frame['imageUrl'])
    print('road conditions:', frame['attributes']['road conditions'])

print("-"*80)



# 读取demo3.json中的内容
with open('demo_3.json', 'r') as f:
    data = json.load(f)

# 遍历 frames 数组，打印出每个元素的 imageUrl 和 road conditions 字段
print("type: ", type(data))             # dict
print("type: ", type(data['frames']))   # list
for frame in data['frames']:
    print("type: ", frame)              # dict
    print("type: ", frame["frames"])    # list
    for f in frame["frames"]:
        print("type: ", type(f))        # dict
        print('imageUrl:', f['imageUrl'])
        print('road conditions:', f['attributes']['road conditions'])

print("-"*80)