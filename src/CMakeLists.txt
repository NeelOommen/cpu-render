add_executable(render main.cpp)

target_include_directories(render PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/libs
)