#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MinimalSubscriber
: public rclcpp::Node
{
public:
// 생성자
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, std::placeholders::_1)
        );
    }

private:
// 멤버 변수
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

// 멤버 함수
    void topic_callback(const std_msgs::msg::String& msg) 
    {
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
    }
};


int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}