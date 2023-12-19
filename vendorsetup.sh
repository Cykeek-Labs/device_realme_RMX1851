#!/bin/bash

banner(){
clear
echo "================================"
echo "|                              |"
echo "|   Realme 3 Pro Setup Script  |"
echo "|       Branch: CR14           |"
echo "|    Maintained By: R15Hi      |"
echo "|                              |"
echo "================================"
}

banner 2>1

# Define the folder names and their corresponding download URLs
repos=(
    "https://github.com/Cykeek-Labs/android_vendor_RMX1851.git cr14 vendor/realme/RMX1851"
    "https://github.com/Cykeek-Labs/kernel_realme_sdm710-RUI2.git cr14 kernel/realme/sdm710"
    "https://github.com/kdrag0n/proton-clang.git master prebuilts/clang/host/linux-x86/clang-proton"
)

# Loop through the repos and clone them with the specified branch and folder
for repo_info in "${repos[@]}"; do
    # Split repo_info into repo_url, branch, and folder
    IFS=" " read -r repo_url branch folder <<< "$repo_info"

    # Check if the repository folder exists
    if [ -d "$folder" ]; then
        echo "Repository '$folder' already exists. No need to clone."
    else
        echo "Repository '$folder' doesn't exist. Cloning..."
        # Execute the clone command with branch information and target folder
        if [ "$folder" == "prebuilts/clang/host/linux-x86/clang-proton" ]; then
            git clone -b $branch --depth=1 $repo_url $folder
        else
            git clone -b $branch $repo_url $folder
        fi
    fi
done

