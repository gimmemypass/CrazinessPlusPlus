#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>


namespace sf
{
    const float kEpsilonNormalSqrt = 1e-15F;

    template <typename TVector>
    concept Vector3D = requires(TVector Vector) {
        { Vector.x } -> std::convertible_to<float>;
        { Vector.y } -> std::convertible_to<float>;
        { Vector.z } -> std::convertible_to<float>;
    };
    
    template <typename TVector>
    concept Vector2D = requires(TVector Vector) {
        { Vector.x } -> std::convertible_to<float>;
        { Vector.y } -> std::convertible_to<float>;
    };


    template <typename T>
    concept IsScalar = std::is_scalar<T>::value;

    static const auto PI = acos( -1 );

    /*
     * Vector addition
     */
    template <Vector2D T>
    T operator+( const T& vec1, const T& vec2 )
    {
        const auto newX = vec1.x + vec2.x;
        const auto newY = vec1.y + vec2.y;

        return T( newX, newY );
    }

    /*
     * Vector subtraction
     */
    template <Vector2D T>
    T operator-( const T& vec1, const T& vec2 )
    {
        const auto newX = vec1.x - vec2.x;
        const auto newY = vec1.y - vec2.y;

        return T( newX, newY );
    }

    /*
     * Scalar multiplication
     */
    template <Vector2D T, IsScalar U>
    T operator*( const T& vec, U scalar )
    {
        const auto newX = vec.x * scalar;
        const auto newY = vec.y * scalar;

        return T( newX, newY );
    }

    /*
     * Scalar multiplication
     */
    template <IsScalar U, Vector2D T>
    T operator*( U scalar, const T& vec )
    {
        const auto newX = vec.x * scalar;
        const auto newY = vec.y * scalar;

        return T( newX, newY );
    }

    /*
     * Returns the dot product of two given vectors
     */
    template <Vector2D T>
    double operator*( const T& vec1, const T& vec2 )
    {
        return vec1.x * vec2.x + vec1.y * vec2.y;
    }
    
    // /*
    //  * Returns the dot product of two given vectors
    //  */
    // template <Vector3D T>
    // double operator*( const T& vec1, const T& vec2 )
    // {
    //     return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
    // }

    /*
     * Returns the square of a given value
     */
    template <IsScalar T>
    inline T sqr( T value )
    {
        return value * value;
    }

    /*
     * Converts radians to degrees
     */
    template <IsScalar T>
    inline double radToDeg( T radians )
    {
        return radians * 180.0 / PI;
    }

    /*
     * Converts degrees to radian
     */
    template <IsScalar T>
    inline double degToRad( T degree )
    {
        return degree / 180.0 * PI;
    }

    /*
     * Returns the length of a given vector
     */
    template <Vector2D T>
    inline double magnitude( const T& vec )
    {
        return sqrt( sqr( vec.x ) + sqr( vec.y ) );
    }
    // /*
    //  * Returns the length of a given vector
    //  */
    // template <Vector3D T>
    // inline double magnitude( const T& vec )
    // {
    //     return sqrt( sqr( vec.x ) + sqr( vec.y ) + sqr(vec.z));
    // }

    // /*
    //  * Returns the length of a given vector
    //  */
    // template <Vector3D T>
    // inline double sqrMagnitude( const T& vec )
    // {
    //     return sqr( vec.x ) + sqr( vec.y ) + sqr(vec.z);
    // }
    
    /*
     * Returns the length of a given vector
     */
    template <Vector2D T>
    inline double sqrMagnitude( const T& vec )
    {
        return sqr( vec.x ) + sqr( vec.y );
    }


    /*
     * Returns an inverted vector
     */
    template <Vector2D T>
    inline T getInverted( const T& vec )
    {
        return T( -vec.x, -vec.y );
    }

    /*
     * Inverts a given vector in-place
     */
    template <Vector2D T>
    inline T& invert( T& vec )
    {
        vec.x = -vec.x;
        vec.y = -vec.y;

        return vec;
    }

    /*
     * Returns a normalized vector
     */
    template <Vector2D T>
    inline T getNormalized( const T& vec )
    {
        const double length = magnitude( vec );
        const double newX   = vec.x / length;
        const double newY   = vec.y / length;

        return T( newX, newY );
    }

    /*
     * Normalizes a given vector in-place
     */
    template <Vector2D T>
    inline T& normalize( T& vec )
    {
        const double length = magnitude( vec );
        vec.x /= length;
        vec.y /= length;

        return vec;
    }

    /*
     * Returns the distance between two given points
     */
    template <Vector2D T>
    float distance(const T &point1, const T &point2) {
        float dx = point2.x - point1.x;
        float dy = point2.y - point1.y;
        return std::sqrt(dx * dx + dy * dy);
    }


