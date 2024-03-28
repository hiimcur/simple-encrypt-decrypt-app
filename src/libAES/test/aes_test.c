/*#include <gtest/gtest.h>
extern "C"{
    #include <aes.h>
    #include <utils.h>
}


class AESTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(HandleInputTest, InvalidMode) {
    int mode = 18; //invalid node
    char* inputFolder = "./validFolder";
    char* outputFolder = "./validOutputFolder";
    FileInfo* files = nullptr;
    int fileCount = 0;
    uint8_t key[16]; 
    uint8_t iv[16]; 
    int num_threads = 4;

    HandleInputUsingThread(mode, inputFolder, outputFolder, files, fileCount, key, iv, num_threads);
}

TEST_F(HandleInputTest, NonExistentInputFolder) {
    int mode = 1; 
    char* inputFolder = "./nonExistFolder";
    char* outputFolder = "./validOutputFolder";
    FileInfo* files = nullptr; 
    int fileCount = 0;
    uint8_t key[16]; 
    uint8_t iv[16];
    int num_threads = 4;

    HandleInputUsingThread(mode, inputFolder, outputFolder, files, fileCount, key, iv, num_threads);
}

TEST_F(HandleInputTest, NonExistentOutputFolder) {
    int mode = 1; 
    char* inputFolder = "./validFolder";
    char* outputFolder = "./notCreateFolder";
    FileInfo* files = nullptr; 
    int fileCount = 0;
    uint8_t key[16]; 
    uint8_t iv[16]; 
    int num_threads = 4;

    HandleInputUsingThread(mode, inputFolder, outputFolder, files, fileCount, key, iv, num_threads);
}

TEST_F(HandleInputTest, ValidParameters) {
    int mode = 1; 
    char* inputFolder = "./validFolder";
    char* outputFolder = "./validOutputFolder";
    FileInfo* files = nullptr;
    int fileCount = 0;
    uint8_t key[16]; 
    uint8_t iv[16];
    int num_threads = 4;

    HandleInputUsingThread(mode, inputFolder, outputFolder, files, fileCount, key, iv, num_threads);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/