#pragma once
#include <glad/glad.h>

namespace gl {

enum class Type : GLenum
{
	Byte = GL_BYTE,
	Short = GL_SHORT,
	Int = GL_INT,
	UnsignedByte = GL_UNSIGNED_BYTE,
	UnsignedShort = GL_UNSIGNED_SHORT,
	UnsignedInt = GL_UNSIGNED_INT,
	x2Bytes = GL_2_BYTES,
	x3Bytes = GL_3_BYTES,
	x4Bytes = GL_4_BYTES,
	Fixed = GL_FIXED,
	HalfFloat = GL_HALF_FLOAT,
	Float = GL_FLOAT,
	Double = GL_DOUBLE,
};

template <typename T> struct TypeId;
template <> struct TypeId<GLbyte> { static constexpr Type value = Type::Byte; };
template <> struct TypeId<GLshort> { static constexpr Type value = Type::Short; };
template <> struct TypeId<GLint> { static constexpr Type value = Type::Int; };
template <> struct TypeId<GLubyte> { static constexpr Type value = Type::UnsignedByte; };
template <> struct TypeId<GLushort> { static constexpr Type value = Type::UnsignedShort; };
template <> struct TypeId<GLuint> { static constexpr Type value = Type::UnsignedInt; };
template <> struct TypeId<GLfloat> { static constexpr Type value = Type::Float; };
template <> struct TypeId<GLdouble> { static constexpr Type value = Type::Double; };

struct Id
{
	GLuint value = 0;
	Id() = default;
	Id(Id const &) = default;
	explicit Id(GLuint id) : value(id) {}
	explicit operator GLuint() const { return value; }
	explicit operator bool() const { return value; }
	bool operator!() const { return !value; }
};

}
