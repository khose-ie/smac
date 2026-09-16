#ifndef _SMAC_MCU_H_
#define _SMAC_MCU_H_

/// @file smac-mcu.h
/// @brief MCU abstraction layer for SMAC.
/// @details This header defines the MCU abstraction layer for the SMAC library, providing
/// interfaces for UART operations and event handling.
/// @author Khose-ie<khose-ie@outlook.com>
/// @date 2024-08-09
///
/// This approach is efficient, type-safe, and follows the standard FFI pattern for dynamic dispatch
/// across language boundaries.

#include <smac.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/// @brief Special timeout values for MCU operations.
#define SMAC_MCU_WAIT_NOW     (0x00000000)
#define SMAC_MCU_WAIT_FOREVER (0xFFFFFFFF)

/// ============================================================================
/// @defgroup smac_peripheral_handles SMAC Peripheral Device Handles
/// @brief Handle types for various SMAC peripheral devices.
/// @details This group contains the handle types for different SMAC peripheral devices.
/// @{
/// ============================================================================

/// @brief MCU event data type.
/// @details This type represents the event data associated with MCU events.
typedef void* smacMcuEventData_t;

/// @brief ADC handle type.
/// @details This type represents the handle associated with an ADC instance.
typedef void* smacAdc_t;

/// @brief CAN handle type.
/// @details This type represents the handle associated with a CAN instance.
typedef void* smacCan_t;

/// @brief CAN FD handle type.
/// @details This type represents the handle associated with a CAN FD instance.
typedef void* smacCanFd_t;

/// @brief Internal FLASH handle type.
/// @details This type represents the handle associated with an Internal FLASH instance.
typedef void* smacFlash_t;

/// @brief I2C handle type.
/// @details This type represents the handle associated with an I2C instance.
typedef void* smacI2c_t;

/// @brief IO handle type.
/// @details This type represents the handle associated with an IO instance.
typedef void* smacIo_t;

/// @brief PWM handle type.
/// @details This type represents the handle associated with a PWM instance.
typedef void* smacPwm_t;

/// @brief SPI handle type.
/// @details This type represents the handle associated with an SPI instance.
typedef void* smacSpi_t;

/// @brief Timer handle type.
/// @details This type represents the handle associated with a Timer instance.
typedef void* smacTim_t;

/// @brief UART handle type.
/// @details This type represents the handle associated with a UART instance.
typedef void* smacUart_t;

/// @brief Watchdog handle type.
/// @details This type represents the handle associated with a Watchdog instance.
typedef void* smacWdt_t;

/// @}

/// ============================================================================
/// @defgroup smac_peripheral_callbacks SMAC Peripheral Device Callbacks
/// @brief Callback structures for various SMAC peripheral device events.
/// @details This group contains the structures defining the callback functions for different SMAC
/// peripheral device events.
/// @{
/// ============================================================================

/// @brief Structure containing ADC event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various ADC events, such as conversion complete, over-threshold condition, and error.
typedef struct
{
    /// @brief ADC event callback for conversion complete.
    /// @param adc The ADC instance.
    /// @param event_data The event data associated with the conversion complete event.
    /// @param value The converted ADC value.
    void (*convert_complete)(smacAdc_t adc, smacMcuEventData_t event_data, uint32_t value);

    /// @brief ADC event callback for over-threshold condition.
    /// @param adc The ADC instance.
    /// @param event_data The event data associated with the over-threshold event.
    void (*over_threshold)(smacAdc_t adc, smacMcuEventData_t event_data);

    /// @brief ADC event callback for error.
    /// @param adc The ADC instance.
    /// @param event_data The event data associated with the error event.
    /// @param error_code The error code associated with the error event.
    void (*error)(smacAdc_t adc, smacMcuEventData_t event_data, uint32_t error_code);
} smacAdcEvent_t;

/// @brief Structure containing CAN event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various CAN events, such as transmission complete and reception complete.
typedef struct
{
    /// @brief CAN event callback for transmission complete.
    /// @param can The CAN instance.
    /// @param event_data The event data associated with the transmission complete event.
    void (*tx_complete)(smacCan_t can, smacMcuEventData_t event_data);

    /// @brief CAN event callback for reception complete.
    /// @param can The CAN instance.
    /// @param event_data The event data associated with the reception complete event.
    void (*rx_complete)(smacCan_t can, smacMcuEventData_t event_data);
    // void (*message_received)(smacCan_t can, smacMcuEventData_t event_data);
} smacCanEvent_t;

/// @brief Structure containing CAN FD event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various CAN FD events, such as transmission complete and reception complete.
typedef struct
{
    /// @brief CAN FD event callback for transmission complete.
    /// @param canfd The CAN FD instance.
    /// @param event_data The event data associated with the transmission complete event.
    void (*tx_complete)(smacCanFd_t canfd, smacMcuEventData_t event_data);

    /// @brief CAN FD event callback for reception complete.
    /// @param canfd The CAN FD instance.
    /// @param event_data The event data associated with the reception complete event.
    void (*rx_complete)(smacCanFd_t canfd, smacMcuEventData_t event_data);
} smacCanFdEvent_t;

/// @brief Structure containing I2C master event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various I2C master events, such as transmission complete and reception complete.
typedef struct
{
    /// @brief I2C master event callback for transmission complete.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the transmission complete event.
    void (*tx_complete)(smacI2c_t i2c, smacMcuEventData_t event_data);

    /// @brief I2C master event callback for reception complete.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the reception complete event.
    void (*rx_complete)(smacI2c_t i2c, smacMcuEventData_t event_data);

    /// @brief I2C event callback for error.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the error event.
    void (*error)(smacI2c_t i2c, smacMcuEventData_t event_data);
} smacI2cMasterEvent_t;

/// @brief Structure containing I2C slave event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various I2C slave events, such as transmission complete, reception complete, listen complete,
/// and being selected by the master.
typedef struct
{
    /// @brief I2C slave event callback for transmission complete.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the transmission complete event.
    void (*tx_complete)(smacI2c_t i2c, smacMcuEventData_t event_data);

    /// @brief I2C slave event callback for reception complete.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the reception complete event.
    void (*rx_complete)(smacI2c_t i2c, smacMcuEventData_t event_data);

    /// @brief I2C slave event callback for listen complete.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the listen complete event.
    void (*listen_complete)(smacI2c_t i2c, smacMcuEventData_t event_data);

    /// @brief I2C slave event callback for being selected by the master.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the selected event.
    void (*selected)(smacI2c_t i2c, smacMcuEventData_t event_data);

    /// @brief I2C event callback for error.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the error event.
    void (*error)(smacI2c_t i2c, smacMcuEventData_t event_data);
} smacI2cSlaveEvent_t;

/// @brief Structure containing I2C memory event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various I2C memory events, such as memory write complete, memory read complete, and error.
typedef struct
{
    /// @brief I2C event callback for memory write complete.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the memory write complete event.
    void (*write_complete)(smacI2c_t i2c, smacMcuEventData_t event_data);

    /// @brief I2C event callback for memory read complete.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the memory read complete event.
    void (*read_complete)(smacI2c_t i2c, smacMcuEventData_t event_data);

    /// @brief I2C event callback for error.
    /// @param i2c The I2C instance.
    /// @param event_data The event data associated with the error event.
    void (*error)(smacI2c_t i2c, smacMcuEventData_t event_data);
} smacI2cMemEvent_t;

/// @brief Structure containing IO event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various IO events, such as state change.
typedef struct
{
    /// @brief IO event callback for state change.
    /// @param io The IO instance.
    /// @param event_data The event data associated with the state change event.
    void (*state_change)(smacIo_t io, smacMcuEventData_t event_data);
} smacIoEvent_t;

/// @brief Structure containing PWM event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various PWM events, such as pulse completion.
typedef struct
{
    /// @brief PWM event callback for pulse completion.
    /// @param pwm The PWM instance.
    /// @param channel The PWM channel associated with the completion event.
    /// @param event_data The event data associated with the completion event.
    void (*pulse_complete)(smacPwm_t pwm, uint32_t channel, smacMcuEventData_t event_data);
} smacPwmEvent_t;

