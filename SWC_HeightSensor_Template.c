/**
 *
 * \file SWC_HeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 03:02 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightSensor.h"


/**
 *
 * Runnable HeightSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pp_HeightSensor_Opr_GetPosition
 *
 */

void HeightSensor_GetPosition (Impl_SensorPositionType* position)
{
	Std_ReturnType status = ADC_ReadGroup (SensorGroup , position);
}

