#!/bin/bash

banner(){
clear
echo "================================"
echo "|                              |"
echo "|   Realme 3 Pro Setup Script  |"
echo "|       Branch: cr14           |"
echo "|    Maintained By: R15Hi      |"
echo "|                              |"
echo "================================"
}

banner 2>1

# Kernel
banner 2>1
echo "Cloning Kernel..."
git clone --depth=1 https://github.com/kdrag0n/proton-clang.git prebuilts/clang/host/linux-x86/clang-proton
git clone --depth=1 https://github.com/Cykeek-Labs/kernel_realme_sdm710-RUI2 kernel/realme/sdm710

# vendor
banner 2>1
echo "Cloning vendor..."
git clone https://github.com/Cykeek-Labs/android_vendor_RMX1851 vendor/realme/RMX1851
