cmake_minimum_required(VERSION 3.30)
project(app)

# Create an executable from main.cpp
add_executable(main main.cpp)

# Link the executable with the shared libraries
target_link_libraries(main PRIVATE math geometry physics)

# Set path to shared libraries during runtime (Linux-specific)
if (UNIX)
    set_target_properties(main PROPERTIES INSTALL_RPATH "$ORIGIN/../libmath:$ORIGIN/../libgeo:$ORIGIN/../libphysics")
endif()
