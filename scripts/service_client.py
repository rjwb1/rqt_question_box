#!/usr/bin/env python

from __future__ import print_function

import sys
import rospy
from rqt_question_box.srv import *

def get_gui(question, type):
    rospy.wait_for_service('rqt_question_box')
    try:
        rqt_question_box_client = rospy.ServiceProxy('rqt_question_box', GetGui)
        resp1 = rqt_question_box_client(question, type)
        return resp1.response
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

def usage(valid_input):
    return "Please Use Arg of Choices: {}".format(valid_input)

if __name__ == "__main__":
    valid_input = ["int", "bool", "string"]
    if len(sys.argv) == 2:
        input = str(sys.argv[1])
        if input not in valid_input:
            print(usage(valid_input))
            sys.exit(1)
    else:
        print(usage(valid_input))
        sys.exit(1)
    print("Requesting %s"%(input) + " gui")
    print("Repsonse: {}".format(get_gui("Foo Bar?", input)))