#include "VertexBufferLayout.h"
#include <cassert>

VertexBufferElement::VertexBufferElement(unsigned int t, unsigned int c, bool n)
    : type(t), count(c), normalized(n)
{
}

unsigned int VertexBufferElement::GetSizeOfType(unsigned int type)
{
    switch (type)
    {
    case GL_FLOAT:
        return sizeof(GLfloat);
    case GL_UNSIGNED_INT:
        return sizeof(GLuint);
    case GL_UNSIGNED_BYTE:
        return sizeof(GLubyte);
    }
    assert(false);
    return 0;
}

VertexBufferLayout::VertexBufferLayout()
    : m_stride(0)
{
}
