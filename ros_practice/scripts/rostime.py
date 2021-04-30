#! /usr/bin/env python

import roslib
import rospy
import actionlib
import sys
import os
import time

def Run():
	print("time.time ", time.time())
	now = rospy.rostime.get_rostime()
	rospy.rostime.wallsleep(1)
	n =rospy.Time().now()
	duration = n - now
	print(duration.secs, duration.nsecs)

  #rospy.loginfo("time", now.secs)
	#print("rospy.Time.now() ", rospy.Time.now().nsecs)
	#print("float time format", rospy.get_time())

if __name__ == '__main__':
  try:
		rospy.init_node('time_test')
		Run()
  except rospy.ROSInterruptException:
    print("error.")