//
// speed.h
// Storage class for speed measurements.
// This header file should not be included directly into user code.
// Written by Andrew Lin
//
#ifndef SPEED_H
#define SPEED_H

// Class that stores the measurement value in the base units defined
// in speedunits.h.
// T - storage container type for the measurement value. The type
//    must have the arithmetic operators overloaded (addition,
//    subtraction, multiplication, division).
template< typename T >
class Speed
{
public:
    
    // Copy constructor.
    Speed( Speed const & rhs ) : value( rhs.value ) {}
    
    // Addition of a Speed.
    Speed & operator +=( Speed const & rhs )
    {
        value += rhs.value;
        return *this;
    }
    
    // Subtraction of a Speed.
    Speed & operator -=( Speed const & rhs )
    {
        value -= rhs.value;
        return *this;
    }
    
    // Multiplication by a scalar.
    Speed & operator *=( T const & rhs )
    {
        value *= rhs;
        return *this;
    }
    
    // Division by a scalar.
    Speed & operator/=( T const & rhs )
    {
        value /= rhs;
        return *this;
    }
    
protected:
    
    // Disallow default construction of a Speed without associated 
    // units.
    Speed() {}
    
    // Initialization constructor. Protected to allow the
    // SpeedWithUnits class to have access.
    explicit Speed( T const & rhs ) : value( rhs ) {}
    
    // Storage for the value is protected to allow the SpeedWithUnits 
    // class to have direct access.
    T value;
};


// Addition.
template< typename T >
Speed< T > const & operator +
( 
    Speed< T > const & lhs, 
    Speed< T > const & rhs 
)
{
    return Speed< T >( lhs ) += rhs;
}

// Subtraction.
template< typename T >
Speed< T > const & operator -
( 
    Speed< T > const & lhs, 
    Speed< T > const & rhs 
)
{
    return Speed< T >( lhs ) -= rhs;
}

// Mutiplication by a scalar.
template< typename T >
Speed< T > const & operator *( Speed< T > const & lhs, T const & rhs )
{
    return Speed< T >( lhs ) *= rhs;
}

template< typename T >
Speed< T > const & operator *( T const & lhs, Speed< T > const & rhs )
{
    return Speed< T >( rhs ) *= lhs;
}

// Division by a scalar.
template< typename T >
Speed< T > const & operator /( Speed< T > const & lhs, T const & rhs )
{
    return Speed< T >( lhs ) /= rhs;
}

#endif
