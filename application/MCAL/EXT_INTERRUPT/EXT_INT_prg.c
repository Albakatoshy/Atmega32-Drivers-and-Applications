/*
 * EXT_INT_prg.C
 *
 *  Created on: Jul 23, 2025
 *      Author: anaal
 */

#include "EXT_INT_int.h"

static void (*GlobalPtrInterruptHandler[3])(void)={0};

void MEXT_INT_vEnableDisablePrepheral(u8 A_u8ExtIntx , u8 A_u8Mode )
{
    switch (A_u8ExtIntx)
    {
        case EXT_INT0:
            if (A_u8Mode == EXT_INT_ENABLE)
            {
                SET_BIT(GICR, GICR_INT0);
            }
            else if (A_u8Mode == EXT_INT_DISABLE)
            {
                CLEAR_BIT(GICR, GICR_INT0);
            }
            break;

        case EXT_INT1:
            if (A_u8Mode == EXT_INT_ENABLE)
            {
                SET_BIT(GICR, GICR_INT1);
            }
            else if (A_u8Mode == EXT_INT_DISABLE)
            {
                CLEAR_BIT(GICR, GICR_INT1);
            }
            break;

        case EXT_INT2:
            if (A_u8Mode == EXT_INT_ENABLE)
            {
                SET_BIT(GICR, GICR_INT2);
            }
            else if (A_u8Mode == EXT_INT_DISABLE)
            {
                CLEAR_BIT(GICR, GICR_INT2);
            }
            break;

        default:break;
    }
}


void MEXT_INT_vIntSenstivity(u8 A_u8ExtIntx, u8 A_u8Senstivity)
{
    switch (A_u8ExtIntx)
    {
        case EXT_INT0:
            switch (A_u8Senstivity)
            {
                case EXT_INT_LOW_LEVEL_SENSTIVITY:
                    CLEAR_BIT(MCUCR, MCUCR_ISC00);
                    CLEAR_BIT(MCUCR, MCUCR_ISC01);
                    break;

                case EXT_INT_ANY_LOGIC_CHANGE_SENSTIVITY:
                    SET_BIT(MCUCR, MCUCR_ISC00);
                    CLEAR_BIT(MCUCR, MCUCR_ISC01);
                    break;

                case EXT_INT_FALLING_EDGE_SENSTIVITY:
                    CLEAR_BIT(MCUCR, MCUCR_ISC00);
                    SET_BIT(MCUCR, MCUCR_ISC01);
                    break;

                case EXT_INT_RISING_EDGE_SENSTIVITY:
                    SET_BIT(MCUCR, MCUCR_ISC00);
                    SET_BIT(MCUCR, MCUCR_ISC01);
                    break;
            }
            break;

        case EXT_INT1:
            switch (A_u8Senstivity)
            {
                case EXT_INT_LOW_LEVEL_SENSTIVITY:
                    CLEAR_BIT(MCUCR, MCUCR_ISC10);
                    CLEAR_BIT(MCUCR, MCUCR_ISC11);
                    break;

                case EXT_INT_ANY_LOGIC_CHANGE_SENSTIVITY:
                    SET_BIT(MCUCR, MCUCR_ISC10);
                    CLEAR_BIT(MCUCR, MCUCR_ISC11);
                    break;

                case EXT_INT_FALLING_EDGE_SENSTIVITY:
                    CLEAR_BIT(MCUCR, MCUCR_ISC10);
                    SET_BIT(MCUCR, MCUCR_ISC11);
                    break;

                case EXT_INT_RISING_EDGE_SENSTIVITY:
                    SET_BIT(MCUCR, MCUCR_ISC10);
                    SET_BIT(MCUCR, MCUCR_ISC11);
                    break;
            }
            break;

        case EXT_INT2:

            switch (A_u8Senstivity)
            {
                case EXT_INT_FALLING_EDGE_SENSTIVITY:
                    CLEAR_BIT(MCUCSR, MCUCSR_ISC2);
                    break;

                case EXT_INT_RISING_EDGE_SENSTIVITY:
                    SET_BIT(MCUCSR, MCUCSR_ISC2);
                    break;

                default:break;
            }
            break;

        default:break;
    }
}

