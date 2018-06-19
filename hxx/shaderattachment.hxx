#pragma once
#ifndef GLXX
#error Never include this file directly; use gl++.hxx instead
#endif
#include "shader.hxx"
#include "program.hxx"

namespace gl {
inline namespace hxx {

class ShaderAttachment
{
	ProgramId program;
	ShaderId shader;

public:
	ShaderAttachment(ProgramId _program, ShaderId _shader);
	ShaderAttachment(ProgramRef &_program, ShaderRef &_shader);
	~ShaderAttachment();
};


inline ShaderAttachment::ShaderAttachment(ProgramId _program, ShaderId _shader) :
	program(_program), shader(_shader)
{
	AttachShader(program, shader);
}

inline ShaderAttachment::ShaderAttachment(ProgramRef &_program, ShaderRef &_shader) :
	ShaderAttachment(*_program, *_shader)
{
}

inline ShaderAttachment::~ShaderAttachment()
{
	DetachShader(program, shader);
}

}
}
