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

#ifndef _IID_PLATFORM_H_
#define _IID_PLATFORM_H_

#include "iid_configuration.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*! \addtogroup Platform
*/
/*@{*/

#if IID_HAS_LIMITS_H == 1
#include <limits.h>
#elif !defined(CHAR_BIT)
/*! \brief The number of bits in a \p char.
    \details The number of bits in a \p char. Most architectures use 8 bits per \p char. Some older architectures used to have 7 bits per \p char.
*/
#define CHAR_BIT 8
#endif

#if IID_HAS_STDINT_H == 1
#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif
#else /* IID_HAS_STDINT_H == 1 */
#ifdef WIN32

/*! \brief Signed 8 bit value.
    \details A signed integer type with width 8.
*/
typedef signed __int8    int8_t;

/*! \brief Signed 16 bit value.
    \details A signed integer type with width 16.
*/
typedef signed __int16   int16_t;

/*! \brief Signed 32 bit value.
    \details A signed integer type with width 32.
*/
typedef signed __int32   int32_t;

/*! \brief Signed 64 bit value.
    \details A signed integer type with width 64.
*/
typedef signed __int64   int64_t;

/*! \brief Unsigned 8 bit value.
    \details An unsigned integer type with width 8.
*/
typedef unsigned __int8  uint8_t;

/*! \brief Unsigned 16 bit value.
    \details An unsigned integer type with width 16.
*/
typedef unsigned __int16 uint16_t;

/*! \brief Unsigned 32 bit value.
    \details An unsigned integer type with width 32.
*/
typedef unsigned __int32 uint32_t;

/*! \brief Unsigned 64 bit value.
    \details An unsigned integer type with width 64.
*/
typedef unsigned __int64 uint64_t;

/*! \brief Unsigned 32 bit pointer.
    \details An unsigned pointer type with width 32.
*/
typedef uint32_t           uintptr_t;

#else /* WIN32 */

/* These defaults may need tweaking. */

/*! \brief Signed 8 bit value.
    \details A signed integer type with width 8.
*/
typedef signed char        int8_t;

/*! \brief Signed 16 bit value.
    \details A signed integer type with width 16.
*/
typedef signed short       int16_t;

/*! \brief Signed 32 bit value.
    \details A signed integer type with width 32.
*/
typedef signed long        int32_t;

#if IID_HAS_LONG_LONG == 1
/*! \brief Signed 64 bit value.
    \details A signed integer type with width 64.
*/
typedef signed long long   int64_t;
#endif

/*! \brief Unsigned 8 bit value.
    \details An unsigned integer type with width 8.
*/
typedef unsigned char      uint8_t;

/*! \brief Unsigned 16 bit value.
    \details An unsigned integer type with width 16.
*/
typedef unsigned short     uint16_t;

/*! \brief Unsigned 32 bit value.
    \details An unsigned integer type with width 32.
*/
typedef unsigned long      uint32_t;

#if IID_HAS_LONG_LONG == 1
/*! \brief Unsigned 64 bit value.
    \details An unsigned integer type with width 64.
*/
typedef unsigned long long uint64_t;
#endif

#if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__)
/*! \brief Unsigned 64 bit pointer.
    \details An unsigned pointer type with width 64.
*/
typedef uint64_t           uintptr_t;
#else
/*! \brief Unsigned 32 bit pointer.
    \details An unsigned pointer type with width 32.
*/
typedef uint32_t           uintptr_t;
#endif

#endif /* WIN32 */

#ifndef _SIZE_T_DEFINED_
/*! \brief Represents a memory related quantity.
    \details Used to represent the maximum size of any object (including arrays) in this particular implementation.
*/
typedef unsigned int size_t;
#define _SIZE_T_DEFINED_
#endif

#ifndef __CONCAT
#define __CONCATenate(left,right)       left##right
#define __CONCAT(left,right)            __CONCATenate(left,right)
#endif

#ifndef INT8_C
/*! \brief Appends the correct suffix to a 8-bit signed integer literal.
    \details This macro appends the correct suffix to a 8-bit signed integer literal.
*/
#define INT8_C(value)       ((int8_t)value)
#endif

#ifndef INT16_C
/*! \brief Appends the correct suffix to a 16-bit signed integer literal.
    \details This macro appends the correct suffix to a 16-bit signed integer literal.
*/
#define INT16_C(value)      ((int16_t)value)
#endif

