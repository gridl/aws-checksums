#ifndef AWS_CRC_H_
#define AWS_CRC_H_
/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <stdint.h>
#include <aws/checksums/aws_checksums_exports.h>

#ifdef __cplusplus
extern "C" {  // only need to export C interface if
              // used by C++ source code
#endif

/**
* The entry point function to perform a CRC32 (Ethernet, gzip) computation.
* Selects a suitable implementation based on hardware capabilities.
* Pass 0 in the previousCrc32 parameter as an initial value unless continuing
* to update a running crc in a subsequent call.
*/
AWS_CHECKSUMS_API uint32_t aws_checksums_crc32(const uint8_t *input, int length, uint32_t previousCrc32);

/**
* The entry point function to perform a Castagnoli CRC32c (iSCSI) computation.
* Selects a suitable implementation based on hardware capabilities.
* Pass 0 in the previousCrc32 parameter as an initial value unless continuing
* to update a running crc in a subsequent call.
*/
AWS_CHECKSUMS_API uint32_t aws_checksums_crc32c(const uint8_t *input, int length, uint32_t previousCrc32);

#ifdef __cplusplus
}
#endif

#endif /* AWS_CRC_H_ */
