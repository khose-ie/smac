#ifndef _SMAC_MCU_H_
#define _SMAC_MCU_H_

/// @file smac-mcu.h
/// @brief MCU abstraction layer for SMAC.
/// @details This header defines the MCU abstraction layer for the SMAC library, providing
/// interfaces for UART operations and event handling.
/// @author Khose-ie<khose-ie@outlook.com>
/// @date 2024-08-09

#include <smac.h>
#include <stdbool.h>
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

/// @brief PWM event callback for pulse completion.
/// @param pwm The PWM instance.
/// @param event_data The event data associated with the completion event.
typedef void (*smacPwmEventPulseComplete)(smacPwm_t pwm, smacMcuEventData_t event_data);

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

/// @brief CAN message header structure.
/// @details This structure defines the header of a CAN message, including standard and extended
/// IDs, identifier type, remote transmission request, and data length code.
/// @note The fields in this structure should be populated according to the CAN message being
/// transmitted or received.
typedef struct
{
    uint32_t STD_ID;
    uint32_t EXT_ID;
    uint32_t IDE;
    uint32_t RTR;
    uint32_t DLC;
} smacCanMessageHead;

/// @brief CAN message data structure.
/// @details This structure defines the data portion of a CAN message, which typically contains up
/// to 8 bytes of data.
/// @note The content array should be populated according to the CAN message being transmitted or
/// received.
typedef struct
{
    uint8_t content[8];
} smacCanMessageData;

/// @brief CAN message structure.
/// @details This structure defines a complete CAN message, including both the header and data
/// portions.
/// @note The fields in this structure should be populated according to the CAN message being
/// transmitted or received.
typedef struct
{
    smacCanMessageHead head;
    smacCanMessageData data;
} smacCanMessage;

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
/// @param on_pulse_complete Callback for pulse completion event.
/// @return @ref SMAC_RET_OK if the callbacks are set successfully, otherwise an error code.
smacRetCode_t smac_mcu_set_pwm_event(smacPwmEventPulseComplete on_pulse_complete);

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

/// @brief Perform a conversion on the specified ADC instance.
/// @details This function performs a conversion on the specified ADC instance with the provided
/// data.
/// @param adc The ADC instance.
/// @param data The data to be converted.
/// @return @ref SMAC_RET_OK if the conversion is successful, otherwise an error code.
smacRetCode_t smac_adc_convert(smacAdc_t adc, uint32_t data);

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

/// ============================================================================
/// @brief CAN interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on CAN instances within the MCU abstraction layer.
/// ============================================================================

/// @brief Create a CAN instance within the MCU abstraction layer.
/// @details This function creates a CAN instance within the MCU abstraction layer, associating it
/// with the provided handle and FIFO configuration.
/// @param handle The handle associated with the CAN instance.
/// @param fifo The FIFO configuration for the CAN instance.
/// @return The created CAN instance handle.
smacCan_t smac_can_create(void* handle, uint32_t fifo);

/// @brief Drop a CAN instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified CAN instance.
/// @param can The CAN instance to be dropped.
void smac_can_drop(smacCan_t can);

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

/// @brief Receive a message over the specified CAN instance.
/// @details This function receives a message over the specified CAN instance with the provided
/// message buffer and timeout.
/// @param can The CAN instance.
/// @param message The buffer to store the received message.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_can_receive(smacCan_t can, smacCanMessage* message, uint32_t timeout);

/// @brief Asynchronously transmit a message over the specified CAN instance.
/// @details This function initiates an asynchronous transmission of the specified message over the
/// CAN instance within the MCU abstraction layer.
/// @param can The CAN instance.
/// @param message The message data to be transmitted.
/// @return @ref SMAC_RET_OK if the asynchronous transmission is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_can_async_transmit(smacCan_t can, const smacCanMessage* message);

/// @brief Asynchronously receive a message over the specified CAN instance.
/// @details This function initiates an asynchronous reception of a message over the CAN instance
/// within the MCU abstraction layer.
/// @param can The CAN instance.
/// @param message The buffer to store the received message.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_can_async_receive(smacCan_t can, smacCanMessage* message);

