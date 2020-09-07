#ifndef CLASS_DELAY_H
#define CLASS_DELAY_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include <stdint.h>


/* Associated objects */
#include "Class_Triggered_Timer.h"


/*============================================================================*/
/* Class */
/*============================================================================*/
typedef struct _Class_Delay Class_Delay;

typedef struct {
    bool Is_Output_On;
} Class_Delay_Var;

typedef struct {
    void (*set) ( const Class_Delay* );
    void (*reset) ( const Class_Delay* );
    void (*timer_is_up) ( const Class_Delay* );
} Class_Delay_Virtual_Operations;

struct _Class_Delay {

    /* Variable attributes */
    Class_Delay_Var* var_attr;
    
    /* Virtual operations */
    const Class_Delay_Virtual_Operations* virt_op;
    
    /* Sent events */
    void (*Delay_Is_Up)( void );
    
    /* Associated objects */
    const Class_Triggered_Timer* My_Timer;
    
    /* Configuration_Parameters */
    uint32_t Delay_Duration;
    
};


/*============================================================================*/
/* Public methods */
/*============================================================================*/
bool Delay__Get( const Class_Delay* Me );


/*============================================================================*/
/* Virtual operations */
/*============================================================================*/
/* Public methods */
void Delay__Set( const Class_Delay* Me );
void Delay__Reset( const Class_Delay* Me );
/* Event reception */
void Delay__Timer_Is_Up( const Class_Delay* Me );


#endif