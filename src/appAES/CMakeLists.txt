add_executable(appAES app_aes.c)
target_link_libraries(appAES PUBLIC libAES libLog)
set_target_properties(appAES PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)