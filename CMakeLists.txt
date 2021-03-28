cmake_minimum_required(VERSION 3.8)
project(LastCourseWork)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.1\\mingw81_64\\lib\\cmake")


# включаем поиск библиотек с использованием find_package()
# через REQUIRED указываем, что библиотеки обязательны
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

#if (APPLE)
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++")
#else
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
#endif()
#set(SOURCE_FILES main.cpp)
include_directories(${CMAKE_BINARY_DIR})
add_executable(LastCourseWork main.cpp mainwindow.cpp rsa.cpp elgamal.cpp)

# указываем, какие библиотеки необходимо подключить
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
