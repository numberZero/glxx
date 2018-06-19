#pragma once
#ifndef GLXX
#error Never include this file directly; use gl++.hxx instead
#endif

namespace gl {
inline namespace hxx {

class ProgramRef
{
	ProgramId id = ProgramId();

public:
	ProgramRef() = default;
	ProgramRef(ProgramRef const &) = delete;
	ProgramRef(ProgramRef &&b);
	explicit ProgramRef(ProgramId _id);
	~ProgramRef();

	ProgramRef &operator=(ProgramRef const &) = delete;
	ProgramRef &operator=(ProgramRef &&b);
	ProgramId operator*() const;
	bool operator!() const;
	operator bool() const;

	ProgramId get() const;
	void reset(ProgramId _id = ProgramId());
};

inline ProgramRef::ProgramRef(ProgramRef &&b) :
	id(b.id)
{
	b.reset();
}

inline ProgramRef::ProgramRef(ProgramId _id) :
	id(_id)
{
}

inline ProgramRef::~ProgramRef()
{
	reset();
}

inline ProgramRef &ProgramRef::operator=(ProgramRef &&b)
{
	std::swap(id, b.id);
	return *this;
}

inline ProgramId ProgramRef::operator*() const
{
	return id;
}

inline bool ProgramRef::operator!() const
{
	return !id;
}

inline ProgramRef::operator bool() const
{
	return !!id;
}

#ifdef GLXX_IMPLICIT_DEREF
inline ProgramRef::operator ProgramId() const
{
	return id;
}
#endif

inline ProgramId ProgramRef::get() const
{
	return id;
}

inline void ProgramRef::reset(ProgramId _id)
{
	if (id)
		DeleteProgram(id);
	id = _id;
}

}
}
