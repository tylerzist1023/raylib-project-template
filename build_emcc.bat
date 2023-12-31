@echo off
setlocal

set CompileFlags=-I../../include -DPLATFORM_WEB -DCOMPILER_EMCC -s USE_GLFW=3
set LinkFlags=-L../../lib ../../lib/libraylib.a --shell-file=../../include/shell.html

set DebugCompileFlags=-g -O0 -DDEBUG
set DebugLinkFlags=

set ReleaseCompileFlags=-O3
set ReleaseLinkFlags=

set Compiler=emcc
set CompilerName=emscripten

set ExeCommand=-o
set BinaryExtension=html

call build_win32.bat %1