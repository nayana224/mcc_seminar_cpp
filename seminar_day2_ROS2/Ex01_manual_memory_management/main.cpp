#include <iostream>

class MotorDriver 
{
public:
// 생성자
    MotorDriver()
    {
        std::cout << "[HW] 모터 드라이버 연결 성공\n";
    }

// 소멸자
    ~MotorDriver()
    {
        std::cout << "[HW] 모터 드라이버 연결 해제\n";
    }

// 멤버함수
    void move(int velocity)
    {
        std::cout << "모터를 " << velocity << " 속도로 구동\n";
    }
};


int main()
{
    MotorDriver* motor = new MotorDriver;
    motor->move(100);

    delete motor;

    return 0;
}

