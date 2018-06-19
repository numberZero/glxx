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
	glAttachShader((GLuint)program, (GLuint)shader);
}

inline void BindAttribLocation(ProgramId program, GLuint index, char const *name)
{
	glBindAttribLocation((GLuint)program, index, name);
}

/*
inline void BlendEquationSeparate()
{
	return glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha;
}
*/
inline void CompileShader(ShaderId shader)
{
	glCompileShader((GLuint)shader);
}

inline ProgramId CreateProgram()
{
	return ProgramId(glCreateProgram());
}

inline ShaderId CreateShader(ShaderType type)
{
	return ShaderId(glCreateShader((GLenum)type));
}

inline void DeleteProgram(ProgramId program)
{
	return glDeleteProgram((GLuint)program);
}

inline void DeleteShader(ShaderId shader)
{
	return glDeleteShader((GLuint)shader);
}

inline void DetachShader(ProgramId program, ShaderId shader)
{
	glDetachShader((GLuint)program, (GLuint)shader);
}
/*
inline void DisableVertexAttribArray()
{
	return glDisableVertexAttribArray();
}

inline void DrawBuffers()
{
	return glDrawBuffers();
}

inline void EnableVertexAttribArray()
{
	return glEnableVertexAttribArray();
}

inline void GetActiveAttrib()
{
	return glGetActiveAttrib();
}

inline void GetActiveUniform()
{
	return glGetActiveUniform();
}

inline void GetAttachedShaders()
{
	return glGetAttachedShaders();
}

inline void GetAttribLocation()
{
	return glGetAttribLocation();
}
*/
inline void GetProgramInfoLog(ProgramId program, GLsizei bufSize, GLsizei *length, char *buffer)
{
	glGetProgramInfoLog((GLuint)program, bufSize, length, buffer);
}

inline void GetProgram(ProgramId program, ProgramInfo what, GLint *result)
{
	glGetProgramiv((GLuint)program, (GLenum)what, result);
}

inline void GetShaderInfoLog(ShaderId shader, GLsizei bufSize, GLsizei *length, char *buffer)
{
	glGetShaderInfoLog((GLuint)shader, bufSize, length, buffer);
}

inline void GetShaderSource(ShaderId shader, GLsizei bufSize, GLsizei *length, char *buffer)
{
	glGetShaderSource((GLuint)shader, bufSize, length, buffer);
}

inline void GetShader(ShaderId shader, ShaderInfo what, GLint *result)
{
	glGetShaderiv((GLuint)shader, (GLenum)what, result);
}

inline GLint GetUniformLocation(ProgramId program, char const *name)
{
	return glGetUniformLocation((GLuint)program, name);
}
/*
inline void GetUniformfv()
{
	return glGetUniformfv();
}

inline void GetUniformiv()
{
	return glGetUniformiv();
}

inline void GetVertexAttribPointerv()
{
	return glGetVertexAttribPointerv();
}

inline void GetVertexAttribdv()
{
	return glGetVertexAttribdv();
}

inline void GetVertexAttribfv()
{
	return glGetVertexAttribfv();
}

inline void GetVertexAttribiv()
{
	return glGetVertexAttribiv();
}
*/
inline bool IsProgram(ProgramId id)
{
	return glIsProgram((GLuint)id);
}

inline bool IsShader(ShaderId id)
{
	return glIsShader((GLuint)id);
}

inline void LinkProgram(ProgramId id)
{
	glLinkProgram((GLuint)id);
}

inline void ShaderSource(ShaderId shader, GLint count, char const *const *code, GLint *length = nullptr)
{
	glShaderSource((GLuint)shader, count, code, length);
}

/*
inline void StencilFuncSeparate()
{
	return glStencilFuncSeparate();
}

inline void StencilMaskSeparate()
{
	return glStencilMaskSeparate();
}

inline void StencilOpSeparate()
{
	return glStencilOpSeparate();
}
*/
template <typename T> void Uniform(GLint location, T x);
template <typename T> void Uniform(GLint location, T x, T y);
template <typename T> void Uniform(GLint location, T x, T y, T z);
template <typename T> void Uniform(GLint location, T x, T y, T z, T w);
template <GLint N, typename T> void Uniform(GLint location, GLint count, T const *v);

