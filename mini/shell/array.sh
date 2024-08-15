main() {
local cmake_args=(
              "-DCMAKE_TOOLCHAIN_FILE=platforms/toolchain-LE.cmake"
              "-DCMAKE_INSTALL_PREFIX=install/SYSTEM_NAME"
              "-DBUSGO_PROFILE=PROFILE"
              "-DBUSGO_PROFILE_PROFILE=ON"
              "-DCUSTOM_PATH=CUSTOM_PATH"
            )

mdl=xxxx
local origin_cmake_args="${cmake_args[@]}"
local current_cmake_args="${origin_cmake_args} -DMODULE_NAME=${mdl}"
current_cmake_args+=("-DMODULE_NAME=111")
current_cmake_args+=("-DMODULE_NAME=222")

echo ${current_cmake_args}
echo ${current_cmake_args[@]}
echo "======================"
current_cmake_args="${cmake_args[@]}"
echo ${current_cmake_args}
echo ${current_cmake_args[@]}

current_cmake_args=()
echo "~~~~~~~~~~~~~~~~~"
echo ${current_cmake_args}
echo ${current_cmake_args[@]}

}


main