/// ============================================================================
/// @brief Internal FLASH interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on Internal FLASH instances within the MCU abstraction layer.
/// ============================================================================

/// @brief Create an Internal FLASH instance within the MCU abstraction layer.
/// @details This function creates an Internal FLASH instance within the MCU abstraction layer,
/// associating it with the provided handle.
/// @param handle The handle associated with the Internal FLASH instance.
/// @return The created Internal FLASH instance handle.
smacFlash_t smac_flash_create(void* handle);

/// @brief Drop an Internal FLASH instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified Internal FLASH
/// instance.
/// @param flash The Internal FLASH instance to be dropped.
void smac_flash_drop(smacFlash_t flash);

/// @brief Erase the specified Internal FLASH instance.
/// @details This function erases the contents of the specified Internal FLASH instance.
/// @param flash The Internal FLASH instance to be erased.
/// @return @ref SMAC_RET_OK if the erase operation is successful, otherwise an error code.
smacRetCode_t smac_flash_erase(smacFlash_t flash);

/// @brief Write 8-bit data to the specified Internal FLASH instance.
/// @details This function writes the specified 8-bit data to the given address within the Internal
/// FLASH instance.
/// @param flash The Internal FLASH instance.
/// @param address The address within the Internal FLASH instance to write to.
/// @param data The data to be written.
/// @param size The size of the data to be written.
/// @return @ref SMAC_RET_OK if the write operation is successful, otherwise an error code.
smacRetCode_t smac_flash_write8(smacFlash_t flash, uint32_t address, const uint8_t* data,
                                uint32_t size);

/// @brief Write 16-bit data to the specified Internal FLASH instance.
/// @details This function writes the specified 16-bit data to the given address within the Internal
/// FLASH instance.
/// @param flash The Internal FLASH instance.
/// @param address The address within the Internal FLASH instance to write to.
/// @param data The data to be written.
/// @param size The size of the data to be written.
/// @return @ref SMAC_RET_OK if the write operation is successful, otherwise an error code.
smacRetCode_t smac_flash_write16(smacFlash_t flash, uint32_t address, const uint8_t* data,
                                 uint32_t size);

/// @brief Write 32-bit data to the specified Internal FLASH instance.
/// @details This function writes the specified 32-bit data to the given address within the Internal
/// FLASH instance.
/// @param flash The Internal FLASH instance.
/// @param address The address within the Internal FLASH instance to write to.
/// @param data The data to be written.
/// @param size The size of the data to be written.
/// @return @ref SMAC_RET_OK if the write operation is successful, otherwise an error code.
smacRetCode_t smac_flash_write32(smacFlash_t flash, uint32_t address, const uint32_t* data,
                                 uint32_t size);

/// @brief Write 64-bit data to the specified Internal FLASH instance.
/// @details This function writes the specified 64-bit data to the given address within the Internal
/// FLASH instance.
/// @param flash The Internal FLASH instance.
/// @param address The address within the Internal FLASH instance to write to.
/// @param data The data to be written.
/// @param size The size of the data to be written.
/// @return @ref SMAC_RET_OK if the write operation is successful, otherwise an error code.
smacRetCode_t smac_flash_write64(smacFlash_t flash, uint32_t address, const uint32_t* data,
                                 uint32_t size);

/// ============================================================================
/// @brief I2C interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on I2C instances within the MCU abstraction layer.
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

/// @brief Check if the I2C master device is in a ready state.
/// @param i2c The I2C master instance.
/// @return true if the device is ready, otherwise false.
bool smac_i2c_master_device_in_ready_state(smacI2c_t i2c);

/// @brief Transmit data over the specified I2C master instance.
/// @details This function transmits the specified data to the given address over the I2C master
/// instance within the MCU abstraction layer.
/// @param i2c The I2C master instance.
/// @param address The address of the I2C slave device.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @param timeout The timeout for the transmission operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the transmission is successful, otherwise an error code.
smacRetCode_t smac_i2c_master_transmit(smacI2c_t i2c, uint16_t address, const uint8_t* data,
                                       uint32_t size, uint32_t timeout);

