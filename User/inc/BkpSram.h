
#ifndef TM_BKPSRAM_H
#define TM_BKPSRAM_H 

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"
//#include "defines.h"

/* Check compatibility */
#if defined(STM32F401xx) || defined(STM32F411xE)
	#error "Not available on F401/F411 devices"
#endif	


/**
 * @brief  Gets memory size for internal backup SRAM
 * @param  None
 * @retval Memory size in bytes
 */
#define BKPSRAM_GetMemorySize()			(0x00001000)

/**
 * @brief  Initializes backup SRAM peripheral
 * @note   This function initializes and enable backup SRAM domain.
 *         
 * @note   With this settings you have access to save/get from locations where SRAM is.
 * @param  None
 * @retval None
 */
void BKP_SRAM_Init(void);

/**
 * @brief  Writes 8-bit value to backup SRAM at desired location
 * @param  address: Address where to save data in SRAM.
 * 		      - Value between 0 and TM_BKPSRAM_GetMemorySize() - 1 is valid, if more, HardFault error can happen.
 * @param  value: 8-bit value which will be stored to backup SRAM
 * @retval None
 * @note   Defined as macro for faster execution
 */
#define BKPSRAM_Write8(address, value)	(*(__IO uint8_t *) (BKPSRAM_BASE + (address)) = (value))

/**
 * @brief  Reads 8-bit value from backup SRAM at desired location
 *
 * Parameters:
 * @param  address: Address where to save data in SRAM.
 * 		      - Value between 0 and TM_BKPSRAM_GetMemorySize() - 1 is valid, if more, HardFault error can happen.
 * @retval 8-bit value at specific location
 * @note   Defined as macro for faster execution
 */
#define BKPSRAM_Read8(address)			(*(__IO uint8_t *) (BKPSRAM_BASE + address))

/**
 * @brief  Writes 16-bit value to backup SRAM at desired location
 * @param  address: Address where to save data in SRAM.
 * 		      - Value between 0 and TM_BKPSRAM_GetMemorySize() - 2 is valid, if more, HardFault error can happen.
 * @param  value: 16-bit value which will be stored to backup SRAM
 * @retval None
 * @note   Defined as macro for faster execution
 */
#define BKPSRAM_Write16(address, value)	(*(__IO uint16_t *) (BKPSRAM_BASE + (address)) = (value))

/**
 * @brief  Reads 16-bit value from backup SRAM at desired location
 *
 * Parameters:
 * @param  address: Address where to save data in SRAM.
 * 		      - Value between 0 and TM_BKPSRAM_GetMemorySize() - 2 is valid, if more, HardFault error can happen.
 * @retval 16-bit value at specific location
 * @note   Defined as macro for faster execution
 */
#define BKPSRAM_Read16(address)			(*(__IO uint16_t *) (BKPSRAM_BASE + address))

/**
 * @brief  Writes 32-bit value to backup SRAM at desired location
 * @param  address: Address where to save data in SRAM.
 * 		      - Value between 0 and TM_BKPSRAM_GetMemorySize() - 4 is valid, if more, HardFault error can happen.
 * @param  value: 32-bit value which will be stored to backup SRAM
 * @retval None
 * @note   Defined as macro for faster execution
 */
#define BKPSRAM_Write32(address, value)	(*(__IO uint32_t *) (BKPSRAM_BASE + (address)) = (value))

/**
 * @brief  Reads 32-bit value from backup SRAM at desired location
 *
 * Parameters:
 * @param  address: Address where to save data in SRAM.
 * 		      - Value between 0 and BKPSRAM_GetMemorySize() - 4 is valid, if more, HardFault error can happen.
 * @retval 32-bit value at specific location
 * @note   Defined as macro for faster execution
 */
#define BKPSRAM_Read32(address)			(*(__IO uint32_t *) (BKPSRAM_BASE + address))

/**
 * @brief  Writes 32-bit float value to backup SRAM at desired location
 * @param  address: Address where to save data in SRAM.
 * 		      - Value between 0 and TM_BKPSRAM_GetMemorySize() - 4 is valid, if more, HardFault error can happen.
 * @param  value: 32-bit float value which will be stored to backup SRAM
 * @retval None
 * @note   Defined as macro for faster execution
 */
#define BKPSRAM_WriteFloat(address, value)	(*(__IO float *) (BKPSRAM_BASE + (address)) = (value))

/**
 * @brief  Reads 32-bit float value from backup SRAM at desired location
 *
 * Parameters:
 * @param  address: Address where to save data in SRAM.
 * 		      - Value between 0 and TM_BKPSRAM_GetMemorySize() - 4 is valid, if more, HardFault error can happen.
 * @retval 32-bit float value at specific location
 * @note   Defined as macro for faster execution
 */
#define BKPSRAM_ReadFloat(address)			(*(__IO float *) (BKPSRAM_BASE + address))

/**
 * @}
 */
 
/**
 * @}
 */
 
/**
 * @}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif