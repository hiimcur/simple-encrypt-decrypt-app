file(GLOB LIB_AES_HEADERS "aes.h" "pkcs7_padding.h")
file(GLOB LIB_AES_SOURCES "aes.c" "pkcs7_padding.c")
file(GLOB LIB_UTILS_HEADERS "utils.h")
file(GLOB LIB_UTILS_SOURCES "utils.c")

add_library(aes_obj OBJECT ${LIB_AES_SOURCES})
set_property(TARGET aes_obj PROPERTY POSITION_INDEPENDENT_CODE ON)
add_library(utils_obj OBJECT ${LIB_UTILS_SOURCES})
set_property(TARGET utils_obj PROPERTY POSITION_INDEPENDENT_CODE ON)

add_library(libAES $<TARGET_OBJECTS:aes_obj> $<TARGET_OBJECTS:utils_obj>)
target_include_directories(libAES PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(libAES PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libAES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/libAES
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/libAES
)

find_package(Threads REQUIRED)
target_link_libraries(libAES PRIVATE ${CMAKE_THREAD_LIBS_INIT})

#add_library(libUtils $<TARGET_OBJECTS:utils_obj>)
#target_include_directories(libUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#set_target_properties(libUtils PROPERTIES
#    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libAES
#    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/libAES
#    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/libAES
#)

