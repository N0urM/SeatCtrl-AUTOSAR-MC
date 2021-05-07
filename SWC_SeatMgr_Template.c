/**
 *
 * \file SWC_SeatMgr_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatMgr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 12:25 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SeatMgr.h"
#define MULTI_STATE_BTN_INIT
#define MULTI_STATE_BTN_MINUS
#define MULTI_STATE_BTN_PLUS

#define MOTOR_STEP_MINUS
#define MOTOR_STEP_PLUS


/**
 *
 * Runnable SeatMgr_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rp_SeatCtrlBtns_DE_HeightBtnState
 *
 */

void SeatMgr_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_HeightBtnState;
	StepMotorStepType Arg_step;

	/* Data Receive Points */
	status = Rte_Read_rp_SeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);
	
	if (DE_HeightBtnState == MULTI_STATE_BTN_PLUS) Arg_step =  MOTOR_STEP_PLUS;
	else if (DE_HeightBtnState == MULTI_STATE_BTN_MINUS) Arg_step =  MOTOR_STEP_MINUS;
	else {}

	/* Server Call Points */
	status = Rte_Call_rp_HeightMotor_Opr_Move(Arg_step);
	
}


/**
 *
 * Runnable SeatMgr_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rp_SeatCtrlBtns_DE_InclineBtnState
 *
 */

void SeatMgr_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_InclineBtnState;
	StepMotorStepType Arg_step;

	/* Data Receive Points */
	status = Rte_Read_rp_SeatCtrlBtns_DE_InclineBtnState(&DE_InclineBtnState);

	if (DE_InclineBtnState == MULTI_STATE_BTN_PLUS) Arg_step =  MOTOR_STEP_PLUS;
	else if (DE_InclineBtnState == MULTI_STATE_BTN_MINUS) Arg_step = MOTOR_STEP_MINUS;
	else {}

	/* Server Call Points */
	Rte_Call_rp_InclineMotor_Opr_Move(Arg_step);

}
	
}


/**
 *
 * Runnable SeatMgr_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rp_SeatCtrlBtns_DE_SlideBtnState
 *
 */

void SeatMgr_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_SlideBtnState;
	StepMotorStepType Arg_step;

	/* Data Receive Points */
	status = Rte_Read_rp_SeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);
	
	if (DE_SlideBtnState == MULTI_STATE_BTN_PLUS) Arg_step =  MOTOR_STEP_PLUS;
	else if (DE_SlideBtnState == MULTI_STATE_BTN_MINUS) Arg_step =  MOTOR_STEP_MINUS; 
	else {}
	/* Server Call Points */
	status = Rte_Call_rp_SlideMotor_Opr_Move(Arg_step);
	
}

