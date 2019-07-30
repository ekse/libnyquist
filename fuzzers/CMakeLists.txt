include_directories(../include)

add_executable(FuzzNyquist FuzzNyquist.cpp)
target_link_libraries(FuzzNyquist ${CMAKE_THREAD_LIBS_INIT} libnyquist libopus libwavpack FLAC)
