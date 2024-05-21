add_library(customcontainer customcontainer.cpp customcontainer.hpp)
set_property(TARGET customcontainer PROPERTY CXX_STANDARD 20)
target_include_directories(customcontainer PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)