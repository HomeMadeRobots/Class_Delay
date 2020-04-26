#include "Class_Turn_On_Delay.h"

#include <stddef.h>


/*============================================================================*/
/* Public methods */
/*============================================================================*/
void Turn_On_Delay__Set( const Class_Turn_On_Delay* Me )
{
    if( false==Class_Triggered_Timer__Is_Active( Me->My_Timer ) )
    {
        Class_Triggered_Timer__Start(
            Me->My_Timer,
            Me->Turn_On_Delay_Duration );
    }
}
/*----------------------------------------------------------------------------*/
void Turn_On_Delay__Reset( const Class_Turn_On_Delay* Me )
{
    Class_Triggered_Timer__Stop( Me->My_Timer );
    Me->var_attr->Is_Output_On = false;
}
/*----------------------------------------------------------------------------*/
bool Turn_On_Delay__Get( const Class_Turn_On_Delay* Me )
{
    return Me->var_attr->Is_Output_On;
}
/*----------------------------------------------------------------------------*/
void Turn_On_Delay__Tick( const Class_Turn_On_Delay* Me )
{
    Class_Triggered_Timer__Tick( Me->My_Timer );
}


/*============================================================================*/
/* Received events */
/*============================================================================*/
void Turn_On_Delay__Timer_Is_Up( const Class_Turn_On_Delay* Me )
{
    Me->var_attr->Is_Output_On = true;
    if( Me->Delay_Is_Up != NULL )
    {
        Me->Delay_Is_Up();
    }
}