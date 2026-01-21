from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import xacro
import os


def generate_launch_description():

    # eduArm_description 패키지의 share 경로 찾기
    pkg_share = FindPackageShare("eduArm_description").find("eduArm_description")

    # xacro 파일 절대 경로 구성
    xacro_file = os.path.join(pkg_share, "urdf", "robot.urdf.xacro")

    # Xacro → URDF 변환
    doc = xacro.process_file(xacro_file)
    robot_description = {"robot_description": doc.toxml()}

    return LaunchDescription(
        [
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                parameters=[robot_description],
                output="screen",
            ),
            Node(
                package="joint_state_publisher",
                executable="joint_state_publisher",
                output="screen",
            ),
            Node(
                package="joint_state_publisher_gui",
                executable="joint_state_publisher_gui",
                output="screen",
            ),
            Node(
                package="rviz2",
                executable="rviz2",
                output="screen",
            ),
        ]
    )