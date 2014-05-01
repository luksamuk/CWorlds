// SW_CommonTypes.hpp
// Header for common custom types used on the engine
// e.g. point definitions.

#ifndef SW_COMMONTYPES_HPP
#define SW_COMMONTYPES_HPP

#include "SW_Base.hpp"
#include <cstdint>

// Most part is a straight copy from OficinaFramework, but it doesn't
// has to be a secret to anyone.

/// \defgroup Datatypes Data Types
/// \brief Data types with controlled size, ideal for bitwise operations.
/// Based on definitions for integer types.
/// @{

/// \brief 8-bit unsigned type.
typedef uint8_t  byte;
/// \brief 16-bit unsigned type.
typedef uint16_t word;
/// \brief 32-bit unsigned type.
typedef uint32_t dword;
/// \brief 64-bit unsigned type.
typedef uint64_t qword;

/// \brief 8-bit signed type.
typedef int8_t  byte_s;
/// \brief 16-bit signed type.
typedef int16_t word_s;
/// \brief 32-bit signed type.
typedef int32_t dword_s;
/// \brief 64-bit signed type.
typedef int64_t qword_s;
/// @}


/// \brief A class representing a point in 2D space.
class vec2
{
    friend ostream& operator<<(ostream& oss, const vec2& v) {
        char buffer[255];
        sprintf(buffer, "{%0.04f, %0.04f}", v.x, v.y);
        //oss << buffer;
        return oss;
    }
public:
    /// \brief Constructs class with null values.
    vec2();
    /// \brief Constructs class with two equal values.
    /// @param n
    /// Value to be given to coordinates.
    vec2(float n);
    ///
    /// \brief Constructs class with two values.
    /// @param X
    /// Value to be given to x coordinate.
    /// @param Y
    /// Value to be given to y coordinate.
    vec2(float X, float Y);

    /// \brief X coordinate of point.
    float x;
    /// \brief Y coordinate of point.
    float y;

    vec2&      operator=(const vec2);
    vec2&      operator=(const float);
    const vec2 operator+(const vec2);
    const vec2 operator+(const float);
    vec2&      operator+=(const vec2);
    vec2&      operator+=(const float);
    const vec2 operator-(const vec2);
    const vec2 operator-(const float);
    vec2&      operator-=(const vec2);
    vec2&      operator-=(const float);
    const vec2 operator*(const vec2);
    const vec2 operator*(const float);
    vec2&      operator*=(const vec2);
    vec2&      operator*=(const float);
    const vec2 operator/(const vec2);
    const vec2 operator/(const float);
    vec2&      operator/=(const vec2);
    vec2&      operator/=(const float);
    bool       operator>(const vec2);
    bool       operator>(const float);
    bool       operator<(const vec2);
    bool       operator<(const float);
    bool       operator>=(const vec2);
    bool       operator>=(const float);
    bool       operator<=(const vec2);
    bool       operator<=(const float);
    bool       operator==(const vec2);
    bool       operator==(const float);
    bool       operator!=(const vec2);
    bool       operator!=(const float);

    /// \brief Returns a vec2 with both coordinates having the value 0.0f.
    /// \return A null-values vec2.
    static vec2 Zero();
    /// \brief Returns a vec2 with both coordinates having the value 1.0f.
    /// \return An unitary-value vec2.
    static vec2 One();
    /// \brief Returns a copy of this vec2 truncated to the nearest integer.
    /// \return The truncated vec2 of this.
    vec2        get_truncated();
    /// \brief Truncates the coordinates of this.
    void        truncate();
};

/// \brief A class representing a point in 2D space,
/// using a given data type.
/// Only works with predefined types.
/// See the vec2t Types module for more details.
/// \see Vec2Types
template<typename T>
class vec2t
{
public:
        /// \brief Constructs class with null values.
		vec2t();
        /// \brief Constructs class with two equal values.
        /// @param n
        /// Value to be given to coordinates.
		vec2t(T n);
        /// \brief Constructs class with two values.
        /// @param X
        /// Value to be given to x coordinate.
        /// @param Y
        /// Value to be given to y coordinate.
		vec2t(T X, T Y);

        /// \brief X coordinate of point.
		T x;
		/// \brief Y coordinate of point.
		T y;

		vec2t<T>&      operator=(const vec2t<T>);
		vec2t<T>&      operator=(const T);
		const vec2t<T> operator+(const vec2t<T>);
		const vec2t<T> operator+(const T);
		vec2t<T>&      operator+=(const vec2t<T>);
		vec2t<T>&      operator+=(const T);
		const vec2t<T> operator-(const vec2t<T>);
		const vec2t<T> operator-(const T);
		vec2t<T>&      operator-=(const vec2t<T>);
		vec2t<T>&      operator-=(const T);
		const vec2t<T> operator*(const vec2t<T>);
		const vec2t<T> operator*(const T);
		vec2t<T>&      operator*=(const vec2t<T>);
		vec2t<T>&      operator*=(const T);
		const vec2t<T> operator/(const vec2t<T>);
		const vec2t<T> operator/(const T);
		vec2t<T>&      operator/=(const vec2t<T>);
		vec2t<T>&      operator/=(const T);
		bool          operator>(const vec2t<T>);
		bool          operator>(const T);
		bool          operator<(const vec2t<T>);
		bool          operator<(const T);
		bool          operator>=(const vec2t<T>);
		bool          operator>=(const T);
		bool          operator<=(const vec2t<T>);
		bool          operator<=(const T);
		bool          operator==(const vec2t<T>);
		bool          operator==(const T);
		bool          operator!=(const vec2t<T>);
		bool          operator!=(const T);

		/// \brief Converts this class to a vec2.
		/// \return A vec2 equivalent of this class.
		vec2          toVec2();

		static vec2t<T> Zero();
		static vec2t<T> One();
};

// Typedefs for the vec2t valid types

/// \defgroup Vec2Types vec2t Types
///  Typedefs for using vec2t<T>.
/// \see vec2t
/// \see Datatypes
/// @{

/// \brief A class representing a point in 2D space, with double precision.
typedef vec2t<double> vec2d;

///  \brief A class representing a point in 2D space, with 8-bit precision.
typedef vec2t<byte>    vec2b;
///  \brief A class representing a point in 2D space, with 16-bit precision.
typedef vec2t<word>    vec2w;
///  \brief A class representing a point in 2D space, with 32-bit precision.
typedef vec2t<dword>   vec2dw;
///  \brief A class representing a point in 2D space, with 64-bit precision.
typedef vec2t<qword>   vec2qw;

///  \brief A class representing a point in 2D space, with signed 8-bit precision.
typedef vec2t<byte_s>    vec2sb;
///  \brief A class representing a point in 2D space, with signed 16-bit precision.
typedef vec2t<word_s>    vec2sw;
///  \brief A class representing a point in 2D space, with signed 64-bit precision.
typedef vec2t<qword_s>   vec2sqw;
/// @}

#endif