#ifndef INT32_C
/*! \brief Appends the correct suffix to a 32-bit signed integer literal.
    \details This macro appends the correct suffix to a 32-bit signed integer literal.
*/
#define INT32_C(value)      ((int32_t)__CONCAT(value, L))
#endif

#if IID_HAS_LONG_LONG == 1
#ifndef INT64_C
/*! \brief Appends the correct suffix to a 64-bit signed integer literal.
    \details This macro appends the correct suffix to a 64-bit signed integer literal.
*/
#define INT64_C(value)      ((int64_t)__CONCAT(value, LL))
#endif
#endif

#ifndef UINT8_C
/*! \brief Appends the correct suffix to a 8-bit unsigned integer literal.
    \details This macro appends the correct suffix to a 8-bit unsigned integer literal.
*/
#define UINT8_C(value)      ((uint8_t)__CONCAT(value, U))
#endif

#ifndef UINT16_C
/*! \brief Appends the correct suffix to a 16-bit unsigned integer literal.
    \details This macro appends the correct suffix to a 16-bit unsigned integer literal.
*/
#define UINT16_C(value)     ((uint16_t)__CONCAT(value, U))
#endif

#ifndef UINT32_C
/*! \brief Appends the correct suffix to a 32-bit unsigned integer literal.
    \details This macro appends the correct suffix to a 32-bit unsigned integer literal.
*/
#define UINT32_C(value)     ((uint32_t)__CONCAT(value, UL))
#endif

#if IID_HAS_LONG_LONG == 1
#ifndef UINT64_C
/*! \brief Appends the correct suffix to a 64-bit unsigned integer literal.
    \details This macro appends the correct suffix to a 64-bit unsigned integer literal.
*/
#define UINT64_C(value)     ((uint64_t)__CONCAT(value, ULL))
#endif
#endif /* IID_HAS_LONG_LONG == 1 */

#ifndef INT8_MAX
/*! \brief Max signed 8 bit value
    \details The maximum value of a 8 bit signed data type.
*/
#define INT8_MAX        0x7F
#endif

#ifndef INT8_MIN
/*! \brief Min signed 8 bit value
    \details The minimum value of a 8 bit signed data type.
*/
#define INT8_MIN        (-INT_MAX - 1)
#endif

#ifndef UINT8_MAX
/*! \brief Max unsigned 8 bit value
    \details The maximum value of a 8 bit unsigned data type.
*/
#define UINT8_MAX       ((INT8_MAX * 2) + 1)
#endif

#ifndef INT16_MAX
/*! \brief Max signed 16 bit value
    \details The maximum value of a 16 bit signed data type.
*/
#define INT16_MAX       0x7FFF
#endif

/*! \brief Min signed 16 bit value
    \details The minimum value of a 16 bit signed data type.
*/
#define INT16_MIN       (-INT16_MAX -1)

#ifndef UINT16_MAX
/*! \brief Max unsigned 16 bit value
    \details The maximum value of a 16 bit unsigned data type.
*/
#define UINT16_MAX      ((__CONCAT(INT16_MAX, U) * 2U) + 1U)
#endif

#ifndef INT32_MAX
/*! \brief Max signed 32 bit value
    \details The maximum value of a 32 bit signed data type.
*/
#define INT32_MAX       0x7FFFFFFFL
#endif

#ifndef INT32_MIN
/*! \brief Min signed 32 bit value
    \details The minimum value of a 32 bit signed data type.
*/
#define INT32_MIN       (-INT32_MAX -1L)
#endif

#ifndef UINT32_MAX
/*! \brief Max unsigned 32 bit value
    \details The maximum value of a 32 bit unsigned data type.
*/
#define UINT32_MAX      ((__CONCAT(INT32_MAX, U) * 2UL) + 1UL)
#endif

#if IID_HAS_LONG_LONG == 1
#ifndef INT64_MAX
/*! \brief Max signed 64 bit value
    \details The maximum value of a 64 bit signed data type.
*/
#define INT64_MAX       0x7FFFFFFFFFFFFFFFLL
#endif

#ifndef INT64_MIN
/*! \brief Min signed 64 bit value
    \details The minimum value of a 64 bit signed data type.
*/
#define INT64_MIN       (-INT64_MAX -1LL)
#endif

