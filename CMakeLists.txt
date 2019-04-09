cmake_minimum_required(VERSION 3.10)

project(libhunter-message LANGUAGES C CXX VERSION 1.0.0)
include(GNUInstallDirs)

set(config_install_dir "${CMAKE_INSTALL_FULL_LIBDIR}/cmake/${PROJECT_NAME}")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets.cmake")
set(namespace "${ProjectName}::")

set(SRCS message.c)
set(HDRS include/libhunter-message/message.h)

add_library(hunter-message ${SRCS})
target_include_directories(hunter-message PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS hunter-message
    EXPORT "${TARGETS_EXPORT_NAME}"
    ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_FULL_INCLUDE_DIR}/libhunter-message
    )
install(
    DIRECTORY "include/libhunter-message"
    DESTINATION "${CMAKE_INSTALL_FULL_INCLUDEDIR}"
    FILES_MATCHING PATTERN "*.h"
    )


include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
    )

configure_package_config_file(
    "cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
    )

install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
    )

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
    )

