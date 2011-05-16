//
// intervalwithunits.h
// Access class for time intervals.
// This header file should not be included directly into user code.
// Written by Andrew Lin
//
#ifndef INTERVALWITHUNITS_H
#define INTERVALWITHUNITS_H

#include "interval.h"

// Class that converts between the base units and the requested units.
// Template arguments are:
// T - storage container type for the measurement value. The type
//    must have the arithmetic operators overloaded (addition,
//    subtraction, multiplication, division).
// numerator - the numerator of the conversion factor for converting
//    from the base units to the requested units.
// denominator - the denominator of the conversion factor for
//    converting from the base units to the requested units.
template< typename T, T numerator, T denominator >
class IntervalWithUnits : public Interval< T >
{
public:
    
    // Initialization constructor.
    explicit IntervalWithUnits( T const & rhs ) : 
        Interval< T >( rhs * denominator / numerator )
    {
    }
    
    // Copy constructor.
    IntervalWithUnits( Interval< T > const & rhs ) :
        Interval< T >( rhs )
    {
    }
    
    // Retrieves the value in the units specified for this template.
    T const get() const
    {
        return Interval< T >::value * numerator / denominator;
    }
    
    // Streams out the value in the units specified for this template.
    std::ostream & streamout( std::ostream & strm ) const
    {
        strm << static_cast< double >( Interval< T >::value ) * 
                numerator / denominator;
        return strm;
    }
    
private:
    
    // Disallow construction without a value.
    IntervalWithUnits() {}
};

// Streamout operator for all IntervalWithUnits.
template< typename T, T numerator, T denominator >
std::ostream & operator <<
( 
    std::ostream & strm, 
    IntervalWithUnits< T, numerator, denominator > const & rhs 
)
{
    return rhs.streamout( strm );
}

#endif