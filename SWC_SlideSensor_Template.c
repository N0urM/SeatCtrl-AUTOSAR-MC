/**
 *
 * \file SWC_SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 07:30 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideSensor.h"


/**
 *
 * Runnable SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pp_SlideSensor_Opr_GetPosition
 *
 */

void SlideSensor_GetPosition (Impl_SensorPositionType* Position)
{
	Std_ReturnType status;
	IoPositionSensorReadingType position;

	/* Server Call Points */
	status = Rte_Call_rp_IoGetSlide_Opr_IOGet(&position);

	if (position == 0 )
	{
		Position = SENSOR_POSITION_STEP_0;
	}
	if (position >0 && position <= 64)
	{
		Position = SENSOR_POSITION_STEP_1;
	}
	if (position >64 && position <= 192)
	{
		Position = SENSOR_POSITION_STEP_2;
	}
	if (position >192 && position <= 255)
	{
		Position = SENSOR_POSITION_STEP_3;
	}
	
}

