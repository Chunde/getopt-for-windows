# getopt-for-windows

getopt.h and getopt.c is very often used in linux, to make it easy for windows user, two files were extracted from glibc. In order to make it works properly in windows, some modification was done and you may compare the change using original source files. Enjoy it!

## CMake howto

### Installation

To install with cmake, first configure the repo. This assumes that you have cmake and visual studio already installed in your developement environment correctly.

```shell
mkdir build-out
cd build-out
cmake ..
```

After the configure has executed, you can build the project. Either open the project form visual studio and build or from a developer command prompt execute the build commands. It has no external dependencies so its as simple as:

```shell
devenv getopt_for_windows.sln /Build
```

You may also use `msbuild getopt_for_windows.sln`.

Finally, from within an administrative developer command prompt, execute:

```shell
devenv INSTALL.vcxproj /Build
```

Now you have it installed.

### Usage

To use `getopt-for-windows` as part of your project, you need to add lines similar to the following to your `CMakeLists.txt`

```cmake
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    find_package(getopt_for_windows)
    list(APPEND INCLUDE_LIST ${getopt_for_windows_INCLUDE_DIR})
    target_link_directories(${PROJECT_NAME} PRIVATE ${getopt_for_windows_LIB_DIR})
    list(APPEND LINK_LIST getopt_for_windows_static)
endif()
```

Then, your C file needs to explicitly include the getopt header:

```c
#ifdef _WIN32
#include <winpos.h>
#endif
```

And that's it! you have added getopt to your windows project!

(also provides functionality for some posix routines windows doesn't typically support, such as:
    getline
    S_ISREG
    strncasecmp
    strcasecmp)