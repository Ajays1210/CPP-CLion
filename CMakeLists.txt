cmake_minimum_required(VERSION 3.20)
project(MyCppProjects)

set(CMAKE_CXX_STANDARD 20)

# Auto-find all main.cpp files
file(GLOB_RECURSE MAIN_SOURCES "Programs/*/main.cpp")

foreach(main_file ${MAIN_SOURCES})
    get_filename_component(example_dir ${main_file} DIRECTORY)
    get_filename_component(parent_dir ${example_dir} DIRECTORY)
    get_filename_component(parent_name ${parent_dir} NAME)
    get_filename_component(example_name ${example_dir} NAME)

    # Create unique target name (e.g., "ImplementingMethods_Example1")
    set(target_name "${parent_name}_${example_name}")

    # Include all source and header files in the example directory
    file(GLOB local_sources "${example_dir}/*.cpp")
    file(GLOB local_headers "${example_dir}/*.h")

    add_executable(${target_name} ${main_file} ${local_sources}
            Programs/ObjectOrientedProgramming/ImplementingMethods/Example3/person.cpp
            Programs/ObjectOrientedProgramming/ImplementingMethods/Example3/person.h
            Programs/ObjectOrientedProgramming/ImplementingMethods/Example4/example.cpp
            Programs/ObjectOrientedProgramming/ImplementingMethods/Example4/example.h)
    target_include_directories(${target_name} PRIVATE ${example_dir})

    message("Added target: ${target_name} (from ${example_dir})")
endforeach()