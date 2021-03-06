/*-
 *   BSD LICENSE
 * 
 *   Copyright(c) 2010-2014 Intel Corporation. All rights reserved.
 *   All rights reserved.
 * 
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 * 
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 * 
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>

#include <errno.h>
#include <stdint.h>
#include <rte_cpuflags.h>
#include <rte_debug.h>

#include "test.h"


/* convenience define */
#define CHECK_FOR_FLAG(x) \
			result = rte_cpu_get_flag_enabled(x);    \
			printf("%s\n", cpu_flag_result(result)); \
			if (result == -ENOENT)                   \
				return -1;

/*
 * Helper function to display result
 */
static inline const char *
cpu_flag_result(int result)
{
	switch (result) {
	case 0:
		return "NOT PRESENT";
	case 1:
		return "OK";
	default:
		return "ERROR";
	}
}



/*
 * CPUID test
 * ===========
 *
 * - Check flags from different registers with rte_cpu_get_flag_enabled()
 * - Check if register and CPUID functions fail properly
 */

int
test_cpuflags(void)
{
	int result;
	printf("\nChecking for flags from different registers...\n");

	printf("Check for SSE:\t\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_SSE);

	printf("Check for SSE2:\t\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_SSE2);

	printf("Check for SSE3:\t\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_SSE3);

	printf("Check for SSE4.1:\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_SSE4_1);

	printf("Check for SSE4.2:\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_SSE4_2);

	printf("Check for AVX:\t\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_AVX);

	printf("Check for AVX2:\t\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_AVX2);

	printf("Check for TRBOBST:\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_TRBOBST);

	printf("Check for ENERGY_EFF:\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_ENERGY_EFF);

	printf("Check for LAHF_SAHF:\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_LAHF_SAHF);

	printf("Check for 1GB_PG:\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_1GB_PG);

	printf("Check for INVTSC:\t");
	CHECK_FOR_FLAG(RTE_CPUFLAG_INVTSC);



	/*
	 * Check if invalid data is handled properly
	 */
	printf("\nCheck for invalid flag:\t");
	result = rte_cpu_get_flag_enabled(RTE_CPUFLAG_NUMFLAGS);
	printf("%s\n", cpu_flag_result(result));
	if (result != -ENOENT)
		return -1;

	return 0;
}
