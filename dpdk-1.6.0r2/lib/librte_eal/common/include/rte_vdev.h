/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2014 6WIND S.A.
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
 *     * Neither the name of 6WIND S.A. nor the names of its
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

#ifndef _RTE_VDEV_H_
#define _RTE_VDEV_H_

/**
 * @file
 *
 * RTE Virtual Devices Interface
 *
 * This file manages the list of the virtual device drivers.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/queue.h>

/** Double linked list of virtual device drivers. */
TAILQ_HEAD(rte_vdev_driver_list, rte_vdev_driver);

/**
 * Initialization function called for each virtual device probing.
 */
typedef int (rte_vdev_init_t)(const char *name, const char *args);

/**
 * A structure describing a virtual device driver.
 */
struct rte_vdev_driver {
	TAILQ_ENTRY(rte_vdev_driver) next;  /**< Next in list. */
	const char *name;                   /**< Driver name. */
	rte_vdev_init_t *init;              /**< Device init. function. */
};

/**
 * Register a virtual device driver.
 *
 * @param driver
 *   A pointer to a rte_vdev structure describing the driver
 *   to be registered.
 */
void rte_eal_vdev_driver_register(struct rte_vdev_driver *driver);

/**
 * Unregister a virtual device driver.
 *
 * @param driver
 *   A pointer to a rte_vdev structure describing the driver
 *   to be unregistered.
 */
void rte_eal_vdev_driver_unregister(struct rte_vdev_driver *driver);

#ifdef __cplusplus
}
#endif

#endif /* _RTE_VDEV_H_ */
