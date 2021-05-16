/**
 *
 * \file SWC_HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/16/2021 07:53 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HMI.h"
#define NOT_UPDATED
#define Timeout
#define MULTI_STATE_BTN_INIT
#define MULTI_STATE_BTN_MINUS
#define MULTI_STATE_BTN_PLUS

/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_HeightBtnState;
	MultiStateBtnType DE_InclineBtnState;
	MultiStateBtnType DE_SlideBtnState;
	uint8 DE_Height;
	uint8 DE_Incline;
	uint8 DE_Slide;

	/* Data Receive Points */
	status = Rte_Read_rp_SeatCtrlData_DE_Height(&DE_Height);
	status = Rte_Read_rp_SeatCtrlData_DE_Incline(&DE_Incline);
	status = Rte_Read_rp_SeatCtrlData_DE_Slide(&DE_Slide);
	
	if (DE_Height==0 || NOT_UPDATED || Timeout) DE_HeightBtnState = MULTI_STATE_BTN_INIT;
	else if (DE_Height == 1) DE_HeightBtnState=MULTI_STATE_BTN_MINUS;
	else DE_HeightBtnState=MULTI_STATE_BTN_PLUS;

	if (DE_Incline==0 || NOT_UPDATED || Timeout) DE_InclineBtnState = MULTI_STATE_BTN_INIT;
	else if (DE_Incline == 1) DE_InclineBtnState=MULTI_STATE_BTN_MINUS;
	else DE_InclineBtnState=MULTI_STATE_BTN_PLUS;

	if (DE_Slide==0 || NOT_UPDATED || Timeout) DE_SlideBtnState = MULTI_STATE_BTN_INIT;
	else if (DE_Slide == 1) DE_SlideBtnState=MULTI_STATE_BTN_MINUS;
	else DE_SlideBtnState=MULTI_STATE_BTN_PLUS;

	/* Data Send Points */
	status = Rte_Write_pp_SeatCtrlBtns_DE_HeightBtnState(DE_HeightBtnState);
	status = Rte_Write_pp_SeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
	status = Rte_Write_pp_SeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
		
}


/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rp_SeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged (void)
{
	Std_ReturnType status;
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	status = Rte_Read_rp_SeatModeBtn_SeatModeBtn(&SeatModeBtn);
	
	switch (SeatModeBtn)
	{
	case SEAT_MODE_BTN_MANUAL:
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
		break;
	case SEAT_MODE_BTN_AUTO:
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
		break;
	default:
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;
		break;
	}
	/* Mode Switch Points */
	status = Rte_Switch_pp_SeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
	
}

