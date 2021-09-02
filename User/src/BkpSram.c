#include "BkpSram.h"

void BKP_SRAM_Init(void)
{
	/* Power interface clock enable */
	__HAL_RCC_PWR_CLK_ENABLE();

	/* DBP location 1, enabling access to the backup domain */
	HAL_PWR_EnableBkUpAccess();

	/* Enables backup of the SRAM clock by setting the BKPSRAMEN bit in the RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) */
	__HAL_RCC_BKPSRAM_CLK_ENABLE();

	/* The application must wait for the Backup Regulator Ready Flag (BRR) to be set to 1, indicating that the data written to RAM will be held in standby mode and VBAT mode. */
	HAL_PWREx_EnableBkUpReg();
	
//	 // Wait until the Backup SRAM low power Regulator is ready
//    while(PWR_GetFlagStatus(PWR_FLAG_BRR) == RESET)
//    {}
//	while((PWR->CSR &= PWR_CSR_BRR)==0)
//	{
//	}
			
}