/*
Copyright (c) 2017, prpl Foundation
Permission to use, copy, modify, and/or distribute this software for any purpose with or without
fee is hereby granted, provided that the above copyright notice and this permission notice appear
in all copies.
THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE
FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef IID_CONFIGURATION_H
#define IID_CONFIGURATION_H

#ifdef __cplusplus
extern "C"
{
#endif

/*! \addtogroup Configuration
*/

/*@{*/

/******************************************************************************
 * POSIX headers 
 *****************************************************************************/

/*! \brief Does <limits.h> exist.
    \details Macro IID_HAS_LIMITS_H can be set to 1 if <limits.h> is available AND it defines macro CHAR_BIT.
 */
#define IID_HAS_LIMITS_H 1

/*! \brief Does <stdint.h> exist.
    \details Macro IID_HAS_STDINT_H can be set to 1 if <stdint.h> is available AND it defines type definitions for intN_t and uintN_t.
 */
#define IID_HAS_STDINT_H 1

/*! \brief Does <stdbool.h> exist.
    \details Macro IID_HAS_STDBOOL_H can be set to 1 if <stdbool.h> is available AND it defines the type definition for bool and _Bool.
 */
#define IID_HAS_STDBOOL_H 1

/*! \brief Does <string.h> exist.
    \details Macro IID_HAS_STRING_H can be set to 1 if <string.h> is available AND it declares function prototypes for \p memcmp, \p memcpy and \p memset.
 */
#define IID_HAS_STRING_H 1

/*! \brief Does <assert.h> exist.
    \details Macro IID_HAS_ASSERT_H can be set to 1 if <assert.h> is available AND it declares the macro \p assert.
 */
#define IID_HAS_ASSERT_H 1

/*! \brief Does long long type exist.
    \details Macro IID_HAS_LONG_LONG can be set to 1 if the data type \p long \p long exists for the current platform.
 */
#define IID_HAS_LONG_LONG 1

/*@}*/

#ifdef __cplusplus
}
#endif

#endif /* IID_CONFIGURATION_H */
