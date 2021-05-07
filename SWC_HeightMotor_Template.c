/**
 *
 * \file SWC_HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 12:24 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightMotor.h"

#define MOTOR_STEP_MINUS
#define MOTOR_STEP_PLUS

#define HEIGHT_MOTOR_PIN

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
		switch (Arg_step)
	{
		case MOTOR_STEP_MINUS:
			Dio_WriteChannel( HEIGHT_MOTOR_PIN , STD_LOW);
			break; 
		case MOTOR_STEP_PLUS:
			Dio_WriteChannel( HEIGHT_MOTOR_PIN , STD_HIGH);
			break; 
	}

}

