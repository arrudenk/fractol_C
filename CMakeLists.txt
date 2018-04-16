cmake_minimum_required(VERSION 3.9)
project(fractol_C)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_C_STANDARD 99)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(MLX -lft -lmlx -lXext -lX11 -lm)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # Tbma, do you OSX stuff here
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit -lm")
    link_directories(${PROJECT_SOURCE_DIR}/minilibx_macos)
    include_directories(${PROJECT_SOURCE_DIR}/minilibx_macos)
    link_directories(${PROJECT_SOURCE_DIR}/libft)
    include_directories(${PROJECT_SOURCE_DIR}/libft)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

set(SOURCE_FILES src/fractol.c src/fractol.h src/main.c)

add_executable(fractol_C ${SOURCE_FILES})

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(fractol_C -lft -lm)
    target_link_libraries(fractolc_C -lft -lmlx -lm)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(fractol_C ${MLX})
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")