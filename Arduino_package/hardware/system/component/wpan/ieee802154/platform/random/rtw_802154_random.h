/* Copyright (c) 2019, Realtek
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this
 *      list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *
 *   3. Neither the name of Realtek nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * @brief Module that defines the pseudo-random number generator Abstraction Layer.
 *
 */

#ifndef RTW_802154_RANDOM_H_
#define RTW_802154_RANDOM_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup rtw_802154_random Random Abstraction Layer for the 802.15.4 driver
 * @{
 * @ingroup rtw_802154_random
 * @brief The pseudo-random number generator Abstraction Layer interface for the 802.15.4 driver.
 *
 * The Random Abstraction Layer is an abstraction layer of a pseudo-random number generator that is
 * used to perform CSMA-CA procedure correctly.
 *
 */

/**
 * @brief Initializes the random number generator.
 */
void rtw_802154_random_init(void);

/**
 * @brief Deinitializes the random number generator.
 */
void rtw_802154_random_deinit(void);

/**
 * @brief Gets a pseudo-random number.
 *
 * @returns Pseudo-random number.
 */
uint32_t rtw_802154_random_get(void);

/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif /* RTW_802154_RANDOM_H_ */
