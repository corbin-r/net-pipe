/*!
 * \file pipe.h
 * \brief Network piping code
 * \details This file contains all code related to network piping and network packet creation
 * \author Corbin Matschull
 * \version 1.1r2
 * \date Aug 28. 2015
 * \pre Make sure you have run ./configure with all options chosen
 * \warning File with throw errors if run outside of GCC or LLVM/Clang
 * \copyright Apache Version 2
 */
#ifndef PIPE_H_
#define PIPE_H_

#include <stdio.h>

/**
 * @brief Global for maximum number of bit outflow through network pipe
 */
#define MAX_PIPE_OUTFLOW 1024

/**
 * \brief This is used to define different sizes of network pipe.
 */
struct pipe_sizes
{
    unsigned short pipe16_t; /**< 16-bit pipe (max of 32-Bit packet size)*/
    unsigned int   pipe32_t; /**< 32-Bit pipe (max of 64-Bit packet size)*/
    unsigned long  pipe64_t; /**< 64-Bit pipe (max of 128-Bit packet size)*/
} pipe_t ; /**< Typename for pipe_sizes */

/**
 * \brief Driver flags
 * \details This contains all flags used for driver deletion and creation
 *
 * \param STACK_CALL_FROM_NULL - Throw in cases of the stack trying to return a null component or variable
 * \param STACK_CALL_HAS_NO_DRIVER - Throw in cases of trying to load a null or missing driver
 * \param STACK_CALL_FORCED_DRIVER - Forces driver to load under all circumstances
 * \param STACK_HAS_EXPLICIT_DRIVER - Uses driver under an explicit circumstance.
 *
 */
enum STACK_DRIVERS
{
    STACK_CALL_FROM_NULL = 0x1C,
    STACK_CALL_HAS_NO_DRIVER = 0x2C,
    STACK_CALL_HAS_FORCED_DRIVER = 0x3C,
    STACK_CALL_HAS_EXPLICIT_DRIVER = 04C
} STACKD_T; /**< Typename variable for STACK_DRIVERS */

/**
 * \brief Checks for precondition code
 *
 * \param cond - What condition is this being run under?
 * \param mcmd[] - Command to be run
 *
 * \return Nothing
 *
 */
void has_precondition(unsigned int *cond, const char mcmd[]);

/**
 * \brief Checks if current pipe has checking in current process
 *
 * \param proc_id - Current Process ID
 * \param psize - Pipe size
 *
 * \return 1 if process has check, 0 if process does not have check
 */
int has_code_check(int proc_id, pipe_sizes *psize);

/**
 * \brief Check for CRC precheck
 *
 * \param check - int value to sign the check with
 *
 * \throw HAS_NO_CRC_CHECK_ERROR
 *
 * \return precheck hash
 */
int has_no_precheck(int check);

/**
 * \brief Delete CRC sign
 *
 * \param check - Check sign
 *
 * \throw HAS_NO_CRC_CHECK_ERROR
 *
 * \return Nothing
 */
void delete_crc(int *check);

#endif
