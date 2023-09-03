#
# Copyright (C) 2019 The evolutionOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

$(call inherit-product, device/realme/RMX1851/device.mk)

# Inherit some common voltageOS stuff.
$(call inherit-product, vendor/voltage/config/common_full_phone.mk)

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := voltage_RMX1851
PRODUCT_DEVICE := RMX1851
PRODUCT_BRAND := Realme
PRODUCT_MODEL := Realme 3 Pro
PRODUCT_MANUFACTURER := Realme

# disable/enable blur support, default is false
TARGET_ENABLE_BLUR := true

# Bootanimation
TARGET_BOOT_ANIMATION_RES := 1080

# Quick tap feature
TARGET_SUPPORTS_QUICK_TAP := true

# Face Unlock
TARGET_FACE_UNLOCK_SUPPORTED := true

BUILD_FINGERPRINT := Realme/RMX1851/RMX1851:11/RKQ1.201217.002/1632356164254:user/release-keys

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="RMX1851-user 11 RKQ1.201217.002 1632356164254 release-keys" \
    PRODUCT_NAME="RMX1851"

PRODUCT_GMS_CLIENTID_BASE := android-oppo

# VoltageOS
VOLTAGE_BUILD_TYPE := OFFICIAL
