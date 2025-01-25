# Мы уже вызвали include(FetchContent) в корневом CMakeLists.txt

# Объявляем, откуда скачать Google Test
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# Собираем и подключаем
FetchContent_MakeAvailable(googletest)

# Создаём тестовый исполняемый файл
add_executable(test_lab2
        test_lab2.cpp
)

# Линкуем с gtest_main и нашей библиотекой lab2_cache
target_link_libraries(test_lab2
        PRIVATE
        gtest_main
        lab2_cache
)

# Регистрируем тест под именем test_lab2
add_test(NAME test_lab2 COMMAND test_lab2)
