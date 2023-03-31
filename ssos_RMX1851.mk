#
# Copyright (C) 2019 The octaviOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

$(call inherit-product, device/realme/RMX1851/device.mk)

# Inherit some common ssos stuff.
$(call inherit-product, vendor/ssos/config/common_full_phone.mk)

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := ssos_RMX1851
PRODUCT_DEVICE := RMX1851
PRODUCT_BRAND := Realme
PRODUCT_MODEL := realme 3 Pro
PRODUCT_MANUFACTURER := Realme

# BootAnimation Resolution
TARGET_BOOT_ANIMATION_RES := 1080

TARGET_FACE_UNLOCK_SUPPORTED := true

BUILD_FINGERPRINT := "google/raven/raven:12/SQ1D.220205.003/8069835:user/release-keys"

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="RMX1851-user 10 QKQ1.190918.001 1611387308 release-keys" \
    PRODUCT_NAME="RMX1851"

PRODUCT_GMS_CLIENTID_BASE := android-oppo
