#! /usr/bin/env python

import roslib
import rospy
import math
import tf
import geometry_msgs.msg
import tf_conversions
# from tf_conversions.transformations import quaternion_from_euler

if __name__ == '__main__':
  rospy.init_node('tf_listener')

  listener = tf.TransformListener()

  rate = rospy.Rate(15.0)
  while not rospy.is_shutdown():
    try:
        (trans,rot) = listener.lookupTransform('/map', '/laser', rospy.Time(0))
    except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
        continue
    (r,p,y) = tf_conversions.transformations.euler_from_quaternion(rot)
    print("yaw: ", y)
    rate.sleep()

# quat = [0, 1, 0, 0]
# quat_msg = Quaternion(quat[0], quat[1], quat[2], quat[3])
# q = quaternion_from_euler(1.57,0,1.57)