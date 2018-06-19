#pragma once
#include "typedefs.hxx"
#include "constants.hxx"

namespace gl {

enum class Type : GLenum
{
	Byte = GL_BYTE,
	Short = GL_SHORT,
	Int = GL_INT,
	UnsignedByte = GL_UNSIGNED_BYTE,
	UnsignedShort = GL_UNSIGNED_SHORT,
	UnsignedInt = GL_UNSIGNED_INT,
	Fixed = GL_FIXED,
	HalfFloat = GL_HALF_FLOAT,
	Float = GL_FLOAT,
	Double = GL_DOUBLE,
};

template <typename T> struct TypeId;
template <> struct TypeId<sbyte> { static constexpr Type value = Type::Byte; };
template <> struct TypeId<ubyte> { static constexpr Type value = Type::UnsignedByte; };
template <> struct TypeId<short> { static constexpr Type value = Type::Short; };
template <> struct TypeId<unsigned short> { static constexpr Type value = Type::UnsignedShort; };
template <> struct TypeId<int> { static constexpr Type value = Type::Int; };
template <> struct TypeId<unsigned> { static constexpr Type value = Type::UnsignedInt; };
template <> struct TypeId<float> { static constexpr Type value = Type::Float; };
template <> struct TypeId<double> { static constexpr Type value = Type::Double; };

struct Id
{
	unsigned value = 0;
	Id() = default;
	Id(Id const &) = default;
	explicit Id(unsigned id) : value(id) {}
	explicit operator unsigned() const { return value; }
	explicit operator bool() const { return value; }
	bool operator!() const { return !value; }
};

}
