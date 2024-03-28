# Copyright (C) 2009 The Android Open Source Project
# Copyright (c) 2011, The Linux Foundation. All rights reserved.
# Copyright (C) 2017-2020 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import common

def FullOTA_InstallEnd(info):
    OTA_UpdateFirmware(info)
    OTA_InstallEnd(info)
    return

def IncrementalOTA_InstallEnd(info):
    OTA_UpdateFirmware(info)
    OTA_InstallEnd(info)
    return

def OTA_UpdateFirmware(info):
    firmware_images = [
        "abl.img", "xbl.img", "xbl_config.img", "vbmeta.img", "splash.img",
        "dpAP.img", "cmnlib.img", "hyp.img", "DRIVER.img", "keymaster64.img",
        "storsec.img", "cmnlib64.img", "modem.img", "BTFM.img", "tz.img",
        "static_nvbk.img", "aop.img", "devcfg.img", "dspso.img", "dpMSA.img",
        "qupv3fw.img", "oppo_sec.img", "recovery.img"
    ]
    for image in firmware_images:
        source_path = f"install/firmware-update/{image}"
        destination_path = f"/dev/block/bootdevice/by-name/{image.split('.')[0]}"
        info.script.AppendExtra(f'package_extract_file("{source_path}", "{destination_path}");')
    info.script.AppendExtra('ui_print("Flashing RUI2-C06 firmware images");')

def AddImage(info, basename, dest):
    path = f"IMAGES/{basename}"
    if path in info.input_zip.namelist():
        data = info.input_zip.read(path)
        common.ZipWriteStr(info.output_zip, basename, data)
        info.script.Print(f"Patching {dest.split('/')[-1]} image unconditionally...")
        info.script.AppendExtra(f'package_extract_file("{basename}", "{dest}");')

def OTA_InstallEnd(info):
    AddImage(info, "dtbo.img", "/dev/block/bootdevice/by-name/dtbo")
    AddImage(info, "vbmeta.img", "/dev/block/bootdevice/by-name/vbmeta")
    return