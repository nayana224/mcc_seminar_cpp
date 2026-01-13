#include <iostream>
#include <memory>
#include <vector>

// 1. 하드웨어 드라이버 (독점 리소스)
class MotorDriver {
public:
    MotorDriver() { std::cout << "[HW] 모터 드라이버 연결 성공\n"; }
    ~MotorDriver() { std::cout << "[HW] 모터 드라이버 연결 해제\n"; }
    void move(int velocity) { std::cout << "모터를 " << velocity << " 속도로 구동\n"; }
};

// 2. 센서 데이터 (공유 리소스)
class LidarData {
public:
    LidarData() { std::cout << "[Data] 라이다 데이터 생성\n"; }
    ~LidarData() { std::cout << "[Data] 라이다 데이터 소멸\n"; }
    void info() { std::cout << "장애물 거리: 1.5m\n"; }
};

int main() {
    // --- [unique_ptr 예제] ---
    // 모터 드라이버는 시스템에 단 하나만 존재해야 하며, 제어권이 명확해야 함
    std::unique_ptr<MotorDriver> motor = std::make_unique<MotorDriver>();
    motor->move(100);

    // std::unique_ptr<MotorDriver> error_ptr = motor; // (에러!) 복사 불가능
    std::unique_ptr<MotorDriver> new_owner = std::move(motor); // 소유권 이전 가능
    if (!motor) std::cout << "기존 motor 포인터는 이제 빈 껍데기입니다.\n";


    // --- [shared_ptr 예제] ---
    // 센서 데이터는 여러 모듈(장애물 회피, 지도 생성 등)이 동시에 참조함
    std::shared_ptr<LidarData> raw_data = std::make_shared<LidarData>();
    {
        std::shared_ptr<LidarData> obstacle_avoidance_module = raw_data; // 참조 횟수 2
        std::shared_ptr<LidarData> mapping_module = raw_data;           // 참조 횟수 3
        
        std::cout << "현재 데이터를 공유 중인 모듈 수: " << raw_data.use_count() << "\n";
        obstacle_avoidance_module->info();
    } // 블록을 벗어나면 두 모듈은 소멸하지만, raw_data가 살아있어 데이터는 유지됨

    std::cout << "블록 밖 참조 수: " << raw_data.use_count() << "\n";

    return 0;
} // 모든 main 함수가 끝날 때 raw_data와 new_owner가 자동으로 해제됨