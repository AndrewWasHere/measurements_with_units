//
// length.h
// Storage class for length measurements.
// This header file should not be included directly into user code.
// Written by Andrew Lin
//
#ifndef LENGTH_H
#define LENGTH_H

// Class that stores the measurement value in the base units defined
// in lengthunits.h.
// T - storage container type for the measurement value. The type
//    must have the arithmetic operators overloaded (addition,
//    subtraction, multiplication, division).
template< typename T >
class Length
{
public:
    
    // Copy constructor.
    Length( Length const & rhs ) : value( rhs.value ) {}
    
    // Addition of a Length.
    Length & operator +=( Length const & rhs )
    {
        value += rhs.value;
        return *this;
    }
    
    // Subtraction of a Length.
    Length & operator -=( Length const & rhs )
    {
        value -= rhs.value;
        return *this;
    }
    
    // Multiplication by a scalar.
    Length & operator *=( T const & rhs )
    {
        value *= rhs;
        return *this;
    }
    
    // Division by a scalar.
    Length & operator/=( T const & rhs )
    {
        value /= rhs;
        return *this;
    }
    
protected:
    
    // Disallow default construction of a Length without associated 
    // units.
    Length() {}
    
    // Initialization constructor. Protected to allow the
    // LengthWithUnits class to have access.
    explicit Length( T const & rhs ) : value( rhs ) {}
    
    // Storage for the value is protected to allow the LengthWithUnits 
    // class to have direct access.
    T value;
};


// Addition.
template< typename T >
Length< T > const & operator +
( 
    Length< T > const & lhs, 
    Length< T > const & rhs 
)
{
    return Length< T >( lhs ) += rhs;
}

// Subtraction.
template< typename T >
Length< T > const & operator -
( 
    Length< T > const & lhs, 
    Length< T > const & rhs 
)
{
    return Length< T >( lhs ) -= rhs;
}

// Mutiplication by a scalar.
template< typename T >
Length< T > const & operator *
( 
    Length< T > const & lhs, 
    T           const & rhs 
)
{
    return Length< T >( lhs ) *= rhs;
}

template< typename T >
Length< T > const & operator *
( 
    T           const & lhs, 
    Length< T > const & rhs 
)
{
    return Length< T >( rhs ) *= lhs;
}

// Division by a scalar.
template< typename T >
Length< T > const & operator /
( 
    Length< T > const & lhs, 
    T           const & rhs 
)
{
    return Length< T >( lhs ) /= rhs;
}

#endif
