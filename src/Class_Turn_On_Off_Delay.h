#ifndef CLASS_TURN_ON_OFF_DELAY_H
#define CLASS_TURN_ON_OFF_DELAY_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include <stdint.h>
#include <stdbool.h>


/* Associated objects */
#include "Class_Triggered_Timer.h"


/*============================================================================*/
/* Class */
/*============================================================================*/
typedef struct {
    bool Is_Output_On;
    bool Is_Input_On;
} Class_Turn_On_Off_Delay_Var;

typedef struct {

    /* Variable attributes */
    Class_Turn_On_Off_Delay_Var* var_attr;
    
    /* Sent events */
    void (*Delay_Is_Up)( void );
    
    /* Associated objects */
    const Class_Triggered_Timer* My_Timer;
    
    /* Constants attributes */
    uint32_t Turn_On_Delay_Duration;
    uint32_t Turn_Off_Delay_Duration;
    
} Class_Turn_On_Off_Delay;


/*============================================================================*/
/* Public methods */
/*============================================================================*/
void Turn_On_Off_Delay__Set( const Class_Turn_On_Off_Delay* Me );
void Turn_On_Off_Delay__Reset( const Class_Turn_On_Off_Delay* Me );
bool Turn_On_Off_Delay__Get( const Class_Turn_On_Off_Delay* Me );
void Turn_On_Off_Delay__Tick( const Class_Turn_On_Off_Delay* Me );


/*============================================================================*/
/* Event reception */
/*============================================================================*/
void Turn_On_Off_Delay__Timer_Is_Up( const Class_Turn_On_Off_Delay* Me );


#endif