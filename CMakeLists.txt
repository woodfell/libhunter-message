cmake_minimum_required(VERSION 3.10)

project(hunter-libmessage)
include(GNUInstallDirs)

set(SRCS message.c)
set(HDRS include/libhunter-message/message.h)

add_library(hunter-libmessage ${SRCS})
target_include_directories(hunter-libmessage PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS hunter-libmessage
    ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )
install(FILES ${HDRS} DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}/hunter-libmessage)


