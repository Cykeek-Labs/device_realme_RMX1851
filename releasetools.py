# Copyright (C) 2009 The Android Open Source Project
# Copyright (c) 2011, The Linux Foundation. All rights reserved.
# Copyright (C) 2017-2018 The LineageOS Project
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

import hashlib
import common
import re

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
        "abl.img", "xbl.img", "xbl_config.img", "dpAP.img", "dtbo.img", 
        "tz.img", "modem.img", "DRIVER.img", "qupv3fw.img", "oppo_sec.img", 
        "vbmeta.img", "splash.img", "devcfg.img", "dpMSA.img", "BTFM.img", 
        "static_nvbk.img", "dspso.img", "cmnlib.img", "cmnlib64.img", "aop.img", 
        "storsec.img", "keymaster64.img", "hyp.img", "recovery.img"
    ]
    
    info.script.AppendExtra('ui_print("Flashing RUI1-C18 firmware images");')
    
    for image in firmware_images:
        partition_name = image.split('.')[0]
        info.script.AppendExtra('package_extract_file("install/firmware-update/{}", "/dev/block/bootdevice/by-name/{}");'.format(image, partition_name))

def IncrementalOTA_Assertions(info):
    AddTrustZoneAssertion(info, info.target_zip)
    return

def OTA_InstallEnd(info):
    AddImage(info, "vbmeta.img", "/dev/block/bootdevice/by-name/vbmeta")
    AddImage(info, "dtbo.img", "/dev/block/bootdevice/by-name/dtbo")
    return

def AddImage(info, basename, dest):
    path = "IMAGES/" + basename
    if path in info.input_zip.namelist():
        data = info.input_zip.read(path)
        common.ZipWriteStr(info.output_zip, basename, data)
        info.script.Print("Patching {} image unconditionally...".format(dest.split('/')[-1]))
        info.script.AppendExtra('package_extract_file("%s", "%s");' % (basename, dest))

def AddTrustZoneAssertion(info, input_zip):
    android_info = info.input_zip.read("OTA/android-info.txt")
    m = re.search(r'require\s+version-trustzone\s*=\s*(\S+)', android_info)
    if m:
        versions = m.group(1).split('|')
        if len(versions) and '*' not in versions:
            cmd = 'assert(RMX1851.verify_trustzone(' + ','.join(['"%s"' % tz for tz in versions]) + ') == "1");'
            info.script.AppendExtra(cmd)
    return