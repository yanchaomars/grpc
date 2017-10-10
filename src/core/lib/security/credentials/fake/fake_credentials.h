/*
 *
 * Copyright 2016 gRPC authors.
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
 *
 */

#ifndef GRPC_CORE_LIB_SECURITY_CREDENTIALS_FAKE_FAKE_CREDENTIALS_H
#define GRPC_CORE_LIB_SECURITY_CREDENTIALS_FAKE_FAKE_CREDENTIALS_H

#include "src/core/lib/security/credentials/credentials.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Fake transport security credentials. -- */

/* Creates a fake transport security credentials object for testing. */
grpc_channel_credentials *grpc_fake_transport_security_credentials_create(void);

/* Creates a fake server transport security credentials object for testing. */
grpc_server_credentials *grpc_fake_transport_security_server_credentials_create(
    void);

/* Used to verify the target names given to the fake transport security
 * connector.
 *
 * The syntax of \a expected_targets by example:
 * For LB channels:
 *     "backend_target_1,backend_target_2,...;lb_target_1,lb_target_2,..."
 * For regular channels:
 *     "backend_taget_1,backend_target_2,..."
 *
 * That is to say, LB channels have a heading list of LB targets separated from
 * the list of backend targets by a semicolon. For non-LB channels, only the
 * latter is present. */
grpc_arg grpc_fake_transport_expected_targets_arg(char *expected_targets);

/* Return the value associated with the expected targets channel arg or NULL */
const char *grpc_fake_transport_get_expected_targets(
    const grpc_channel_args *args);

/* --  Metadata-only Test credentials. -- */

typedef struct {
  grpc_call_credentials base;
  grpc_mdelem md;
  bool is_async;
} grpc_md_only_test_credentials;

#ifdef __cplusplus
}
#endif

#endif /* GRPC_CORE_LIB_SECURITY_CREDENTIALS_FAKE_FAKE_CREDENTIALS_H */
