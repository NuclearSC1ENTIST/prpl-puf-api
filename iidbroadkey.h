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
#ifndef __IID_BROADKEY__H__
#define __IID_BROADKEY__H__

#include "iid_platform.h"

#ifdef __cplusplus
extern "C"
{
#endif

/************************************************************************
*                        D E F I N I T I O N S                          *
*************************************************************************/
#define BK_SECURITY_SIZE_BITS          256

#define BK_SRAM_SIZE_BYTES             1024
#define BK_AC_SIZE_BYTES               788

#define BK_KEY_CODE_HEADER_SIZE_BYTES  44

/*! \brief Defines the key types used in the \ref bk_get_key function.
*/
typedef enum key_type {
    /* Symmetric key types */
    S_128          = 0x53300080,
    S_192          = 0x533000C0,
    S_256          = 0x53300100,

    /* ECC curves for private key generation */
    E_SECP192R1    = 0x453000C0,
    E_SECP224R1    = 0x453000E0,
    E_SECP256R1    = 0x45300100,
    E_SECP384R1    = 0x45300180,
    E_SECP521R1    = 0x45300209
} key_type_t;


/****************************************************************************
*                      P U B L I C  I N T E R F A C E                       *
*****************************************************************************/
/*! \brief Get the software version.

    \details Get the software version of this Broadkey module.

    \param[out] *majorVersion Pointer to a byte for holding the major software version.

    \param[out] *minorVersion Pointer to a byte for holding the minor software version.

    \returns \ref IID_SUCCESS if success, otherwise another return code.
*/
iid_return_t bk_get_software_version(uint8_t * const major_version,
                                     uint8_t * const minor_version);


/*! \brief Initalizes Broadkey module.

    \details This function initializes the Broadkey module and it must
             be called prior to any other Broadkey function call.

    \param[in] *sram_puf Pointer to physical SRAM that will be used
                by Broadkey as PUF memory.
                Its address must be aligned to 32 bits.

    \param[in] sram_puf_size The size in bytes of available SRAM PUF that can
                             be used by Broadkey. It must be of at least
                             \ref BK_SRAM_SIZE_BYTES.

    \returns \ref IID_SUCCESS if success, otherwise another return code.
*/
iid_return_t bk_init(      uint8_t  * const sram_puf,
                     const uint16_t         sram_puf_size);


/*! \brief Enrolls Broadkey by generating of an activation code.

    \details Activation code is generated by this function call based on
             the PUF memory.

    \param[out] *activation_code Pointer to an array of bytes of size defined by
                                 \ref BK_AC_SIZE_BYTES that will contain the
                                 resulting activation code.
                                 Its address must be aligned to 32 bits.

    \returns \ref IID_SUCCESS if success, otherwise another return code.
*/
iid_return_t bk_enroll(uint8_t * const activation_code);


/*! \brief Reconstructs the intrinsic key.

    \details Reconstructs the intrinsic key using the PUF area of SRAM and the
             activation code given as a parameter.

    \param[in] *activation_code Pointer to an array of bytes containing an activation
                                code, previously generated by \ref bk_enroll function
                                call. The size in bytes of the activation code is
                                defined by the \ref BK_AC_SIZE_BYTES constant.
                                Its address must be aligned to 32 bits.

    \returns \ref IID_SUCCESS.
*/
iid_return_t bk_start(const uint8_t * const activation_code);


/*! \brief Finalize Broadkey usage.

    \details Cleans internal Broadkey data that was filled in response to
             \ref bk_start and \bk_enroll calls (intrinsic and other
             internally generated/used keys).

    \returns \ref IID_SUCCESS if success, otherwise another return code.
*/
iid_return_t bk_stop(void);


/*! \brief Get a device-specific key.

    \details This function generates either a symmetric or ECC private device-specific key.
             It can be called after enrollment or start.

    \param[in] key_type Value that specifies the type of the key which will be generated.
                        Its value must be one of the values enumerated in \ref key_type_t.

    \param[in] index Value between 0 and 255 specifying the index associated to the key
                     that will be generated.

    \param[out] *key Pointer to an array of bytes which will hold the generated key.
                     Its size depends on the specified \ref key_type:
                        - 16 bytes for SYMMETRIC_128
                        - 24 bytes for SYMMETRIC_192
                        - 32 bytes for SYMMETRIC_256
                        - 24 bytes for SECP_192R1
                        - 28 bytes for SECP_224R1
                        - 32 bytes for SECP_256R1
                        - 48 bytes for SECP_384R1
                        - 66 bytes for SECP_521R1

    \returns \ref IID_SUCCESS if success, otherwise another return code.
*/
iid_return_t bk_get_key(const key_type_t         key_type,
                        const uint8_t            index,
                              uint8_t    * const key);


/*! \brief Wrap a key into a key code.

    \details This functions wraps a key into a key code.
             It can be called after enrollment or start.

    \param[in] index Value between 0 and 255 specifying the index associated to the
                     key that will be generated.

    \param[in] *key Pointer to an array of bytes which holds the key that has to be wrapped.
                    Its size in bytes must be in the [4, 1024] range and a multiple of 4.
                    Its address must be aligned to 32 bits.

    \param[in] key_length Value that specifies the length in bytes of \ref key.
                          Its value must be in the [4, 1024] range and a multiple of 4.

    \param[out] *key_code Pointer to an array of bytes which will hold the wrapped key.
                          Its size in bytes must be of \ref BK_KEY_CODE_HEADER_SIZE_BYTES +
                          the size of \ref key.
                          Its address must be aligned to 32 bits.

    \returns \ref IID_SUCCESS if success, otherwise another return code.
*/
iid_return_t bk_wrap(const uint8_t          index,
                     const uint8_t  * const key,
                     const uint16_t         key_length,
                           uint8_t  * const key_code);


/*! \brief Unwrap a key code into a key.

    \details This functions unwraps a key code into a key.
             It can be called after enrollment or start.

    \param[in] *key_code Pointer to an array of bytes that holds the key code generated by
                         \ref bk_wrap.
                         Its address must be aligned to 32 bits.

    \param[out] *key Pointer to an array of bytes which will hold the unwrapped key.
                     Its size in bytes must be the same of \ref key used in \ref bk_wrap.
                     Alternatively, its size in bytes can be calculated by subtracting
                     \ref BK_KEY_CODE_HEADER_SIZE_BYTES from the size of \ref key_code.
                     Its address must be aligned to 32 bits.

    \param[out] *key_length Pointer to a byte buffer which will contain the size in bytes
                            of \ref key.
                            Its value will be in the [4, 1024] range and a multiple of 4.

    \param[out] *index Pointer to a byte buffer which will contain the index associated to
                       \ref key.

    \returns \ref IID_SUCCESS if success, otherwise another return code.
*/
iid_return_t bk_unwrap(const uint8_t  * const key_code,
                             uint8_t  * const key,
                             uint16_t * const key_length,
                             uint8_t  * const index);


#ifdef __cplusplus
}
#endif

#endif /* __IID_BROADKEY__H__ */