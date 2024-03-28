find_package(GTest REQUIRED)

add_executable(logTest log_test.c)

set_source_files_properties(log_test.c PROPERTIES LANGUAGE CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -coverage")

target_link_libraries(logTest PUBLIC libLog GTest::GTest GTest::Main)
set_target_properties(logTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)