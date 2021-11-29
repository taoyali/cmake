# 1. cmake version： 指定cmake版本
cmake_minimum_required(VERSION 3.10)




# 2. project name：指定项目名称，一般和项目的文件夹名称对应
project(Mymake VERSION 1.0)




# 3. head file path： 头文件目录
# include_directories(
#   src
# )





# 4. source directory: 源文件目录
# 查找src目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
# aux_source_directory(src DIR_SRCS)

# aux_source_directory(src/files DIR_SRCS)

# aux_source_directory(src/files DIR_SRCS_FILES)

file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/files/*.h"
    "${PROJECT_SOURCE_DIR}/src/files/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
    "${PROJECT_SOURCE_DIR}/src/*.cc"
)






# 5. set enviroment variable：设置环境变量，编译用到的源文件全部要放到这里，
#                             否则编译能够通过，但是执行的时候会出现各种问题， 比如“symbol lookup error xxxx, undefined symbol”
# set(PROJECT_SRC ${DIR_SRCS})






# 6. add executable file: 添加要编译的可执行文件

# add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

# add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES} ${DIR_SRCS_FILES})

# add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)






# 7. add link library: 添加可执行文件所需的库，
#                     比如用到了libm.so(命名规则：lib+name+.so), m就是添加该库的名称
# target_link_libraries(${CMAKE_PROJECT_NAME} m)






# 8. 添加config
# configure_file 的作用将一份文件拷贝到另一个位置，并修改它的内容，使得在代码中使用CMake中定义的变量
# 版本号：
# configure_file(src/AppConfigure.h.in src/AppConfigure.h)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/AppConfigure.h.in"
  "${PROJECT_BINARY_DIR}/src/AppConfigure.h"
  )
# include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(Mymake_VERSION_MAJOR 1)

# set 定义变量
set(CMAKE_CXX_STANDARD 11)    
set(CMAKE_CXX_STANDARD_REQUIRED True)


# 添加lib库配置     
option(USE_MYMATH "Use tutorial provided math implementation" on) 
Message(status " " ${USE_MYMATH} " This is a USE_MYMATH")






# 9. build项目中的库： 项目中的代码以库的方式被引用
        # add the MathFunctions library,Add a subdirectory to the build，将新加的子目录用于build 
        
# # 第一种方式
# if(USE_MYMATH) 
#   # 需要重新定义USE_MYMATH变量
#   add_definitions(-DUSE_MYMATH)
#   add_subdirectory(math)
#   list(APPEND EXTRA_LIBS math)
#   Message(status " " "${PROJECT_SOURCE_DIR}/math" " This is a Project_source_dir")
# endif(USE_MYMATH) 

# 第二种方式
if(USE_MYMATH)
  add_definitions(-DUSE_MYMATH)
  add_library(math STATIC math/MathFunctions.cpp)
  target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/math/)
# list(APPEND EXTRA_LIBS math)
endif(USE_MYMATH)





# 10. 引用系统、开源库库文件
#    - 1. find_library()                   //  查找lib库  PATHS 不写时默认到系统的/usr/bin下查找
#    - 2. set()                            //  设置头文件集合
#    - 3. target_include_directories()     //  导入头文件到工程
#    - 4. target_link_libraries()          //  指明target依赖的库


find_library(ZMQ libzmq.a REQUIRED PATHS /usr/local/Cellar/zeromq/4.3.4/lib/libzmq.a)
set(LIBZMQ_INCLUDE_DIR /usr/local/Cellar/zeromq/4.3.4/include/)


add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})
# 打开C++17的支持
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)


# target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${LIBZMQ_INCLUDE_DIR})
# target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${libzmq}) 

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC 
                           ${PROJECT_BINARY_DIR}
                           ${LIBZMQ_INCLUDE_DIR}
                           ${math}
                           )
    
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${EXTRA_LIBS} ${ZMQ}) 




# include_directories("${PROJECT_BINARY_DIR}")


# 11. install: 没有install时， make命令不能添加install，只能使用make  不能用make install
# install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin) 
# install(FILES "${PROJECT_BINARY_DIR}/src/AppConfigure.h" 
#   DESTINATION include 
# ) 



# 12. Copy assets files after build 
#
# add_custom_command(
#   TARGET ${CMAKE_PROJECT_NAME}
#   POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_directory
#           "${PROJECT_SOURCE_DIR}/assets"
#           "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/assets")

# add_custom_command(
#   TARGET ${CMAKE_PROJECT_NAME}
#   POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_directory
#           "${PROJECT_SOURCE_DIR}/shader/"
#           "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/shader")


  
# 13. cmake log
Message(status " " ${PROJECT_SOURCE_DIR} " This is a Project_source_dir")
Message(status " " ${Mymake_SOURCE_DIR} " This is a Project_source_dir")
Message(status " " ${PROJECT_BINARY_DIR} " This is a Project_binary_dir")



