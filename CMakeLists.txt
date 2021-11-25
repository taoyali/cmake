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
aux_source_directory(src DIR_SRCS)

# 5. set enviroment variable：设置环境变量，编译用到的源文件全部要放到这里，
#                             否则编译能够通过，但是执行的时候会出现各种问题， 比如“symbol lookup error xxxx, undefined symbol”
set(PROJECT_SRC ${DIR_SRCS})

# 5. add executable file: 添加要编译的可执行文件
add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SRC})
# add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

# 6. add link library: 添加可执行文件所需的库，
#                     比如用到了libm.so(命名规则：lib+name+.so), m就是添加该库的名称
# target_link_libraries(${CMAKE_PROJECT_NAME} m)



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
option(USE_MYMATH "Use tutorial provided math implementation" ON) 
Message(status " " ${USE_MYMATH} " This is a USE_MYMATH")

# add the MathFunctions library,Add a subdirectory to the build，将新加的子目录用于build 
if(USE_MYMATH) 
  # 需要重新定义USE_MYMATH变量
  add_definitions(-DUSE_MYMATH)
  add_subdirectory(math)
  list(APPEND EXTRA_LIBS math)
  Message(status " " "${PROJECT_SOURCE_DIR}/math" " This is a Project_source_dir")
endif(USE_MYMATH) 



    
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${EXTRA_LIBS}) 

# target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC 
                          #  "${PROJECT_BINARY_DIR}" 
                          #  )


include_directories("${PROJECT_BINARY_DIR}")


install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin) 
install(FILES "${PROJECT_BINARY_DIR}/src/AppConfigure.h" 
  DESTINATION include 
  ) 








  
Message(status " " ${PROJECT_SOURCE_DIR} " This is a Project_source_dir")
Message(status " " ${Mymake_SOURCE_DIR} " This is a Project_source_dir")

Message(status " " ${PROJECT_BINARY_DIR} " This is a Project_binary_dir")



