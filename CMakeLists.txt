cmake_minimum_required(VERSION 3.0)

project(sensor-laser-test-project VERSION "0.1.0" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)

# From: https://stackoverflow.com/a/60844772/1319478
# if (MSVC)
#     add_definitions(-D_WIN32_WINNT=0x600)
#     add_compile_options(
#            $<$<CONFIG:>:/MT> #---------|
#            $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
#            $<$<CONFIG:Release>:/MT> #--|
#    )
# endif ()

# set libraries
#set(CXXOPTS_PATH third-party/cxxopts)
#add_subdirectory(${CXXOPTS_PATH})

add_executable(sensor-laser-test src/main.cpp)

target_link_libraries(sensor-laser-test RecFusion) # cxxopts
target_include_directories(sensor-laser-test PRIVATE ${RECFUSION_PATH}/include)
target_link_directories(sensor-laser-test PRIVATE ${RECFUSION_PATH}/lib)