EXT_INT_STD_ERR MEXT_INT_InterruptHandler(u8 A_u8ExtTIntx , void (*LocalPtrInterruptHandler)(void)){
	 if (LocalPtrInterruptHandler == NULL)
	{
		return NULL_POINTER_ERROR;
	}
	else
	{
		switch(A_u8ExtTIntx){
			case EXT_INT0:
				GlobalPtrInterruptHandler[0]=LocalPtrInterruptHandler;
				break;
			case EXT_INT1:
				GlobalPtrInterruptHandler[1]=LocalPtrInterruptHandler;
				break;
			case EXT_INT2:
				GlobalPtrInterruptHandler[2]=LocalPtrInterruptHandler;
				break;
		}
	}

	if (A_u8ExtTIntx >= 3)
	{
		return INVALID_EXT_INT;
	}

	return EXT_INT_OK;
}


void MEXTI_vInit(void){
#if 	EXT_INT0_CFG == EXT_INT_ENABLE

	#if     EXT_INT_SENSTIVITY_ENABLE_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		CLEAR_BIT(MCUCR, MCUCR_ISC00);
		CLEAR_BIT(MCUCR, MCUCR_ISC01);
	#elif     EXT_INT_ANY_LOGIC_CHANGE_SENSTIVITY_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		SET_BIT(MCUCR, MCUCR_ISC00);
		CLEAR_BIT(MCUCR, MCUCR_ISC01);
	#elif     EXT_INT_FALLING_EDGE_SENSTIVITY_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		CLEAR_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);
	#elif     EXT_INT_RISING_EDGE_SENSTIVITY_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		SET_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);
	#endif

	MINT_vGlobalIntEnableDisable(INT_GLOBAL_INTERRUPT_ENABLE);
	SET_BIT(GICR, GICR_INT0);


#endif

#if 	EXT_INT1_CFG == EXT_INT_ENABLE
	#if     EXT_INT_SENSTIVITY_ENABLE_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		CLEAR_BIT(MCUCR, MCUCR_ISC10);
		CLEAR_BIT(MCUCR, MCUCR_ISC11);

	#elif     EXT_INT_ANY_LOGIC_CHANGE_SENSTIVITY_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		SET_BIT(MCUCR, MCUCR_ISC10);
		CLEAR_BIT(MCUCR, MCUCR_ISC11);
	#elif     EXT_INT_FALLING_EDGE_SENSTIVITY_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		CLEAR_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
	#elif     EXT_INT_RISING_EDGE_SENSTIVITY_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		SET_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
	#endif

		MINT_vGlobalIntEnableDisable(INT_GLOBAL_INTERRUPT_ENABLE);
		SET_BIT(GICR, GICR_INT1);
#endif

#if 	EXT_INT2_CFG == EXT_INT_ENABLE
	#if     EXT_INT_FALLING_EDGE_SENSTIVITY_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		CLEAR_BIT(MCUCSR, MCUCSR_ISC2);

	#elif     EXT_INT_RISING_EDGE_SENSTIVITY_CFG == EXT_INT_LOW_LEVEL_SENSTIVITY_CFG
		SET_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
	#endif

		MINT_vGlobalIntEnableDisable(INT_GLOBAL_INTERRUPT_ENABLE);
		SET_BIT(GICR, GICR_INT2);
#endif
}


void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if(GlobalPtrInterruptHandler[0]){
		GlobalPtrInterruptHandler[0]();
	}
}


void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if(GlobalPtrInterruptHandler[1]){
		GlobalPtrInterruptHandler[1]();
	}
}


void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	if(GlobalPtrInterruptHandler[2]){
		GlobalPtrInterruptHandler[2]();
	}
}








