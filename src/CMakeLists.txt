project(ExampleApplication)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# For Visual Studio, use /MT for static linking

# this a demostration of what NOT to do, by addding this, the application and the dll with both statically link the runtime
# that is not a problem in itself, but it requires that all allocations that happen in the DLL are freed in the DLL
# and also all allocations that happen in the Application MUST be freed in the Application.
# this naturally DOES NOT happen when using RAII objects in C++, because the callee can often allocate, while the caller frees the memory
# when the scope ends.

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

add_library(example_dynamic_library SHARED
  shared.h
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
