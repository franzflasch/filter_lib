cmake_minimum_required(VERSION 2.8.7)
project(filter_lib)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(LIB_SRCS src/lib_filter_fir1.c
             src/lib_filter_sos.c)

set(FILTER_PUBLIC_HEADERS inc/lib_filter_fir1.h 
                          inc/lib_filter_sos.h)

add_library(filter SHARED ${LIB_SRCS})
include_directories(inc)
set_target_properties(filter PROPERTIES PUBLIC_HEADER "${FILTER_PUBLIC_HEADERS}")
set_target_properties(filter PROPERTIES SOVERSION "1")

install(TARGETS filter DESTINATION lib PUBLIC_HEADER DESTINATION inc)

add_executable(example_fir1 src/example_fir1.c)
add_executable(example_sos src/example_sos.c)

target_link_libraries(example_fir1 filter)
target_link_libraries(example_sos filter)

### Debian Package generation
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_VERSION "0.1.0")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Franz Flasch") #required
include(CPack)
