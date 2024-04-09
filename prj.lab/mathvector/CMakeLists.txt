add_library(mathvector mathvector.hpp mathvector.cpp)
set_property(TARGET mathvector PROPERTY CXX_STANDARD 20)
target_include_directories(mathvector PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS mathvector)