/// @brief Structure containing SPI event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various SPI events, such as transmission complete, reception complete, simultaneous
/// transmission and reception complete, abort sync completion, and error.
typedef struct
{
    /// @brief SPI event callback for transmission complete.
    /// @param spi The SPI instance.
    /// @param event_data The event data associated with the transmission complete event.
    void (*tx_complete)(smacSpi_t spi, smacMcuEventData_t event_data);

    /// @brief SPI event callback for reception complete.
    /// @param spi The SPI instance.
    /// @param event_data The event data associated with the reception complete event.
    void (*rx_complete)(smacSpi_t spi, smacMcuEventData_t event_data);

    /// @brief SPI event callback for simultaneous transmission and reception complete.
    /// @param spi The SPI instance.
    /// @param event_data The event data associated with the transmission and reception complete
    /// event.
    void (*tx_rx_complete)(smacSpi_t spi, smacMcuEventData_t event_data);

    /// @brief SPI event callback for abort sync completion.
    /// @param spi The SPI instance.
    /// @param event_data The event data associated with the abort event.
    void (*abort_complete)(smacSpi_t spi, smacMcuEventData_t event_data);

    /// @brief SPI event callback for error.
    /// @param spi The SPI instance.
    /// @param event_data The event data associated with the error event.
    void (*error)(smacSpi_t spi, smacMcuEventData_t event_data);
} smacSpiEvent_t;

/// @brief Structure containing Timer event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various Timer events, such as timeout.
typedef struct
{
    /// @brief Timer event callback for timeout.
    /// @param tim The Timer instance.
    /// @param event_data The event data associated with the timeout event.
    void (*timeout)(smacTim_t tim, smacMcuEventData_t event_data);
} smacTimEvent_t;

/// @brief Structure containing UART event callbacks.
/// @details This structure defines the set of callback functions that are invoked in response
/// to various UART events, such as transmission complete, reception complete, abort, and error.
typedef struct
{
    /// @brief UART event callback for transmission complete.
    /// @param uart The UART instance.
    /// @param event_data The event data associated with the transmission complete event.
    void (*tx_complete)(smacUart_t uart, smacMcuEventData_t event_data);

    /// @brief UART event callback for reception complete.
    /// @param uart The UART instance.
    /// @param event_data The event data associated with the reception complete event.
    /// @param length The length of the received data.
    void (*rx_complete)(smacUart_t uart, smacMcuEventData_t event_data, uint32_t length);

    /// @brief UART event callback for reception of a specific size complete.
    /// @param uart The UART instance.
    /// @param event_data The event data associated with the reception of a specific size complete
    /// event.
    void (*rx_size_complete)(smacUart_t uart, smacMcuEventData_t event_data);

    /// @brief UART event callback for abort.
    /// @param uart The UART instance.
    /// @param event_data The event data associated with the abort event.
    void (*abort_complete)(smacUart_t uart, smacMcuEventData_t event_data);

    /// @brief UART event callback for error.
    /// @param uart The UART instance.
    /// @param event_data The event data associated with the error event.
    /// @param error_code The error code associated with the error event.
    void (*error)(smacUart_t uart, smacMcuEventData_t event_data, uint32_t error_code);
} smacUartEvent_t;

/// @}

/// @brief CAN bit rate switch type.
/// @details This type defines whether the CAN FD message should use a bit rate switch.
typedef bool smacCanBitRateSwitch;

/// @brief CAN frame kind type.
/// @details This type defines whether the CAN message uses a standard or extended frame format.
typedef enum
{
    SMAC_CAN_FRAME_STANDARD,
    SMAC_CAN_FRAME_EXTENDED,
} smacCanFrameKind;

/// @brief CAN request kind type.
/// @details This type defines whether the CAN message is a data frame or a remote frame.
typedef enum
{
    SMAC_CAN_DATA,
    SMAC_CAN_REMOTE,
} smacCanRequestKind;

/// @brief CAN error state type.
/// @details This type defines the error state of the CAN controller, indicating whether it is
/// active or passive.
typedef enum
{
    SMAC_CAN_ERROR_ACTIVE,
    SMAC_CAN_ERROR_PASSIVE
} smacCanErrorState;

typedef enum
{
    SMAC_CAN_CLASSIC,
    SMAC_CAN_FD
} smacCanFormat;

/// @brief CAN message header structure.
/// @details This structure defines the header of a CAN message, including standard and extended
/// IDs, identifier type, remote transmission request, and data length code.
/// @note The fields in this structure should be populated according to the CAN message being
/// transmitted or received.
/// @note The identifier field should be populated with the appropriate CAN identifier, whether
/// standard or extended.
typedef struct
{
    uint32_t ident;
    smacCanFrameKind frame_kind;
    smacCanRequestKind request_kind;
    uint32_t data_length;
} smacCanMessageHead;

/// @brief CAN message structure.
/// @details This structure defines a complete CAN message, including both the header and data
/// portions.
/// @note The fields in this structure should be populated according to the CAN message being
/// transmitted or received.
typedef struct
{
    smacCanMessageHead head;
    uint8_t data[8];
} smacCanMessage;

/// @brief CAN FD message header structure.
/// @details This structure defines the header of a CAN FD message, including standard and extended
/// IDs, identifier type, error state, bit rate switch, and data length code.
/// @note The fields in this structure should be populated according to the CAN FD message being
/// transmitted or received.
/// @note The identifier field should be populated with the appropriate CAN FD identifier, whether
/// standard or extended.
typedef struct
{
    uint32_t ident;
    smacCanFrameKind frame_kind;
    smacCanRequestKind request_kind;
    smacCanErrorState error_state;
    smacCanBitRateSwitch switch_bit_rate;
    smacCanFormat format;
    uint32_t data_length;
} smacCanFdMessageHead;

/// @brief CAN FD message structure.
/// @details This structure defines a complete CAN FD message, including both the header and data
/// portions.
/// @note The fields in this structure should be populated according to the CAN FD message being
/// transmitted or received.
typedef struct
{
    smacCanFdMessageHead head;
    uint8_t data[64];
} smacCanFdMessage;

typedef enum
{
    SMAC_FLASH_WRITE_8BIT,
    SMAC_FLASH_WRITE_16BIT,
    SMAC_FLASH_WRITE_32BIT,
    SMAC_FLASH_WRITE_64BIT,
    SMAC_FLASH_WRITE_128BIT,
} smacFlashWriteWide;

/// @brief I2C memory address size enumeration.
/// @details This enumeration defines the possible memory address sizes for I2C memory operations.
/// @note The memory address size should match the requirements of the specific I2C memory device.
typedef enum
{
    SMAC_I2C_MEM_ADDR_BIT8,
    SMAC_I2C_MEM_ADDR_BIT16
} smacI2cMemAddrSize;

/// @brief IO state enumeration.
/// @details This enumeration defines the possible states for an IO instance.
/// @note The IO state should reflect the actual hardware state of the IO instance.
typedef enum
{
    SMAC_IO_RST = 0,
    SMAC_IO_SET = 1
} smacIoState;

/// @brief Macro to initialize a standard CAN message.
/// @details This macro sets up the CAN message header with the specified identifier, request kind,
/// and data length.
/// @param message The CAN message structure to initialize.
/// @param ident The standard identifier for the CAN message.
/// @param request_kind The request kind for the CAN message (e.g., data frame or remote frame).
/// @param data_length The length of the data in the CAN message.
/// @note The message data should be set separately using the smac_can_message_set_data macro.
#define smac_can_message_init(message, ident, request_kind, data_length)                           \
    {                                                                                              \
        message.head.ident        = ident;                                                         \
        message.head.frame_kind   = SMAC_CAN_FRAME_STANDARD;                                       \
        message.head.request_kind = request_kind;                                                  \
        message.head.data_length  = data_length;                                                   \
    }

/// @brief Macro to initialize an extended CAN message.
/// @details This macro sets up the CAN message header with the specified identifier, extended
/// identifier, request kind, and data length.
/// @param message The CAN message structure to initialize.
/// @param ident The standard identifier for the CAN message.
/// @param request_kind The request kind for the CAN message (e.g., data frame or remote frame).
/// @param data_length The length of the data in the CAN message.
/// @note The message data should be set separately using the smac_can_message_set_data macro.
#define smac_can_message_init_extended(message, ident, request_kind, data_length)                  \
    {                                                                                              \
        message.head.ident        = ident;                                                         \
        message.head.frame_kind   = SMAC_CAN_FRAME_EXTENDED;                                       \
        message.head.request_kind = request_kind;                                                  \
        message.head.data_length  = data_length;                                                   \
    }