template <> inline void Uniform<GLfloat>(GLint location, GLfloat x) { glUniform1f(location, x); }
template <> inline void Uniform<GLfloat>(GLint location, GLfloat x, GLfloat y) { glUniform2f(location, x, y); }
template <> inline void Uniform<GLfloat>(GLint location, GLfloat x, GLfloat y, GLfloat z) { glUniform3f(location, x, y, z); }
template <> inline void Uniform<GLfloat>(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { glUniform4f(location, x, y, z, w); }
template <> inline void Uniform<1, GLfloat>(GLint location, GLint count, GLfloat const *v) { glUniform1fv(location, count, v); }
template <> inline void Uniform<2, GLfloat>(GLint location, GLint count, GLfloat const *v) { glUniform2fv(location, count, v); }
template <> inline void Uniform<3, GLfloat>(GLint location, GLint count, GLfloat const *v) { glUniform3fv(location, count, v); }
template <> inline void Uniform<4, GLfloat>(GLint location, GLint count, GLfloat const *v) { glUniform4fv(location, count, v); }

template <> inline void Uniform<GLint>(GLint location, GLint x) { glUniform1i(location, x); }
template <> inline void Uniform<GLint>(GLint location, GLint x, GLint y) { glUniform2i(location, x, y); }
template <> inline void Uniform<GLint>(GLint location, GLint x, GLint y, GLint z) { glUniform3i(location, x, y, z); }
template <> inline void Uniform<GLint>(GLint location, GLint x, GLint y, GLint z, GLint w) { glUniform4i(location, x, y, z, w); }
template <> inline void Uniform<1, GLint>(GLint location, GLint count, GLint const *v) { glUniform1iv(location, count, v); }
template <> inline void Uniform<2, GLint>(GLint location, GLint count, GLint const *v) { glUniform2iv(location, count, v); }
template <> inline void Uniform<3, GLint>(GLint location, GLint count, GLint const *v) { glUniform3iv(location, count, v); }
template <> inline void Uniform<4, GLint>(GLint location, GLint count, GLint const *v) { glUniform4iv(location, count, v); }

template <GLint N, typename T> void UniformMatrix(GLint location, GLint count, T const *v);

template <> inline void UniformMatrix<2, GLfloat>(GLint location, GLint count, GLfloat const *v) { glUniformMatrix2fv(location, count, false, v); }
template <> inline void UniformMatrix<3, GLfloat>(GLint location, GLint count, GLfloat const *v) { glUniformMatrix3fv(location, count, false, v); }
template <> inline void UniformMatrix<4, GLfloat>(GLint location, GLint count, GLfloat const *v) { glUniformMatrix4fv(location, count, false, v); }

inline void UseProgram(ProgramId program = ProgramId())
{
	glUseProgram((GLuint)program);
}

inline void ValidateProgram(ProgramId program)
{
	glValidateProgram((GLuint)program);
}

template <typename T> void VertexAttrib(GLuint index, T x);
template <typename T> void VertexAttrib(GLuint index, T x, T y);
template <typename T> void VertexAttrib(GLuint index, T x, T y, T z);
template <typename T> void VertexAttrib(GLuint index, T x, T y, T z, T w);
template <GLint N, typename T> void VertexAttrib(GLuint index, T const *v);
template <typename T> void VertexAttribN(GLuint index, T x, T y, T z, T w);
template <GLint N, typename T> void VertexAttribN(GLuint index, T const *v);

template <> inline void VertexAttrib<GLdouble>(GLuint index, GLdouble x) { glVertexAttrib1d(index, x); }
template <> inline void VertexAttrib<GLdouble>(GLuint index, GLdouble x, GLdouble y) { glVertexAttrib2d(index, x, y); }
template <> inline void VertexAttrib<GLdouble>(GLuint index, GLdouble x, GLdouble y, GLdouble z) { glVertexAttrib3d(index, x, y, z); }
template <> inline void VertexAttrib<GLdouble>(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glVertexAttrib4d(index, x, y, z, w); }
template <> inline void VertexAttrib<1, GLdouble>(GLuint index, GLdouble const *v) { glVertexAttrib1dv(index, v); }
template <> inline void VertexAttrib<2, GLdouble>(GLuint index, GLdouble const *v) { glVertexAttrib2dv(index, v); }
template <> inline void VertexAttrib<3, GLdouble>(GLuint index, GLdouble const *v) { glVertexAttrib3dv(index, v); }
template <> inline void VertexAttrib<4, GLdouble>(GLuint index, GLdouble const *v) { glVertexAttrib4dv(index, v); }

template <> inline void VertexAttrib<GLfloat>(GLuint index, GLfloat x) { glVertexAttrib1f(index, x); }
template <> inline void VertexAttrib<GLfloat>(GLuint index, GLfloat x, GLfloat y) { glVertexAttrib2f(index, x, y); }
template <> inline void VertexAttrib<GLfloat>(GLuint index, GLfloat x, GLfloat y, GLfloat z) { glVertexAttrib3f(index, x, y, z); }
template <> inline void VertexAttrib<GLfloat>(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { glVertexAttrib4f(index, x, y, z, w); }
template <> inline void VertexAttrib<1, GLfloat>(GLuint index, GLfloat const *v) { glVertexAttrib1fv(index, v); }
template <> inline void VertexAttrib<2, GLfloat>(GLuint index, GLfloat const *v) { glVertexAttrib2fv(index, v); }
template <> inline void VertexAttrib<3, GLfloat>(GLuint index, GLfloat const *v) { glVertexAttrib3fv(index, v); }
template <> inline void VertexAttrib<4, GLfloat>(GLuint index, GLfloat const *v) { glVertexAttrib4fv(index, v); }

template <> inline void VertexAttrib<GLshort>(GLuint index, GLshort x) { glVertexAttrib1s(index, x); }
template <> inline void VertexAttrib<GLshort>(GLuint index, GLshort x, GLshort y) { glVertexAttrib2s(index, x, y); }
template <> inline void VertexAttrib<GLshort>(GLuint index, GLshort x, GLshort y, GLshort z) { glVertexAttrib3s(index, x, y, z); }
template <> inline void VertexAttrib<GLshort>(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) { glVertexAttrib4s(index, x, y, z, w); }
template <> inline void VertexAttrib<1, GLshort>(GLuint index, GLshort const *v) { glVertexAttrib1sv(index, v); }
template <> inline void VertexAttrib<2, GLshort>(GLuint index, GLshort const *v) { glVertexAttrib2sv(index, v); }
template <> inline void VertexAttrib<3, GLshort>(GLuint index, GLshort const *v) { glVertexAttrib3sv(index, v); }
template <> inline void VertexAttrib<4, GLshort>(GLuint index, GLshort const *v) { glVertexAttrib4sv(index, v); }

template <> inline void VertexAttrib<4, GLbyte>(GLuint index, GLbyte const *v) { glVertexAttrib4bv(index, v); }
template <> inline void VertexAttrib<4, GLint>(GLuint index, GLint const *v) { glVertexAttrib4iv(index, v); }
template <> inline void VertexAttrib<4, GLubyte>(GLuint index, GLubyte const *v) { glVertexAttrib4ubv(index, v); }
template <> inline void VertexAttrib<4, GLushort>(GLuint index, GLushort const *v) { glVertexAttrib4usv(index, v); }
template <> inline void VertexAttrib<4, GLuint>(GLuint index, const GLuint *v) { glVertexAttrib4uiv(index, v); }

template <> inline void VertexAttribN<GLubyte>(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {	glVertexAttrib4Nub(index, x, y, z, w); }

template <> inline void VertexAttribN<4, GLbyte>(GLuint index, GLbyte const *v) { glVertexAttrib4Nbv(index, v); }
template <> inline void VertexAttribN<4, GLshort>(GLuint index, GLshort const *v) { glVertexAttrib4Nsv(index, v); }
template <> inline void VertexAttribN<4, GLint>(GLuint index, GLint const *v) { glVertexAttrib4Niv(index, v); }

template <> inline void VertexAttribN<4, GLubyte>(GLuint index, GLubyte const *v) { glVertexAttrib4Nubv(index, v); }
template <> inline void VertexAttribN<4, GLushort>(GLuint index, GLushort const *v) { glVertexAttrib4Nusv(index, v); }
template <> inline void VertexAttribN<4, GLuint>(GLuint index, GLuint const *v) { glVertexAttrib4Nuiv(index, v); }

inline void VertexAttribPointer(GLuint index, GLint size, Type type, bool normalized, GLsizei stride, void const *pointer)
{
	glVertexAttribPointer(index, size, (GLenum)type, normalized, stride, pointer);
}

inline GLint GetProgram(ProgramId program, ProgramInfo what)
{
	GLint result;
	GetProgram(program, what, &result);
	return result;
}

inline GLint GetShader(ShaderId shader, ShaderInfo what)
{
	GLint result;
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
	GLint length = GetProgram(program, ProgramInfo::InfoLogLength);
	std::vector<char> buffer(length);
	GetProgramInfoLog(program, length, &length, buffer.data());
	return std::string(buffer.data(), length);
}

inline std::string GetShaderInfoLog(ShaderId shader)
{
	GLint length = GetShader(shader, ShaderInfo::InfoLogLength);
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
	GLint location = GetUniformLocation(program, name.c_str());
	if (location == -1)
		throw std::runtime_error("Uniform does not exist");
	return location;
}
#endif
}
}
