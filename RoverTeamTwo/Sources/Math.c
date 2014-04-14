#include "Math.h"
#include "Rover.h"


static const Word TangentLut[] = 
{
   0, 1, 3, 5, 6, 8, 10, 12, 14,
   15, 17, 19, 21, 23, 24, 26, 28, 30,
   32, 34, 36, 38, 40, 42, 44, 46, 48,
   50, 53, 55, 57, 60, 62, 64, 67, 70,
   72, 75, 78, 80, 83, 86, 90, 93, 96,
   99, 103, 107, 111, 115, 119, 123, 127, 132,
   137, 142, 148, 153, 160, 166, 173, 180, 188,
   196, 205, 214, 224, 235, 247, 260, 274, 290,
   307, 327, 348, 373, 401, 433, 470, 514, 567,
   631, 711, 814, 951, 1142, 1430, 1908, 2863, 5728
};


degree_t arcTangent( sWord y, sWord x )
{
   Word uNumerator, uDenominator, uRatio;
   degree_t low, high;

   uNumerator = ( y > 0 ? y : -y );
   uDenominator = ( x > 0 ? x : -x );

   if ( uDenominator == 0 ) return ( 180 * ( y > 0 ) - 90 );
   
   uRatio = 100 * ( uNumerator / uDenominator );
   uNumerator = 10 * ( uNumerator % uDenominator );
   uRatio += 10 * ( uNumerator / uDenominator );
   uNumerator = 10 * ( uNumerator % uDenominator );
   uRatio += uNumerator / uDenominator;
   
   low = 0;
   high = 91;
   
   while ( high - low > 1 )
   {
      if ( uRatio > TangentLut[ ( low + high ) / 2 ] )
      {
         low = ( low + high ) / 2;
      }
      else
      {          
         high = ( low + high ) / 2;
      }
   }


   if ( y >= 0 )
   {
      // Quadrant I
      if ( x > 0 )
         return low;
      // Quadrant II
      else
         return 180 - low;
   }
   else
   {
      // Quadrant III
      if ( x < 0 )
         return low - 180;
      // Quadrant IV
      else
         return ~low + 1;
   }
}