/// @brief Receive data over the specified I2C master instance.
/// @details This function receives data from the given address over the I2C master instance within
/// the MCU abstraction layer.
/// @param i2c The I2C master instance.
/// @param address The address of the I2C slave device.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_i2c_master_receive(smacI2c_t i2c, uint16_t address, uint8_t* data, uint32_t size,
                                      uint32_t timeout);

/// @brief Asynchronously transmit data over the specified I2C master instance.
/// @details This function initiates an asynchronous transmission of the specified data to the given
/// address over the I2C master instance within the MCU abstraction layer.
/// @param i2c The I2C master instance.
/// @param address The address of the I2C slave device.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @return @ref SMAC_RET_OK if the asynchronous transmission is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_i2c_master_async_transmit(smacI2c_t i2c, uint16_t address, const uint8_t* data,
                                             uint32_t size);

/// @brief Asynchronously receive data over the specified I2C master instance.
/// @details This function initiates an asynchronous reception of data from the given address over
/// the I2C master instance within the MCU abstraction layer.
/// @param i2c The I2C master instance.
/// @param address The address of the I2C slave device.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_i2c_master_async_receive(smacI2c_t i2c, uint16_t address, uint8_t* data,
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

/// @brief Listen for incoming communication on the specified I2C slave instance.
/// @details This function puts the I2C slave instance into a listening state, ready to respond to
/// master requests.
/// @param i2c The I2C slave instance.
/// @return @ref SMAC_RET_OK if the slave is successfully set to listen, otherwise an error code.
smacRetCode_t smac_i2c_slave_listen(smacI2c_t i2c);

/// @brief Transmit data over the specified I2C slave instance.
/// @details This function transmits the specified data to the given address over the I2C slave
/// instance within the MCU abstraction layer.
/// @param i2c The I2C slave instance.
/// @param address The address of the I2C master device.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @param timeout The timeout for the transmission operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the transmission is successful, otherwise an error code.
smacRetCode_t smac_i2c_slave_transmit(smacI2c_t i2c, uint16_t address, const uint8_t* data,
                                      uint32_t size, uint32_t timeout);

/// @brief Receive data over the specified I2C slave instance.
/// @details This function receives data from the given address over the I2C slave instance within
/// the MCU abstraction layer.
/// @param i2c The I2C slave instance.
/// @param address The address of the I2C master device.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @param timeout The timeout for the reception operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the reception is successful, otherwise an error code.
smacRetCode_t smac_i2c_slave_receive(smacI2c_t i2c, uint16_t address, uint8_t* data, uint32_t size,
                                     uint32_t timeout);

/// @brief Asynchronously transmit data over the specified I2C slave instance.
/// @details This function initiates an asynchronous transmission of the specified data to the given
/// address over the I2C slave instance within the MCU abstraction layer.
/// @param i2c The I2C slave instance.
/// @param address The address of the I2C master device.
/// @param data The data to be transmitted.
/// @param size The size of the data to be transmitted.
/// @return @ref SMAC_RET_OK if the asynchronous transmission is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_i2c_slave_async_transmit(smacI2c_t i2c, uint16_t address, const uint8_t* data,
                                            uint32_t size);

/// @brief Asynchronously receive data over the specified I2C slave instance.
/// @details This function initiates an asynchronous reception of data from the given address over
/// the I2C slave instance within the MCU abstraction layer.
/// @param i2c The I2C slave instance.
/// @param address The address of the I2C master device.
/// @param data The buffer to store the received data.
/// @param size The size of the data to be received.
/// @return @ref SMAC_RET_OK if the asynchronous reception is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_i2c_slave_async_receive(smacI2c_t i2c, uint16_t address, uint8_t* data,
                                           uint32_t size);

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

