cmake_minimum_required(VERSION 3.5)

# Project name
get_filename_component(DIR_AS_PROJECT ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" DIR_AS_PROJECT ${DIR_AS_PROJECT})
project(${DIR_AS_PROJECT})
message(STATUS "Configuring ${DIR_AS_PROJECT}...")
# Use C11
set(CMAKE_C_STANDARD 11)

message(STATUS "Adding source/head files...")
file(GLOB_RECURSE SRC_LIST FOLLOW_SYMLINKS *.c)
file(GLOB_RECURSE HEAD_FILES FOLLOW_SYMLINKS *.h)
add_library(shared SHARED ${SRC_LIST})

message(STATUS "Adding php-src...")
# Define path to php-src, change accordingly
set(PHP_SOURCE ../php-src)
# Import php sources
include_directories(
        ${PHP_SOURCE}
        ${PHP_SOURCE}/main
        ${PHP_SOURCE}/Zend
        ${PHP_SOURCE}/TSRM
        ${PHP_SOURCE}/ext
        ${PHP_SOURCE}/sapi
        ${PHP_SOURCE}/pear
)
