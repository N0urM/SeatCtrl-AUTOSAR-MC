/**
 *
 * \file SWC_InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 12:24 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineMotor.h"

#define MOTOR_STEP_MINUS
#define MOTOR_STEP_PLUS
#define INCLINE_MOTOR_PIN

/**
 *
 * Runnable RE_InclineMotorMove
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pp_HeightMotor_Opr_Move
 *
 */

void RE_InclineMotorMove (StepMotorStepType Arg_step)
{
	switch (Arg_step)
	{
		case MOTOR_STEP_MINUS:
			Dio_WriteChannel( INCLINE_MOTOR_PIN , STD_LOW);
			break; 
		case MOTOR_STEP_PLUS:
			Dio_WriteChannel( INCLINE_MOTOR_PIN , STD_HIGH);
			break; 
	}

}

