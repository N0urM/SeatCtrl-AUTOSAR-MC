/**
 *
 * \file SWC_SeatMgr_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatMgr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 02:32 AM
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

#define SENSOR_POSITION_STEP_0		0
#define SENSOR_POSITION_STEP_1		1
#define SENSOR_POSITION_STEP_2		2
#define SENSOR_POSITION_STEP_3		3

static boolean IsPositionAdjustingNeeded (Impl_SensorPositionType position , Impl_SensorWeightType weight , StepMotorStepType * step)
{
	boolean adjustMotor = FALSE;
	switch (position)
	{
	case  SENSOR_POSITION_STEP_0:
		if (weight > 60)
		{
			step = MOTOR_STEP_PLUS;
			adjutMotor = TRUE;
		}
		)
		break;
	case  SENSOR_POSITION_STEP_1:
		if (weight > 80)
		{
			step = MOTOR_STEP_PLUS;
			adjutMotor = TRUE;
		}
		else if (weight > 60 && weight < 80){
			// Do nothing
		}
		else if (weight < 60){
			step = MOTOR_STEP_PLUS;
			adjutMotor = TRUE;
		}
		)
		break;
	case  SENSOR_POSITION_STEP_2:
		if (weight > 100)
		{
			step = MOTOR_STEP_PLUS;
			adjutMotor = TRUE;
		}
		else if (weight > 80 && weight < 100){
			// Do nothing
		}
		else if (weight < 80){
			step = MOTOR_STEP_MINUS;
			adjutMotor = TRUE;
		}		
		break;
	case  SENSOR_POSITION_STEP_3:
		if (weight < 100){
			step = MOTOR_STEP_MINUS;
			adjutMotor = TRUE;	
		}
		break;
	default:
		break;
	}
}
/**
 *
 * Runnable SeatMgr_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatMgr_AutoHeight_200ms
 *
 */

void SeatMgr_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	Impl_SensorPositionType position;
	Impl_SensorWeightType weight;
	
	/* Server Call Points */
	status = Rte_Call_rp_HeightSensor_Opr_GetPosition(&position);
	status = Rte_Call_rp_WeightSensor_GetWeight(&weight);

	IsPositionAdjustingNeeded(position  , weight , &step);

	status = Rte_Call_rp_HeightMotor_Opr_Move(step);

}


/**
 *
 * Runnable SeatMgr_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatMgr_AutoIncline_200ms
 *
 */

void SeatMgr_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType tep;
	Impl_SensorPositionType position;
	Impl_SensorWeightType weight;

	/* Server Call Points */
	status = Rte_Call_rp_InclineSensor_Opr_GetPosition(&position);
	status = Rte_Call_rp_WeightSensor_GetWeight(&weight);

	IsPositionAdjustingNeeded(position  , weight , &step);

	status = Rte_Call_rp_InclineMotor_Opr_Move(step);

}


/**
 *
 * Runnable SeatMgr_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatMgr_AutoSlide_200ms
 *
 */

void SeatMgr_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	Impl_SensorPositionType position;
	Impl_SensorWeightType weight;

	/* Server Call Points */
	status = Rte_Call_rp_SlideSensor_Opr_GetPosition(&position);
	status = Rte_Call_rp_WeightSensor_GetWeight(&weight);

	IsPositionAdjustingNeeded(position  , weight , &step);

	status = Rte_Call_rp_SlideMotor_Opr_Move(step);

}



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
