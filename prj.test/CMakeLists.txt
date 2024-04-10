add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex)

add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational rational)

add_executable(test_mathvector test_mathvector.cpp)
target_link_libraries(test_mathvector mathvector)

add_executable(test_stackarr test_stackarr.cpp)
target_link_libraries(test_stackarr stackarr)

add_executable(test_stacklst test_stacklst.cpp)
target_link_libraries(test_stacklst stacklst)

add_executable(test_stackarrt test_stackarrt.cpp)
target_link_libraries(test_stackarrt stackarrt)

add_executable(test_stacklstt test_stacklstt.cpp)
target_link_libraries(test_stacklstt stacklstt)