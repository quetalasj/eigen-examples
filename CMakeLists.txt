cmake_minimum_required(VERSION 3.16)
project(eigenMatrix)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)
find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})


add_executable(eigenMatrix eigenMatrix.cpp)
add_executable(useGeometry useGeometry.cpp)
add_executable(coordinateTransform coordinateTransform.cpp)
add_executable(plotTrajectory plotTrajectory.cpp)
add_executable(visualizeGeometry visualizeGeometry.cpp)

target_link_libraries(eigenMatrix Eigen3::Eigen)
target_link_libraries(useGeometry Eigen3::Eigen)
target_link_libraries(coordinateTransform Eigen3::Eigen)


target_link_libraries(plotTrajectory Eigen3::Eigen ${Pangolin_LIBRARIES})
target_link_libraries(visualizeGeometry Eigen3::Eigen ${Pangolin_LIBRARIES})