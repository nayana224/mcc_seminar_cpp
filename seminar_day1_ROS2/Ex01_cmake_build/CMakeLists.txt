# CMake 최소 버전 설정
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 설정
project(Ex01_cmake_build)

# 실행 파일 생성 및 소스 파일 지정
add_executable(main
    src/main.cpp
    src/utils.cpp
)

# 헤더 파일 경로 지정
# 컴파일러가 "include" 폴더 안의 .hpp 파일들을 찾게 함
target_include_directories(main PUBLIC include)
