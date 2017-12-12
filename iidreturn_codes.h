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

#ifndef _IID_RETURN_CODES_H_
#define _IID_RETURN_CODES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*! \defgroup BroadkeyReturnCodes
    \ingroup Broadkey
    \brief The possible return codes returned by Broadkey functions.
*/

/*@{*/

/*! \brief Successful execution
    \details Value indicating the successful execution of the called function.
*/
#define IID_SUCCESS                       0x00

/*! \brief Generic return codes base
    \details Value used internally as the base value for all generic return codes.
*/
#define IID_RETURN_BASE                   0x01

/*! \brief Broadkey return codes base
    \details Value used internally as the base value for all Broadkey-specific return codes.
*/
#define IID_RETURN_BK                     0x20


/******************************* Generic Return Codes *******************************/
/*! \brief Function call not allowed in the current state
    \details Value indicating that the given function call is not allowed in the current
             state of the Broadkey module.
*/
#define IID_NOT_ALLOWED                  (IID_RETURN_BASE + 0x00)

/*! \brief Invalid function parameters
    \details Value indicating that at least one of the parameters passed as argument
             to the function call has an invalid form and/or content.
*/
#define IID_INVALID_PARAMETERS           (IID_RETURN_BASE + 0x01)


/************************** Broadkey Specific Return Codes **************************/
/*! \brief Error startup data
    \details Value indicating that the appointed SRAM address does not contain
             qualitative start-up data which can be used as an SRAM PUF by Broadkey.
             Re-power the device and try again.
*/
#define IID_ERROR_STARTUP_DATA           (IID_RETURN_BK + 0x00)

/*! \brief Invalid activation code
    \details An invalid activation code has been supplied to the \ref bk_start function.
*/
#define IID_INVALID_AC                   (IID_RETURN_BK + 0x01)

/*! \brief Invalid key code
    \details An invalid key code has been supplied to the \ref bk_unwrap function.
*/
#define IID_INVALID_KEY_CODE             (IID_RETURN_BK + 0x04)

/*@}*/

#ifdef __cplusplus
}
#endif

#endif /* _IID_RETURN_CODES_H_ */
