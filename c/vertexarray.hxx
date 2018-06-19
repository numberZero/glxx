#pragma once

namespace gl {
inline namespace c {

struct VertexArrayId : Id { using Id::Id; };

void BindVertexArray(VertexArrayId array = VertexArrayId())
{
	glBindVertexArray((GLuint)array);
}

void DeleteVertexArrays(GLsizei n, VertexArrayId const *arrays)
{
	glDeleteVertexArrays(n, (GLuint const *)arrays);
}

void GenVertexArrays(GLsizei n, VertexArrayId *arrays)
{
	glGenVertexArrays(n, (GLuint *)arrays);
}

GLboolean IsVertexArray(VertexArrayId array)
{
	return glIsVertexArray((GLuint)array);
}

VertexArrayId GenVertexArray()
{
	VertexArrayId array;
	GenVertexArrays(1, &array);
	return array;
}

void DeleteVertexArray(VertexArrayId array)
{
	DeleteVertexArrays(1, &array);
}

#ifndef GLXX_NO_STL
std::vector<VertexArrayId> GenVertexArrays(unsigned n)
{
	std::vector<VertexArrayId> arrays(n);
	GenVertexArrays(arrays.size(), arrays.data());
	return arrays;
}

void DeleteVertexArrays(std::vector<VertexArrayId> const &arrays)
{
	DeleteVertexArrays(arrays.size(), arrays.data());
}
#endif

}
}
