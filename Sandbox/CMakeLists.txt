cmake_minimum_required(VERSION 3.15)

project(Sandbox VERSION 0.1.0 LANGUAGES CXX)
DeclareProjectInstallDirectories()

add_executable(Sandbox)
add_subdirectory(src)
target_link_libraries(Sandbox
    PRIVATE
        Hazel::Hazel
        Hazel::BuildFlags
)

set_target_properties(Sandbox
    PROPERTIES
        MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>$<$<BOOL:${BUILD_SHARED_LIBS}>:DLL>
        RUNTIME_OUTPUT_DIRECTORY                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Sandbox
        RUNTIME_OUTPUT_DIRECTORY_DEBUG          ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}/Sandbox
        RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO}/Sandbox
        RUNTIME_OUTPUT_DIRECTORY_RELEASE        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}/Sandbox
        ARCHIVE_OUTPUT_DIRECTORY                ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/Sandbox
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG          ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}/Sandbox
        ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO}/Sandbox
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE}/Sandbox
        LIBRARY_OUTPUT_DIRECTORY                ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Sandbox
        LIBRARY_OUTPUT_DIRECTORY_DEBUG          ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG}/Sandbox
        LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO}/Sandbox
        LIBRARY_OUTPUT_DIRECTORY_RELEASE        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}/Sandbox
)

InstallProject(TARGETS Sandbox)

# Copy Hazel dll into Sandbox build directory
add_custom_command(
    TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Hazel>
        $<TARGET_FILE_DIR:Sandbox>
    DEPENDS Hazel
    VERBATIM
    USES_TERMINAL
    COMMAND_EXPAND_LISTS
)
add_custom_command(
    TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${Sandbox_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:Sandbox>/assets
    DEPENDS Hazel
    VERBATIM
    USES_TERMINAL
    COMMAND_EXPAND_LISTS
)
