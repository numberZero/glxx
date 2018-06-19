#pragma once
#ifndef GLXX
#error Never include this file directly; use gl++.hxx instead
#endif

namespace gl {
inline namespace hxx {

static struct Checked_Tag {} Checked;

void CompileShader(ShaderId shader, Checked_Tag)
{
	c::CompileShader(shader);
	if (!GetShader(shader, ShaderInfo::CompileStatus))
		throw std::runtime_error(std::string("Can't compile shader:\n") + GetShaderInfoLog(shader));
}

void CompileShader(ShaderRef const &shader, Checked_Tag = Checked)
{
	CompileShader(*shader, Checked);
}

void LinkProgram(ProgramId program, Checked_Tag)
{
	c::LinkProgram(program);
	if (!GetProgram(program, ProgramInfo::LinkStatus))
		throw std::runtime_error(std::string("Can't link program:\n") + GetProgramInfoLog(program));
}

void LinkProgram(ProgramRef const &program, Checked_Tag = Checked)
{
	LinkProgram(*program, Checked);
}

}
}
