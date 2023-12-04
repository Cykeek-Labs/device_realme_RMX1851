#
# Copyright (C) 2021-2022 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit some common Lineage stuff
TARGET_BOOT_ANIMATION_RES := 1080
TARGET_NOT_USES_BLUR := true

$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Inherit from RMX1851 device
$(call inherit-product, $(LOCAL_PATH)/device.mk)

# Viper
$(call inherit-product, packages/apps/ViPER4AndroidFX/config.mk)

PRODUCT_BRAND := realme
PRODUCT_DEVICE := RMX1851
PRODUCT_MANUFACTURER := realme
PRODUCT_NAME := lineage_RMX1851
PRODUCT_MODEL := RMX1851

PRODUCT_SYSTEM_NAME := RMX1851
PRODUCT_SYSTEM_DEVICE := RMX1851

PRODUCT_GMS_CLIENTID_BASE := android-oppo

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="RMX1851-user 11 RKQ1.201217.002 1623376276806 release-keys" \
    TARGET_DEVICE=RMX1851 \
    TARGET_PRODUCT=RMX1851

# Set BUILD_FINGERPRINT variable to be picked up by both system and vendor build.prop
BUILD_FINGERPRINT := realme/RMX1851/RMX1851:11/RKQ1.201217.002/1623376276806:user/release-keys

PRODUCT_PRODUCT_PROPERTIES += \
    ro.build.fingerprint=$(BUILD_FINGERPRINT)