/// @brief Macro to set the data for a CAN message.
/// @details This macro copies the data from the provided array into the CAN message's data field.
/// The number of bytes copied is the lesser of the message's data length and 8.
/// @param message The CAN message structure to set the data for.
/// @param data_array The array containing the data to copy into the CAN message.
#define smac_can_message_set_data(message, data_array)                                             \
    {                                                                                              \
        memcpy((message)->data, data_array,                                                        \
               (message)->head.data_length > 8 ? 8 : (message)->head.data_length);                 \
    }

/// @brief Macro to initialize a CAN FD message.
/// @details This macro sets up the CAN FD message header with the specified identifier, error
/// status, switch bit rate, and data length.
/// @param message The CAN FD message structure to initialize.
/// @param ident The standard identifier for the CAN FD message.
/// @param frame_kind The frame kind for the CAN FD message.
/// @param request_kind The request kind for the CAN FD message.
/// @param data_length The length of the data in the CAN FD message.
/// @param error_status The error status for the CAN FD message.
/// @param switch_bit_rate The switch bit rate for the CAN FD message.
/// @note The message data should be set separately using the smac_can_fd_message_set_data macro.
#define smac_can_fd_message_init(message, ident, frame_kind, request_kind, data_length,            \
                                 error_status, switch_bit_rate)                                    \
    {                                                                                              \
        message.head.ident           = ident;                                                      \
        message.head.frame_kind      = frame_kind;                                                 \
        message.head.request_kind    = request_kind;                                               \
        message.head.data_length     = data_length;                                                \
        message.head.format          = SMAC_CAN_FD;                                                \
        message.head.error_status    = error_status;                                               \
        message.head.switch_bit_rate = switch_bit_rate;                                            \
    }

/// @brief Macro to initialize a CAN FD message.
/// @details This macro sets up the CAN FD message header with the specified identifier, error
/// status, switch bit rate, and data length.
/// @param message The CAN FD message structure to initialize.
/// @param ident The standard identifier for the CAN FD message.
/// @param frame_kind The frame kind for the CAN FD message.
/// @param request_kind The request kind for the CAN FD message.
/// @param data_length The length of the data in the CAN FD message.
/// @param error_status The error status for the CAN FD message.
/// @param switch_bit_rate The switch bit rate for the CAN FD message.
/// @note The message data should be set separately using the smac_can_fd_message_set_data macro.
#define smac_can_fd_message_init_classic(message, ident, frame_kind, request_kind, data_length,    \
                                         error_status, switch_bit_rate)                            \
    {                                                                                              \
        message.head.ident           = ident;                                                      \
        message.head.frame_kind      = frame_kind;                                                 \
        message.head.request_kind    = request_kind;                                               \
        message.head.data_length     = data_length;                                                \
        message.head.format          = SMAC_CAN_CLASSIC;                                           \
        message.head.error_status    = error_status;                                               \
        message.head.switch_bit_rate = switch_bit_rate;                                            \
    }

/// @brief Macro to set the data for a CAN FD message.
/// @details This macro copies the data from the provided array into the CAN FD message's data
/// field. The number of bytes copied is the lesser of the message's data length and 64.
/// @param message The CAN FD message structure to set the data for.
/// @param data_array The array containing the data to copy into the CAN FD message.
#define smac_can_fd_message_set_data(message, data_array)                                          \
    {                                                                                              \
        memcpy((message)->data, data_array,                                                        \
               (message)->head.data_length > 64 ? 64 : (message)->head.data_length);               \
    }

/// ============================================================================
/// @defgroup smac_mcu_interface MCU Abstraction Layer Interface
/// @brief Functions for interacting with the MCU abstraction layer in the SMAC library.
/// @details This group contains functions for initializing the MCU abstraction layer and setting up
/// event callbacks for various peripherals.
/// @{
/// ============================================================================

/// @brief Initialize the MCU abstraction layer for SMAC.
/// @details This function initializes the MCU abstraction layer for the SMAC library, setting
/// up necessary resources, shall be called before using any other MCU abstraction functions.
/// @param  None.
/// @return @ref SMAC_RET_OK if initialization is successful, otherwise an error code.
smacRetCode_t smac_mcu_initialize(void);

/// @brief Introduce a delay for the specified number of milliseconds.
/// @details This function introduces a blocking delay for the specified number of milliseconds.
/// @param milliseconds The number of milliseconds to delay.
void smac_mcu_delay(uint32_t milliseconds);

/// @}

/// ============================================================================
/// @defgroup smac_mcu_adc ADC Interface
/// @brief Functions for interacting with the ADC peripheral in the MCU abstraction layer.
/// @details This group contains functions for creating, dropping, and performing various operations
/// on ADC instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create an ADC instance within the MCU abstraction layer.
/// @details This function creates an ADC instance within the MCU abstraction layer, associating it
/// with the provided handle.
/// @param handle The handle associated with the ADC instance.
/// @return The created ADC instance handle.
smacAdc_t smac_adc_create(void* handle);

/// @brief Drop an ADC instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified ADC instance.
/// @param adc The ADC instance to be dropped.
void smac_adc_drop(smacAdc_t adc);

/// @brief Set ADC event callbacks for the specified ADC instance.
/// @param adc The ADC instance.
/// @param event The ADC event to be associated with the ADC instance. This should be a static
/// pointer due to SMAC will not copy it.
/// @param data The event data to be associated with the ADC instance.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
/// @note If you don't want to use the interrupt/event of the ADC instance, you could don't call
/// this function.
/// @note This function cannot enable the interrupt and also needs you to enable the interrupt in
/// MCU driver.
smacRetCode_t smac_adc_set_event(smacAdc_t adc, smacAdcEvent_t* event, smacMcuEventData_t data);

/// @brief Clean ADC event callbacks for the specified ADC instance.
/// @param adc The ADC instance.
/// @note This function will remove all event callbacks associated with the specified ADC instance.
void smac_adc_clean_event(smacAdc_t adc);

/// @brief Perform a conversion on the specified ADC instance.
/// @details This function performs a conversion on the specified ADC instance with the provided
/// data.
/// @param adc The ADC instance.
/// @param data Pointer to the variable where the converted data will be stored.
/// @param timeout The timeout for the conversion operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the conversion is successful, otherwise an error code.
smacRetCode_t smac_adc_convert(smacAdc_t adc, uint32_t* data, uint32_t timeout);

/// @brief Perform an asynchronous conversion on the specified ADC instance.
/// @details This function initiates an asynchronous conversion on the specified ADC instance.
/// @param adc The ADC instance.
/// @return @ref SMAC_RET_OK if the asynchronous conversion is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_adc_async_convert(smacAdc_t adc);

/// @brief Start an asynchronous conversion on the specified ADC instance.
/// @details This function starts an asynchronous conversion on the specified ADC instance with the
/// provided data buffer and size.
/// @param adc The ADC instance.
/// @param data The buffer to store the conversion data.
/// @param size The size of the data buffer.
/// @return @ref SMAC_RET_OK if the asynchronous conversion is started successfully, otherwise an
/// error code.
smacRetCode_t smac_adc_async_conversion_start(smacAdc_t adc, uint32_t* data, uint32_t size);

/// @brief Stop an asynchronous conversion on the specified ADC instance.
/// @details This function stops an ongoing asynchronous conversion on the specified ADC instance.
/// @param adc The ADC instance.
/// @return @ref SMAC_RET_OK if the asynchronous conversion is stopped successfully, otherwise an
/// error code.
smacRetCode_t smac_adc_async_conversion_stop(smacAdc_t adc);

/// @}

/// ============================================================================
/// @defgroup smac_mcu_can CAN Interface
/// @brief CAN interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on CAN instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create a CAN instance within the MCU abstraction layer.
/// @details This function creates a CAN instance within the MCU abstraction layer, associating it
/// with the provided handle and FIFO configuration.
/// @param handle The handle associated with the CAN instance.
/// @return The created CAN instance handle.
smacCan_t smac_can_create(void* handle);

/// @brief Drop a CAN instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified CAN instance.
/// @param can The CAN instance to be dropped.
void smac_can_drop(smacCan_t can);