/// @brief Check if the I2C memory device is in a ready state.
/// @details This function checks whether the I2C memory device associated with the specified I2C
/// instance is ready for communication.
/// @param i2c The I2C memory instance.
/// @return true if the device is ready, otherwise false.
bool smac_i2c_mem_device_in_ready_state(smacI2c_t i2c);

/// @brief Write data to the specified I2C memory device.
/// @details This function writes the specified data to the given memory address of the I2C memory
/// device associated with the specified I2C instance.
/// @param i2c The I2C memory instance.
/// @param slave_addr The address of the I2C memory device.
/// @param mem_addr The memory address within the I2C memory device.
/// @param mem_addr_size The size of the memory address.
/// @param data The data to be written.
/// @param size The size of the data to be written.
/// @param timeout The timeout for the write operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the write operation is successful, otherwise an error code.
smacRetCode_t smac_i2c_mem_write(smacI2c_t i2c, uint16_t slave_addr, uint16_t mem_addr,
                                 smacI2cMemAddrSize mem_addr_size, const uint8_t* data,
                                 uint16_t size, uint32_t timeout);

/// @brief Read data from the specified I2C memory device.
/// @details This function reads data from the given memory address of the I2C memory device
/// associated with the specified I2C instance.
/// @param i2c The I2C memory instance.
/// @param slave_addr The address of the I2C memory device.
/// @param mem_addr The memory address within the I2C memory device.
/// @param mem_addr_size The size of the memory address.
/// @param data The buffer to store the read data.
/// @param size The size of the data to be read.
/// @param timeout The timeout for the read operation. @ref SMAC_MCU_WAIT_NOW for no wait,
/// @ref SMAC_MCU_WAIT_FOREVER for indefinite wait.
/// @return @ref SMAC_RET_OK if the read operation is successful, otherwise an error code.
smacRetCode_t smac_i2c_mem_read(smacI2c_t i2c, uint16_t slave_addr, uint16_t mem_addr,
                                smacI2cMemAddrSize mem_addr_size, uint8_t* data, uint16_t size,
                                uint32_t timeout);

/// @brief Asynchronously write data to the specified I2C memory device.
/// @details This function initiates an asynchronous write of the specified data to the given memory
/// address of the I2C memory device associated with the specified I2C instance.
/// @param i2c The I2C memory instance.
/// @param slave_addr The address of the I2C memory device.
/// @param mem_addr The memory address within the I2C memory device.
/// @param mem_addr_size The size of the memory address.
/// @param data The data to be written.
/// @param size The size of the data to be written.
/// @return @ref SMAC_RET_OK if the asynchronous write is initiated successfully, otherwise an error
/// code.
smacRetCode_t smac_i2c_mem_async_write(smacI2c_t i2c, uint16_t slave_addr, uint16_t mem_addr,
                                       smacI2cMemAddrSize mem_addr_size, const uint8_t* data,
                                       uint16_t size);

/// @brief Asynchronously read data from the specified I2C memory device.
/// @details This function initiates an asynchronous read of data from the given memory address of
/// the I2C memory device associated with the specified I2C instance.
/// @param i2c The I2C memory instance.
/// @param slave_addr The address of the I2C memory device.
/// @param mem_addr The memory address within the I2C memory device.
/// @param mem_addr_size The size of the memory address.
/// @param data The buffer to store the read data.
/// @param size The size of the data to be read.
/// @return @ref SMAC_RET_OK if the asynchronous read is initiated successfully, otherwise an error
/// code.
smacRetCode_t smac_i2c_mem_async_read(smacI2c_t i2c, uint16_t slave_addr, uint16_t mem_addr,
                                      smacI2cMemAddrSize mem_addr_size, uint8_t* data,
                                      uint16_t size);

/// ============================================================================
/// @brief IO interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on IO instances within the MCU abstraction layer.
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

/// ============================================================================
/// @brief PWM interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on PWM instances within the MCU abstraction layer.
/// ============================================================================

