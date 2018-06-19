#pragma once
#ifndef GLXX
#error Never include this file directly; use gl++.hxx instead
#endif

namespace gl {
inline namespace hxx {

class ShaderRef
{
	ShaderId id = ShaderId();

public:
	ShaderRef() = default;
	ShaderRef(ShaderRef const &) = delete;
	ShaderRef(ShaderRef &&b);
	explicit ShaderRef(ShaderId _id);
	~ShaderRef();

	ShaderRef &operator=(ShaderRef const &) = delete;
	ShaderRef &operator=(ShaderRef &&b);
	ShaderId operator*() const;
	bool operator!() const;
	operator bool() const;
#ifdef GLXX_IMPLICIT_DEREF
	operator ShaderId() const;
#endif

	ShaderId get() const;
	void reset(ShaderId _id = ShaderId());
};

inline ShaderRef::ShaderRef(ShaderRef &&b) :
	id(b.id)
{
	b.reset();
}

inline ShaderRef::ShaderRef(ShaderId _id) :
	id(_id)
{
}

inline ShaderRef::~ShaderRef()
{
	reset();
}

inline ShaderRef &ShaderRef::operator=(ShaderRef &&b)
{
	std::swap(id, b.id);
	return *this;
}

inline ShaderId ShaderRef::operator*() const
{
	return id;
}

inline bool ShaderRef::operator!() const
{
	return !id;
}

inline ShaderRef::operator bool() const
{
	return !!id;
}

#ifdef GLXX_IMPLICIT_DEREF
inline ShaderRef::operator ShaderId() const
{
	return id;
}
#endif

inline ShaderId ShaderRef::get() const
{
	return id;
}

inline void ShaderRef::reset(ShaderId _id)
{
	if (id)
		DeleteShader(id);
	id = _id;
}

}
}
