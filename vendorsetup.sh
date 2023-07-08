#!/bin/bash

banner(){
clear
echo "================================"
echo "|                              |"
echo "|   Realme 3 Pro Setup Script  |"
echo "|       Branch: Lineage        |"
echo "|    Maintained By: Cykeek     |"
echo "|                              |"
echo "================================"
}

banner 2>1

# Kernel
banner 2>1
echo "Cloning Kernel..."
git clone https://gitlab.com/PixelOS-Devices/playgroundtc.git prebuilts/clang/host/linux-x86/clang-playground
git clone https://github.com/Cykeek-Labs/kernel_realme_sdm710 -b close_A13 kernel/realme/sdm710

# RealmeParts
banner 2>1
echo "Cloning RealmeParts..."
git clone https://github.com/Cykeek-Labs/packages_apps_realmeparts packages/apps/RealmeParts