/// @brief Create a PWM instance within the MCU abstraction layer.
/// @details This function creates a PWM instance within the MCU abstraction layer, associating it
/// with the provided handle and channel.
/// @param handle The handle associated with the PWM instance.
/// @param channel The channel number for the PWM instance.
/// @return The created PWM instance handle.
smacPwm_t smac_pwm_create(void* handle, uint32_t channel);

/// @brief Drop a PWM instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified PWM instance.
/// @param pwm The PWM instance to be dropped.
void smac_pwm_drop(smacPwm_t pwm);

/// @brief Activate the specified PWM instance.
/// @details This function activates the PWM signal generation for the specified PWM instance.
/// @param pwm The PWM instance.
/// @return @ref SMAC_RET_OK if the PWM is started successfully, otherwise an error code.
smacRetCode_t smac_pwm_activate(smacPwm_t pwm);

/// @brief Deactivate the specified PWM instance.
/// @details This function stops the PWM signal generation for the specified PWM instance.
/// @param pwm The PWM instance.
/// @return @ref SMAC_RET_OK if the PWM is deactivated successfully, otherwise an error code.
smacRetCode_t smac_pwm_deactivate(smacPwm_t pwm);

/// @brief Asynchronously activate the specified PWM instance.
/// @details This function initiates an asynchronous activation of the PWM signal generation for the
/// specified PWM instance.
/// @param pwm The PWM instance.
/// @return @ref SMAC_RET_OK if the asynchronous start is initiated successfully, otherwise an error
/// code.
smacRetCode_t smac_pwm_async_activate(smacPwm_t pwm);

/// @brief Asynchronously deactivate the specified PWM instance.
/// @details This function initiates an asynchronous deactivation of the PWM signal generation for
/// the specified PWM instance.
/// @param pwm The PWM instance.
/// @return @ref SMAC_RET_OK if the asynchronous stop is initiated successfully, otherwise an error
/// code.
smacRetCode_t smac_pwm_async_deactivate(smacPwm_t pwm);

/// @brief Asynchronously activate the specified PWM instance with the provided data.
/// @details This function initiates an asynchronous activation of the PWM signal generation for the
/// specified PWM instance using the provided data.
/// @param pwm The PWM instance.
/// @param data The data to be used for the PWM signal generation.
/// @param size The size of the data.
/// @return @ref SMAC_RET_OK if the asynchronous activation is initiated successfully, otherwise an
/// error code.
smacRetCode_t smac_pwm_async_activate_data(smacPwm_t pwm, const uint32_t* data, uint16_t size);

/// @brief Asynchronously deactivate the specified PWM instance with the provided data.
/// @details This function initiates an asynchronous deactivation of the PWM signal generation for
/// the specified PWM instance using the provided data.
/// @param pwm The PWM instance.
/// @return @ref SMAC_RET_OK if the asynchronous deactivation is initiated successfully, otherwise
/// an error code.
smacRetCode_t smac_pwm_async_deactivate_data(smacPwm_t pwm);

/// ============================================================================
/// @brief SPI interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on SPI instances within the MCU abstraction layer.
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

/// ============================================================================
/// @brief Timer interface functions for the MCU abstraction layer.
/// @details These functions provide an interface for creating, dropping, and performing various
/// operations on Timer instances within the MCU abstraction layer.
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

/// @brief Create a Watchdog instance within the MCU abstraction layer.
/// @details This function creates a Watchdog instance within the MCU abstraction layer, associating
/// it with the provided handle.
/// @param handle The handle associated with the Watchdog instance.
/// @return The created Watchdog instance handle.
smacWdt_t smac_wdt_create(void* handle);

/// @brief Drop a Watchdog instance within the MCU abstraction layer.
/// @details This function releases the resources associated with the specified Watchdog instance.
/// @param wdt The Watchdog instance to be dropped.
smacRetCode_t smac_wdt_drop(smacWdt_t wdt);

/// @brief Refresh the specified Watchdog instance.
/// @details This function refreshes the specified Watchdog instance to prevent it from timing out.
/// @param wdt The Watchdog instance to be refreshed.
void smac_wdt_refresh(smacWdt_t wdt);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SMAC_MCU_H_
