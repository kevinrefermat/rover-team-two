#include <hidef.h>
#include "derivative.h"
#include <libdefs.h>

#include "Rover.h"
#include "MotorControlSystem.h"
#include "NavigationSystem.h"
#include "ObstacleAvoidanceSystem.h"


#include "Compass.h"
#include "I2C.h"


void main( void )
{  
   
   
   TurnOffErrorLight();
   
   
   
   InitializeCompass();
   for ( ; ; )
   {
      GetDataFromCompass();
   }
   
   
   //InitializeTimers();
   
   //InitializeMotorControlSystem();
   //EnablePeriodicObstacleDetection( 300 );

   

   //MoveForward( 1200 );
   
   //MoveForward( 60 ); 
   //Rotate( 90 ); 
   for(;;);


   InitializeNavigationSystem();

   Dijkstra( 17, 18 );
    
   EnableInterrupts;    
   CommenceTurnByTurnExecution();
   
   for (;;); 
   //initializePeriodicObjectDetection();
}
