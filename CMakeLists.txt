cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Set project name and version
project(asteroids VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Find SFML shared libraries
find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED
  )

# Compile executable
add_executable(asteroids main.cpp "src/Spaceship.cpp" "src/Animation.cpp" "src/Entity.cpp" "src/Bullet.cpp" "src/Asteroid.cpp" "src/Explosion.cpp")

# Set include directory search paths
target_include_directories(asteroids 
  PRIVATE
  "${PROJECT_BINARY_DIR}"
  )

# Link executable to required SFML libraries
target_link_libraries(asteroids sfml-graphics)
include_directories("inc/")

# Install target
install(TARGETS asteroids DESTINATION bin)