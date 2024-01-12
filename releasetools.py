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
    info.script.AppendExtra('ui_print("Flashing RUI2-C06 firmware images");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/abl.img", "/dev/block/bootdevice/by-name/abl");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/xbl.img", "/dev/block/bootdevice/by-name/xbl");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/xbl_config.img", "/dev/block/bootdevice/by-name/xbl_config");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/vbmeta.img", "/dev/block/bootdevice/by-name/vbmeta");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/splash.img", "/dev/block/bootdevice/by-name/splash");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/dpAP.img", "/dev/block/bootdevice/by-name/apdp");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/cmnlib.img", "/dev/block/bootdevice/by-name/cmnlib");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/hyp.img", "/dev/block/bootdevice/by-name/hyp");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/DRIVER.img", "/dev/block/bootdevice/by-name/DRIVER");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/keymaster64.img", "/dev/block/bootdevice/by-name/keymaster");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/storsec.img", "/dev/block/bootdevice/by-name/storsec");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/cmnlib64.img", "/dev/block/bootdevice/by-name/cmnlib64");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/modem.img", "/dev/block/bootdevice/by-name/modem");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/BTFM.img", "/dev/block/bootdevice/by-name/bluetooth");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/tz.img", "/dev/block/bootdevice/by-name/tz");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/static_nvbk.img", "/dev/block/bootdevice/by-name/oppostanvbk");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/aop.img", "/dev/block/bootdevice/by-name/aop");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/devcfg.img", "/dev/block/bootdevice/by-name/devcfg");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/dspso.img", "/dev/block/bootdevice/by-name/dsp");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/dpMSA.img", "/dev/block/bootdevice/by-name/msadp");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/qupv3fw.img", "/dev/block/bootdevice/by-name/qupfw");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/oppo_sec.img", "/dev/block/bootdevice/by-name/oppo_sec");')
    info.script.AppendExtra('package_extract_file("install/firmware-update/recovery.img", "/dev/block/bootdevice/by-name/recovery");')


def AddImage(info, basename, dest):
  path = "IMAGES/" + basename
  if path not in info.input_zip.namelist():
    return

  data = info.input_zip.read(path)
  common.ZipWriteStr(info.output_zip, basename, data)
  info.script.Print("Patching {} image unconditionally...".format(dest.split('/')[-1]))
  info.script.AppendExtra('package_extract_file("%s", "%s");' % (basename, dest))

def OTA_InstallEnd(info):
  AddImage(info, "dtbo.img", "/dev/block/bootdevice/by-name/dtbo")
  AddImage(info, "vbmeta.img", "/dev/block/bootdevice/by-name/vbmeta")
  return