/// @brief Set CAN event callbacks for the specified CAN instance.
/// @param can The CAN instance.
/// @param event The specific CAN event to set the callback for. This should be a static pointer due
/// to SMAC will not copy it.
/// @param data The event data to be associated with the CAN instance.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
/// @note If you don't want to use the interrupt/event of the CAN instance, you could don't call
/// this function.
/// @note This function cannot enable the interrupt and also needs you to enable the interrupt in
/// MCU driver.
smacRetCode_t smac_can_set_event(smacCan_t can, smacCanEvent_t* event, smacMcuEventData_t data);

/// @brief Clean CAN event callbacks for the specified CAN instance.
/// @param can The CAN instance.
/// @note This function will remove all event callbacks associated with the specified CAN instance.
void smac_can_clean_event(smacCan_t can);

/// @brief Activate a CAN instance within the MCU abstraction layer.
/// @details This function activates the specified CAN instance, making it ready for communication.
/// @param can The CAN instance to be activated.
/// @return @ref SMAC_RET_OK if the activation is successful, otherwise an error code.
smacRetCode_t smac_can_active(smacCan_t can);

/// @brief Deactivate a CAN instance within the MCU abstraction layer.
/// @details This function deactivates the specified CAN instance, stopping its communication.
/// @param can The CAN instance to be deactivated.
/// @return @ref SMAC_RET_OK if the deactivation is successful, otherwise an error code.
smacRetCode_t smac_can_deactive(smacCan_t can);

/// @brief Transmit a message over the specified CAN instance.
/// @details This function transmits a message over the specified CAN instance with the provided
/// message data and timeout.
/// @param can The CAN instance.
/// @param message The message data to be transmitted.
/// @param timeout The timeout for the transmission operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the transmission is successful, otherwise an error code.
smacRetCode_t smac_can_transmit(smacCan_t can, const smacCanMessage* message, uint32_t timeout);

/// @brief Receive a message over channel 0 of the specified CAN instance.
/// @details This function receives a message over channel 0 of the specified CAN instance with the
/// provided message buffer and timeout.
/// @param can The CAN instance.
/// @param message The buffer to store the received message.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_can_receive_channel0(smacCan_t can, smacCanMessage* message, uint32_t timeout);

/// @brief Receive a message over channel 1 of the specified CAN instance.
/// @details This function receives a message over channel 1 of the specified CAN instance with the
/// provided message buffer and timeout.
/// @param can The CAN instance.
/// @param message The buffer to store the received message.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_can_receive_channel1(smacCan_t can, smacCanMessage* message, uint32_t timeout);

/// @brief Asynchronously transmit a message over the specified CAN instance.
/// @details This function initiates an asynchronous transmission of the specified message over the
/// CAN instance within the MCU abstraction layer.
/// @param can The CAN instance.
/// @param message The message data to be transmitted.
/// @return @ref SMAC_RET_OK if the asynchronous transmission is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_can_async_transmit(smacCan_t can, const smacCanMessage* message);

/// @brief Asynchronously receive a message over channel 0 of the specified CAN instance.
/// @details This function initiates an asynchronous reception of a message over channel 0 of the
/// CAN instance within the MCU abstraction layer.
/// @param can The CAN instance.
/// @param message The buffer to store the received message.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_can_async_receive_channel0(smacCan_t can, smacCanMessage* message);

/// @brief Asynchronously receive a message over channel 1 of the specified CAN instance.
/// @details This function initiates an asynchronous reception of a message over channel 1 of the
/// CAN instance within the MCU abstraction layer.
/// @param can The CAN instance.
/// @param message The buffer to store the received message.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_can_async_receive_channel1(smacCan_t can, smacCanMessage* message);

/// @}

/// ============================================================================
/// @defgroup smac_mcu_can_fd CAN FD Interface
/// @brief CAN FD interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on CAN FD instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create a CAN FD instance.
/// @details This function creates a CAN FD instance within the MCU abstraction layer.
/// @param handle The handle to the underlying CAN FD hardware.
/// @return The created CAN FD instance.
smacCanFd_t smac_can_fd_create(void* handle);

/// @brief Drop a CAN FD instance.
/// @details This function drops the specified CAN FD instance within the MCU abstraction layer.
/// @param canfd The CAN FD instance to be dropped.
void smac_can_fd_drop(smacCanFd_t canfd);

/// @brief Set an event for the specified CAN FD instance.
/// @details This function sets an event for the specified CAN FD instance within the MCU
/// abstraction layer.
/// @param canfd The CAN FD instance.
/// @param event The specific CAN FD event to set the callback for. This should be a static pointer
/// due to SMAC will not copy it.
/// @param data The event data to be set.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
smacRetCode_t smac_can_fd_set_event(smacCanFd_t canfd, smacCanFdEvent_t* event,
                                    smacMcuEventData_t data);

/// @brief Clean the event for the specified CAN FD instance.
/// @details This function cleans the event for the specified CAN FD instance within the MCU
/// abstraction layer.
/// @param canfd The CAN FD instance.
void smac_can_fd_clean_event(smacCanFd_t canfd);

/// @brief Activate the specified CAN FD instance.
/// @details This function activates the specified CAN FD instance within the MCU abstraction layer.
/// @param canfd The CAN FD instance to be activated.
/// @return @ref SMAC_RET_OK if the activation is successful, otherwise an error code.
smacRetCode_t smac_can_fd_active(smacCanFd_t canfd);

/// @brief Deactivate the specified CAN FD instance.
/// @details This function deactivates the specified CAN FD instance within the MCU abstraction
/// layer.
/// @param canfd The CAN FD instance to be deactivated.
/// @return @ref SMAC_RET_OK if the deactivation is successful, otherwise an error code.
smacRetCode_t smac_can_fd_deactive(smacCanFd_t canfd);

/// @brief Transmit a CAN FD message using the specified CAN FD instance.
/// @details This function transmits a CAN FD message using the specified CAN FD instance within the
/// MCU abstraction layer.
/// @param canfd The CAN FD instance to be used for transmission.
/// @param message The CAN FD message to be transmitted.
/// @param timeout The timeout duration for the transmission operation.
/// @return @ref SMAC_RET_OK if the transmission is successful, otherwise an error code.
smacRetCode_t smac_can_fd_transmit(smacCanFd_t canfd, const smacCanFdMessage* message,
                                   uint32_t timeout);

/// @brief Receive a CAN FD message using the specified CAN FD instance.
/// @details This function receives a CAN FD message using the specified CAN FD instance within the
/// MCU abstraction layer.
/// @param canfd The CAN FD instance to be used for reception.
/// @param message The CAN FD message structure to store the received message.
/// @param timeout The timeout duration for the reception operation.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_can_fd_receive_channel0(smacCanFd_t canfd, smacCanFdMessage* message,
                                           uint32_t timeout);

/// @brief Receive a CAN FD message using the specified CAN FD instance on channel 1.
/// @details This function receives a CAN FD message using the specified CAN FD instance on channel
/// 1 within the MCU abstraction layer.
/// @param canfd The CAN FD instance to be used for reception.
/// @param message The CAN FD message structure to store the received message.
/// @param timeout The timeout duration for the reception operation.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_can_fd_receive_channel1(smacCanFd_t canfd, smacCanFdMessage* message,
                                           uint32_t timeout);

/// @brief Asynchronously transmit a CAN FD message using the specified CAN FD instance.
/// @details This function initiates an asynchronous transmission of a CAN FD message using the
/// specified CAN FD instance within the MCU abstraction layer.
/// @param canfd The CAN FD instance to be used for transmission.
/// @param message The CAN FD message to be transmitted.
/// @return @ref SMAC_RET_OK if the asynchronous transmission is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_can_fd_async_transmit(smacCanFd_t canfd, const smacCanFdMessage* message);

/// @brief Asynchronously receive a CAN FD message using the specified CAN FD instance on channel 0.
/// @details This function initiates an asynchronous reception of a CAN FD message using the
/// specified CAN FD instance on channel 0 within the MCU abstraction layer.
/// @param canfd The CAN FD instance to be used for reception.
/// @param message The CAN FD message structure to store the received message.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_can_fd_async_receive_channel0(smacCanFd_t canfd, smacCanFdMessage* message);

