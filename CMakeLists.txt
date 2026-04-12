cmake_minimum_required(VERSION 3.10)

project(Qubit_Simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Qubit_Simulator  
    src/Complex.cpp
    src/Circuit.cpp
    src/Gate.cpp
    src/GateFactory.cpp
    src/QubitRegister.cpp
    src/main.cpp
)

target_include_directories(Qubit_Simulator PRIVATE src)