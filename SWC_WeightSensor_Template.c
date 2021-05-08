/**
 *
 * \file SWC_WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 03:02 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_WeightSensor.h"


/**
 *
 * Runnable WeightSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pp_WeightSensor_GetWeight
 *
 */

void WeightSensor_GetPosition (Impl_SensorWeightType* weight)
{
	Std_ReturnType status = ADC_ReadGroup (SensorGroup , weight);

}