/// @brief Asynchronously receive a CAN FD message using the specified CAN FD instance.
/// @details This function initiates an asynchronous reception of a CAN FD message using the
/// specified CAN FD instance within the MCU abstraction layer.
/// @param canfd The CAN FD instance to be used for reception.
/// @param message The CAN FD message structure to store the received message.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_can_fd_async_receive_channel1(smacCanFd_t canfd, smacCanFdMessage* message);

/// @}

/// ============================================================================
/// @defgroup smac_mcu_flash Internal FLASH Interface
/// @brief Internal FLASH interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on Internal FLASH instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Erase the specified Internal FLASH instance.
/// @details This function erases the contents of the specified Internal FLASH instance.
/// @param bank The bank within the Internal FLASH instance.
/// @param sector The starting sector within the Internal FLASH instance to be erased.
/// @param num The number of sectors to be erased.
/// @return @ref SMAC_RET_OK if the erase operation is successful, otherwise an error code.
smacRetCode_t smac_flash_erase(uint32_t bank, uint32_t sector, uint32_t num);

/// @brief Write data to the specified Internal FLASH instance.
/// @details This function writes the specified data to the given address within the Internal
/// FLASH instance.
/// @param bank The bank within the Internal FLASH instance.
/// @param address The address within the Internal FLASH instance to write to.
/// @param data The data to be written.
/// @param size The size of the data to be written.
/// @return @ref SMAC_RET_OK if the write operation is successful, otherwise an error code.
smacRetCode_t smac_flash_write(uint32_t bank, uint32_t address, const uint8_t* data, uint32_t size);

/// @}

/// ============================================================================
/// @defgroup smac_mcu_i2c I2C Interface
/// @brief I2C interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on I2C instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create an I2C master instance within the MCU abstraction layer.
/// @details This function creates an I2C master instance within the MCU abstraction layer,
/// associating it with the provided handle.
/// @param handle The handle associated with the I2C master instance.
/// @return The created I2C master instance handle.
smacI2c_t smac_i2c_master_create(void* handle);

/// @brief Drop an I2C master instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified I2C master instance.
/// @param i2c The I2C master instance to be dropped.
void smac_i2c_master_drop(smacI2c_t i2c);

/// @brief Set I2C master event callbacks for the specified I2C master instance.
/// @param i2c The I2C master instance.
/// @param event The specific I2C master event to set the callback for. This should be a static
/// pointer due to SMAC will not copy it.
/// @param data The event data to be associated with the I2C master instance.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
/// @note If you don't want to use the interrupt/event of the I2C master instance, you could don't
/// call this function.
/// @note This function cannot enable the interrupt and also needs you to enable the interrupt in
/// MCU driver.
smacRetCode_t smac_i2c_master_set_event(smacI2c_t i2c, smacI2cMasterEvent_t* event,
                                        smacMcuEventData_t data);

/// @brief Clean I2C master event callbacks for the specified I2C master instance.
/// @param i2c The I2C master instance.
/// @note This function will remove all event callbacks associated with the specified I2C master
/// instance.
void smac_i2c_master_clean_event(smacI2c_t i2c);

/// @brief Checks if the specified I2C slave device is ready for communication.
/// @details This function checks whether the specified I2C slave device associated with the given
/// I2C master instance is ready for communication.
/// @param i2c The I2C master instance.
/// @param slave The address of the I2C slave device.
/// @param timeout The timeout for checking the device readiness. @ref SMAC_MCU_WAIT_NOW for no
/// wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the device is ready, otherwise an error code.
smacRetCode_t smac_i2c_master_selected_device_in_ready_state(smacI2c_t i2c, uint16_t slave,
                                                             uint32_t timeout);

/// @brief Transmit data over the specified I2C master instance.
/// @details This function transmits the specified data to the given address over the I2C master
/// instance within the MCU abstraction layer.
/// @param i2c The I2C master instance.
/// @param slave The address of the I2C slave device.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @param timeout The timeout for the transmission operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the transmission is successful, otherwise an error code.
smacRetCode_t smac_i2c_master_transmit(smacI2c_t i2c, uint16_t slave, const uint8_t* data,
                                       uint32_t size, uint32_t timeout);

/// @brief Receive data over the specified I2C master instance.
/// @details This function receives data from the given address over the I2C master instance within
/// the MCU abstraction layer.
/// @param i2c The I2C master instance.
/// @param slave The address of the I2C slave device.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_i2c_master_receive(smacI2c_t i2c, uint16_t slave, uint8_t* data, uint32_t size,
                                      uint32_t timeout);

/// @brief Asynchronously transmit data over the specified I2C master instance.
/// @details This function initiates an asynchronous transmission of the specified data to the given
/// address over the I2C master instance within the MCU abstraction layer.
/// @param i2c The I2C master instance.
/// @param slave The address of the I2C slave device.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @return @ref SMAC_RET_OK if the asynchronous transmission is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_i2c_master_async_transmit(smacI2c_t i2c, uint16_t slave, const uint8_t* data,
                                             uint32_t size);

/// @brief Asynchronously receive data over the specified I2C master instance.
/// @details This function initiates an asynchronous reception of data from the given address over
/// the I2C master instance within the MCU abstraction layer.
/// @param i2c The I2C master instance.
/// @param slave The address of the I2C slave device.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_i2c_master_async_receive(smacI2c_t i2c, uint16_t slave, uint8_t* data,
                                            uint32_t size);

/// @brief Create an I2C slave instance within the MCU abstraction layer.
/// @details This function creates an I2C slave instance within the MCU abstraction layer,
/// associating it with the provided handle.
/// @param handle The handle associated with the I2C slave instance.
/// @return The created I2C slave instance handle.
smacI2c_t smac_i2c_slave_create(void* handle);

/// @brief Drop an I2C slave instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified I2C slave instance.
/// @param i2c The I2C slave instance to be dropped.
void smac_i2c_slave_drop(smacI2c_t i2c);

/// @brief Set I2C slave event callbacks for the specified I2C slave instance.
/// @param i2c The I2C slave instance.
/// @param event The specific I2C slave event to set the callback for. This should be a static
/// pointer due to SMAC will not copy it.
/// @param data The event data to be associated with the I2C slave instance.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
/// @note If you don't want to use the interrupt/event of the I2C slave instance, you could don't
/// call this function.
/// @note This function cannot enable the interrupt and also needs you to enable the interrupt in
/// MCU driver.
smacRetCode_t smac_i2c_slave_set_event(smacI2c_t i2c, smacI2cSlaveEvent_t* event,
                                       smacMcuEventData_t data);

/// @brief Clean I2C slave event callbacks for the specified I2C slave instance.
/// @param i2c The I2C slave instance.
/// @note This function will remove all event callbacks associated with the specified I2C slave
/// instance.
void smac_i2c_slave_clean_event(smacI2c_t i2c);

/// @brief Listen for incoming communication on the specified I2C slave instance.
/// @details This function puts the I2C slave instance into a listening state, ready to respond to
/// master requests.
/// @param i2c The I2C slave instance.
/// @return @ref SMAC_RET_OK if the slave is successfully set to listen, otherwise an error code.
smacRetCode_t smac_i2c_slave_listen(smacI2c_t i2c);

/// @brief Transmit data over the specified I2C slave instance.
/// @details This function transmits the specified data over the I2C slave
/// instance within the MCU abstraction layer.
/// @param i2c The I2C slave instance.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @param timeout The timeout for the transmission operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the transmission is successful, otherwise an error code.
smacRetCode_t smac_i2c_slave_transmit(smacI2c_t i2c, const uint8_t* data, uint32_t size,
                                      uint32_t timeout);

/// @brief Receive data over the specified I2C slave instance.
/// @details This function receives data over the I2C slave instance within
/// the MCU abstraction layer.
/// @param i2c The I2C slave instance.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_i2c_slave_receive(smacI2c_t i2c, uint8_t* data, uint32_t size, uint32_t timeout);

/// @brief Asynchronously transmit data over the specified I2C slave instance.
/// @details This function initiates an asynchronous transmission of the specified data over the I2C
/// slave instance within the MCU abstraction layer.
/// @param i2c The I2C slave instance.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @return @ref SMAC_RET_OK if the asynchronous transmission is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_i2c_slave_async_transmit(smacI2c_t i2c, const uint8_t* data, uint32_t size);

