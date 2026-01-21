cmake_minimum_required(VERSION 3.8)
project(open_manipulator_x_description)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

#####################################################
# install 폴더로 새로 만든 launch, urdf, meshes 폴더 복사하기
#####################################################
install(
  DIRECTORY launch urdf meshes
  DESTINATION share/${PROJECT_NAME}
)


ament_package()
