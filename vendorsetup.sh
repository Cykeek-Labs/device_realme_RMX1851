#!/bin/bash

banner(){
clear
echo "================================"
echo "|                                                           |"
echo "|   Realme 3 Pro Setup Script  |"
echo "|       Branch: Arrow13          |"
echo "|    Maintained By: R15Hi      |"
echo "|                              |"
echo "================================"
}

banner

# Kernel
banner
echo "Cloning Kernel, clang, and Realmeparts..."
git clone --depth=1 https://gitlab.com/PixelOS-Devices/playgroundtc.git prebuilts/clang/host/linux-x86/clang-playground
git clone --depth=1 https://github.com/Cykeek-Labs/kernel_realme_sdm710 kernel/realme/sdm710
git clone https://github.com/Cykeek-Labs/packages_apps_realmeparts packages/apps/RealmeParts

# vendor
banner
echo "Cloning vendor and Rui1fw..."
git clone https://github.com/Cykeek-Labs/android_vendor_RMX1851 -b 13 vendor/realme/RMX1851
if [ ! -d "vendor/realme/RMX1851-fw" ]; then
    pushd vendor/realme
    mkdir RMX1851-fw
    cd RMX1851-fw
    wget https://github.com/R15Hi/Dump/releases/download/scripts/Rui1fw.zip
    unzip Rui1fw.zip
    rm -rf Rui1fw.zip
    popd
fi