#pragma once

namespace gl {
inline namespace c {

struct BufferId : Id { using Id::Id; };

enum class BufferTarget : GLenum
{
	Array = GL_ARRAY_BUFFER,
	AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
	CopyRead = GL_COPY_READ_BUFFER,
	CopyWrite = GL_COPY_WRITE_BUFFER,
	DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
	DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
	ElementArray = GL_ELEMENT_ARRAY_BUFFER,
	PixelPack = GL_PIXEL_PACK_BUFFER,
	PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
	Query = GL_QUERY_BUFFER,
	ShaderStorage = GL_SHADER_STORAGE_BUFFER,
	Texture = GL_TEXTURE_BUFFER,
	TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
	Uniform = GL_UNIFORM_BUFFER,
};

enum class BufferUsage : GLenum
{
	StreamDraw = GL_STREAM_DRAW,
	StreamRead = GL_STREAM_READ,
	StreamCopy = GL_STREAM_COPY,
	StaticDraw = GL_STATIC_DRAW,
	StaticRead = GL_STATIC_READ,
	StaticCopy = GL_STATIC_COPY,
	DynamicDraw = GL_DYNAMIC_DRAW,
	DynamicRead = GL_DYNAMIC_READ,
	DynamicCopy = GL_DYNAMIC_COPY,
};

enum class BufferParameter : GLenum
{
	Access = GL_BUFFER_ACCESS,
	Mapped = GL_BUFFER_MAPPED,
	Size = GL_BUFFER_SIZE,
	Usage = GL_BUFFER_USAGE,
};

enum class BufferPointer : GLenum
{
	MapPointer = GL_BUFFER_MAP_POINTER,
};

struct QueryId : Id { using Id::Id; };

enum class QueryTarget : GLenum
{
	SamplesPassed = GL_SAMPLES_PASSED,
	AnySamplesPassed = GL_ANY_SAMPLES_PASSED,
	AnySamplesPassedConservative = GL_ANY_SAMPLES_PASSED_CONSERVATIVE,
	PrimitivesGenerated = GL_PRIMITIVES_GENERATED,
	TransformFeedbackPrimitivesWritten = GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN,
	TimeElapsed = GL_TIME_ELAPSED,
};

void BeginQuery(QueryTarget target, QueryId id)
{
	glBeginQuery((GLenum)target, (GLuint)id);
}

void BindBuffer(BufferTarget target, BufferId buffer = gl::BufferId())
{
	glBindBuffer((GLenum)target, (GLuint)buffer);
}

void BufferData(BufferTarget target, GLsizeiptr size, void const *data, BufferUsage usage)
{
	glBufferData((GLenum)target, size, data, (GLenum)usage);
}

void BufferSubData(BufferTarget target, GLintptr offset, GLsizeiptr size, void const *data)
{
	glBufferSubData((GLenum)target, offset, size, data);
}

void DeleteBuffers(GLsizei n, BufferId const *buffers)
{
	glDeleteBuffers((GLsizei)n, (GLuint const *)buffers);
}

void DeleteQueries(GLsizei n, QueryId const *ids)
{
	glDeleteQueries((GLsizei)n, (GLuint const *)ids);
}

void EndQuery(QueryTarget target)
{
	glEndQuery((GLenum)target);
}

void GenBuffers(GLsizei n, BufferId *buffers)
{
	glGenBuffers((GLsizei)n, (GLuint *)buffers);
}

void GenQueries(GLsizei n, QueryId *ids)
{
	glGenQueries((GLsizei)n, (GLuint *)ids);
}

template <typename T> void GetBufferParameter(BufferTarget target, BufferParameter pname, T *params);

template <> void GetBufferParameter<GLint>(BufferTarget target, BufferParameter pname, GLint *params) { glGetBufferParameteriv((GLenum)target, (GLenum)pname, params); }

void GetBufferPointer(BufferTarget target, BufferPointer pname, void **params)
{
	glGetBufferPointerv((GLenum)target, (GLenum)pname, params);
}

void GetBufferSubData(BufferTarget target, GLintptr offset, GLsizeiptr size, void *data)
{
	glGetBufferSubData((GLenum)target, offset, size, data);
}
/*
void GetQueryObjectiv(QueryId id, GLenum pname, GLint *params)
{
	glGetQueryObjectiv((GLuint)id, (GLenum)pname, params);
}

void GetQueryObjectuiv(QueryId id, GLenum pname, GLuint *params)
{
	glGetQueryObjectuiv((GLuint)id, (GLenum)pname, params);
}

void GetQueryiv(QueryTarget target, GLenum pname, GLint *params)
{
	glGetQueryiv((GLenum)target, (GLenum)pname, params);
}
*/
[[nodiscard]] GLboolean IsBuffer(BufferId buffer)
{
	return glIsBuffer((GLuint)buffer);
}

[[nodiscard]] GLboolean IsQuery(QueryId id)
{
	return glIsQuery((GLuint)id);
}

[[nodiscard]] void *MapBuffer(BufferTarget target, GLenum access)
{
	return glMapBuffer((GLenum)target, (GLenum)access);
}

void UnmapBuffer(BufferTarget target)
{
	glUnmapBuffer((GLenum)target);
}

BufferId GenBuffer()
{
	BufferId buffer;
	GenBuffers(1, &buffer);
	return buffer;
}

}
}
