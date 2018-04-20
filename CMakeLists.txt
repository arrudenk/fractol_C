cmake_minimum_required(VERSION 3.9)
project(fractol_C)

set(CMAKE_C_STANDARD 99)



    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit -lm")

    link_directories(${PROJECT_SOURCE_DIR}/minilibx_macos)
    include_directories(${PROJECT_SOURCE_DIR}/minilibx_macos)
    link_directories(${PROJECT_SOURCE_DIR}/libft)
    include_directories(${PROJECT_SOURCE_DIR}/libft)

set(SOURCE_FILES src/fractol.c includes/fractol.h src/main.c src/draw.c src/mlx.c src/image.c includes/keyx.h src/new_vector.c)

add_executable(fractol_C ${SOURCE_FILES})

    target_link_libraries(fractol_C ${PROJECT_SOURCE_DIR}/libft/libft.a ${PROJECT_SOURCE_DIR}/minilibx_macos/libmlx.a -lm)
