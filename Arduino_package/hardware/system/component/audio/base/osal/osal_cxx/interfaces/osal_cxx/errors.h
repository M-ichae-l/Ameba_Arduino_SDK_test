/*
 * Copyright (c) 2021 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup OSAL
 * @{
 *
 * @brief Declares the structures and interfaces for the Operating System Abstraction Layer (OSAL) module.
 *
 * The OSAL module provide a unified interfaces that adapter to different OS. The interfaces include the
 * memory management, thread, mutex, semaphore, time.
 *
 * @since 1.0
 * @version 1.0
 */

/**
 * @file errors.h
 *
 * @brief Declares commonly used error codes.
 *
 * @since 1.0
 * @version 1.0
 */

#ifndef AMEBA_BASE_OSAL_OSAL_CXX_INTERFACES_OSAL_CXX_ERRORS_H
#define AMEBA_BASE_OSAL_OSAL_CXX_INTERFACES_OSAL_CXX_ERRORS_H

#include <sys/types.h>
#include <errno.h>

namespace ameba
{

// use this type to return error codes
typedef int32_t res_t;

/*
 * Error codes.
 * All error codes are negative values.
 */

enum {
	OK                = 0,    // Everything's swell.
	NO_ERROR          = 0,    // No errors.

	UNKNOWN_ERROR       = (-2147483647 - 1), // INT32_MIN value

	NO_MEMORY           = -ENOMEM,
	INVALID_OPERATION   = -ENOSYS,
	BAD_VALUE           = -EINVAL,
	BAD_TYPE            = (UNKNOWN_ERROR + 1),
	NAME_NOT_FOUND      = -ENOENT,
	PERMISSION_DENIED   = -EPERM,
	NO_INIT             = -ENODEV,
	ALREADY_EXISTS      = -EEXIST,
	DEAD_OBJECT         = -EPIPE,
	FAILED_TRANSACTION  = (UNKNOWN_ERROR + 2),
	BAD_INDEX           = -EOVERFLOW,
	NOT_ENOUGH_DATA     = -ENODATA,
	WOULD_BLOCK         = -EWOULDBLOCK,
	TIMED_OUT           = -ETIMEDOUT,
	UNKNOWN_TRANSACTION = -EBADMSG,
	FDS_NOT_ALLOWED     = (UNKNOWN_ERROR + 7),
	UNEXPECTED_NULL     = (UNKNOWN_ERROR + 8),

	OPERATION_FAIL      = (UNKNOWN_ERROR + 9),
};

}; // namespace ameba

#endif // AMEBA_BASE_OSAL_OSAL_CXX_INTERFACES_OSAL_CXX_ERRORS_H
/** @} */
