cmake_minimum_required(VERSION 2.8.3)
#project(yolov2)
project(yolov2)
#添加c++ 11标准支持
set(CMAKE_CXX_FLAGS "-std=c++11")
#寻找Opencv库
find_package(OpenCV  REQUIRED)
#添加头文件
#include_directories("../include" "../ncnn/src/" "../ncnn/build/install/include/")
#添加需要链接的库文件目录
#link_directories(../ ../ncnn/build/install/lib/)
#可执行文件的名称和源文件的路径
add_executable(savevideo savevideo.cpp)
#链接Opencv库
#target_link_libraries(savevideo)
target_link_libraries(savevideo ${OpenCV_LIBS})
