#pragma once

namespace gl {
inline namespace c {

struct VertexArrayId : Id { using Id::Id; };

void BindVertexArray(VertexArrayId array = VertexArrayId())
{
	fn.BindVertexArray((unsigned)array);
}

void DeleteVertexArrays(int n, VertexArrayId const *arrays)
{
	fn.DeleteVertexArrays(n, (unsigned const *)arrays);
}

void GenVertexArrays(int n, VertexArrayId *arrays)
{
	fn.GenVertexArrays(n, (unsigned *)arrays);
}

GLboolean IsVertexArray(VertexArrayId array)
{
	return fn.IsVertexArray((unsigned)array);
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
