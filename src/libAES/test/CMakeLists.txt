find_package(GTest REQUIRED)

add_executable(aesTest aes_test.c)

set_source_files_properties(aes_test.c PROPERTIES LANGUAGE CXX)

target_link_libraries(aesTest PUBLIC libAES GTest::GTest GTest::Main)
set_target_properties(aesTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
