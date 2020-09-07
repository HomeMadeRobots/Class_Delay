#include "Class_Turn_On_Delay.h"

#include <stddef.h>


/*============================================================================*/
/* Elements access */
/*============================================================================*/
#define Me_Is_Output_On (Me->super.var_attr->Is_Output_On)
#define Me_My_Timer (Me->super.My_Timer)
#define Me_Delay_Is_Up (Me->super.Delay_Is_Up)
#define Me_Delay_Duration (Me->super.Delay_Duration)


/*============================================================================*/
/* Public methods */
/*============================================================================*/
static void Turn_On_Delay__Set( const Class_Turn_On_Delay* Me );
static void Turn_On_Delay__Reset( const Class_Turn_On_Delay* Me );
/*----------------------------------------------------------------------------*/
static void Turn_On_Delay__Set( const Class_Turn_On_Delay* Me )
{
    if( false==Class_Triggered_Timer__Is_Active( Me_My_Timer ) )
    {
        Class_Triggered_Timer__Start(
            Me_My_Timer,
            Me_Delay_Duration );
    }
}
/*----------------------------------------------------------------------------*/
static void Turn_On_Delay__Reset( const Class_Turn_On_Delay* Me )
{
    Class_Triggered_Timer__Stop( Me_My_Timer );
    Me_Is_Output_On = false;
}


/*============================================================================*/
/* Received events */
/*============================================================================*/
static void Turn_On_Delay__Timer_Is_Up( const Class_Turn_On_Delay* Me );
static void Turn_On_Delay__Timer_Is_Up( const Class_Turn_On_Delay* Me )
{
    Me_Is_Output_On = true;
    if( Me_Delay_Is_Up != NULL )
    {
        Me_Delay_Is_Up();
    }
}


/*============================================================================*/
/* Virtual operations realization */
/*============================================================================*/
Class_Delay_Virtual_Operations Turn_On_Delay_Operations = {
    /* set */
    ( void (*) (const Class_Delay*) )Turn_On_Delay__Set,
    /* reset */
    ( void (*) (const Class_Delay*) )Turn_On_Delay__Reset,
    /* time_is_up */
    ( void (*) (const Class_Delay*) )Turn_On_Delay__Timer_Is_Up
};