#ifndef UINT64_MAX
/*! \brief Max unsigned 64 bit value
    \details The maximum value of a 64 bit unsigned data type.
*/
#define UINT64_MAX      ((__CONCAT(INT64_MAX, U) * 2ULL) + 1ULL)
#endif
#endif /* IID_HAS_LONG_LONG == 1 */

#endif /* IID_HAS_STDINT_H == 1 */

#ifndef NULL
#ifdef __cplusplus
/*! \brief Pointer to an invalid object.
    \details Indicates that the pointer does not refer to a valid object.
*/
#define NULL    0
#else
/*! \brief Pointer to an invalid object.
    \details Indicates that the pointer does not refer to a valid object.
*/
#define NULL    ((void *)0)
#endif
#endif /* NULL */

#if IID_HAS_STDBOOL_H == 1
    #include <stdbool.h>
#else

/*! \brief Signed int value.
    \details A signed integer type.
*/
/*typedef int _Bool;*/

/*! \brief Expands to \ref _Bool
   \details Expands to \ref _Bool. This is a reserved keyword in C++.
*/
#define bool uint8_t

/*! \brief Expands to the integer 1.
    \details Expands to the integer 1.
*/
#define true    1

/*! \brief Expands to the integer 0.
    \details Expands to the integer 0.
*/
#define false   0

/*! \brief Expands to the integer 1.
    \details Expands to the integer 1.
    \remark An application may undefine and then possibly redefine the macros bool, true, and false.
*/
#define __bool_true_false_are_defined   1
#endif /* IID_HAS_STDBOOL_H == 1 */

#if IID_HAS_STRING_H == 1
#ifdef __KERNEL__
#include <linux/string.h>
#else
#include <string.h>
#endif

/*! \brief Macro defining the used memory compare function.
    \details This macro defines which memory compare function is used in the code. The function chosen may enforce bit allignment and data sizes for speed optimizations.
*/
#define iid_memcmp memcmp

/*! \brief Macro defining the used memory copy function.
    \details This macro defines which memory copy function is used in the code. The function chosen may enforce bit allignment and data sizes for speed optimizations.
*/
#define iid_memcpy memcpy

/*! \brief Macro defining the used memory set function.
    \details This macro defines which memory set function is used in the code. The function chosen may enforce bit allignment and data sizes for speed optimizations.
*/
#define iid_memset memset
#else
/*! \brief Compare two blocks of memory.
    \details Compares the first num bytes of the block of memory pointed by ptr1 to the first num bytes pointed by ptr2, returning zero if they all match or a value different from zero representing which is greater if they do not.
    \param[in] ptr1 Pointer to block of memory.
    \param[in] ptr2 Pointer to block of memory.
    \param[in] num Number of bytes to compare.
    \returns Returns an integral value indicating the relationship between the content of the memory blocks:
    - A zero value indicates that the contents of both memory blocks are equal.
    - A value greater than zero indicates that the first byte that does not match in both memory blocks has a greater value in ptr1 than in ptr2 as if evaluated as unsigned char values; And a value less than zero indicates the opposite.

*/
extern int iid_memcmp(const void *ptr1, const void *ptr2, size_t num);

/*! \brief Copy block of memory.
    \details Copies the values of \p num bytes from the location pointed by \p source directly to the memory block pointed by \p destination.\n\n
     The underlying type of the objects pointed by both the source and destination pointers are irrelevant for this function; The result is a binary copy of the data.\n\n
     The function does not check for any terminating null character in \p source - it always copies exactly \p num bytes.\n\n
     To avoid overflows, the size of the arrays pointed by both the \p destination and \p source parameters, shall be at least \p num bytes, and should not overlap.
    \param[in] destination Pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
    \param[in] source Pointer to the source of data to be copied, type-casted to a pointer of type void*.
    \param[in] num Number of bytes to copy.
    \returns \p destination is returned.
*/
extern void *iid_memcpy(void *destination, const void *source, size_t num);

/*! \brief Fill block of memory
    \details Sets the first \p num bytes of the block of memory pointed by \p ptr to the specified \p value (interpreted as an unsigned char).
    \param[in] ptr Pointer to the block of memory to fill.
    \param[in] value Value to be set. The value is passed as an \p int, but the function fills the block of memory using the \p unsigned \p char conversion of this \p value.
    \param[in] num Number of bytes to be set to the value.
    \returns \p ptr is returned.
*/
extern void *iid_memset(void *ptr, int32_t value, size_t num);
#endif /* IID_HAS_STRING_H == 1 */

