#ifndef _SMAC_MCU_H_
#define _SMAC_MCU_H_

/// @file smac-mcu.h
/// @brief MCU abstraction layer for SMAC.
/// @details This header defines the MCU abstraction layer for the SMAC library, providing
/// interfaces for UART operations and event handling.
/// @author Khose-ie<khose-ie@outlook.com>
/// @date 2024-08-09

#include <smac.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/// @brief Special timeout values for MCU operations.
#define SMAC_MCU_WAIT_NOW     (0x00000000)
#define SMAC_MCU_WAIT_FOREVER (0xFFFFFFFF)

/// @brief MCU event data type.
/// @details This type represents the event data associated with MCU events.
typedef void* smacMcuEventData_t;

/// @brief UART handle type.
/// @details This type represents the handle associated with a UART instance.
typedef void* smacUart_t;

/// @brief UART event callback for transmission complete.
/// @param uart The UART instance.
/// @param event_data The event data associated with the transmission complete event.
typedef void (*smacUartEventOnTxComplete)(smacUart_t uart, smacMcuEventData_t event_data);

/// @brief UART event callback for reception complete.
/// @param uart The UART instance.
/// @param event_data The event data associated with the reception complete event.
/// @param length The length of the received data.
typedef void (*smacUartEventOnRxComplete)(smacUart_t uart, smacMcuEventData_t event_data,
                                          uint32_t length);

/// @brief UART event callback for reception of a specific size complete.
/// @param uart The UART instance.
/// @param event_data The event data associated with the reception of a specific size complete
/// event.
typedef void (*smacUartEventOnRxSizeComplete)(smacUart_t uart, smacMcuEventData_t event_data);

/// @brief UART event callback for abort.
/// @param uart The UART instance.
/// @param event_data The event data associated with the abort event.
typedef void (*smacUartEventOnAbort)(smacUart_t uart, smacMcuEventData_t event_data);

/// @brief UART event callback for error.
/// @param uart The UART instance.
/// @param event_data The event data associated with the error event.
typedef void (*smacUartEventOnError)(smacUart_t uart, smacMcuEventData_t event_data);

/// @brief Initialize the MCU abstraction layer for SMAC.
/// @details This function initializes the MCU abstraction layer for the SMAC library, setting up
/// necessary resources, shall be called before using any other MCU abstraction functions.
/// @param  None.
/// @return @ref SMAC_RET_OK if initialization is successful, otherwise an error code.
smacRetCode_t smac_mcu_initialize(void);

/// @brief Set UART event callbacks for the MCU abstraction layer.
/// @param on_tx_complete Callback for transmission complete event.
/// @param on_rx_complete Callback for reception complete event.
/// @param on_rx_size_complete Callback for reception of a specific size complete event.
/// @param on_abort Callback for abort event.
/// @param on_error Callback for error event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_uart_event(smacUartEventOnTxComplete on_tx_complete,
                                      smacUartEventOnRxComplete on_rx_complete,
                                      smacUartEventOnRxSizeComplete on_rx_size_complete,
                                      smacUartEventOnAbort on_abort, smacUartEventOnError on_error);

/// ============================================================================
/// @brief UART interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on UART instances within the MCU abstraction layer.
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

/// @brief Open UART event handling for the specified UART instance.
/// @details This function enables event/interrupt handling for the specified UART instance within
/// the MCU abstraction layer.
/// @param uart The UART instance.
/// @param event_data The event data associated with the UART instance.
/// @return @ref SMAC_RET_OK if the event handling is opened successfully, otherwise an error code.
/// @note If open the event, and set the UART event callbacks using @ref smac_mcu_set_uart_event,
/// the specified callbacks will be invoked for the corresponding events.
smacRetCode_t smac_uart_open_event(smacUart_t uart, smacMcuEventData_t event_data);

/// @brief Close UART event handling for the specified UART instance.
/// @details This function disables event/interrupt handling for the specified UART instance within
/// the MCU abstraction layer.
/// @param uart The UART instance.
void smac_uart_close_event(smacUart_t uart);

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

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SMAC_MCU_H_
