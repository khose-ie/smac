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

/// @brief ADC handle type.
/// @details This type represents the handle associated with an ADC instance.
typedef void* smacAdc_t;

/// @brief CAN handle type.
/// @details This type represents the handle associated with a CAN instance.
typedef void* smacCan_t;

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

/// @brief ADC event callback for conversion complete.
/// @param adc The ADC instance.
/// @param event_data The event data associated with the conversion complete event.
/// @param value The converted ADC value.
typedef void (*smacAdcEventConvertComplete)(smacAdc_t adc, smacMcuEventData_t event_data,
                                            uint32_t value);

/// @brief ADC event callback for over-threshold condition.
/// @param adc The ADC instance.
/// @param event_data The event data associated with the over-threshold event.
typedef void (*smacAdcEventOverThreshold)(smacAdc_t adc, smacMcuEventData_t event_data);

/// @brief ADC event callback for error.
/// @param adc The ADC instance.
/// @param event_data The event data associated with the error event.
/// @param error_code The error code associated with the error event.
typedef void (*smacAdcEventError)(smacAdc_t adc, smacMcuEventData_t event_data,
                                  uint32_t error_code);

/// @brief CAN event callback for reception complete.
/// @param can The CAN instance.
/// @param event_data The event data associated with the reception complete event.
typedef void (*smacCanEventRxComplete)(smacCan_t can, smacMcuEventData_t event_data);

/// @brief I2C master event callback for transmission complete.
/// @param i2c The I2C instance.
/// @param event_data The event data associated with the transmission complete event.
typedef void (*smacI2cMasterEventTxComplete)(smacI2c_t i2c, smacMcuEventData_t event_data);

/// @brief I2C master event callback for reception complete.
/// @param i2c The I2C instance.
/// @param event_data The event data associated with the reception complete event.
typedef void (*smacI2cMasterEventRxComplete)(smacI2c_t i2c, smacMcuEventData_t event_data);

/// @brief I2C slave event callback for transmission complete.
/// @param i2c The I2C instance.
/// @param event_data The event data associated with the transmission complete event.
typedef void (*smacI2cSlaveEventTxComplete)(smacI2c_t i2c, smacMcuEventData_t event_data);

/// @brief I2C slave event callback for reception complete.
/// @param i2c The I2C instance.
/// @param event_data The event data associated with the reception complete event.
typedef void (*smacI2cSlaveEventRxComplete)(smacI2c_t i2c, smacMcuEventData_t event_data);

/// @brief I2C slave event callback for listen complete.
/// @param i2c The I2C instance.
/// @param event_data The event data associated with the listen complete event.
typedef void (*smacI2cSlaveEventListenComplete)(smacI2c_t i2c, smacMcuEventData_t event_data);

/// @brief I2C slave event callback for being selected by the master.
/// @param i2c The I2C instance.
/// @param event_data The event data associated with the selected event.
typedef void (*smacI2cSlaveEventSelected)(smacI2c_t i2c, smacMcuEventData_t event_data);

/// @brief I2C event callback for memory write complete.
/// @param i2c The I2C instance.
/// @param event_data The event data associated with the memory write complete event.
typedef void (*smacI2cEventMemWriteComplete)(smacI2c_t i2c, smacMcuEventData_t event_data);

/// @brief I2C event callback for memory read complete.
/// @param i2c The I2C instance.
/// @param event_data The event data associated with the memory read complete event.
typedef void (*smacI2cEventMemReadComplete)(smacI2c_t i2c, smacMcuEventData_t event_data);

/// @brief I2C event callback for error.
/// @param i2c The I2C instance.
/// @param event_data The event data associated with the error event.
typedef void (*smacI2cEventError)(smacI2c_t i2c, smacMcuEventData_t event_data);

/// @brief IO event callback for state change.
/// @param io The IO instance.
/// @param event_data The event data associated with the state change event.
typedef void (*smacIoEventStateChange)(smacIo_t io, smacMcuEventData_t event_data);

