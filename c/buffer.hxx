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
	fn.BeginQuery((GLenum)target, (unsigned)id);
}

void BindBuffer(BufferTarget target, BufferId buffer = gl::BufferId())
{
	fn.BindBuffer((GLenum)target, (unsigned)buffer);
}

void BufferData(BufferTarget target, std::ptrdiff_t size, void const *data, BufferUsage usage)
{
	fn.BufferData((GLenum)target, size, data, (GLenum)usage);
}

void BufferSubData(BufferTarget target, std::intptr_t offset, std::ptrdiff_t size, void const *data)
{
	fn.BufferSubData((GLenum)target, offset, size, data);
}

void DeleteBuffers(int n, BufferId const *buffers)
{
	fn.DeleteBuffers(n, (unsigned const *)buffers);
}

void DeleteQueries(int n, QueryId const *ids)
{
	fn.DeleteQueries(n, (unsigned const *)ids);
}

void EndQuery(QueryTarget target)
{
	fn.EndQuery((GLenum)target);
}

void GenBuffers(int n, BufferId *buffers)
{
	fn.GenBuffers((int)n, (unsigned *)buffers);
}

void GenQueries(int n, QueryId *ids)
{
	fn.GenQueries((int)n, (unsigned *)ids);
}

template <typename T> void GetBufferParameter(BufferTarget target, BufferParameter pname, T *params);

template <> void GetBufferParameter<int>(BufferTarget target, BufferParameter pname, int *params) { fn.GetBufferParameteriv((GLenum)target, (GLenum)pname, params); }

void GetBufferPointer(BufferTarget target, BufferPointer pname, void **params)
{
	fn.GetBufferPointerv((GLenum)target, (GLenum)pname, params);
}

void GetBufferSubData(BufferTarget target, std::intptr_t offset, std::ptrdiff_t size, void *data)
{
	fn.GetBufferSubData((GLenum)target, offset, size, data);
}
/*
void GetQueryObjectiv(QueryId id, GLenum pname, int *params)
{
	fn.GetQueryObjectiv((unsigned)id, (GLenum)pname, params);
}

void GetQueryObjectuiv(QueryId id, GLenum pname, unsigned *params)
{
	fn.GetQueryObjectuiv((unsigned)id, (GLenum)pname, params);
}

void GetQueryiv(QueryTarget target, GLenum pname, int *params)
{
	fn.GetQueryiv((GLenum)target, (GLenum)pname, params);
}
*/
[[nodiscard]] GLboolean IsBuffer(BufferId buffer)
{
	return fn.IsBuffer((unsigned)buffer);
}

[[nodiscard]] GLboolean IsQuery(QueryId id)
{
	return fn.IsQuery((unsigned)id);
}

[[nodiscard]] void *MapBuffer(BufferTarget target, GLenum access)
{
	return fn.MapBuffer((GLenum)target, (GLenum)access);
}

void UnmapBuffer(BufferTarget target)
{
	fn.UnmapBuffer((GLenum)target);
}

BufferId GenBuffer()
{
	BufferId buffer;
	GenBuffers(1, &buffer);
	return buffer;
}

}
}
