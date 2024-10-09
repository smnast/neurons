set(SOURCES
    main.cpp
    world.cpp
    view.cpp
    grid.cpp
    vector.cpp
    color.cpp
    neuron.cpp
    input_group.cpp
    texture_manager.cpp
)

add_executable(neurons ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)

set_target_properties(neurons PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_GFX_INCLUDE_DIRS})
target_link_libraries(neurons ${SDL2_LIBRARIES} SDL2_image::SDL2_image ${SDL2_GFX_LIBRARIES})
