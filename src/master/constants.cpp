/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>

#include <string>

#include <stout/bytes.hpp>

#include "master/constants.hpp"

namespace mesos {
namespace internal {
namespace master {

const int MAX_OFFERS_PER_FRAMEWORK = 50;
const double MIN_CPUS = 0.1;
const Bytes MIN_MEM = Megabytes(32);
const Duration SLAVE_PING_TIMEOUT = Seconds(15);
const uint32_t MAX_SLAVE_PING_TIMEOUTS = 5;
const double RECOVERY_SLAVE_REMOVAL_PERCENT_LIMIT = 1.0; // 100%.
const size_t MAX_DEACTIVATED_SLAVES = 100000;
const uint32_t MAX_COMPLETED_FRAMEWORKS = 50;
const uint32_t MAX_COMPLETED_TASKS_PER_FRAMEWORK = 1000;
const Duration WHITELIST_WATCH_INTERVAL = Seconds(5);
const uint32_t TASK_LIMIT = 100;
const std::string MASTER_INFO_LABEL = "info";

} // namespace mesos {
} // namespace internal {
} // namespace master {
