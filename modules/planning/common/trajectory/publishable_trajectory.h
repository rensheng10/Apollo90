/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file publishable_trajectory.h
 **/

#ifndef MODULES_PLANNING_COMMON_TRAJECTORY_PUBLISHABLE_TRAJECTORY_H_
#define MODULES_PLANNING_COMMON_TRAJECTORY_PUBLISHABLE_TRAJECTORY_H_

#include "modules/planning/common/trajectory/discretized_trajectory.h"
#include "modules/planning/proto/planning.pb.h"

namespace apollo {
namespace planning {

class PublishableTrajectory : public DiscretizedTrajectory {
 public:
  PublishableTrajectory() = default;

  PublishableTrajectory(const double header_time,
      std::vector<common::TrajectoryPoint> trajectory_points);

  virtual ~PublishableTrajectory() = default;

  common::TrajectoryPoint EvaluateAbsoluteTime(
      const double abs_time) const;

  common::TrajectoryPoint EvaluateAbsoluteTimeUsingLinearApproximation(
      const double abs_time) const;

  std::uint32_t QueryNearestPointAbsoluteTime(const double abs_time) const;

  double header_time() const;

  void set_header_time(const double header_time);

  void PopulateTrajectoryProtobuf(ADCTrajectory* trajectory_pb) const;

 private:
  double header_time_ = 0.0;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_COMMON_TRAJECTORY_PUBLISHABLE_TRAJECTORY_H