    /*
     * Returns the angle of a given vector from 0 to 360° depending its direction on the unit circle
     */
    template <Vector2D T>
    inline double getRotationAngle( const T& vec )
    {
        const T      normalizedVec = getNormalized( vec );
        const double angleXRad     = acos( normalizedVec.x );
        const double angleYRad     = asin( normalizedVec.y );
        double       angleRad;

        if ( angleYRad < 0 )
            angleRad = degToRad( 360 ) - angleXRad;
        else
            angleRad = angleXRad;

        return radToDeg( angleRad );
    }

    /*
     * Returns the angle in degrees between two given vectors
     */
    template <Vector2D T>
    inline double getAngleBetween( const T& from, const T& to )
    {
        const double angle = acos( ( from * to ) / ( magnitude( from ) * magnitude( to ) ) );

        return radToDeg( angle );
    }
    
    // /*
    //  * Returns the angle in degrees between two given vectors
    //  */
    // template <Vector3D T>
    // inline double getAngleBetween3D( const T& from, const T& to)
    // {
    //     float denominator = std::sqrt(sqrMagnitude<T>(from) * sqrMagnitude<T>(to));
    //     if (denominator < kEpsilonNormalSqrt)
    //         return 0;
    //
    //     const float dot = std::clamp(from*to / denominator, -1.f, 1.f);
    //     return radToDeg(std::acos(dot));
    // }

    /*
     * Returns a vector rotated with a given angle in degrees
     */
    template <Vector2D T>
    inline void getRotated( const T& vec, double angle )
    {
        const double angleRad = degToRad( -angle );
        const double newX     = vec.x * cos( angleRad ) - vec.y * sin( angleRad );
        const double newY     = vec.x * sin( angleRad ) + vec.y * cos( angleRad );

        return T( newX, newY );
    }

    /*
     * Rotates a vector in-place with a given angle in degrees
     */
    template <Vector2D T>
    inline T& rotate( T& vec, double angle )
    {
        const double angleRad = degToRad( -angle );
        
        vec.x = vec.x * cos( angleRad ) - vec.y * sin( angleRad );
        vec.y = vec.x * sin( angleRad ) + vec.y * cos( angleRad );

        return vec;
    }

    /*
     * Returns the projection of a vector on a given axis
     */
    template <Vector2D T>
    T projection( const T& vec, const T& axis ) {
        T NullVector(0, 0);
        if (axis == NullVector) {
            return NullVector;
        }
        float k = (vec * axis) / (axis * axis);
        return k * axis;
    }


    /**
     * Returns the reflection of a vector on a given normal
     */
    template <Vector2D T>
    T reflect(const T& vec, const T& normal) {
        return  normal * 2.0 * vec * normal;
    }


    /**
     * Returns the normal of a vector between two points
     */
    template <Vector2D T>
    T normalBetweenPoints(const T &point1, const T &point2) {
        T direction = point2 - point1;
        T normal = {direction.y, -direction.x};
        return sf::normalize(normal);
    }
    
    template<Vector3D T3>
    T3 cross(const T3 from, const T3 to)
    {
        const float cross_x = from.y * to.z - from.z * to.y;
        const float cross_y = from.z * to.x - from.x * to.z;
        const float cross_z = from.x * to.y - from.y * to.x;
        return T3(cross_x, cross_y, cross_z);
    }
    
    template<Vector2D T2, Vector3D T3>
    T3 cross(const T2 from, const T2 to)
    {
        const float crossZ = from.x * to.y - from.y * to.x;
        return T3(0,0,crossZ);
    }
    // template<Vector3D T3>
    // float signedAngle(const T3 from, const T3 to, const T3 axis)
    // {
    //     const float unsignedAngle = getAngleBetween3D(from, to);
    //
    //     const float cross_x = from.y * to.z - from.z * to.y;
    //     const float cross_y = from.z * to.x - from.x * to.z;
    //     const float cross_z = from.x * to.y - from.y * to.x;
    //     const float sign = std::signbit(axis.x * cross_x + axis.y * cross_y + axis.z * cross_z);
    //     return unsignedAngle * sign;
    // }
    
    template<Vector2D T2>
    float signedAngle(const T2 from, const T2 to)
    {
        // return signedAngle(T3(from.x, from.y,0), T3(to.x, to.y,0), T3(0,0,1));
        const float unsignedAngle = getAngleBetween(from, to);

        const float crossZ = from.x * to.y - from.y * to.x;
        const float sign = std::signbit(crossZ) == 1 ? -1 : 1;
        return unsignedAngle * sign;
    }

    inline float normalizeAngle(float angle) {
        float normalizedAngle = std::fmod(angle, 360.0);
        if (normalizedAngle < 0) {
            normalizedAngle += 360.f;
        }
        return normalizedAngle;
    }
    
    template<Vector2D T2>
    T2 lerp(const T2 from, const T2 to, const float t)
    {
        return T2(
            std::lerp(from.x, to.x, t),
            std::lerp(from.y, to.y, t)
            );
    }

}
