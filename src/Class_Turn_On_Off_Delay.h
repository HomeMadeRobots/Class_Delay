#ifndef CLASS_TURN_ON_OFF_DELAY_H
#define CLASS_TURN_ON_OFF_DELAY_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
#include "Class_Delay.h"


/*============================================================================*/
/* Class */
/*============================================================================*/
typedef struct {
    /* Inheritance */
    Class_Delay_Var super;

    bool Is_Input_On;
} Class_Turn_On_Off_Delay_Var;

typedef struct {

    /* Inheritance */
    Class_Delay super;

    /* Configuration_Parameters */
    uint32_t Off_Delay_Duration;
    
} Class_Turn_On_Off_Delay;


/*============================================================================*/
/* Virtual operations realization */
/*============================================================================*/
extern Class_Delay_Virtual_Operations Turn_On_Off_Delay_Operations;


#endif