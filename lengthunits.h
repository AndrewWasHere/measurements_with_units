//
// lengthunits.h
// Definition of access classes for lengths with units.
// Written by Andrew Lin
//
#ifndef LENGTHUNITS_H
#define LENGTHUNITS_H

#include "lengthwithunits.h"

// NOTE: Storage units for Length are defined to be micrometers (um). 
// All declared units must be derived from that.

// Base storage type.
typedef Length< long > length;

// Metric Units.
typedef LengthWithUnits< long, 1, 1 >          length_um;
typedef LengthWithUnits< long, 1, 1000 >       length_mm;
typedef LengthWithUnits< long, 1, 10000 >      length_cm;
typedef LengthWithUnits< long, 1, 1000000 >    length_m;
typedef LengthWithUnits< long, 1, 1000000000 > length_km;

// English Units.
typedef LengthWithUnits< long, 1, 25400 >      length_inches;
typedef LengthWithUnits< long, 1, 304800 >     length_feet;
typedef LengthWithUnits< long, 1, 914400 >     length_yards;
typedef LengthWithUnits< long, 1, 1609344000 > length_miles;

#endif
