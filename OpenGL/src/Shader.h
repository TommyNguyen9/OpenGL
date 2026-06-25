#pragma once

#include <string>

class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	// Cache for uniforms
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	// Set uniforms:
	void SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3);
private:
	bool CompileShader();
	unsigned int GetUniformLocation(const std::string& name);
};