#include <iostream>
#include <memory>


// [Data 영역] 초기화된 전역 변수
int sensor_id = 101;

void process_data(int param) // [Stack 영역] 매개 변수 
{
    // [Stack 영역] 지역 변수 (함수 종료 시 자동 소멸) 
    int local_val = 50;

    // [Heap 영역] 동적 할당 (사용자가 직접 관리)
    int* heap_val = new int(200);

    std::cout << "작업 중...\n";

    delete heap_val; // 해체하지 않으면  Memory Leak 발생
}

int main()
{   
    // [Code 영역] 함수 호출 관련
    process_data(10);
    return 0;
}