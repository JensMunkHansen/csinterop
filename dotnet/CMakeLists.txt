include(CSharpUtilities)

add_executable(Main
 Program.cs
 Properties/launchsettings.json
)

set_property(TARGET Main PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.8")

set_property(TARGET Main PROPERTY WIN32_EXECUTABLE TRUE)

set_property(TARGET Main PROPERTY VS_DOTNET_REFERENCES
	"System"
)

# Adds the references
target_link_libraries(Main PUBLIC MyLibraryInterop)


# Does not locate the files!!!!!
target_include_directories(Main PUBLIC "${NET_PROJECT_DIR}")



