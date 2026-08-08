#ifndef _SMAC_H_
#define _SMAC_H_

/// @file smac.h
/// @brief SMAC Common Definitions
/// @details This header file defines common types and return values used across the SMAC
///          middleware and its components.
/// @author Khose-ie<khose-ie@outlook.com>
/// @date   2026-08-09

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/// @brief Standard return value enumeration
/// @details Represents standard return values for SAM functions
typedef enum
{
    //===============================
    // General logic errors 0x00
    //===============================
    SMAC_RET_OK             = 0x0000, ///< Success
    SMAC_RET_PARAM_ERR      = 0x0001, ///< Invalid parameter
    SMAC_RET_BUSY           = 0x0002, ///< Resource busy
    SMAC_RET_TIMEOUT        = 0x0003, ///< Timeout occurred
    SMAC_RET_STACK_OVERFLOW = 0x0004, ///< Stack overflow
    SMAC_RET_PERMISSION     = 0x0005, ///< Permission denied
    SMAC_RET_NULL_REF       = 0x0006, ///< Null pointer reference

    SMAC_RET_NOT_SUPPORT   = 0x0008, ///< Operation not supported
    SMAC_RET_NOT_AVAILABLE = 0x0009, ///< Resource not available

    //===============================
    //  Basic operation errors 0x01
    //===============================
    SMAC_RET_MEM_ALLOC_FAILURE = 0x0100, ///< Memory allocation failure
    SMAC_RET_FORMAT_FAILURE    = 0x0101, ///< Format failure
    SMAC_RET_LOW_LEVEL_FAILURE = 0x0102, ///< Low-level API failure

    //===============================
    //  Instance management errors 0x02
    //===============================
    SMAC_RET_INSTANCE_CREATE_FAILURE = 0x0200, ///< Failed to create instance
    SMAC_RET_INSTANCE_NOT_FOUND      = 0x0201, ///< Instance not found
    SMAC_RET_INSTANCE_DUPLICATE      = 0x0202, ///< Instance already exists
    SMAC_RET_INSTANCE_IN_USE         = 0x0203, ///< Instance is in use
    SMAC_RET_INSTANCE_UNAVAILABLE    = 0x0204, ///< Instance unavailable

    //===============================
    //  MCU specific errors 0x04
    //===============================
    SMAC_RET_MCU_HW_FAILURE    = 0x0400, ///< MCU hardware failure
    SMAC_RET_MCU_CLOCK_FAILURE = 0x0401, ///< MCU clock or timing error
    SMAC_RET_MCU_RESET         = 0x0402, ///< Unexpected MCU reset

    //===============================
    //  OS specific errors 0x05
    //===============================
    SMAC_RET_OS_KERNEL_ERR    = 0x0500, ///< OS kernel operation failed
    SMAC_RET_OS_EVENT_ERR     = 0x0501, ///< Task deletion failed
    SMAC_RET_OS_MEM_POOL_ERR  = 0x0502, ///< Memory pool operation failed
    SMAC_RET_OS_MQ_ERR        = 0x0503, ///< Message queue operation failed
    SMAC_RET_OS_MUTEX_ERR     = 0x0504, ///< Mutex operation failed
    SMAC_RET_OS_SEMAPHORE_ERR = 0x0505, ///< Semaphore operation failed
    SMAC_RET_OS_TASK_ERR      = 0x0506, ///< Task deletion failed
    SMAC_RET_OS_TIMER_ERR     = 0x0507, ///< Timer creation failed

    //===============================
    //  File system errors 0x06
    //===============================
    SMAC_RET_FS_MOUNT_FAILURE     = 0x0600, ///< File system mount failure
    SMAC_RET_FS_FORMAT_FAILURE    = 0x0601, ///< File system format failure
    SMAC_RET_FS_NOT_VALID_FS      = 0x0602, ///< No valid file system found
    SMAC_RET_FS_NOT_FILE          = 0x0603, ///< Not a file
    SMAC_RET_FS_NOT_DIR           = 0x0604, ///< Not a directory
    SMAC_RET_FS_DIR_NOT_EMPTY     = 0x0605, ///< Directory not empty
    SMAC_RET_FS_DISK_NOT_READY    = 0x0606, ///< Disk not ready
    SMAC_RET_DISK_WRITE_PROTECTED = 0x0607, ///< Disk write protected
    SMAC_RET_DISK_IO_ERR          = 0x0608, ///< Low-level disk I/O error

    //===============================
    //  Network errors 112-127
    //===============================

    //===============================
    //  Peripheral extension errors 128-254
    //===============================

    //===============================
    //  Unknown error 255
    //===============================
    SMAC_RET_UNKNOWN = 0xFFFF ///< Unknown error
} smacRetCode_t;

/// @brief Function used to get count of aligned type
/// @details This function calculates the number of elements of the aligned type required to hold an
/// object of the specified type.
#define aligned_countof(type, aligned_type)                                                        \
    (((sizeof(type) + (sizeof(aligned_type))) - 1) / sizeof(aligned_type))

/// @brief Function used to get byte size aligned to a specific type
/// @details This function calculates the byte size of a type aligned to the specified alignment
/// type.
#define aligned_sizeof(type, aligned_type)                                                         \
    (aligned_countof(type, aligned_type) * sizeof(aligned_type))

/// @brief Function used to align a byte size to a 32-bit boundary
/// @details This function calculates the byte size aligned to the next 32-bit boundary.
#define align32up(number_of_bytes) (((number_of_bytes) + 3) & ~3)

/// @brief Function used to align a byte size to a 32-bit boundary downwards
/// @details This function calculates the byte size aligned to the previous 32-bit boundary.
#define align32down(number_of_bytes) ((number_of_bytes) & ~3)

/// @brief Function used to align a byte size to a 64-bit boundary
/// @details This function calculates the byte size aligned to the next 64-bit boundary.
#define align64up(number_of_bytes) (((number_of_bytes) + 7) & ~7)

/// @brief Function used to align a byte size to a 64-bit boundary downwards
/// @details This function calculates the byte size aligned to the previous 64-bit boundary.
#define align64down(number_of_bytes) ((number_of_bytes) & ~7)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SMAC_H_
