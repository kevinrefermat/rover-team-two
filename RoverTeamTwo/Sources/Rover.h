#ifndef _ROVER_H_
#define _ROVER_H_

#include "MC9S12C128.h"
#include <stdtypes.h>

/*** TYPE DECLARATIONS ***/

typedef Byte boolean_t;
typedef sWord degree_t;
typedef Word pulseCount_t;
typedef Byte direction_t;
typedef Byte registerValue8_t;
typedef Word registerValue16_t;

// Time  
typedef Word milliseconds_t;
typedef LWord microseconds_t;
typedef Word timerCount_t;

// Distance
typedef Word inches_t; 
typedef Byte feet_t;


// NavigationSystem Types

typedef sByte nodeNumber_t;
typedef sByte obstacleNumber_t;

typedef struct
{
   inches_t x;
   inches_t y;
} coordinates_t;

/*** ROVER IO CONTROL ***/

extern const direction_t FORWARD_MOTION;
extern const direction_t REVERSE_MOTION;
extern const direction_t STOP_MOTION;
extern const direction_t ROTATE_MOTION;

extern const microseconds_t WAIT_FOR_ROVER_TO_ACTUALLY_STOP_DELAY;

#define MOTOR_DRIVE_IO PORTA
#define MOTOR_DRIVE_DDR DDRA
#define MOTOR_DRIVE_LEFT_IN_0 PORTA_BIT0
#define MOTOR_DRIVE_LEFT_IN_1 PORTA_BIT1
#define MOTOR_DRIVE_RIGHT_IN_0 PORTA_BIT2
#define MOTOR_DRIVE_RIGHT_IN_1 PORTA_BIT3
#define MOTOR_DRIVE_LEFT_ENABLE PWME_PWME2  
#define MOTOR_DRIVE_LEFT_PERIOD PWMPER2
#define MOTOR_DRIVE_LEFT_DUTY PWMDTY2
#define MOTOR_DRIVE_RIGHT_ENABLE PWME_PWME3   
#define MOTOR_DRIVE_RIGHT_PERIOD PWMPER3
#define MOTOR_DRIVE_RIGHT_DUTY PWMDTY3
 
#define OBJECT_DETECTION_PIN PTT_PTT0
#define OBJECT_DETECTION_DDR DDRT_DDRT0


/*** CONSTANTS ***/

#define MAX_16_BIT_VALUE 65535

#define CLOCK_SPEED_HZ 2000000
#define TIMER_COUNTER_PRESCALE 128
#define TIMER_COUNTER_TICKS_PER_S ( CLOCK_SPEED_HZ / TIMER_COUNTER_PRESCALE )
#define TIMER_COUNTER_TICKS_PER_MS ( TIMER_COUNTER_TICKS_PER_S / 1000 )

#define MAX_PERIOD_OF_INTERRUPT_MS ( ( MAX_16_BIT_VALUE * 1000 ) / TIMER_COUNTER_TICKS_PER_S )

#define SPEED_OF_SOUND_INCH_PER_SEC 13506
#define CLOCK_TICKS_PER_INCH_OF_SOUND_TRAVEL ( CLOCK_SPEED_HZ / SPEED_OF_SOUND_INCH_PER_SEC )

#define DC_MOTOR_ENCODER_FREQ 70

extern const boolean_t False;
extern const boolean_t True;

/*** USEFUL FUNCTIONS ***/

void Delay( microseconds_t time );

void TurnOnErrorLight( void );
void TurnOffErrorLight( void );


// I don't like the CPU hogging delay function in delay() FIX IT

/*** INITIALIZATION FUNCTIONS ***/

void InitializeTimers( void );

#endif
