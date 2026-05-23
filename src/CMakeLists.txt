file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)
add_executable(render ${SOURCES})

target_include_directories(render PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(render SYSTEM PRIVATE ${CMAKE_SOURCE_DIR}/libs)