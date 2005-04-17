#if __ide_target("W32 All-in-1 DLL")

#pragma precompile_target "W32Allin1DLL.mch"

#pragma always_inline on

#define WIN32

#define VCF_ALLIN1
#define VCF_ALLIN1_DLL
#define VCF_ALLIN1_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 All-in-1 DLL (D)")

#pragma precompile_target "W32Allin1DLLDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define VCF_ALLIN1
#define VCF_ALLIN1_DLL
#define VCF_ALLIN1_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 All-in-1 LIB")

#pragma precompile_target "W32Allin1LIB.mch"

#pragma always_inline on

#define WIN32

#define VCF_ALLIN1

#endif

#if __ide_target("W32 All-in-1 LIB (D)")

#pragma precompile_target "W32Allin1LIBDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define VCF_ALLIN1

#endif

#ifdef VCF_ALLIN1

// All-in-1 kit exclusions here
//#define VCF_ALLIN1_NO_OPENGLKIT

#endif

#if __ide_target("W32 FoundationKit DLL")

#pragma precompile_target "W32FoundationDLL.mch"

#pragma always_inline on

#define WIN32

#define FOUNDATIONKIT
#define FOUNDATIONKIT_DLL
#define FOUNDATIONKIT_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 FoundationKit DLL (D)")

#pragma precompile_target "W32FoundationDLLDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define FOUNDATIONKIT
#define FOUNDATIONKIT_DLL
#define FOUNDATIONKIT_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 FoundationKit LIB")

#pragma precompile_target "W32FoundationLIB.mch"

#pragma always_inline on

#define WIN32

#define FOUNDATIONKIT

#endif

#if __ide_target("W32 FoundationKit LIB (D)")

#pragma precompile_target "W32FoundationLIBDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define FOUNDATIONKIT

#endif

#if __ide_target("W32 GraphicsKit DLL")

#pragma precompile_target "W32GraphicsDLL.mch"

#pragma always_inline on

#define WIN32

#define GRAPHICSKIT
#define GRAPHICSKIT_DLL
#define GRAPHICSKIT_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 GraphicsKit DLL (D)")

#pragma precompile_target "W32GraphicsDLLDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define GRAPHICSKIT
#define GRAPHICSKIT_DLL
#define GRAPHICSKIT_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 GraphicsKit LIB")

#pragma precompile_target "W32GraphicsLIB.mch"

#pragma always_inline on

#define WIN32

#define GRAPHICSKIT

#endif

#if __ide_target("W32 GraphicsKit LIB (D)")

#pragma precompile_target "W32GraphicsLIBDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define GRAPHICSKIT

#endif

#if __ide_target("W32 ApplicationKit DLL")

#pragma precompile_target "W32ApplicationDLL.mch"

#pragma always_inline on

#define WIN32

#define APPLICATIONKIT
#define APPLICATIONKIT_DLL
#define APPLICATIONKIT_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 ApplicationKit DLL (D)")

#pragma precompile_target "W32ApplicationDLLDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define APPLICATIONKIT
#define APPLICATIONKIT_DLL
#define APPLICATIONKIT_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 ApplicationKit LIB")

#pragma precompile_target "W32ApplicationLIB.mch"

#pragma always_inline on

#define WIN32

#define APPLICATIONKIT

#endif

#if __ide_target("W32 ApplicationKit LIB (D)")

#pragma precompile_target "W32ApplicationLIBDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define APPLICATIONKIT

#endif

#if __ide_target("W32 OpenGLKit DLL")

#pragma precompile_target "W32OpenGLDLL.mch"

#pragma always_inline on

#define WIN32

#define OPENGLKIT
#define OPENGLKIT_DLL
#define OPENGLKIT_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 OpenGLKit DLL (D)")

#pragma precompile_target "W32OpenGLDLLDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define OPENGLKIT
#define OPENGLKIT_DLL
#define OPENGLKIT_EXPORTS

#include "UseDLLPrefix.h"

#endif

#if __ide_target("W32 OpenGLKit LIB")

#pragma precompile_target "W32OpenGLLIB.mch"

#pragma always_inline on

#define WIN32

#define OPENGLKIT

#endif

#if __ide_target("W32 OpenGLKit LIB (D)")

#pragma precompile_target "W32OpenGLLIBDebug.mch"

#pragma always_inline on

#define WIN32
#define _DEBUG

#define OPENGLKIT

#endif

// UNICODE define may or may not be appropriate
//#define UNICODE