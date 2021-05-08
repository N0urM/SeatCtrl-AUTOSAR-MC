/**
 *
 * \file SWC_InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 07:18 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineMotor.h"


/**
 *
 * Runnable RE_InclineMotorMove
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pp_InclineMotor_Opr_Move
 *
 */

void RE_InclineMotorMove (StepMotorStepType Arg_step)
{
	Std_ReturnType status;

	/* Server Call Points */
	switch (Arg_step)
	{
		case MOTOR_STEP_MINUS:
			status = Rte_Call_rp_IoSetIncline_Opr_IOSetReversed();
			break; 
		case MOTOR_STEP_PLUS:
			status = Rte_Call_rp_IoSetIncline_Opr_IOSetForward();
			break; 
	}
	
}