/// @brief PWM event callback for completion.
/// @param pwm The PWM instance.
/// @param event_data The event data associated with the completion event.
typedef void (*smacPwmEventComplete)(smacPwm_t pwm, smacMcuEventData_t event_data);

/// @brief SPI event callback for transmission complete.
/// @param spi The SPI instance.
/// @param event_data The event data associated with the transmission complete event.
typedef void (*smacSpiEventTxComplete)(smacSpi_t spi, smacMcuEventData_t event_data);

/// @brief SPI event callback for reception complete.
/// @param spi The SPI instance.
/// @param event_data The event data associated with the reception complete event.
typedef void (*smacSpiEventRxComplete)(smacSpi_t spi, smacMcuEventData_t event_data);

/// @brief SPI event callback for simultaneous transmission and reception complete.
/// @param spi The SPI instance.
/// @param event_data The event data associated with the transmission and reception complete event.
typedef void (*smacSpiEventTxRxComplete)(smacSpi_t spi, smacMcuEventData_t event_data);

/// @brief SPI event callback for abort.
/// @param spi The SPI instance.
/// @param event_data The event data associated with the abort event.
typedef void (*smacSpiEventAbort)(smacSpi_t spi, smacMcuEventData_t event_data);

/// @brief SPI event callback for error.
/// @param spi The SPI instance.
/// @param event_data The event data associated with the error event.
typedef void (*smacSpiEventError)(smacSpi_t spi, smacMcuEventData_t event_data);

/// @brief Timer event callback for timeout.
/// @param tim The Timer instance.
/// @param event_data The event data associated with the timeout event.
typedef void (*smacTimEventTimeout)(smacTim_t tim, smacMcuEventData_t event_data);

/// @brief UART event callback for transmission complete.
/// @param uart The UART instance.
/// @param event_data The event data associated with the transmission complete event.
typedef void (*smacUartEventTxComplete)(smacUart_t uart, smacMcuEventData_t event_data);

/// @brief UART event callback for reception complete.
/// @param uart The UART instance.
/// @param event_data The event data associated with the reception complete event.
/// @param length The length of the received data.
typedef void (*smacUartEventRxComplete)(smacUart_t uart, smacMcuEventData_t event_data,
                                        uint32_t length);

/// @brief UART event callback for reception of a specific size complete.
/// @param uart The UART instance.
/// @param event_data The event data associated with the reception of a specific size complete
/// event.
typedef void (*smacUartEventRxSizeComplete)(smacUart_t uart, smacMcuEventData_t event_data);

/// @brief UART event callback for abort.
/// @param uart The UART instance.
/// @param event_data The event data associated with the abort event.
typedef void (*smacUartEventAbort)(smacUart_t uart, smacMcuEventData_t event_data);

/// @brief UART event callback for error.
/// @param uart The UART instance.
/// @param event_data The event data associated with the error event.
/// @param error_code The error code associated with the error event.
typedef void (*smacUartEventError)(smacUart_t uart, smacMcuEventData_t event_data,
                                   uint32_t error_code);

/// @brief Initialize the MCU abstraction layer for SMAC.
/// @details This function initializes the MCU abstraction layer for the SMAC library, setting up
/// necessary resources, shall be called before using any other MCU abstraction functions.
/// @param  None.
/// @return @ref SMAC_RET_OK if initialization is successful, otherwise an error code.
smacRetCode_t smac_mcu_initialize(void);

/// @brief Set ADC event callbacks for the MCU abstraction layer.
/// @param on_convert_complete Callback for conversion complete event.
/// @param on_over_threshold Callback for over-threshold event.
/// @param on_error Callback for error event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_adc_event(smacAdcEventConvertComplete on_convert_complete,
                                     smacAdcEventOverThreshold on_over_threshold,
                                     smacAdcEventError on_error);

/// @brief Set CAN event callbacks for the MCU abstraction layer.
/// @param on_rx_complete Callback for reception complete event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_can_event(smacCanEventRxComplete on_rx_complete);

