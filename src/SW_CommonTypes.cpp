#include "SW_CommonTypes.hpp"

int SW_Log(const char* fmt, ...)
{
#ifdef DEBUG
	va_list args;
	va_start(args, fmt);
	int ret = vprintf(fmt, args);
	va_end(args);
	return ret;
#else
	return 0;
#endif
}

//-----------------------------------------------
//           vec2 class definitions             |
//-----------------------------------------------

vec2::vec2()
{
    x = y = 0.0f;
}

vec2::vec2(float n)
{
    x = y = n;
}

vec2::vec2(float X, float Y)
{
    x = X;
    y = Y;
}

vec2& vec2::operator=(const vec2 n)
{
    if(!(this == &n))
    {
        this->x = n.x;
        this->y = n.y;
    }
    return (*this);
}

vec2& vec2::operator=(const float n)
{
    this->x = this->y = n;
    return (*this);
}


const vec2 vec2::operator+(const vec2 n)
{
    vec2 res = (*this);
    res.x += n.x;
    res.y += n.y;
    return res;
}

const vec2 vec2::operator+(const float n)
{
    vec2 res = (*this);
    res.x += n;
    res.y += n;
    return res;
}

vec2& vec2::operator+=(const vec2 n)
{
    if(!(this == &n))
    {
        this->x += n.x;
        this->y += n.y;
    }
    return (*this);
}

vec2& vec2::operator+=(const float n)
{
    this->x += n;
    this->y += n;
    return (*this);
}


const vec2 vec2::operator-(const vec2 n)
{
    vec2 res = (*this);
    res.x -= n.x;
    res.y -= n.y;
    return res;
}

const vec2 vec2::operator-(const float n)
{
    vec2 res = (*this);
    res.x -= n;
    res.y -= n;
    return res;
}

vec2& vec2::operator-=(const vec2 n)
{
    if(!(this == &n))
    {
        this->x -= n.x;
        this->y -= n.y;
    }
    return (*this);
}

vec2& vec2::operator-=(const float n)
{
    this->x -= n;
    this->y -= n;
    return (*this);
}


const vec2 vec2::operator*(const vec2 n)
{
    vec2 res = (*this);
    res.x *= n.x;
    res.y *= n.y;
    return res;
}

const vec2 vec2::operator*(const float n)
{
    vec2 res = (*this);
    res.x *= n;
    res.y *= n;
    return res;
}

vec2& vec2::operator*=(const vec2 n)
{
    if(!(this == &n))
    {
        this->x *= n.x;
        this->y *= n.y;
    }
    return (*this);
}

vec2& vec2::operator*=(const float n)
{
    this->x *= n;
    this->y *= n;
    return (*this);
}


const vec2 vec2::operator/(const vec2 n)
{
    vec2 res = (*this);
    res.x /= n.x;
    res.y /= n.y;
    return res;
}

const vec2 vec2::operator/(const float n)
{
    vec2 res = (*this);
    res.x /= n;
    res.y /= n;
    return res;
}

vec2& vec2::operator/=(const vec2 n)
{
    if(!(this == &n))
    {
        this->x /= n.x;
        this->y /= n.y;
    }
    return (*this);
}

vec2& vec2::operator/=(const float n)
{
    this->x /= n;
    this->y /= n;
    return (*this);
}


bool vec2::operator>(const vec2 n)
{
    return((this->x > n.x) && (this->y > n.y));
}

bool vec2::operator>(const float n)
{
    return((this->x > n) && (this->y > n));
}

bool vec2::operator<(const vec2 n)
{
    return((this->x < n.x) && (this->y < n.y));
}

bool vec2::operator<(const float n)
{
    return((this->x < n) && (this->y < n));
}


bool vec2::operator>=(const vec2 n)
{
    return((this->x >= n.x) && (this->y >= n.y));
}

bool vec2::operator>=(const float n)
{
    return((this->x >= n) && (this->y >= n));
}

bool vec2::operator<=(const vec2 n)
{
    return((this->x <= n.x) && (this->y <= n.y));
}

bool vec2::operator<=(const float n)
{
    return((this->x <= n) && (this->y <= n));
}


bool vec2::operator==(const vec2 n)
{
    if((this == &n)) return true;
    return ((this->x == n.x) && (this->y == n.y));
}

bool vec2::operator==(const float n)
{
    return ((this->x == n) && (this->y == n));
}

bool vec2::operator!=(const vec2 n)
{
    if((this == &n)) return false;
    return ((this->x != n.x) && (this->y != n.y));
}

bool vec2::operator!=(const float n)
{
    return ((this->x != n) && (this->y != n));
}

vec2 vec2::Zero()
{
    return vec2(0.0f, 0.0f);
}

vec2 vec2::One()
{
    return vec2(1.0f, 1.0f);
}

vec2 vec2::get_truncated()
{
    vec2 res = (*this);
    res.truncate();
    return res;
}

void vec2::truncate()
{
    this->x = int(this->x);
    this->y = int(this->y);
}

ostream& operator<<(ostream& oss, const vec2& v) {
    char buffer[255];
    sprintf(buffer, "{%0.04f, %0.04f}", v.x, v.y);
    oss << buffer;
    return oss;
}

//-----------------------------------------------
//          vec2t class definitions             |
//-----------------------------------------------

template<typename T>
vec2t<T>::vec2t()
{
	x = y = 0;
}

template<typename T>
vec2t<T>::vec2t(T n)
{
	x = y = n;
}

template<typename T>
vec2t<T>::vec2t(T X, T Y)
{
	x = X; y = Y;
}

