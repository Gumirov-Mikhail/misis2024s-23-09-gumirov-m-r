add_library(template_stackarr template_stackarr.hpp)
target_link_libraries(template_stackarr complex)
set_property(TARGET template_stackarr PROPERTY CXX_STANDARD 20)
target_include_directories(template_stackarr PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)