#if IID_HAS_ASSERT_H == 1
#include <assert.h>
#else
/* For now define an empty assert*/
#define assert(_Expression)     ((void)0)
#endif /* IID_HAS_ASSERT_H */

/*! \brief The number of bits in a \p word.
    \details The number of bits in a \p word. Most architectures use 32 bits per \p word.
*/
#define WORD_BIT        32

/*! \brief The number of bytes in a \p word.
    \details The number of bytes in a \p word. Most architectures use 4 bytes per \p word.
*/
#define WORD_BYTE       4

/*! \brief Possible Symmetric Key sizes.
    \details This enum enumerates the symmetric key sizes that can be used in the Broadkey module
*/
typedef enum
{
    SYM_KEY_SIZE_128 = 16, /*!< Symmetric key of 128 bits */
    SYM_KEY_SIZE_192 = 24, /*!< Symmetric key of 192 bits */
    SYM_KEY_SIZE_256 = 32  /*!< Symmetric key of 256 bits */
} sym_key_size_t;

#if 0
/*
 * The next construction does not work under linux since SIZE_MAX is not defined.
 * We are currently not using this. so we comment iy out for now.
 */
#ifndef SIZE_MAX
#error SIZE_MAX must be defined to determine processor type
#else /* SIZE_MAX */

#if defined(CPU16) || defined(CPU32) || defined (CPU64)
#error Platform contains CPUX defintions, correct iid_platform.h
#else

#if SIZE_MAX == UINT16_MAX
#define CPU16   2
#endif

#if SIZE_MAX == UINT32_MAX
#define CPU32   4
#endif

#if IID_HAS_LONG_LONG == 1
#if SIZE_MAX == UINT64_MAX
#define CPU64   8
#endif
#endif /* IID_HAS_LONG_LONG == 1 */

#endif /* defined(CPU8) || defined(CPU16) || defined(CPU32) || defined (CPU64) */

#endif /* SIZE_MAX */
#endif

#if defined(_MSC_VER)
/* Visual Studio */

/*! \brief Macro to force memory alignment
    \details Macro to force memory alignment.
*/
#define PRE_HIS_ALIGN           __declspec(align(4))

/*! \brief Macro to force memory alignment
\details Macro to force memory alignment.
*/
#define POST_HIS_ALIGN

#ifdef WIN64
#define UNASSIGNED_POINTER (void *)0xCCCCCCCCCCCCCCCC
#else
#define UNASSIGNED_POINTER (void *)0xCCCCCCCC
#endif

#elif defined(__ICCRX__) || defined(__CCRX__)
/* Renesas RX compiler */

/*! \brief Macro to force memory alignment
    \details Macro to force memory alignment.
*/
#define PRE_HIS_ALIGN

/*! \brief Macro to force memory alignment
    \details Macro to force memory alignment.
*/
#define POST_HIS_ALIGN

#define UNASSIGNED_POINTER NULL

#elif defined(__IAR_SYSTEMS_ICC__)
/* IAR compiler */

/*! \brief Macro to force memory alignment
    \details Macro to force memory alignment.
*/
#define PRE_HIS_ALIGN _Pragma("data_alignment = 4")

/*! \brief Macro to force memory alignment
    \details Macro to force memory alignment.
*/
#define POST_HIS_ALIGN 

#define UNASSIGNED_POINTER NULL

#elif defined(__GNUC__)
/* GCC */

/*! \brief Macro to force memory alignment
    \details Macro to force memory alignment.
*/
#define PRE_HIS_ALIGN

/*! \brief Macro to force memory alignment
    \details Macro to force memory alignment.
*/
#define POST_HIS_ALIGN          __attribute__ ((aligned (4)))

#define UNASSIGNED_POINTER NULL
#else
    
#warning "Compiler not recognized. There are no macros available for alignment. UNASSIGNED_POINTER has been set to NULL."

/*! \brief Macro to force memory alignment
    \details Macro to force memory alignment.
*/
#define PRE_HIS_ALIGN

/*! \brief Macro to force memory alignment
    \details Macro to force memory alignment.
*/
#define POST_HIS_ALIGN

#define UNASSIGNED_POINTER NULL
#endif /* defined(_MSC_VER) */


/*! \brief The function return type
    \details
*/
typedef uint8_t iid_return_t;

/*@}*/

#ifdef __cplusplus
}
#endif

#endif /* _IID_PLATFORM_H_ */