/// @brief Asynchronously receive data over the specified I2C slave instance.
/// @details This function initiates an asynchronous reception of data over the I2C slave instance
/// within the MCU abstraction layer.
/// @param i2c The I2C slave instance.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_i2c_slave_async_receive(smacI2c_t i2c, uint8_t* data, uint32_t size);

/// @brief Create an I2C memory instance within the MCU abstraction layer.
/// @details This function creates an I2C memory instance within the MCU abstraction layer,
/// associating it with the provided handle.
/// @param handle The handle associated with the I2C memory instance.
/// @return The created I2C memory instance handle.
smacI2c_t smac_i2c_mem_create(void* handle);

/// @brief Drop an I2C memory instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified I2C memory instance.
/// @param i2c The I2C memory instance to be dropped.
void smac_i2c_mem_drop(smacI2c_t i2c);

/// @brief Set I2C memory event callbacks for the specified I2C memory instance.
/// @param i2c The I2C memory instance.
/// @param event The specific I2C memory event to set the callback for. This should be a static
/// pointer due to SMAC will not copy it.
/// @param data The event data to be associated with the I2C memory instance.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
/// @note If you don't want to use the interrupt/event of the I2C memory instance, you could don't
/// call this function.
/// @note This function cannot enable the interrupt and also needs you to enable the interrupt in
/// MCU driver.
smacRetCode_t smac_i2c_mem_set_event(smacI2c_t i2c, smacI2cMemEvent_t* event,
                                     smacMcuEventData_t data);

/// @brief Clean I2C memory event callbacks for the specified I2C memory instance.
/// @param i2c The I2C memory instance.
/// @note This function will remove all event callbacks associated with the specified I2C memory
/// instance.
void smac_i2c_mem_clean_event(smacI2c_t i2c);

/// @brief Check if the I2C memory device is in a ready state.
/// @details This function checks whether the I2C memory device associated with the specified I2C
/// instance is ready for communication.
/// @param i2c The I2C memory instance.
/// @param address The address of the I2C memory device to check.
/// @param timeout The timeout for the operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the device is ready, otherwise an error code.
smacRetCode_t smac_i2c_mem_selected_device_in_ready_state(smacI2c_t i2c, uint16_t address,
                                                          uint32_t timeout);

/// @brief Write data to the specified I2C memory device.
/// @details This function writes the specified data to the given memory address of the I2C memory
/// device associated with the specified I2C instance.
/// @param i2c The I2C memory instance.
/// @param slave The address of the I2C memory device.
/// @param mem_addr The memory address within the I2C memory device.
/// @param mem_addr_size The size of the memory address.
/// @param data The data to be written.
/// @param size The size of the data to be written.
/// @param timeout The timeout for the write operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the write operation is successful, otherwise an error code.
smacRetCode_t smac_i2c_mem_write(smacI2c_t i2c, uint16_t slave, uint16_t mem_addr,
                                 smacI2cMemAddrSize mem_addr_size, const uint8_t* data,
                                 uint16_t size, uint32_t timeout);

/// @brief Read data from the specified I2C memory device.
/// @details This function reads data from the given memory address of the I2C memory device
/// associated with the specified I2C instance.
/// @param i2c The I2C memory instance.
/// @param slave The address of the I2C memory device.
/// @param mem_addr The memory address within the I2C memory device.
/// @param mem_addr_size The size of the memory address.
/// @param data The buffer to store the read data.
/// @param size The size of the data to be read.
/// @param timeout The timeout for the read operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the read operation is successful, otherwise an error code.
smacRetCode_t smac_i2c_mem_read(smacI2c_t i2c, uint16_t slave, uint16_t mem_addr,
                                smacI2cMemAddrSize mem_addr_size, uint8_t* data, uint16_t size,
                                uint32_t timeout);

/// @brief Asynchronously write data to the specified I2C memory device.
/// @details This function initiates an asynchronous write of the specified data to the given memory
/// address of the I2C memory device associated with the specified I2C instance.
/// @param i2c The I2C memory instance.
/// @param slave The address of the I2C memory device.
/// @param mem_addr The memory address within the I2C memory device.
/// @param mem_addr_size The size of the memory address.
/// @param data The data to be written.
/// @param size The size of the data to be written.
/// @return @ref SMAC_RET_OK if the asynchronous write is initiated successfully, otherwise an error
/// code.
smacRetCode_t smac_i2c_mem_async_write(smacI2c_t i2c, uint16_t slave, uint16_t mem_addr,
                                       smacI2cMemAddrSize mem_addr_size, const uint8_t* data,
                                       uint16_t size);

/// @brief Asynchronously read data from the specified I2C memory device.
/// @details This function initiates an asynchronous read of data from the given memory address of
/// the I2C memory device associated with the specified I2C instance.
/// @param i2c The I2C memory instance.
/// @param slave The address of the I2C memory device.
/// @param mem_addr The memory address within the I2C memory device.
/// @param mem_addr_size The size of the memory address.
/// @param data The buffer to store the read data.
/// @param size The size of the data to be read.
/// @return @ref SMAC_RET_OK if the asynchronous read is initiated successfully, otherwise an error
/// code.
smacRetCode_t smac_i2c_mem_async_read(smacI2c_t i2c, uint16_t slave, uint16_t mem_addr,
                                      smacI2cMemAddrSize mem_addr_size, uint8_t* data,
                                      uint16_t size);

/// @}

/// ============================================================================
/// @defgroup smac_io IO Interface
/// @brief IO interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on IO instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create an IO instance within the MCU abstraction layer.
/// @details This function creates an IO instance within the MCU abstraction layer, associating it
/// with the provided handle and pin.
/// @param handle The handle associated with the IO instance.
/// @param pin The pin number for the IO instance.
/// @return The created IO instance handle.
smacIo_t smac_io_create(void* handle, uint32_t pin);

/// @brief Drop an IO instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified IO instance.
/// @param io The IO instance to be dropped.
void smac_io_drop(smacIo_t io);

/// @brief Set IO event callbacks for the specified IO instance.
/// @param io The IO instance.
/// @param event The specific IO event to set the callback for. This should be a static pointer due
/// to SMAC will not copy it.
/// @param data The event data to be associated with the IO instance.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
/// @note If you don't want to use the interrupt/event of the IO instance, you could don't call this
/// function.
/// @note This function cannot enable the interrupt and also needs you to enable the interrupt in
/// MCU driver.
smacRetCode_t smac_io_set_event(smacIo_t io, smacIoEvent_t* event, smacMcuEventData_t data);

/// @brief Clean IO event callbacks for the specified IO instance.
/// @param io The IO instance.
/// @note This function will remove all event callbacks associated with the specified IO instance.
void smac_io_clean_event(smacIo_t io);

/// @brief Get the current state of the specified IO instance.
/// @details This function retrieves the current state of the IO instance within the MCU abstraction
/// layer.
/// @param io The IO instance.
/// @return The current state of the IO instance.
smacIoState smac_io_state(smacIo_t io);

/// @brief Set the state of the specified IO instance.
/// @details This function sets the state of the IO instance within the MCU abstraction layer.
/// @param io The IO instance.
/// @param state The desired state to set for the IO instance.
/// @return @ref SMAC_RET_OK if the state is set successfully, otherwise an error code.
smacRetCode_t smac_io_set_state(smacIo_t io, smacIoState state);

/// @brief Reverse the state of the specified IO instance.
/// @details This function toggles the state of the IO instance within the MCU abstraction layer.
/// @param io The IO instance.
/// @return @ref SMAC_RET_OK if the state is reversed successfully, otherwise an error code.
smacRetCode_t smac_io_reverse_state(smacIo_t io);

/// @}

/// ============================================================================
/// @defgroup smac_pwm PWM Interface
/// @brief PWM interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on PWM instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create a PWM instance within the MCU abstraction layer.
/// @details This function creates a PWM instance within the MCU abstraction layer, associating it
/// with the provided handle and channel.
/// @param handle The handle associated with the PWM instance.
/// @return The created PWM instance handle.
smacPwm_t smac_pwm_create(void* handle);

/// @brief Drop a PWM instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified PWM instance.
/// @param pwm The PWM instance to be dropped.
void smac_pwm_drop(smacPwm_t pwm);

