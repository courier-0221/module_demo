rm sync/gen-cpp -rf
rm asyn/gen-cpp -rf

# 生成同步代码
thrift -r -o sync --gen cpp:no_skeleton clientInfo.thrift
# 生成异步代码
thrift -r -o asyn --gen cpp:cob_style,no_skeleton clientInfo.thrift