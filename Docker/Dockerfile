FROM ros:noetic


RUN apt-get update
RUN apt-get install -y git && apt-get install -y python3-pip
RUN apt-get install --assume-yes ros-$(rosversion -d)-turtlesim
RUN mkdir -p /catkin_ws/src && cd /catkin_ws/src && \
    git clone https://github.com/alphacep/ros-vosk.git


    
RUN /bin/bash -c "source /opt/ros/${ROS_DISTRO}/setup.bash && \
    cd /catkin_ws && \
    catkin_make"

RUN echo "source /opt/ros/noetic/setup.bash" >> /root/.bashrc

RUN echo "ALL DONE."