#include <gtest/gtest.h>
extern "C"{
    #include <logLib.h>
}

class LogLibTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(LogLibTest, SetLogLevelTest) {
    setLogLevel(DEBUG);
    EXPECT_EQ(currentLogLevel, DEBUG);

    setLogLevel(INFO);
    EXPECT_EQ(currentLogLevel, INFO);

    setLogLevel(WARNING);
    EXPECT_EQ(currentLogLevel, WARNING);

    setLogLevel(ERROR);
    EXPECT_EQ(currentLogLevel, ERROR);
}

TEST_F(LogLibTest, DebugLogTest) {
    setLogLevel(DEBUG);

    const char* message = "Debug log message";

    testing::internal::CaptureStdout();

    debugLog(message);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("[DEBUG]"), std::string::npos);
    EXPECT_NE(output.find(message), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}