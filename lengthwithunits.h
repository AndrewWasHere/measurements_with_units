//
// lengthwithunits.h
// Access class for lengths with units.
// This header file should not be included directly into user code.
// Written by Andrew Lin
//
#ifndef LENGTHWITHUNITS_H
#define LENGTHWITHUNITS_H

#include "length.h"

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
class LengthWithUnits : public Length< T >
{
public:
    
    // Initialization constructor.
    explicit LengthWithUnits( T const & rhs ) : 
        Length< T >( rhs * denominator / numerator )
    {
    }
    
    // Copy constructor.
    LengthWithUnits( Length< T > const & rhs ) :
        Length< T >( rhs )
    {
    }
    
    // Retrieves the value in the units specified for this template.
    T const get() const
    {
        return Length< T >::value * numerator / denominator;
    }
    
    // Streams out the value in the units specified for this template.
    std::ostream & streamout( std::ostream & strm ) const
    {
        strm << static_cast< double >( Length< T >::value ) *
                numerator / denominator;
        return strm;
    }
    
private:
    
    // Disallow construction without a value.
    LengthWithUnits() {}
};

// Streamout operator for all LengthWithUnits.
template< typename T, T numerator, T denominator >
std::ostream & operator <<
( 
    std::ostream & strm, 
    LengthWithUnits< T, numerator, denominator > const & rhs 
)
{
    return rhs.streamout( strm );
}

#endif