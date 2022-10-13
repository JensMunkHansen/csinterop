include(CSharpUtilities)

if (1)
add_executable(Main
 Program.cs
 Properties/launchsettings.json
)

set_property(TARGET Main PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v6.0")

set_property(TARGET Main PROPERTY WIN32_EXECUTABLE TRUE)
set_property(TARGET Main PROPERTY VS_GLOBAL_Prefer32Bit "false")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_GLOBAL_ROOTNAMESPACE "dotnet")

set_property(TARGET Main PROPERTY VS_DOTNET_REFERENCES
	"System")
add_dependencies(Main mylibs::MyLibraryInterop)
set(CMAKE_CSharp_FLAGS "${CMAKE_CSharp_FLAGS} /langversion:6")

endif()
