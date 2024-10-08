include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES
    main.cpp
)

add_executable(neurons ${SOURCES})

set_target_properties(neurons PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

target_link_libraries(neurons ${SDL2_LIBRARIES})