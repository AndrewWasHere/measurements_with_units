//
// speedwithunits.h
// Access class for speeds with units.
// This header file should not be included directly into user code.
// Written by Andrew Lin
//
#ifndef SPEEDWITHUNITS_H
#define SPEEDWITHUNITS_H

#include "speed.h"

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
class SpeedWithUnits : public Speed< T >
{
public:
    
    // Initialization constructor.
    explicit SpeedWithUnits( T const & rhs ) : 
        Speed< T >( rhs * denominator / numerator )
    {
    }
    
    // Copy constructor.
    SpeedWithUnits( Speed< T > const & rhs ) :
        Speed< T >( rhs )
    {
    }
    
    // Retrieves the value in the units specified for this template.
    T const get() const
    {
        return Speed< T >::value * numerator / denominator;
    }
    
    // Streams out the value in the units specified for this template.
    std::ostream & streamout( std::ostream & strm ) const
    {
        strm << static_cast< double >( Speed< T >::value ) * 
                numerator / denominator;
        return strm;
    }
    
private:
    
    // Disallow construction without a value.
    SpeedWithUnits() {}
};

// Streamout operator for all SpeedWithUnits.
template< typename T, T numerator, T denominator >
std::ostream & operator <<
( 
    std::ostream & strm, 
    SpeedWithUnits< T, numerator, denominator > const & rhs 
)
{
    return rhs.streamout( strm );
}

#endif