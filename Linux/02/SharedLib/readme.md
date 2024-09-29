
# Shared Libraries

- demonstrates the use of shared libraries in C++ using **CMake**. It consists of three libraries (`libmath`, `libgeometry`, `libphysics`) and an application that links to and uses these libraries.

##  Structure

```
my_project/
├── libmath/
│   ├── math.cpp
│   ├── math.h
│   └── CMakeLists.txt
│
├── libgeometry/
│   ├── geometry.cpp
│   ├── geometry.h
│   └── CMakeLists.txt
│
├── libphysics/
│   ├── physics.cpp
│   ├── physics.h
│   └── CMakeLists.txt
│
├── app/
│   ├── main.cpp
│   └── CMakeLists.txt
│
└── CMakeLists.txt      # Root CMake file for building everything
```

## How to Build and Run the Project

### 1. Create a Build Directory
Navigate to the root of the project directory and create a new directory called `build` for the build files:

```bash
mkdir build
cd build
```

### 2. Generate the Build System with CMake
Run CMake from the `build` directory to generate the build system:

```bash
cmake ..
```

This will automatically detect the `CMakeLists.txt` files in the project and generate the necessary Makefiles.

### 3. Build the Project
Use `make` to build the project:

```bash
make
```

This will compile all the shared libraries and the main application.

### 4. Run the Application
After the project has been built, run the compiled application:

```bash
./app/main
```



---
