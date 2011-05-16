//
// interval.h
// Storage class for time interval measurements.
// This header file should not be included directly into user code.
// Written by Andrew Lin
//
#ifndef INTERVAL_H
#define INTERVAL_H

// Class that stores the measurement value in the base units defined
// in intervalunits.h.
// T - storage container type for the measurement value. The type
//    must have the arithmetic operators overloaded (addition,
//    subtraction, multiplication, division).
template< typename T >
class Interval
{
public:
    
    // Copy constructor.
    Interval( Interval const & rhs ) : value( rhs.value ) {}
    
    // Addition of a Interval.
    Interval & operator +=( Interval const & rhs )
    {
        value += rhs.value;
        return *this;
    }
    
    // Subtraction of a Interval.
    Interval & operator -=( Interval const & rhs )
    {
        value -= rhs.value;
        return *this;
    }
    
    // Multiplication by a scalar.
    Interval & operator *=( T const & rhs )
    {
        value *= rhs;
        return *this;
    }
    
    // Division by a scalar.
    Interval & operator/=( T const & rhs )
    {
        value /= rhs;
        return *this;
    }
    
protected:
    
    // Disallow default construction of a Interval without associated
    // units.
    Interval() {}
    
    // Initialization constructor. Protected to allow the
    // IntervalWithUnits class to have access.
    explicit Interval( T const & rhs ) : value( rhs ) {}
    
    // Storage for the value is protected to allow the 
    // IntervalWithUnits class to have direct access.
    T value;
};


// Addition.
template< typename T >
Interval< T > const & operator +
( 
    Interval< T > const & lhs, 
    Interval< T > const & rhs 
)
{
    return Interval< T >( lhs ) += rhs;
}

// Subtraction.
template< typename T >
Interval< T > const operator -
( 
    Interval< T > const & lhs, 
    Interval< T > const & rhs 
)
{
    return Interval< T >( lhs ) -= rhs;
}

// Mutiplication by a scalar.
template< typename T >
Interval< T > const operator *
( 
    Interval< T > const & lhs, 
    T             const & rhs 
)
{
    return Interval< T >( lhs ) *= rhs;
}

template< typename T >
Interval< T > const operator *
( 
    T             const & lhs, 
    Interval< T > const & rhs 
)
{
    return Interval< T >( rhs ) *= lhs;
}

// Division by a scalar.
template< typename T >
Interval< T > const operator /
( 
    Interval< T > const & lhs, 
    T             const & rhs 
)
{
    return Interval< T >( lhs ) /= rhs;
}

#endif
