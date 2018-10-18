/*
 * Copyright (c) <year>, <copyright holder>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MOTION_PRIMITIVE_NODELET_H
#define MOTION_PRIMITIVE_NODELET_H

#include <nodelet/nodelet.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Int8.h>

namespace motion_primitives {
class MotionPrimitiveNodelet : public nodelet::Nodelet {
public:
  MotionPrimitiveNodelet() { return; }
  ~MotionPrimitiveNodelet() { return; }

private:
  void onInit() override;

  // Load parameters and create ROS I/O.
  // These are the processes to be completed during initialization.
  void loadParameters();
  void createRosIO();

  // Callback functions for the action command,
  // which is either from a joystick or a action planner.
  void joyCallback(const sensor_msgs::JoyConstPtr& joy_msg);
  void actionCallback(const std_msgs::Int8ConstPtr& action_msg);


  // Publiser and subscribers.
  ros::Publisher cmd_pub;
  ros::Subscriber action_sub;
  ros::Subscriber joy_sub;
};
} // End namespace motion_primitives.


#endif

