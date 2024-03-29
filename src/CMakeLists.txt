project(ExampleApplication)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# For Visual Studio, use /MT for static linking
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

add_library(example_dynamic_library SHARED
  shared.cpp
)

add_executable(ExampleApplication
  main.cpp
)

set_target_properties(ExampleApplication PROPERTIES
  LINK_FLAGS /SUBSYSTEM:WINDOWS
)

target_link_libraries(ExampleApplication 
  PRIVATE 
    project::warnings_options 
    project::warning_suppressions
    example_dynamic_library
)

if(MSVC)
  target_link_options(${PROJECT_NAME} PRIVATE
    /SUBSYSTEM:CONSOLE
  )
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
