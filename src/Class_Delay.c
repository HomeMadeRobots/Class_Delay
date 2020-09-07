#include "Class_Delay.h"

#include <stddef.h>


/*============================================================================*/
/* Public methods */
/*============================================================================*/
bool Delay__Get( const Class_Delay* Me )
{
    return Me->var_attr->Is_Output_On;
}


/*============================================================================*/
/* Virtual operations */
/*============================================================================*/
void Delay__Set( const Class_Delay* Me )
{
    Me->virt_op->set(Me);
}
/*----------------------------------------------------------------------------*/
void Delay__Reset( const Class_Delay* Me )
{
    Me->virt_op->reset(Me);
}
/*----------------------------------------------------------------------------*/
void Delay__Timer_Is_Up( const Class_Delay* Me )
{
    Me->virt_op->timer_is_up(Me);
}