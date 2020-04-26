#include "Class_Turn_On_Off_Delay.h"

#include <stddef.h>


/*============================================================================*/
/* Public methods */
/*============================================================================*/
void Turn_On_Off_Delay__Set( const Class_Turn_On_Off_Delay* Me )
{
    if( false==Me->var_attr->Is_Input_On )
    {
        Class_Triggered_Timer__Start(
            Me->My_Timer,
            Me->Turn_On_Delay_Duration );
        Me->var_attr->Is_Input_On = true;
    }
    else
    { /* Input is true */
        if( true==Me->var_attr->Is_Output_On )
        {
            Class_Triggered_Timer__Stop( Me->My_Timer );
        }
    }
    
}
/*----------------------------------------------------------------------------*/
void Turn_On_Off_Delay__Reset( const Class_Turn_On_Off_Delay* Me )
{
    if( true==Me->var_attr->Is_Input_On )
    {
        Class_Triggered_Timer__Start(
            Me->My_Timer,
            Me->Turn_Off_Delay_Duration );
        Me->var_attr->Is_Input_On = false;
    }
    else
    { /* Input is false */
        if( false==Me->var_attr->Is_Output_On )
        {
            Class_Triggered_Timer__Stop( Me->My_Timer );
        }
    }
    
}
/*----------------------------------------------------------------------------*/
bool Turn_On_Off_Delay__Get( const Class_Turn_On_Off_Delay* Me )
{
    return Me->var_attr->Is_Output_On;
}
/*----------------------------------------------------------------------------*/
void Turn_On_Off_Delay__Tick( const Class_Turn_On_Off_Delay* Me )
{
    Class_Triggered_Timer__Tick( Me->My_Timer );
}


/*============================================================================*/
/* Received events */
/*============================================================================*/
void Turn_On_Off_Delay__Timer_Is_Up( const Class_Turn_On_Off_Delay* Me )
{
    Me->var_attr->Is_Output_On = Me->var_attr->Is_Input_On;
    if( Me->Delay_Is_Up != NULL )
    {
        Me->Delay_Is_Up();
    }
}