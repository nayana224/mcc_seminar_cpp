cmake_minimum_required(VERSION 3.8)
project(tf2_broadcaster)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


#####################################################
# 필요한 패키지 불러오기
#####################################################
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)

#####################################################
# 실행 파일 생성하기
#####################################################
add_executable(tf2_broadcaster src/tf2_broadcaster.cpp)


#####################################################
# 의존성 연결하기
#####################################################
ament_target_dependencies(tf2_broadcaster
  rclcpp
  tf2_ros
  geometry_msgs
  tf2
)

#####################################################
# ros2 run 명령어로 실행할 수 있도록 install 폴더로 복사하기
#####################################################
install(TARGETS tf2_broadcaster
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
