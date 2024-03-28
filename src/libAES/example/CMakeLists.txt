add_executable(aesExample aes_example.c)
target_link_libraries(aesExample PUBLIC libAES libLog)
set_target_properties(aesExample PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)