#include <vector>
#include <memory>
#include <iostream>

// < >는 데이터 타입을 나타냄
int main()
{
// 가변 배열(vector)에 int를 담겠다!
    std::vector<int> int_list;
    int_list.push_back(10);
    std::cout << "int_list 변수의 값:" << int_list[0] << '\n';

    // 가변 배열(vecotr)에 double을 담겠다!
    std::vector<double> double_list;
    double_list.push_back(3.14);
    std::cout << "double_list 변수의 값:" << double_list[0] << '\n';

// 우리가 배운 shared_ptr에 int을 담겠다!
    std::shared_ptr motor_ptr = std::make_shared<int>(100);
    std::cout << "motor_ptr이 가르키는 값:" << *motor_ptr << '\n';
    
    return 0;
}