#pragma once

#include <GL/glew.h>

#ifdef _MSC_VER
#define DEBUG_BREAK() __debugbreak()
#else
#include <signal.h>
#define DEBUG_BREAK() raise(SIGTRAP)
#endif

#define ASSERT(x) \
	if (!(x))     \
		DEBUG_BREAK();

#ifdef _DEBUG
#define GLCall(x)   \
	GLClearError(); \
	x;              \
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#else
#define GLCall(x) x
#endif

void GLClearError();

bool GLLogCall(const char *func, const char *file, int line);
