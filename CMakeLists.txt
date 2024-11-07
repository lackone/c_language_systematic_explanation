cmake_minimum_required(VERSION 3.29)

#获取cmake当前所在目录的名字
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
#把空格替换成下划线
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C)

set(CMAKE_C_STANDARD 11)

#拿到目录下所有.c的文件，存到files里
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    #添加可执行文件
    add_executable(${name} ${file})
endforeach ()
