#!/bin/bash

name=$1
rosbag filter $name ${name}_filtered.bag 'topic == "/odom" or topic == "/scan" or topic == "/imu" or topic == "/odometry/filtered" or topic == "/tf_static"  or (topic == "/tf" and m.transforms[0].header.frame_id != "map" )'
