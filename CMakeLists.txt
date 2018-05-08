cmake_minimum_required(VERSION 3.9)
project(fractol_C)

set(CMAKE_C_STANDARD 99)



    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit -lm")

    link_directories(${PROJECT_SOURCE_DIR}/minilibx_macos)
    include_directories(${PROJECT_SOURCE_DIR}/minilibx_macos)
    link_directories(${PROJECT_SOURCE_DIR}/libft)
    include_directories(${PROJECT_SOURCE_DIR}/libft)

set(SOURCE_FILES src/julia_set.c includes/fractol.h src/main.c src/mlx_image.c includes/keyx.h src/mandelbrot_set.c src/hook.c src/celtic_set.c src/threads.c src/fractal_tools.c src/tricorn_set.c src/perpendicular_mandelbrot_set.c src/perpen_celtic_set.c src/heart_set.c src/four_mandelbrot_set.c)

add_executable(fractol_C ${SOURCE_FILES})

    target_link_libraries(fractol_C ${PROJECT_SOURCE_DIR}/libft/libft.a ${PROJECT_SOURCE_DIR}/minilibx_macos/libmlx.a -lm)
