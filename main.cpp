//
// main.cpp
// Demonstration code for measurements-with-units
// Written by Andrew Lin
//
#include <iostream>

#include "intervalunits.h"
#include "lengthunits.h"
#include "speedunits.h"

// Display functions demonstrate the passing of unitless measures
// into functions, and the use of casting to measures-with-units
// when displaying the values.
void displayLength( char const * id, length const & len )
{
    // Explicitly associating the intended units with the measurement
    // allows for easy verification that the units labels are correct.
    std::cout << id 
              << " = " << length_um( len ) << " um"
              << " = " << length_mm( len ) << " mm"
              << " = " << length_inches( len ) << " inches"
              << " = " << length_feet( len ) << " feet"
              << std::endl;
}

void displayInterval( char const * id, interval const & delta )
{
    std::cout << id 
              << " = " << interval_us( delta ) << " us"
              << " = " << interval_s( delta ) << " s"
              << " = " << interval_min( delta ) << " min"
              << std::endl;
}

void displaySpeed( char const * id, speed const & spd )
{
    std::cout << id 
              << " = " << speed_meters_per_second( spd ) << " m/s"
              << " = " << speed_inches_per_second( spd ) << " in/s"
              << " = " << speed_kilometers_per_hour( spd ) << " km/h"
              << std::endl;
}

int main (int argc, char * const argv[]) 
{
    // Measures must always be initialized with corresponding units.
    length l1 = length_mm( 42 );
    displayLength( "l1", l1 );
    
    // Different units can be utilized in the code, as long as their
    // relation to the base storage units is enumerated in the
    // measurement's header file (in this case, lengthunits.h).
    length l2 = length_inches( 1 );
    displayLength( "l2", l2 );

    // Math can be done without casting to units.
    displayLength( "l1 + l2", l1 + l2 );
    
    interval t1 = interval_ms( 1500 );
    displayInterval( "t1", t1 );

    // Scaling is defined in the type. Declaring the scalar to be the
    // proper type is necessary for the template to work.
    displayInterval( "t1 / 2", t1 / 2l );

    speed s1 = speed_meters_per_second( 15 );
    displaySpeed( "s1", s1 );

    // Mathematical interactions between measurement types is defined
    // in the header file, allowing the compiler to check that the
    // math makes sense. In this case, length = speed * time.
    displayLength( "s1 * t1", s1 * t1 );
    
    return 0;
}