template<typename T>
vec2t<T>& vec2t<T>::operator=(const vec2t<T> n)
{
	if(!(this == &n))
	{
		this->x = n.x;
		this->y = n.y;
	}
	return (*this);
}

template<typename T>
vec2t<T>& vec2t<T>::operator=(const T n)
{
	this->x = this->y = n;
	return (*this);
}

template<typename T>
const vec2t<T> vec2t<T>::operator+(const vec2t n)
{
	vec2t res = (*this);
	res.x += n.x;
	res.y += n.y;
	return res;
}

template<typename T>
const vec2t<T> vec2t<T>::operator+(const T n)
{
	vec2t res = (*this);
	res.x += n;
	res.y += n;
	return res;
}

template<typename T>
vec2t<T>& vec2t<T>::operator+=(const vec2t n)
{
	if(!(this == &n))
	{
		this->x += n.x;
		this->y += n.y;
	}
	return (*this);
}

template<typename T>
vec2t<T>& vec2t<T>::operator+=(const T n)
{
	this->x += n;
	this->y += n;
	return (*this);
}

template<typename T>
const vec2t<T> vec2t<T>::operator-(const vec2t<T> n)
{
	vec2t res = (*this);
	res.x -= n.x;
	res.y -= n.y;
	return res;
}

template<typename T>
const vec2t<T> vec2t<T>::operator-(const T n)
{
	vec2t res = (*this);
	res.x -= n;
	res.y -= n;
	return res;
}

template<typename T>
vec2t<T>& vec2t<T>::operator-=(const vec2t<T> n)
{
	if(!(this == &n))
	{
		this->x -= n.x;
		this->y -= n.y;
	}
	return (*this);
}

template<typename T>
vec2t<T>& vec2t<T>::operator-=(const T n)
{
	this->x -= n;
	this->y -= n;
	return (*this);
}

template<typename T>
const vec2t<T> vec2t<T>::operator*(const vec2t<T> n)
{
	vec2t res = (*this);
	res.x *= n.x;
	res.y *= n.y;
	return res;
}

template<typename T>
const vec2t<T> vec2t<T>::operator*(const T n)
{
	vec2t res = (*this);
	res.x *= n;
	res.y *= n;
	return res;
}

template<typename T>
vec2t<T>& vec2t<T>::operator*=(const vec2t<T> n)
{
	if(!(this == &n))
	{
		this->x *= n.x;
		this->y *= n.y;
	}
	return (*this);
}

template<typename T>
vec2t<T>& vec2t<T>::operator*=(const T n)
{
	this->x *= n;
	this->y *= n;
	return (*this);
}

template<typename T>
const vec2t<T> vec2t<T>::operator/(const vec2t<T> n)
{
	vec2t res = (*this);
	res.x /= n.x;
	res.y /= n.y;
	return res;
}

template<typename T>
const vec2t<T> vec2t<T>::operator/(const T n)
{
	vec2t res = (*this);
	res.x /= n;
	res.y /= n;
	return res;
}

template<typename T>
vec2t<T>& vec2t<T>::operator/=(const vec2t<T> n)
{
	if(!(this == &n))
	{
		this->x /= n.x;
		this->y /= n.y;
	}
	return (*this);
}

template<typename T>
vec2t<T>& vec2t<T>::operator/=(const T n)
{
	this->x /= n;
	this->y /= n;
	return (*this);
}

template<typename T>
bool vec2t<T>::operator>(const vec2t<T> n)
{
	return((this->x > n.x) && (this->y > n.y));
}

template<typename T>
bool vec2t<T>::operator>(const T n)
{
	return((this->x > n) && (this->y > n));
}

template<typename T>
bool vec2t<T>::operator<(const vec2t<T> n)
{
	return((this->x < n.x) && (this->y < n.y));
}

template<typename T>
bool vec2t<T>::operator<(const T n)
{
	return((this->x < n) && (this->y < n));
}

template<typename T>
bool vec2t<T>::operator>=(const vec2t<T> n)
{
	return((this->x >= n.x) && (this->y >= n.y));
}

template<typename T>
bool vec2t<T>::operator>=(const T n)
{
	return((this->x >= n) && (this->y >= n));
}

template<typename T>
bool vec2t<T>::operator<=(const vec2t<T> n)
{
	return((this->x <= n.x) && (this->y <= n.y));
}

template<typename T>
bool vec2t<T>::operator<=(const T n)
{
	return((this->x <= n) && (this->y <= n));
}

template<typename T>
bool vec2t<T>::operator==(const vec2t<T> n)
{
	if((this == &n)) return true;
	return ((this->x == n.x) && (this->y == n.y));
}

template<typename T>
bool vec2t<T>::operator==(const T n)
{
	return ((this->x == n) && (this->y == n));
}

template<typename T>
bool vec2t<T>::operator!=(const vec2t<T> n)
{
	if((this == &n)) return false;
	return ((this->x != n.x) && (this->y != n.y));
}

template<typename T>
bool vec2t<T>::operator!=(const T n)
{
	return ((this->x != n) && (this->y != n));
}

template<typename T>
vec2 vec2t<T>::toVec2()
{
    return vec2((float)this->x, (float)this->y);
}

template<typename T>
vec2t<T> vec2t<T>::Zero()
{
    return vec2t<T>(0, 0);
}

template<typename T>
vec2t<T> vec2t<T>::One()
{
    return vec2t<T>(1, 1);
}

// Valid instantiations
template class vec2t<double>;
template class vec2t<byte>;
template class vec2t<word>;
template class vec2t<dword>;
template class vec2t<qword>;
template class vec2t<byte_s>;
template class vec2t<word_s>;
template class vec2t<dword_s>;
template class vec2t<qword_s>;
