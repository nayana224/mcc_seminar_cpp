cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#####################################################
# 필요한 패키지 불러오기
#####################################################
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)


#####################################################
# 실행 파일 생성하기
#####################################################
add_executable(talker src/publisher_member_function.cpp)
add_executable(listener src/subscriber_member_function.cpp)


#####################################################
# 의존성 연결하기
#####################################################
ament_target_dependencies(talker
  rclcpp
  std_msgs
)
ament_target_dependencies(listener
  rclcpp
  std_msgs
)


#####################################################
# ros2 run 명령어로 실행할 수 있도록 install 폴더로 복사하기
#####################################################
install(TARGETS
  talker
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
