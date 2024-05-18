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

add_executable(test_stackarrt test_stackarrt.cpp unittest.hpp)
target_link_libraries(test_stackarrt stackarrt)

add_executable(test_stacklstt test_stacklstt.cpp unittest.hpp)
target_link_libraries(test_stacklstt stacklstt)

add_executable(test_dynarr test_dynarr.cpp)
target_link_libraries(test_dynarr dynarr)

add_executable(test_queuearr test_queuearr.cpp)
target_link_libraries(test_queuearr queuearr)

add_executable(test_queuelst test_queuelst.cpp)
target_link_libraries(test_queuelst queuelst)

add_executable(test_binarysearchtree test_binarysearchtree.cpp)
target_link_libraries(test_binarysearchtree binarysearchtree)

add_executable(test_queuelstpr test_queuelstpr.cpp)
target_link_libraries(test_queuelstpr queuelstpr)

add_executable(test_istackarrt test_istackarrt.cpp)
target_link_libraries(test_istackarrt istackarrt)

add_executable(test_istacklstt test_istacklstt.cpp)
target_link_libraries(test_istacklstt istacklstt)

add_executable(test_queuelstprt test_queuelstprt.cpp unittest.hpp)
target_link_libraries(test_queuelstprt queuelstprt)

add_executable(test_queuearrt test_queuearrt.cpp unittest.hpp)
target_link_libraries(test_queuearrt queuearrt)

add_executable(test_queuelstt test_queuelstt.cpp unittest.hpp)
target_link_libraries(test_queuelstt queuelstt)

add_executable(test_dynarrt test_dynarrt.cpp unittest.hpp)
target_link_libraries(test_dynarrt dynarrt)

add_executable(test_hashtable test_hashtable.cpp)
target_link_libraries(test_hashtable hashtable)