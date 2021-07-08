#!/bin/bash

name=$1
rosbag filter $name ${name}_filtered.bag 'topic == "/scan_matched_points2" or (topic == "/tf" and m.transforms[0].header.frame_id != "base_footprint" and m.transforms[0].header.frame_id != "base_link" and m.transforms[0].header.frame_id != "odom")'