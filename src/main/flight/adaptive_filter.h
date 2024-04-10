/*
 * This file is part of INAV Project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License Version 3, as described below:
 *
 * This file is free software: you may copy, redistribute and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 */

#include "common/axis.h"
#include "common/time.h"

#define ADAPTIVE_FILTER_BUFFER_SIZE 64
#define ADAPTIVE_FILTER_RATE_HZ 100
#define ADAPTIVE_FILTER_LPF_HZ 1
#define ADAPTIVE_FILTER_HPF_HZ 15
#define ADAPTIVE_FILTER_INTEGRATOR_THRESHOLD_HIGH 5.0f
#define ADAPTIVE_FILTER_INTEGRATOR_THRESHOLD_LOW -2.0f

void adaptiveFilterPush(const flight_dynamics_index_t index, const float value);
void adaptiveFilterPushRate(const flight_dynamics_index_t index, const float rate, const uint8_t configRate);
void adaptiveFilterResetIntegrator(void);
void adaptiveFilterSetDefaultFrequency(int lpf, int min, int max);
void adaptiveFilterTask(timeUs_t currentTimeUs);
