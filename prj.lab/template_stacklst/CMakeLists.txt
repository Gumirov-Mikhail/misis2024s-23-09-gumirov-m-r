add_library(template_stacklst template_stacklst.hpp)
target_link_libraries(template_stacklst complex)
set_property(TARGET template_stacklst PROPERTY CXX_STANDARD 20)
target_include_directories(template_stacklst PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)