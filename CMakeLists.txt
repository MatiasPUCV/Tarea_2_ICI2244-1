cmake_minimum_required(VERSION 3.26)
project(Tarea2)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(COPY "puntos_interes.csv" "turistas.csv" DESTINATION ${CMAKE_BINARY_DIR})
