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

#ifndef __MASTER_FLAGS_HPP__
#define __MASTER_FLAGS_HPP__

#include <string>

#include <stout/duration.hpp>
#include <stout/flags.hpp>

#include "logging/flags.hpp"

#include "master/constants.hpp"

namespace mesos {
namespace internal {
namespace master {

class Flags : public logging::Flags
{
public:
  Flags()
  {
    add(&Flags::version,
        "version",
        "Show version and exit.",
        false);

    add(&Flags::hostname,
        "hostname",
        "The hostname the master should advertise in ZooKeeper.\n"
        "If left unset, system hostname will be used (recommended).");

    add(&Flags::root_submissions,
        "root_submissions",
        "Can root submit frameworks?",
        true);

    add(&Flags::work_dir,
        "work_dir",
        "Where to store master specific files\n",
        "/tmp/mesos");

    // TODO(bmahler): Add replicated log backed registry.
    add(&Flags::registry,
        "registry",
        "Persistence strategy for the registry;\n"
        "available options are 'in_memory'.",
        "in_memory");

    // TODO(bmahler): Set the default to true in 0.20.0.
    add(&Flags::registry_strict,
        "registry_strict",
        "Whether the Master will take actions based on the persistent\n"
        "information stored in the Registry. Setting this to false means\n"
        "that the Registrar will never reject the admission, readmission,\n"
        "or removal of a slave. Consequently, 'false' can be used to\n"
        "bootstrap the persistent state on a running cluster.",
        false);

    // TODO(bmahler): Add a 'Percentage' abstraction for flags.
    // TODO(bmahler): Add a --production flag for production defaults.
    add(&Flags::recovery_slave_removal_limit,
        "recovery_slave_removal_limit",
        "For failovers, limit on the percentage of slaves that can be removed\n"
        "from the registry *and* shutdown after the re-registration timeout\n"
        "elapses. If the limit is exceeded, the master will fail over rather\n"
        "than remove the slaves.\n"
        "This can be used to provide safety guarantees for production\n"
        "environments. Production environments may expect that across Master\n"
        "failovers, at most a certain percentage of slaves will fail\n"
        "permanently (e.g. due to rack-level failures).\n"
        "Setting this limit would ensure that a human needs to get\n"
        "involved should an unexpected widespread failure of slaves occur\n"
        "in the cluster.\n"
        "Values: [0%-100%]",
        stringify(RECOVERY_SLAVE_REMOVAL_PERCENT_LIMIT * 100.0) + "%");

    add(&Flags::webui_dir,
        "webui_dir",
        "Location of the webui files/assets",
        PKGDATADIR "/webui");

    add(&Flags::whitelist,
        "whitelist",
        "Path to a file with a list of slaves\n"
        "(one per line) to advertise offers for.\n"
        "Path could be of the form 'file:///path/to/file' or '/path/to/file'",
        "*");

    add(&Flags::user_sorter,
        "user_sorter",
        "Policy to use for allocating resources\n"
        "between users. May be one of:\n"
        "  dominant_resource_fairness (drf)",
        "drf");

    add(&Flags::framework_sorter,
        "framework_sorter",
        "Policy to use for allocating resources\n"
        "between a given user's frameworks. Options\n"
        "are the same as for user_allocator",
        "drf");

    add(&Flags::allocation_interval,
        "allocation_interval",
        "Amount of time to wait between performing\n"
        " (batch) allocations (e.g., 500ms, 1sec, etc)",
        Seconds(1));

    add(&Flags::cluster,
        "cluster",
        "Human readable name for the cluster,\n"
        "displayed in the webui");

    add(&Flags::roles,
        "roles",
        "A comma seperated list of the allocation\n"
        "roles that frameworks in this cluster may\n"
        "belong to.");

    add(&Flags::weights,
        "weights",
        "A comma seperated list of role/weight pairs\n"
        "of the form 'role=weight,role=weight'. Weights\n"
        "are used to indicate forms of priority.");

    add(&Flags::authenticate,
        "authenticate",
        "If authenticate is 'true' only authenticated frameworks are allowed\n"
        "to register. If 'false' unauthenticated frameworks are also\n"
        "allowed to register.",
        false);

    add(&Flags::credentials,
        "credentials",
        "Path to a file with a list of credentials.\n"
        "Each line contains a 'principal' and 'secret' separated by whitespace.\n"
        "Path could be of the form 'file:///path/to/file' or '/path/to/file'");
  }

  bool version;
  Option<std::string> hostname;
  bool root_submissions;
  std::string work_dir;
  std::string registry;
  bool registry_strict;
  std::string recovery_slave_removal_limit;
  std::string webui_dir;
  std::string whitelist;
  std::string user_sorter;
  std::string framework_sorter;
  Duration allocation_interval;
  Option<std::string> cluster;
  Option<std::string> roles;
  Option<std::string> weights;
  bool authenticate;
  Option<std::string> credentials;
};

} // namespace mesos {
} // namespace internal {
} // namespace master {

#endif // __MASTER_FLAGS_HPP__
