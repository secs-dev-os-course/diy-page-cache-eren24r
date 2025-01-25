#include <gtest/gtest.h>
#include "lab2_cache.h"

// Простой тест открытия-закрытия
TEST(Lab2CacheTest, OpenClose) {
    int fd = lab2_open("mytestfile.bin");
    EXPECT_GE(fd, 0) << "lab2_open returned negative FD";

    int result = lab2_close(fd);
    EXPECT_EQ(result, 0) << "lab2_close failed";
}

// Ещё тест — чтение-запись
TEST(Lab2CacheTest, ReadWrite) {
    int fd = lab2_open("mytestfile.bin");
    ASSERT_GE(fd, 0);

    const char* testData = "Hello World";
    long long written = lab2_write(fd, testData, 11);
    EXPECT_EQ(written, 11);

    // Вновь лSeek-немся в начало
    lab2_lseek(fd, 0, SEEK_SET);

    char buffer[20] = {0};
    long long readCount = lab2_read(fd, buffer, 11);
    EXPECT_EQ(readCount, 11);
    EXPECT_STREQ(buffer, "Hello World");

    // Закрыть
    lab2_close(fd);
}
