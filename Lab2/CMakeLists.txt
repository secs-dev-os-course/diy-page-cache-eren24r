# Собираем библиотеку lab2_cache в виде SHARED (DLL на Windows, .so на Unix).
add_library(lab2_cache SHARED
        lab2_cache.cpp
)

# Укажем, что при подключении lab2_cache её заголовки (текущая папка) должны быть видны
target_include_directories(lab2_cache
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Если нужно подключить какие-то зависимости WinAPI/Posix, делаем это здесь.
# Например:
target_link_libraries(app PRIVATE lab2_cache)
