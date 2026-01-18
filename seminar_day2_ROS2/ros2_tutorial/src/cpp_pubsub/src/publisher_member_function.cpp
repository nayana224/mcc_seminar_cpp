#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MinimalPublisher 
: public rclcpp::Node
{
public:
// 생성자
    MinimalPublisher()
    : Node("minimal_publisher"), count_(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(500), std::bind(&MinimalPublisher::timer_callback, this)
        );
    }


private:
// 멤버변수
    size_t count_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

// 멤버함수
    void timer_callback()
    {
        std_msgs::msg::String message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: %s ", message.data.c_str());
        publisher_->publish(message);
    }
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv); // ROS2 통신 초기화
    rclcpp::spin(std::make_shared<MinimalPublisher>()); // 노드 생성 후 대기
    rclcpp::shutdown(); // 종료시 자원 반납
    return 0;
}
