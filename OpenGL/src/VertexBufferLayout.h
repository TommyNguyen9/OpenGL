#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <GL/glew.h>

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout()
		: m_Stride(0) {}

	template<typename T>
	void Push(unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		m_Elements.push_back(VertexBufferElement{ GL_FLOAT, count, GL_FALSE });
		m_Stride += sizeof(GLfloat);
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		m_Elements.push_back(VertexBufferElement{ GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += sizeof(GLuint);
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		m_Elements.push_back(VertexBufferElement{ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride += sizeof(GLbyte);
	}

	inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
	inline unsigned int GetStride() const { return m_Stride; }
};