cmake_minimum_required(VERSION 3.16)
project(DeadIsNear)

set(CMAKE_CXX_STANDARD 14)
add_executable(DeadIsNear main.cpp Game.cpp Game.h TextureManager.cpp TextureManager.h GameObject.cpp GameObject.h Map.cpp Map.h ECS/ECS.h ECS/Components.h ECS/SpritesComponent.h ECS/TransformComponent.h Vector2D.h Vector2D.cpp ECS/KeyboardControler.h ECS/ColliderComponent.h Collision.h Collision.cpp ECS/TileComponent.h ECS/ECS.cpp ECS/Animation.h)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(DeadIsNear ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})



