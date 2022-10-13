%module MyLibraryInterop

%include <std_string.i>
%include <typemaps.i>
%include <arrays_csharp.i>
%include <windows.i>

%apply const std::string& {std::string &};

%{
  #include "mylibrary_export.h"
  #include "mylib.h"
%}

// Typemaps

// Pinning
%apply float FIXED[] { const float* pVertices }
%csmethodmodifiers InitializeVertices "public unsafe";
%apply int FIXED[] { const int* pIndices }
%csmethodmodifiers InitializeVertices "public unsafe";

// PInvoke (copy)
%apply float INPUT[] {const float* pDepths }

// TODO: Generate typemap which output using either
//  - System.Runtime.InteropServices.Marshal.Copy
//  - Transfer data to GC

%include "mylibrary_export.h"
%include "mylib.h"
