//
// intervalunits.h
// Definition of storage classes for time intervals with units.
// Written by Andrew Lin
//
#ifndef INTERVALUNITS_H
#define INTERVALUNITS_H

#include "intervalwithunits.h"

// NOTE: Storage units for Interval are defined to be microseconds 
// (us). All declared units must be derived from that.

// Base storage type.
typedef Interval< long > interval;

// Units.
typedef IntervalWithUnits< long, 1, 1 >          interval_us;
typedef IntervalWithUnits< long, 1, 1000 >       interval_ms;
typedef IntervalWithUnits< long, 1, 1000000 >    interval_s;
typedef IntervalWithUnits< long, 1, 60000000 >   interval_min;
typedef IntervalWithUnits< long, 1, 1440000000 > interval_hour;

#endif
