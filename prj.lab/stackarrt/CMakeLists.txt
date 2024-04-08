add_library(stackarrt stackarrt.hpp)
target_link_libraries(stackarrt complex)
set_property(TARGET stackarrt PROPERTY CXX_STANDARD 20)
target_include_directories(stackarrt PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)