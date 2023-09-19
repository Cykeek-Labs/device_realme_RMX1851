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

# Define the folder names and their corresponding download URLs
folders=(
    "packages/apps/RealmeParts=https://github.com/Cykeek-Labs/packages_apps_realmeparts"
    "prebuilts/clang/host/linux-x86/clang-playground=https://gitlab.com/PixelOS-Devices/playgroundtc.git"
    "kernel/realme/sdm710=https://github.com/Cykeek-Labs/kernel_realme_sdm710"
)

# Loop through the folder names and URLs
for folder_info in "${folders[@]}"; do
    # Split folder_info into folder_name and download_url
    IFS="=" read -r folder_name download_url <<< "$folder_info"

    # Check if the folder exists
    if [ -d "$folder_name" ]; then
        echo "Folder '$folder_name' already exists. No need to download."
    else
        echo "Folder '$folder_name' doesn't exist. Downloading..."
        # You can replace the echo statement below with your actual download command.
        git clone $download_url $folder_name
        # Uncomment the line below and replace with your actual download command.
        # git clone "$download_url" "$folder_name"
    fi
done
