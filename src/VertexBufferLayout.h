#pragma once

#include <vector>
#include <GL/glew.h>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    bool normalized;

    VertexBufferElement(unsigned int t, unsigned int c, bool n);

    static unsigned int GetSizeOfType(unsigned int type);
};

class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_stride;

public:
    VertexBufferLayout();

    template <typename T>
    void Push(unsigned int count)
    {
        static_assert(std::false_type::value, "Unsupported type");
    }

    inline const std::vector<VertexBufferElement> &GetElements() const { return m_Elements; }
    inline unsigned int GetStride() const { return m_stride; }
};

template <>
inline void VertexBufferLayout::Push<float>(unsigned int count)
{
    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}

template <>
inline void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    m_stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template <>
inline void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    m_stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}