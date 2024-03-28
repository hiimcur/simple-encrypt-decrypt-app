add_executable(logExample log_example.c)
target_link_libraries(logExample PUBLIC libLog)
set_target_properties(logExample PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
