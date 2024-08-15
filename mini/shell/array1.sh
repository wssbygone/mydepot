#!/bin/bash

main() {
    local cmake_args=(
        "-DCMAKE_TOOLCHAIN_FILE=platforms/toolchain-LE.cmake"
        "-DCMAKE_INSTALL_PREFIX=install/SYSTEM_NAME"
        "-DBUSGO_PROFILE=PROFILE"
        "-DBUSGO_PROFILE_PROFILE=ON"
        "-DCUSTOM_PATH=CUSTOM_PATH"
    )

    mdl="xxxx"
    local origin_cmake_args="${cmake_args[@]}"
    local current_cmake_args=()
    for arg in "${cmake_args[@]}"; do
        current_cmake_args+=("$arg")
    done
    current_cmake_args+=("-DMODULE_NAME=${mdl}")

    echo "${current_cmake_args[@]}"
    echo "======================"

    for arg in "${current_cmake_args[@]}"; do
         echo "$arg"
    done

}

main

