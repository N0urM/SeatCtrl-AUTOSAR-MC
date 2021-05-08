/**
 *
 * \file SWC_HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 07:18 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightMotor.h"


/**
 *
 * Runnable RE_HeightMotorMove
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pp_MotorHeight_Opr_Move
 *
 */

void RE_HeightMotorMove (StepMotorStepType Arg_step)
{
	Std_ReturnType status;

	/* Server Call Points */
	switch (Arg_step)
	{
		case MOTOR_STEP_MINUS:
			status = Rte_Call_rp_IOSetHeight_Opr_IOSetReversed();
			break; 
		case MOTOR_STEP_PLUS:
			status = Rte_Call_rp_IOSetHeight_Opr_IOSetForward();
			break; 
	}
	
}

