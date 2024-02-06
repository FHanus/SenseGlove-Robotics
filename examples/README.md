# SenseGlove-Robotics Examples

Welcome to the SenseGlove-Robotics examples! This README provides detailed instructions on how to build and run the examples in this repository.

## Prerequisites

Before you begin, ensure you have the following prerequisites installed on your system:

1. **Ubuntu 22.04**: This was developed and tested on Ubuntu 22.04

2. **Git**: Verify that Git is installed.

3. **CMake: CMake is required for building projects. You can check if it's installed using:**

    ```bash
    cmake --version
    ```

If not installed, you can install it with:

4. **C++ Compiler: Make sure you have a C++ compiler (e.g., g++) installed:**

    ```bash
    g++ --version
    ```

## Building and Running an Example

Follow these steps to build and run an example:

1. Clone the Repository, if you haven't already cloned your project repository, you can do it using:

    ```bash
    git clone https://github.com/FHanus/SenseGlove-Robotics.git
    ```

2. Navigate to the "examples" Directory:

    Change your working directory to the "examples" folder:

    ```bash
    cd SenseGlove-Robotics/examples
    ```

3. Choose an Example:

    Select the example you want to build from the available options. For example, if you want to build "PositionReader," navigate to its directory:

    ```bash
    cd position_reader
    ```

4. Create a Build Directory:

    Create a directory for building the project:

    ```bash
    mkdir build
    cd build
    ```

5. Run CMake:

    Use CMake to configure the build:

    ```bash
    cmake ..
    ```

6. Build the Project:

    Once CMake is done configuring, build the project:

    ```bash
    make
    ```

7. Run the Example:

    Run the compiled executable. For example, if you're in the "PositionReader" directory:

    ```bash
    ./PositionReader
    ```

Follow the instructions provided by the example to interact with it.