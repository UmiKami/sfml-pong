cmake_minimum_required(VERSION 3.28)
project(PingPong LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_executable(PingPong src/main.cpp src/PlayerCharacter.cpp
        src/PlayerCharacter.h)
target_compile_features(PingPong PRIVATE cxx_std_17)
target_link_libraries(PingPong PRIVATE SFML::Graphics m stdc++ stdc++fs)
# Custom target to build the project
add_custom_target(build_all
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Building the project..."
)

# Custom target to run the built executable
add_custom_target(run
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/PingPong
    DEPENDS build_all
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running the executable..."
)

# Custom target to build and run
add_custom_target(build_and_run
    DEPENDS build_all run
    COMMENT "Building and running the project..."
)
