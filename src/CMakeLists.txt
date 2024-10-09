include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES
    main.cpp
    world.cpp
    view.cpp
    grid.cpp
    vector.cpp
    color.cpp
)

add_executable(neurons ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)

set_target_properties(neurons PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

target_link_libraries(neurons ${SDL2_LIBRARIES})