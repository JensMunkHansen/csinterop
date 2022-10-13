include(CSharpUtilities)

if (1)
  add_executable(Main
   Program.cs
   Properties/launchsettings.json
  )
  
  set_property(TARGET Main PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION ${CSINTEROP_DOTNET_TARGET_FRAMEWORK_VERSION})
  
  set_property(TARGET Main PROPERTY WIN32_EXECUTABLE TRUE)
  set_property(TARGET Main PROPERTY VS_GLOBAL_Prefer32Bit "false")
  set_property(TARGET Main PROPERTY VS_GLOBAL_ROOTNAMESPACE "${GLOBAL_NAMESPACE}")
  target_compile_options(Main PUBLIC "/unsafe")

  set_property(TARGET Main PROPERTY VS_DOTNET_REFERENCES "System")
  # expected assembly manifest

#  set_property(TARGET Main PROPERTY VS_DOTNET_REFERENCE_MyLibraryInterop "C:/github/csinterop/build/interop/Debug/MyLibraryInterop.dll")
  set_property(TARGET Main PROPERTY VS_DOTNET_REFERENCE_MyLibraryInterop "C:/github/csinterop/build/dotnet/bin/Debug/net4.8/MyLibraryInterop.dll")
  add_dependencies(Main MyLibraryInterop)
  target_link_libraries(Main MyLibraryInterop)

endif()

#Use VS_DOTNET_REFERENCES_libraryName

