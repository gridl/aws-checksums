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

#include <intrin.h>
#include <inttypes.h>
#include <aws/checksums/private/aws_cpuid.h>

#if  defined(_M_X64) || defined(_M_IX86)

static int cpuid_check_ran = 0;
static int32_t cpuid_output = 0;

int aws_checksums_is_cpuid_supported(void) {
    return 1;
}

int aws_checksums_do_cpu_id(int32_t *cpuid) {

    if (!cpuid_check_ran) {
        int cpu_info[4] = { -1 };
        __cpuid(cpu_info, 0);
        unsigned nIds_ = cpu_info[0];

        __cpuid(cpu_info, 0);

        if (nIds_ >= 2) {
            __cpuid(cpu_info, 1);
            cpuid_output = cpu_info[2];
        }
        else {
            return 0;
        }

        cpuid_check_ran = 1;
    }

    *cpuid = cpuid_output;
    return 1;
}

#endif
