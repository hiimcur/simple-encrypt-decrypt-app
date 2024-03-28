file(GLOB LIB_LOG_HEADERS "*.h")
file(GLOB LIB_LOG_SOURCES "*.c")

add_library(log_levels_obj OBJECT ${LIB_LOG_SOURCES})
set_property(TARGET log_levels_obj PROPERTY POSITION_INDEPENDENT_CODE ON)

add_library(libLog $<TARGET_OBJECTS:log_levels_obj>)
target_include_directories(libLog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(libLog PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libLog
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/libLog
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/libLog
)
