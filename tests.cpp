//
// Created by Marcin Grześ on 15/06/2024.
//
#include <gtest/gtest.h>
#include "DString.h"

TEST(DStringTest, DefaultConstructor) {
DString str;
EXPECT_TRUE(str.IsEmpty());
}

TEST(DStringTest, ParamConstructor) {
DString str("Test");
EXPECT_EQ(strcmp(str, "Test"), 0);
}

TEST(DStringTest, CopyConstructor) {
DString str1("Test");
DString str2(str1);
EXPECT_EQ(strcmp(str2, "Test"), 0);
}

TEST(DStringTest, AssignmentOperator) {
DString str1("Test");
DString str2;
str2 = str1;
EXPECT_EQ(strcmp(str2, "Test"), 0);
}

TEST(DStringTest, ConcatOperator) {
DString str1("Hello");
DString str2(" World");
DString str3 = str1 + str2;
EXPECT_EQ(strcmp(str3, "Hello World"), 0);
}

TEST(DStringTest, ConcatAssignOperator) {
DString str1("Hello");
DString str2(" World");
str1 += str2;
EXPECT_EQ(strcmp(str1, "Hello World"), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}