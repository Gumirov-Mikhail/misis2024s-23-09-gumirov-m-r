cmake_minimum_required(VERSION 3.26)
project(misis2024s_23_09_gumirov_m_r)

set(CMAKE_CXX_STANDARD 14)

include_directories(prj.lab/complex)

add_executable(misis2024s_23_09_gumirov_m_r
        prj.codeforces/0520a.cpp
        prj.codeforces/0747b.cpp
        prj.codeforces/0768a.cpp
        prj.codeforces/0886b.cpp
        prj.codeforces/0967b.cpp
        prj.codeforces/1017a.cpp
        prj.codeforces/1200a.cpp
        prj.codeforces/1703a.cpp
        prj.lab/complex/complex.cpp
        prj.lab/complex/complex.hpp
        prj.lab/dynarr/pusto.cpp)
