#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"


class SimpleTfBroadcaster
: public rclcpp::Node
{
public:
// 생성자
    SimpleTfBroadcaster()
    : Node("simple_tf2_broadcaster")
    {
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(*this);

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(10), std::bind(&SimpleTfBroadcaster::broadcast_timer_callback, this)
        );

        RCLCPP_INFO(this->get_logger(), "tf2 broadcaster is started!");
    }

private:
// 멤버 변수
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

// 멤버 함수
    void broadcast_timer_callback()
    {
        geometry_msgs::msg::TransformStamped t;

        t.header.stamp = this->get_clock()->now();
        t.header.frame_id = "world";
        t.child_frame_id = "robot_link";

        double time = this->get_clock()->now().seconds();
        t.transform.translation.x = 0.5 * cos(time);
        t.transform.translation.y = 0.5 * sin(time);
        t.transform.translation.z = 0.0;

        tf2::Quaternion q;
        q.setRPY(0, 0, time); // roll, pitch, yaw
        t.transform.rotation.x = q.x();
        t.transform.rotation.y = q.y();
        t.transform.rotation.z = q.z();
        t.transform.rotation.w = q.w();

    // tf 토픽으로 정보 송신
        tf_broadcaster_->sendTransform(t);
    }
    
};


int main(int argc, char* argv[]) 
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleTfBroadcaster>());
    rclcpp::shutdown();
    return 0;
}