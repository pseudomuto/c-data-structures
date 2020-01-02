include(ExternalProject)

ExternalProject_Add(cmocka_ep
        URL https://git.cryptomilk.org/projects/cmocka.git/snapshot/cmocka-1.1.5.tar.gz

        CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}
        -DBUILD_STATIC_LIB=ON
        -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=Debug
        -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=Release
        -DUNIT_TESTING=OFF

        BUILD_COMMAND $(MAKE) cmocka-static
        INSTALL_COMMAND "")


add_library(cmocka STATIC IMPORTED GLOBAL)
ExternalProject_Get_Property(cmocka_ep binary_dir)

set_property(TARGET cmocka PROPERTY IMPORTED_LOCATION "${binary_dir}/src/libcmocka-static.a")
set_property(TARGET cmocka PROPERTY IMPORTED_LOCATION_DEBUG "${binary_dir}/src/Debug/libcmocka-static.a")
set_property(TARGET cmocka PROPERTY IMPORTED_LOCATION_RELEASE "${binary_dir}/src/Release/libcmocka-static.a")

add_dependencies(cmocka cmocka_ep)

ExternalProject_Get_Property(cmocka_ep source_dir)
set(CMOCKA_INCLUDE_DIR ${source_dir}/include GLOBAL)
