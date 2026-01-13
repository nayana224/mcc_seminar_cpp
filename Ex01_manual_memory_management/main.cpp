#include <iostream>

class LidarSensor 
{
public:
// 생성자
    LidarSensor()
    {
        std::cout << "Lidar 전원 ON\n";
    }
// 소멸자
    ~LidarSensor()
    {
        std::cout << "Lidar 전원 OFF\n";
    }
};

// 클래스 생성 & 소멸 함수 호출
void processSensor()
{
    LidarSensor* sensor = new LidarSensor();

    delete sensor;
}


int main()
{
    /*
    // 아래 반복문 코드는 실행하면 안 되는 코드
    while(1)
    {
        processSensor(); // 루프가 반복될수록 메모리가 서서히 잠식됨
    }
    */


    processSensor();

    return 0;
}