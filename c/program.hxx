#pragma once

namespace gl {
inline namespace c {

struct ProgramId : Id { using Id::Id; };

enum class ProgramInfo : GLenum
{
	DeleteStatus = GL_DELETE_STATUS,
	LinkStatus = GL_LINK_STATUS,
	ValidateStatus = GL_VALIDATE_STATUS,
	InfoLogLength = GL_INFO_LOG_LENGTH,
	AttachedShaders = GL_ATTACHED_SHADERS,
	ActiveAttributes = GL_ACTIVE_ATTRIBUTES,
	ActiveAttributeMaxLength = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
	ActiveUniforms = GL_ACTIVE_UNIFORMS,
	ActiveUiformMaxLength = GL_ACTIVE_UNIFORM_MAX_LENGTH,
};

struct ShaderId : Id { using Id::Id; };

enum class ShaderType : GLenum
{
	Vertex = GL_VERTEX_SHADER,
	Fragment = GL_FRAGMENT_SHADER,
	Geometry = GL_GEOMETRY_SHADER,
	Compute = GL_COMPUTE_SHADER,
	TessEvaluation = GL_TESS_EVALUATION_SHADER,
	TessControl = GL_TESS_CONTROL_SHADER,
};

enum class ShaderInfo : GLenum
{
	Type = GL_SHADER_TYPE,
	DeleteStatus = GL_DELETE_STATUS,
	CompileStatus = GL_COMPILE_STATUS,
	InfoLogLength = GL_INFO_LOG_LENGTH,
	SourceLength = GL_SHADER_SOURCE_LENGTH,
};

inline void AttachShader(ProgramId program, ShaderId shader)
{
	fn.AttachShader((unsigned)program, (unsigned)shader);
}

inline void BindAttribLocation(ProgramId program, unsigned index, char const *name)
{
	fn.BindAttribLocation((unsigned)program, index, name);
}

/*
inline void BlendEquationSeparate()
{
	return fn.BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha;
}
*/
inline void CompileShader(ShaderId shader)
{
	fn.CompileShader((unsigned)shader);
}

inline ProgramId CreateProgram()
{
	return ProgramId(fn.CreateProgram());
}

inline ShaderId CreateShader(ShaderType type)
{
	return ShaderId(fn.CreateShader((GLenum)type));
}

inline void DeleteProgram(ProgramId program)
{
	return fn.DeleteProgram((unsigned)program);
}

inline void DeleteShader(ShaderId shader)
{
	return fn.DeleteShader((unsigned)shader);
}

inline void DetachShader(ProgramId program, ShaderId shader)
{
	fn.DetachShader((unsigned)program, (unsigned)shader);
}
/*
inline void DisableVertexAttribArray()
{
	return fn.DisableVertexAttribArray();
}

inline void DrawBuffers()
{
	return fn.DrawBuffers();
}

inline void EnableVertexAttribArray()
{
	return fn.EnableVertexAttribArray();
}

inline void GetActiveAttrib()
{
	return fn.GetActiveAttrib();
}

inline void GetActiveUniform()
{
	return fn.GetActiveUniform();
}

inline void GetAttachedShaders()
{
	return fn.GetAttachedShaders();
}

inline void GetAttribLocation()
{
	return fn.GetAttribLocation();
}
*/
inline void GetProgramInfoLog(ProgramId program, int bufSize, int *length, char *buffer)
{
	fn.GetProgramInfoLog((unsigned)program, bufSize, length, buffer);
}

inline void GetProgram(ProgramId program, ProgramInfo what, int *result)
{
	fn.GetProgramiv((unsigned)program, (GLenum)what, result);
}

inline void GetShaderInfoLog(ShaderId shader, int bufSize, int *length, char *buffer)
{
	fn.GetShaderInfoLog((unsigned)shader, bufSize, length, buffer);
}

inline void GetShaderSource(ShaderId shader, int bufSize, int *length, char *buffer)
{
	fn.GetShaderSource((unsigned)shader, bufSize, length, buffer);
}

inline void GetShader(ShaderId shader, ShaderInfo what, int *result)
{
	fn.GetShaderiv((unsigned)shader, (GLenum)what, result);
}

inline int GetUniformLocation(ProgramId program, char const *name)
{
	return fn.GetUniformLocation((unsigned)program, name);
}
/*
inline void GetUniformfv()
{
	return fn.GetUniformfv();
}

inline void GetUniformiv()
{
	return fn.GetUniformiv();
}

inline void GetVertexAttribPointerv()
{
	return fn.GetVertexAttribPointerv();
}

inline void GetVertexAttribdv()
{
	return fn.GetVertexAttribdv();
}

inline void GetVertexAttribfv()
{
	return fn.GetVertexAttribfv();
}

inline void GetVertexAttribiv()
{
	return fn.GetVertexAttribiv();
}
*/
inline bool IsProgram(ProgramId id)
{
	return fn.IsProgram((unsigned)id);
}

inline bool IsShader(ShaderId id)
{
	return fn.IsShader((unsigned)id);
}

inline void LinkProgram(ProgramId id)
{
	fn.LinkProgram((unsigned)id);
}

inline void ShaderSource(ShaderId shader, int count, char const *const *code, int *length = nullptr)
{
	fn.ShaderSource((unsigned)shader, count, code, length);
}

/*
inline void StencilFuncSeparate()
{
	return fn.StencilFuncSeparate();
}

inline void StencilMaskSeparate()
{
	return fn.StencilMaskSeparate();
}

inline void StencilOpSeparate()
{
	return fn.StencilOpSeparate();
}
*/
template <typename T> void Uniform(int location, T x);
template <typename T> void Uniform(int location, T x, T y);
template <typename T> void Uniform(int location, T x, T y, T z);
template <typename T> void Uniform(int location, T x, T y, T z, T w);
template <int N, typename T> void Uniform(int location, int count, T const *v);

template <> inline void Uniform<float>(int location, float x) { fn.Uniform1f(location, x); }
template <> inline void Uniform<float>(int location, float x, float y) { fn.Uniform2f(location, x, y); }
template <> inline void Uniform<float>(int location, float x, float y, float z) { fn.Uniform3f(location, x, y, z); }
template <> inline void Uniform<float>(int location, float x, float y, float z, float w) { fn.Uniform4f(location, x, y, z, w); }
template <> inline void Uniform<1, float>(int location, int count, float const *v) { fn.Uniform1fv(location, count, v); }
template <> inline void Uniform<2, float>(int location, int count, float const *v) { fn.Uniform2fv(location, count, v); }
template <> inline void Uniform<3, float>(int location, int count, float const *v) { fn.Uniform3fv(location, count, v); }
template <> inline void Uniform<4, float>(int location, int count, float const *v) { fn.Uniform4fv(location, count, v); }

template <> inline void Uniform<int>(int location, int x) { fn.Uniform1i(location, x); }
template <> inline void Uniform<int>(int location, int x, int y) { fn.Uniform2i(location, x, y); }
template <> inline void Uniform<int>(int location, int x, int y, int z) { fn.Uniform3i(location, x, y, z); }
template <> inline void Uniform<int>(int location, int x, int y, int z, int w) { fn.Uniform4i(location, x, y, z, w); }
template <> inline void Uniform<1, int>(int location, int count, int const *v) { fn.Uniform1iv(location, count, v); }
template <> inline void Uniform<2, int>(int location, int count, int const *v) { fn.Uniform2iv(location, count, v); }
template <> inline void Uniform<3, int>(int location, int count, int const *v) { fn.Uniform3iv(location, count, v); }
template <> inline void Uniform<4, int>(int location, int count, int const *v) { fn.Uniform4iv(location, count, v); }

template <int N, typename T> void UniformMatrix(int location, int count, T const *v);

template <> inline void UniformMatrix<2, float>(int location, int count, float const *v) { fn.UniformMatrix2fv(location, count, false, v); }
template <> inline void UniformMatrix<3, float>(int location, int count, float const *v) { fn.UniformMatrix3fv(location, count, false, v); }
template <> inline void UniformMatrix<4, float>(int location, int count, float const *v) { fn.UniformMatrix4fv(location, count, false, v); }

inline void UseProgram(ProgramId program = ProgramId())
{
	fn.UseProgram((unsigned)program);
}

inline void ValidateProgram(ProgramId program)
{
	fn.ValidateProgram((unsigned)program);
}

template <typename T> void VertexAttrib(unsigned index, T x);
template <typename T> void VertexAttrib(unsigned index, T x, T y);
template <typename T> void VertexAttrib(unsigned index, T x, T y, T z);
template <typename T> void VertexAttrib(unsigned index, T x, T y, T z, T w);
template <int N, typename T> void VertexAttrib(unsigned index, T const *v);
template <typename T> void VertexAttribN(unsigned index, T x, T y, T z, T w);
template <int N, typename T> void VertexAttribN(unsigned index, T const *v);

template <> inline void VertexAttrib<double>(unsigned index, double x) { fn.VertexAttrib1d(index, x); }
template <> inline void VertexAttrib<double>(unsigned index, double x, double y) { fn.VertexAttrib2d(index, x, y); }
template <> inline void VertexAttrib<double>(unsigned index, double x, double y, double z) { fn.VertexAttrib3d(index, x, y, z); }
template <> inline void VertexAttrib<double>(unsigned index, double x, double y, double z, double w) { fn.VertexAttrib4d(index, x, y, z, w); }
template <> inline void VertexAttrib<1, double>(unsigned index, double const *v) { fn.VertexAttrib1dv(index, v); }
template <> inline void VertexAttrib<2, double>(unsigned index, double const *v) { fn.VertexAttrib2dv(index, v); }
template <> inline void VertexAttrib<3, double>(unsigned index, double const *v) { fn.VertexAttrib3dv(index, v); }
template <> inline void VertexAttrib<4, double>(unsigned index, double const *v) { fn.VertexAttrib4dv(index, v); }

template <> inline void VertexAttrib<float>(unsigned index, float x) { fn.VertexAttrib1f(index, x); }
template <> inline void VertexAttrib<float>(unsigned index, float x, float y) { fn.VertexAttrib2f(index, x, y); }
template <> inline void VertexAttrib<float>(unsigned index, float x, float y, float z) { fn.VertexAttrib3f(index, x, y, z); }
template <> inline void VertexAttrib<float>(unsigned index, float x, float y, float z, float w) { fn.VertexAttrib4f(index, x, y, z, w); }
template <> inline void VertexAttrib<1, float>(unsigned index, float const *v) { fn.VertexAttrib1fv(index, v); }
template <> inline void VertexAttrib<2, float>(unsigned index, float const *v) { fn.VertexAttrib2fv(index, v); }
template <> inline void VertexAttrib<3, float>(unsigned index, float const *v) { fn.VertexAttrib3fv(index, v); }
template <> inline void VertexAttrib<4, float>(unsigned index, float const *v) { fn.VertexAttrib4fv(index, v); }

template <> inline void VertexAttrib<short>(unsigned index, short x) { fn.VertexAttrib1s(index, x); }
template <> inline void VertexAttrib<short>(unsigned index, short x, short y) { fn.VertexAttrib2s(index, x, y); }
template <> inline void VertexAttrib<short>(unsigned index, short x, short y, short z) { fn.VertexAttrib3s(index, x, y, z); }
template <> inline void VertexAttrib<short>(unsigned index, short x, short y, short z, short w) { fn.VertexAttrib4s(index, x, y, z, w); }
template <> inline void VertexAttrib<1, short>(unsigned index, short const *v) { fn.VertexAttrib1sv(index, v); }
template <> inline void VertexAttrib<2, short>(unsigned index, short const *v) { fn.VertexAttrib2sv(index, v); }
template <> inline void VertexAttrib<3, short>(unsigned index, short const *v) { fn.VertexAttrib3sv(index, v); }
template <> inline void VertexAttrib<4, short>(unsigned index, short const *v) { fn.VertexAttrib4sv(index, v); }

template <> inline void VertexAttrib<4, sbyte>(unsigned index, sbyte const *v) { fn.VertexAttrib4bv(index, v); }
template <> inline void VertexAttrib<4, int>(unsigned index, int const *v) { fn.VertexAttrib4iv(index, v); }
template <> inline void VertexAttrib<4, ubyte>(unsigned index, ubyte const *v) { fn.VertexAttrib4ubv(index, v); }
template <> inline void VertexAttrib<4, unsigned short>(unsigned index, unsigned short const *v) { fn.VertexAttrib4usv(index, v); }
template <> inline void VertexAttrib<4, unsigned>(unsigned index, const unsigned *v) { fn.VertexAttrib4uiv(index, v); }

template <> inline void VertexAttribN<ubyte>(unsigned index, ubyte x, ubyte y, ubyte z, ubyte w) {	fn.VertexAttrib4Nub(index, x, y, z, w); }

template <> inline void VertexAttribN<4, sbyte>(unsigned index, sbyte const *v) { fn.VertexAttrib4Nbv(index, v); }
template <> inline void VertexAttribN<4, short>(unsigned index, short const *v) { fn.VertexAttrib4Nsv(index, v); }
template <> inline void VertexAttribN<4, int>(unsigned index, int const *v) { fn.VertexAttrib4Niv(index, v); }

template <> inline void VertexAttribN<4, ubyte>(unsigned index, ubyte const *v) { fn.VertexAttrib4Nubv(index, v); }
template <> inline void VertexAttribN<4, unsigned short>(unsigned index, unsigned short const *v) { fn.VertexAttrib4Nusv(index, v); }
template <> inline void VertexAttribN<4, unsigned>(unsigned index, unsigned const *v) { fn.VertexAttrib4Nuiv(index, v); }

inline void VertexAttribPointer(unsigned index, int size, Type type, bool normalized, int stride, void const *pointer)
{
	fn.VertexAttribPointer(index, size, (GLenum)type, normalized, stride, pointer);
}

inline int GetProgram(ProgramId program, ProgramInfo what)
{
	int result;
	GetProgram(program, what, &result);
	return result;
}

inline int GetShader(ShaderId shader, ShaderInfo what)
{
	int result;
	GetShader(shader, what, &result);
	return result;
}

inline void ShaderSource(ShaderId shader, char const *code)
{
	ShaderSource(shader, 1, &code);
}

inline void ShaderSource(ShaderId shader, char const *code, int length)
{
	ShaderSource(shader, 1, &code, &length);
}

template <int N, typename T>
void Uniform(int location, T const *v)
{
	Uniform<N, T>(location, 1, v);
}

template <typename T>
void VertexAttribPointer(unsigned index, int size, bool normalized, std::size_t stride, T const *pointer)
{
	VertexAttribPointer(index, size, TypeId<T>::value, normalized, stride, pointer);
}

template <typename T, typename U>
void VertexAttribPointer(unsigned index, int size, bool normalized, T const *pointer, U T::*member)
{
	VertexAttribPointer(index, size, normalized, sizeof(T), &(pointer->*member));
}

#ifndef GLXX_NO_STL
inline std::string GetProgramInfoLog(ProgramId program)
{
	int length = GetProgram(program, ProgramInfo::InfoLogLength);
	std::vector<char> buffer(length);
	GetProgramInfoLog(program, length, &length, buffer.data());
	return std::string(buffer.data(), length);
}

inline std::string GetShaderInfoLog(ShaderId shader)
{
	int length = GetShader(shader, ShaderInfo::InfoLogLength);
	std::vector<char> buffer(length);
	GetShaderInfoLog(shader, length, &length, buffer.data());
	return std::string(buffer.data(), length);
}

inline void BindAttribLocation(ProgramId program, unsigned index, std::string const &name)
{
	BindAttribLocation(program, index, name.c_str());
}

inline void ShaderSource(ShaderId shader, std::string const &code)
{
	ShaderSource(shader, code.data(), code.size());
}

inline int GetUniformLocation(ProgramId program, std::string const &name)
{
	int location = GetUniformLocation(program, name.c_str());
	if (location == -1)
		throw std::runtime_error("Uniform does not exist");
	return location;
}
#endif
}
}
