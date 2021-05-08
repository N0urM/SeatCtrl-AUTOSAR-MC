/**
 *
 * \file SWC_WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/8/2021 07:30 PM
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

void WeightSensor_GetPosition (Impl_SensorWeightType* Weight)
{
	Std_ReturnType status;
	IoWeightSensorReadingType weight;

	/* Server Call Points */
	status = Rte_Call_rp_IoGetWeight_Opr_IOGet(&weight);

	Weight = weight/100; 
	
}

