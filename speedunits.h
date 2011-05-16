//
// lengthunits.h
// Definition of storage classes for speeds with units.
// Written by Andrew Lin
//
#ifndef SPEEDUNITS_H
#define SPEEDUNITS_H

#include "speedwithunits.h"

#include "intervalunits.h"
#include "lengthunits.h"

// NOTE: Storage units for Speed are defined to be micrometers per 
// microsecond (um/us). All declared units must be derived from that.

// Base storage type.
typedef Speed< long > speed;

// Metric Units.
typedef SpeedWithUnits< long, 1, 1 >  speed_meters_per_second;
typedef SpeedWithUnits< long, 18, 5 > speed_kilometers_per_hour;

// English Units.
typedef SpeedWithUnits< long, 5000, 127 >    speed_inches_per_second;
typedef SpeedWithUnits< long, 1250, 381 >    speed_feet_per_second;
typedef SpeedWithUnits< long, 28125, 12573 > speed_miles_per_hour;

// Physical Definitions.
// speed = distance / time interval.
speed const operator /
( 
    length   const & distance, 
    interval const & time 
)
{
    // Math involving different units must specify the units being
    // used since the base unit types are ambiguous.
    return speed_meters_per_second
    ( 
        length_um( distance ).get() / interval_us( time ).get() 
    );
}

// time interval = distance / speed.
interval const operator /
( 
    length const & distance, 
    speed  const & spd 
)
{
    return interval_us
    ( 
        length_um( distance ).get() / 
        speed_meters_per_second( spd ).get() 
    );
}

// distance = speed * time interval.
length const operator *
( 
    speed    const & spd, 
    interval const & time 
)
{
    return length_um
    ( 
        speed_meters_per_second( spd ).get() * 
        interval_us( time ).get() 
    );
}

// distance = time interval * speed.
length const operator *
( 
  interval const & time, 
  speed    const & spd 
)
{
    return length_um
    ( 
      speed_meters_per_second( spd ).get() * 
      interval_us( time ).get() 
      );
}

#endif
