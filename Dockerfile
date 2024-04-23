FROM ros:noetic

ENV ROS_DISTRO=noetic

RUN mkdir -p /catkin_ws/src

COPY <path_to_your_ROS_package(s)> /catkin_ws/src/

RUN apt-get update && apt-get install -y \
    ros-${ROS_DISTRO}-catkin \
    ros-${ROS_DISTRO}-ros \
    ros-${ROS_DISTRO}-your-package-dependencies \
    && rm -rf /var/lib/apt/lists/*

RUN /bin/bash -c "source /opt/ros/${ROS_DISTRO}/setup.bash && \
    cd /catkin_ws && \
    catkin_make"

RUN echo "source /catkin_ws/devel/setup.bash" >> /root/.bashrc

EXPOSE 11311

CMD ["bash"]
