/**
 *
 * \file SWC_SeatMgr_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatMgr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/2/2021 01:58 AM
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
void Rte_Call_rpHeightMotorMove(sint8 Step);
void Rte_Call_rpSlideMotorMove(sint8 Step);
void Rte_Call_rpInclineMotorMove(sint8 Step);

void SeatMgr_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_HeightBtnState;

	/* Data Receive Points */
	status = Rte_Read_rp_SeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);

	if (DE_HeightBtnState == MULTI_STATE_BTN_PLUS) Rte_Call_rpHeightMotorMove (MOTOR_STEP_PLUS);
	else if (DE_HeightBtnState == MULTI_STATE_BTN_MINUS) Rte_Call_rpHeightMotorMove(MOTOR_STEP_MINUS);
	else {}
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

	/* Data Receive Points */
	status = Rte_Read_rp_SeatCtrlBtns_DE_InclineBtnState(&DE_InclineBtnState);
	
	if (DE_InclineBtnState == MULTI_STATE_BTN_PLUS) Rte_Call_rpInclineMotorMove (MOTOR_STEP_PLUS);
	else if (DE_InclineBtnState == MULTI_STATE_BTN_MINUS) Rte_Call_rpInclineMotorMove(MOTOR_STEP_MINUS);
	else {}
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

	/* Data Receive Points */
	status = Rte_Read_rp_SeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);
	
	if (DE_SlideBtnState == MULTI_STATE_BTN_PLUS) Rte_Call_rpSlideMotorMove (MOTOR_STEP_PLUS);
	else if (DE_SlideBtnState == MULTI_STATE_BTN_MINUS) Rte_Call_rpSlideMotorMove(MOTOR_STEP_MINUS);
	else {}

}

