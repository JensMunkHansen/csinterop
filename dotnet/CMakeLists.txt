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






# Consuming the other
project(thing_using_example
    LANGUAGES CSharp)
include(CSharpUtilities)

set(SOURCES
    ThingUsingExample.cs
)

add_executable(${PROJECT_NAME} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.6.1")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_GLOBAL_ROOTNAMESPACE "ThingUsingExample")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_GLOBAL_Prefer32Bit "false")
set(CMAKE_CSharp_FLAGS "${CMAKE_CSharp_FLAGS} /langversion:6")
add_dependencies(${PROJECT_NAME} mylibs::newlib)


