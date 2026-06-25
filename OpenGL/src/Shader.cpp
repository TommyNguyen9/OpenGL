#include "Shader.h"

Shader::Shader(const std::string& filepath)
	: m_FilePath(filepath), m_RendererID(0)
{
	CompileShader();
}

Shader::~Shader()
{

}

bool Shader::CompileShader()
{

}

void Shader::Bind() const
{

}

void Shader::Unbind() const
{

}