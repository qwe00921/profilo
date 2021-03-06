/**
 * Copyright 2004-present, Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cppdistract/dso.h>

namespace facebook {

using namespace cppdistract;

/**
 * These methods return dso objects for the libraries they're named after.
 */

dso const& libart();

dso const& libcxx();

dso const& libc();

dso const& libnativehelper();

dso const& libm();

dso const& libhwui();

dso const& libutils();

dso const& libandroid();

dso const& libcutils();

dso const& libandroid_runtime();

dso const& libbinder();

dso const& libgui();

} // namespace facebook