/// @brief Set I2C event callbacks for the MCU abstraction layer.
/// @param on_master_tx_complete Callback for I2C master transmission complete event.
/// @param on_master_rx_complete Callback for I2C master reception complete event.
/// @param on_slave_tx_complete Callback for I2C slave transmission complete event.
/// @param on_slave_rx_complete Callback for I2C slave reception complete event.
/// @param on_slave_listen_complete Callback for I2C slave listen complete event.
/// @param on_slave_selected Callback for I2C slave selected event.
/// @param on_mem_write_complete Callback for I2C memory write complete event.
/// @param on_mem_read_complete Callback for I2C memory read complete event.
/// @param on_error Callback for I2C error event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_i2c_event(smacI2cMasterEventTxComplete on_master_tx_complete,
                                     smacI2cMasterEventRxComplete on_master_rx_complete,
                                     smacI2cSlaveEventTxComplete on_slave_tx_complete,
                                     smacI2cSlaveEventRxComplete on_slave_rx_complete,
                                     smacI2cSlaveEventListenComplete on_slave_listen_complete,
                                     smacI2cSlaveEventSelected on_slave_selected,
                                     smacI2cEventMemWriteComplete on_mem_write_complete,
                                     smacI2cEventMemReadComplete on_mem_read_complete,
                                     smacI2cEventError on_error);

/// @brief Set IO event callbacks for the MCU abstraction layer.
/// @param on_state_change Callback for state change event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_io_event(smacIoEventStateChange on_state_change);

/// @brief Set PWM event callbacks for the MCU abstraction layer.
/// @param on_complete Callback for completion event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_pwm_event(smacPwmEventComplete on_complete);

/// @brief Set SPI event callbacks for the MCU abstraction layer.
/// @param on_tx_complete Callback for transmission complete event.
/// @param on_rx_complete Callback for reception complete event.
/// @param on_tx_rx_complete Callback for simultaneous transmission and reception complete event.
/// @param on_abort Callback for abort event.
/// @param on_error Callback for error event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_spi_event(smacSpiEventTxComplete on_tx_complete,
                                     smacSpiEventRxComplete on_rx_complete,
                                     smacSpiEventTxRxComplete on_tx_rx_complete,
                                     smacSpiEventAbort on_abort, smacSpiEventError on_error);

/// @brief Set Timer event callbacks for the MCU abstraction layer.
/// @param on_timeout Callback for timeout event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_tim_event(smacTimEventTimeout on_timeout);

/// @brief Set UART event callbacks for the MCU abstraction layer.
/// @param on_tx_complete Callback for transmission complete event.
/// @param on_rx_complete Callback for reception complete event.
/// @param on_rx_size_complete Callback for reception of a specific size complete event.
/// @param on_abort Callback for abort event.
/// @param on_error Callback for error event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_uart_event(smacUartEventTxComplete on_tx_complete,
                                      smacUartEventRxComplete on_rx_complete,
                                      smacUartEventRxSizeComplete on_rx_size_complete,
                                      smacUartEventAbort on_abort, smacUartEventError on_error);

/// ============================================================================
/// @brief ADC interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on ADC instances within the MCU abstraction layer.
/// ============================================================================

/// ============================================================================
/// @brief CAN interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on CAN instances within the MCU abstraction layer.
/// ============================================================================

/// ============================================================================
/// @brief I2C interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on I2C instances within the MCU abstraction layer.
/// ============================================================================

/// ============================================================================
/// @brief IO interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on IO instances within the MCU abstraction layer.
/// ============================================================================

/// ============================================================================
/// @brief PWM interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on PWM instances within the MCU abstraction layer.
/// ============================================================================

/// ============================================================================
/// @brief SPI interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on SPI instances within the MCU abstraction layer.
/// ============================================================================

/// ============================================================================
/// @brief Timer interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on Timer instances within the MCU abstraction layer.
/// ============================================================================

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

/// ============================================================================
/// @brief Watchdog interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on Watchdog instances within the MCU abstraction layer.
/// ============================================================================

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SMAC_MCU_H_
