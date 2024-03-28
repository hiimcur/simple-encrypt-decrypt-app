# AES-ENCRYPT-DESCRYPT

## Essential libraries:
- `stdio`
- `stdarg`
- `stdlib`
- `stddef`
- `pthread`
- `dirent`
- `sys`
- `gtest`
- `gcov`

## Build the project
1. Open the terminal and navigate to the repository directory. Then move to the "build" directory with the following command:
    ```bash
    cd build
    ```

2. Use CMake to configure the project:
    ```bash
    cmake ../src
    ```

3. Finally, use CMake to build the project:
    ```bash
    make .
    ```

## Running the Executable

> **Prerequisite:** Ensure that you have built the project first.

1. Open the terminal and navigate to the repository directory. Then move to the "build" directory and further into the "bin" directory within the "build" directory:

    ```bash
    cd build
    cd bin
    ```
2. Run the executable file "appAES.exe" by the following command:

    ```bash
    ./appAES <-e/-d> <inputFolder> <outputFolder>     
    ```
