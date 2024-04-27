add_library(binarysearchtree binarysearchtree.cpp binarysearchtree.hpp)
set_property(TARGET binarysearchtree PROPERTY CXX_STANDARD 20)
target_include_directories(binarysearchtree PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)