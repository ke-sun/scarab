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

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <pluginlib/class_list_macros.h>
#include <motion_primitives/motion_primitive_nodelet.h>

using namespace std;
using namespace ros;

namespace motion_primitives {

void MotionPrimitiveNodelet::onInit() {

  // Load parameters and create ROS I/O.
  loadParameters();
  createRosIO();

  return;
}

void MotionPrimitiveNodelet::loadParameters() {

  cmd_pub = getPrivateNodeHandle().advertise<
    geometry_msgs::Twist>("vel_cmd", 1);
  joy_sub = getPrivateNodeHandle().subscribe(
      "joy_states", 1, &MotionPrimitiveNodelet::joyCallback, this);
  action_sub = getPrivateNodeHandle().subscribe(
      "action", 1, &MotionPrimitiveNodelet::actionCallback, this);

  return;
}

void MotionPrimitiveNodelet::createRosIO() {
  return;
}

void MotionPrimitiveNodelet::joyCallback(
    const sensor_msgs::JoyConstPtr& joy_msg) {
  return;
}

void MotionPrimitiveNodelet::actionCallback(
    const std_msgs::Int8ConstPtr& action_msg) {
  return;
}

PLUGINLIB_EXPORT_CLASS(
    motion_primitives::MotionPrimitiveNodelet, nodelet::Nodelet);

} // End namespace motion_primitives.


