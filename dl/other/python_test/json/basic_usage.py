import json

# 解析简单的 JSON 对象
json_str = '{"name": "Alice", "age": 30}'
data = json.loads(json_str)
print(data["name"])  # 输出 "Alice"
print(data["age"])  # 输出 30
print("-"*80)

# 解析包含数组的 JSON 对象
json_str = '{"fruits": ["apple", "banana", "orange"]}'
data = json.loads(json_str)
print(data["fruits"])
print(type(data["fruits"])) # type = list

# 方式1
print(data["fruits"][0])  # 输出 "apple"
print(data["fruits"][1])  # 输出 "banana"
print(data["fruits"][2])  # 输出 "orange"
print("\n")

# 方式2
for node in data["fruits"]:
    print(node)

print("-"*80)

# 解析嵌套的 JSON 对象
json_str = '{"person": {"name": "Bob", "age": 25}}'
data = json.loads(json_str)
print(data["person"])
print(type(data["person"]))     # type = dict

# 方式1
print(data["person"]["name"])  # 输出 "Bob"
print(data["person"]["age"])  # 输出 25

# 方式2
# 因为是dict，可以使用items方法访问里面的内容
for key, value in data["person"].items():
    print(f"key: {key}, value: {value}")

print("-"*80)