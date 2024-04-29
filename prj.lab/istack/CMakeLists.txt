add_library(istackarrt INTERFACE istackbase.hpp)
set_property(TARGET istackarrt PROPERTY CXX_STANDARD 20)
target_include_directories(istackarrt INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)

add_library(istacklstt INTERFACE istackbase.hpp)
set_property(TARGET istacklstt PROPERTY CXX_STANDARD 20)
target_include_directories(istacklstt INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