/// @brief Set PWM event callbacks for the specified PWM instance.
/// @param pwm The PWM instance.
/// @param event The specific PWM event to set the callback for. This should be a static pointer due
/// to SMAC will not copy it.
/// @param data The event data to be associated with the PWM instance.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
/// @note If you don't want to use the interrupt/event of the PWM instance, you could don't call
/// this function.
/// @note This function cannot enable the interrupt and also needs you to enable the interrupt in
/// MCU driver.
smacRetCode_t smac_pwm_set_event(smacPwm_t pwm, smacPwmEvent_t* event, smacMcuEventData_t data);

/// @brief Clean PWM event callbacks for the specified PWM instance.
/// @param pwm The PWM instance.
/// @note This function will remove all event callbacks associated with the specified PWM instance.
void smac_pwm_clean_event(smacPwm_t pwm);

/// @brief Activate the specified PWM instance.
/// @details This function activates the PWM signal generation for the specified PWM instance.
/// @param pwm The PWM instance.
/// @param channel The channel number for the PWM instance.
/// @return @ref SMAC_RET_OK if the PWM is started successfully, otherwise an error code.
smacRetCode_t smac_pwm_activate(smacPwm_t pwm, uint32_t channel);

/// @brief Deactivate the specified PWM instance.
/// @details This function stops the PWM signal generation for the specified PWM instance.
/// @param pwm The PWM instance.
/// @param channel The channel number for the PWM instance.
/// @return @ref SMAC_RET_OK if the PWM is deactivated successfully, otherwise an error code.
smacRetCode_t smac_pwm_deactivate(smacPwm_t pwm, uint32_t channel);

/// @brief Asynchronously activate the specified PWM instance.
/// @details This function initiates an asynchronous activation of the PWM signal generation for the
/// specified PWM instance.
/// @param pwm The PWM instance.
/// @param channel The channel number for the PWM instance.
/// @return @ref SMAC_RET_OK if the asynchronous start is initiated successfully, otherwise an error
/// code.
smacRetCode_t smac_pwm_async_activate(smacPwm_t pwm, uint32_t channel);

/// @brief Asynchronously deactivate the specified PWM instance.
/// @details This function initiates an asynchronous deactivation of the PWM signal generation for
/// the specified PWM instance.
/// @param pwm The PWM instance.
/// @param channel The channel number for the PWM instance.
/// @return @ref SMAC_RET_OK if the asynchronous stop is initiated successfully, otherwise an error
/// code.
smacRetCode_t smac_pwm_async_deactivate(smacPwm_t pwm, uint32_t channel);

/// @brief Asynchronously activate the specified PWM instance with the provided data.
/// @details This function initiates an asynchronous activation of the PWM signal generation for the
/// specified PWM instance using the provided data.
/// @param pwm The PWM instance.
/// @param channel The channel number for the PWM instance.
/// @param data The data to be used for the PWM signal generation.
/// @param size The size of the data.
/// @return @ref SMAC_RET_OK if the asynchronous activation is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_pwm_async_activate_data(smacPwm_t pwm, uint32_t channel, const uint32_t* data,
                                           uint16_t size);

/// @brief Asynchronously deactivate the specified PWM instance with the provided data.
/// @details This function initiates an asynchronous deactivation of the PWM signal generation for
/// the specified PWM instance using the provided data.
/// @param pwm The PWM instance.
/// @param channel The channel number for the PWM instance.
/// @return @ref SMAC_RET_OK if the asynchronous deactivation is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_pwm_async_deactivate_data(smacPwm_t pwm, uint32_t channel);

/// @}

/// ============================================================================
/// @defgroup smac_spi SPI Interface
/// @brief SPI interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on SPI instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create an SPI instance within the MCU abstraction layer.
/// @details This function creates an SPI instance within the MCU abstraction layer, associating it
/// with the provided handle.
/// @param handle The handle associated with the SPI instance.
/// @return The created SPI instance handle.
smacSpi_t smac_spi_create(void* handle);

/// @brief Drop an SPI instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified SPI instance.
/// @param spi The SPI instance to be dropped.
void smac_spi_drop(smacSpi_t spi);

/// @brief Set SPI event callbacks for the specified SPI instance.
/// @param spi The SPI instance.
/// @param event The specific SPI event to set the callback for. This should be a static pointer due
/// to SMAC will not copy it.
/// @param data The event data to be associated with the SPI instance.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
/// @note If you don't want to use the interrupt/event of the SPI instance, you could don't call
/// this function.
/// @note This function cannot enable the interrupt and also needs you to enable the interrupt in
/// MCU driver.
smacRetCode_t smac_spi_set_event(smacSpi_t spi, smacSpiEvent_t* event, smacMcuEventData_t data);

/// @brief Clean SPI event callbacks for the specified SPI instance.
/// @param spi The SPI instance.
/// @note This function will remove all event callbacks associated with the specified SPI instance.
void smac_spi_clean_event(smacSpi_t spi);

/// @brief Transmit data over the specified SPI instance.
/// @details This function transmits the specified data over the SPI instance within the MCU
/// abstraction layer.
/// @param spi The SPI instance.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @param timeout The timeout for the transmission operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the transmission is successful, otherwise an error code.
smacRetCode_t smac_spi_transmit(smacSpi_t spi, const uint8_t* data, uint32_t size,
                                uint32_t timeout);

/// @brief Receive data over the specified SPI instance.
/// @details This function receives data over the SPI instance within the MCU abstraction layer.
/// @param spi The SPI instance.
/// @param data The buffer to store the received data.
/// @param size The size of the buffer.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_spi_receive(smacSpi_t spi, uint8_t* data, uint32_t size, uint32_t timeout);

/// @brief Transmit and receive data over the specified SPI instance.
/// @details This function transmits and receives data over the SPI instance within the MCU
/// abstraction layer.
/// @param spi The SPI instance.
/// @param tx_data The data to be transmitted.
/// @param rx_data The buffer to store the received data.
/// @param size The size of the data to be transmitted and received.
/// @param timeout The timeout for the transmit and receive operation. @ref SMAC_MCU_WAIT_NOW for no
/// wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the transmission and reception are successful, otherwise an error
/// code.
smacRetCode_t smac_spi_transmit_receive(smacSpi_t spi, const uint8_t* tx_data, uint8_t* rx_data,
                                        uint32_t size, uint32_t timeout);

/// @brief Asynchronously transmit data over the specified SPI instance.
/// @details This function initiates an asynchronous transmission of the specified data over the SPI
/// instance within the MCU abstraction layer.
/// @param spi The SPI instance.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @return @ref SMAC_RET_OK if the asynchronous transmission is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_spi_async_transmit(smacSpi_t spi, const uint8_t* data, uint32_t size);

/// @brief Asynchronously receive data over the specified SPI instance.
/// @details This function initiates an asynchronous reception of data over the SPI instance within
/// the MCU abstraction layer.
/// @param spi The SPI instance.
/// @param data The buffer to store the received data.
/// @param size The size of the buffer.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_spi_async_receive(smacSpi_t spi, uint8_t* data, uint32_t size);

/// @brief Asynchronously transmit and receive data over the specified SPI instance.
/// @details This function initiates an asynchronous transmission and reception of data over the SPI
/// instance within the MCU abstraction layer.
/// @param spi The SPI instance.
/// @param tx_data The data to be transmitted.
/// @param rx_data The buffer to store the received data.
/// @param size The size of the data to be transmitted and received.
/// @return @ref SMAC_RET_OK if the asynchronous transmission and reception are initiated
/// successfully, otherwise an error code.
smacRetCode_t smac_spi_async_transmit_receive(smacSpi_t spi, const uint8_t* tx_data,
                                              uint8_t* rx_data, uint32_t size);

/// @}

/// ============================================================================
/// @defgroup smac_tim Timer Interface
/// @brief Timer interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on Timer instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create a Timer instance within the MCU abstraction layer.
/// @details This function creates a Timer instance within the MCU abstraction layer, associating it
/// with the provided handle.
/// @param handle The handle associated with the Timer instance.
/// @return The created Timer instance handle.
smacTim_t smac_tim_create(void* handle);

/// @brief Drop a Timer instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified Timer instance.
/// @param tim The Timer instance to be dropped.
void smac_tim_drop(smacTim_t tim);

