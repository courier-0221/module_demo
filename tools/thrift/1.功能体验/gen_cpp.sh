thrift -r --gen cpp student.thrift
#thrift -r --gen java student.thrift     //生成java代码
#thrift -r --gen py student.thrift　　　　//生成python代码

rm gen-cpp/Serv_server.skeleton.cpp -rf