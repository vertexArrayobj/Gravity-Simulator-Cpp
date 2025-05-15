#pragma once

#include <GL/glew.h>

// Platform-independent debug break
#if defined(_MSC_VER)
#define DEBUG_BREAK() __debugbreak()
#elif defined(__GNUC__) || defined(__clang__)
#include <signal.h>
#ifndef SIGTRAP
#define SIGTRAP 5 // Define it manually if not defined
#endif
#define DEBUG_BREAK() raise(SIGTRAP)
#else
#define DEBUG_BREAK() ((void)0)
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
