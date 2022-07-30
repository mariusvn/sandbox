cmake_minimum_required(VERSION 3.23)
project(sandbox C)

IF (NOT ALLEGRO_PATH)
    set(ALLEGRO_PATH ../libs/allegro)
endif()

set(CMAKE_C_STANDARD 17)

file(GLOB SOURCE_FILES src/*.c src/**/*.c)
file(GLOB HEADER_FILES src/*.h src/**/*.h)
add_executable(sandbox ${SOURCE_FILES})

MESSAGE(${ALLEGRO_PATH}/include)
INCLUDE_DIRECTORIES(${ALLEGRO_PATH}/include)
LINK_DIRECTORIES(${ALLEGRO_PATH}/bin)

file(GLOB LIBRARIES "${ALLEGRO_PATH}/lib/*.dll.a")
file(GLOB LIBRARIES_DLLS "${ALLEGRO_PATH}/bin/*.dll")
message("LIBRARIES = ${LIBRARIES}")

target_link_libraries(sandbox ${LIBRARIES})

file(COPY ${LIBRARIES_DLLS} DESTINATION ${CMAKE_BINARY_DIR})