/// @brief Set Timer event callbacks for the specified Timer instance.
/// @param tim The Timer instance.
/// @param event The Timer event to be associated with the Timer instance. This should be a static
/// pointer due to SMAC will not copy it.
/// @param data The event data to be associated with the Timer instance.
/// @return @ref SMAC_RET_OK if the event is set successfully, otherwise an error code.
/// @note If you don't want to use the interrupt/event of the Timer instance, you could don't call
/// this function.
/// @note This function cannot enable the interrupt and also needs you to enable the interrupt in
/// MCU driver.
smacRetCode_t smac_tim_set_event(smacTim_t tim, smacTimEvent_t* event, smacMcuEventData_t data);

/// @brief Clean Timer event callbacks for the specified Timer instance.
/// @param tim The Timer instance.
/// @note This function will remove all event callbacks associated with the specified Timer
/// instance.
void smac_tim_clean_event(smacTim_t tim);

/// @brief Get the current count of the specified Timer instance.
/// @details This function retrieves the current count value of the specified Timer instance within
/// the MCU abstraction layer.
/// @param tim The Timer instance.
/// @return The current count value of the Timer instance.
uint32_t smac_tim_count(smacTim_t tim);

/// @brief Activate the specified Timer instance.
/// @details This function starts the Timer instance within the MCU abstraction layer.
/// @param tim The Timer instance.
/// @return @ref SMAC_RET_OK if the Timer is activated successfully, otherwise an error code.
smacRetCode_t smac_tim_activate(smacTim_t tim);

/// @brief Deactivate the specified Timer instance.
/// @details This function stops the Timer instance within the MCU abstraction layer.
/// @param tim The Timer instance.
/// @return @ref SMAC_RET_OK if the Timer is deactivated successfully, otherwise an error code.
smacRetCode_t smac_tim_deactivate(smacTim_t tim);

/// @brief Asynchronously activate the specified Timer instance.
/// @details This function initiates an asynchronous activation of the Timer instance within the MCU
/// abstraction layer.
/// @param tim The Timer instance.
/// @return @ref SMAC_RET_OK if the asynchronous activation is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_tim_async_activate(smacTim_t tim);

/// @brief Asynchronously deactivate the specified Timer instance.
/// @details This function initiates an asynchronous deactivation of the Timer instance within the
/// MCU abstraction layer.
/// @param tim The Timer instance.
/// @return @ref SMAC_RET_OK if the asynchronous deactivation is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_tim_async_deactivate(smacTim_t tim);

/// @brief Asynchronously activate the specified Timer instance with associated data.
/// @details This function initiates an asynchronous activation of the Timer instance within the MCU
/// abstraction layer, with the provided data.
/// @param tim The Timer instance.
/// @param data The data associated with the Timer activation.
/// @param size The size of the data.
/// @return @ref SMAC_RET_OK if the asynchronous activation is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_tim_async_activate_data(smacTim_t tim, uint32_t* data, uint16_t size);

/// @brief Asynchronously deactivate the specified Timer instance with associated data.
/// @details This function initiates an asynchronous deactivation of the Timer instance within the
/// MCU abstraction layer.
/// @param tim The Timer instance.
/// @return @ref SMAC_RET_OK if the asynchronous deactivation is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_tim_async_deactivate_data(smacTim_t tim);

/// @}

/// ============================================================================
/// @defgroup smac_uart UART Interface
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on UART instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create a UART instance within the MCU abstraction layer.
/// @details This function creates a UART instance within the MCU abstraction layer, associating it
/// with the provided handle.
/// @param handle The handle associated with the UART instance.
/// @return The created UART instance handle.
smacUart_t smac_uart_create(void* handle);

/// @brief Drop a UART instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified UART instance.
/// @param uart The UART instance to be dropped.
void smac_uart_drop(smacUart_t uart);

/// @brief Set UART event handling for the specified UART instance.
/// @details This function configures event/interrupt handling for the specified UART instance
/// within the MCU abstraction layer.
/// @param uart The UART instance.
/// @param event The UART event to be associated with the UART instance. This should be a static
/// pointer due to SMAC will not copy it.
/// @param event_data The event data associated with the UART instance.
/// @return @ref SMAC_RET_OK if the event handling is set successfully, otherwise an error code.
smacRetCode_t smac_uart_set_event(smacUart_t uart, smacUartEvent_t* event,
                                  smacMcuEventData_t event_data);

/// @brief Clean UART event handling for the specified UART instance.
/// @details This function disables and cleans up event/interrupt handling for the specified UART
/// instance within the MCU abstraction layer.
/// @param uart The UART instance.
void smac_uart_clean_event(smacUart_t uart);

/// @brief Transmit data over the specified UART instance.
/// @details This function transmits the specified data over the UART instance within the MCU
/// abstraction layer.
/// @param uart The UART instance.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @param timeout The timeout for the transmission operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the transmission is successful, otherwise an error code.
smacRetCode_t smac_uart_transmit(smacUart_t uart, const uint8_t* data, uint32_t size,
                                 uint32_t timeout);

/// @brief Receive data over the specified UART instance.
/// @details This function receives data over the UART instance within the MCU abstraction layer.
/// @param uart The UART instance.
/// @param data The buffer to store the received data.
/// @param size The size of the buffer.
/// @param received_size The actual size of the received data.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait, @ref
/// SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_uart_receive(smacUart_t uart, uint8_t* data, uint32_t size,
                                uint32_t* received_size, uint32_t timeout);

/// @brief Receive a specific size of data over the specified UART instance.
/// @details This function receives a specific size of data over the UART instance within the MCU
/// abstraction layer.
/// @param uart The UART instance.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait, @ref
/// SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_uart_receive_size(smacUart_t uart, uint8_t* data, uint32_t size,
                                     uint32_t timeout);

/// @brief Asynchronously transmit data over the specified UART instance.
/// @details This function initiates an asynchronous transmission of the specified data over the
/// UART instance within the MCU abstraction layer.
/// @param uart The UART instance.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @return @ref SMAC_RET_OK if the asynchronous transmission is initiated successfully, otherwise
/// an error code.
/// @note This function will work with you have configurated the IT or DMA for the UART instance
/// properly.
smacRetCode_t smac_uart_async_transmit(smacUart_t uart, const uint8_t* data, uint32_t size);

/// @brief Asynchronously receive data over the specified UART instance.
/// @details This function initiates an asynchronous reception of data over the UART instance within
/// the MCU abstraction layer.
/// @param uart The UART instance.
/// @param data The buffer to store the received data.
/// @param size The size of the buffer.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
/// @note This function will work with you have configurated the IT or DMA for the UART instance
/// properly.
smacRetCode_t smac_uart_async_receive(smacUart_t uart, uint8_t* data, uint32_t size);

/// @brief Asynchronously receive a specific size of data over the specified UART instance.
/// @details This function initiates an asynchronous reception of a specific size of data over the
/// UART instance within the MCU abstraction layer.
/// @param uart The UART instance.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
/// @note This function will work with you have configurated the IT or DMA for the UART instance
/// properly.
smacRetCode_t smac_uart_async_receive_size(smacUart_t uart, uint8_t* data, uint32_t size);

/// @brief Asynchronously abort ongoing UART operations for the specified UART instance.
/// @details This function initiates an asynchronous abort of any ongoing UART operations for the
/// specified UART instance within the MCU abstraction layer.
/// @param uart The UART instance.
/// @return @ref SMAC_RET_OK if the asynchronous abort is initiated successfully, otherwise an error
/// code.
smacRetCode_t smac_uart_async_abort(smacUart_t uart);

/// @}

/// ============================================================================
/// @defgroup smac_wdt Watchdog Interface
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on Watchdog instances within the MCU abstraction layer.
/// @{
/// ============================================================================

/// @brief Create a Watchdog instance within the MCU abstraction layer.
/// @details This function creates a Watchdog instance within the MCU abstraction layer, associating
/// it with the provided handle.
/// @param handle The handle associated with the Watchdog instance.
/// @return The created Watchdog instance handle.
smacWdt_t smac_wdt_create(void* handle);

/// @brief Drop a Watchdog instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified Watchdog instance.
/// @param wdt The Watchdog instance to be dropped.
void smac_wdt_drop(smacWdt_t wdt);

/// @brief Refresh the specified Watchdog instance.
/// @details This function refreshes the specified Watchdog instance to prevent it from timing out.
/// @param wdt The Watchdog instance to be refreshed.
void smac_wdt_refresh(smacWdt_t wdt);

/// @}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SMAC_MCU_H_
