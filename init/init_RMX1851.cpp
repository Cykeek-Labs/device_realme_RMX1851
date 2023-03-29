/*
 * Copyright (C) 2020 LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <vector>
#include <sys/sysinfo.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#include "property_service.h"
#include "vendor_init.h"

using android::base::SetProperty;
using android::base::ReadFileToString;
using android::base::Trim;
using std::string;

string heapstartsize, heapgrowthlimit, heapsize,
       heapminfree, heapmaxfree, heaptargetutilization;

static const char *snet_prop_key[] = {
    "ro.boot.vbmeta.device_state",
    "ro.boot.verifiedbootstate",
    "ro.boot.flash.locked",
    "ro.boot.veritymode",
    "ro.boot.warranty_bit",
    "ro.warranty_bit",
    "ro.debuggable",
    "ro.secure",
    "ro.build.type",
    "ro.build.tags",
    "ro.build.selinux",
    NULL
};

static const char *snet_prop_value[] = {
    "locked",
    "green",
    "1",
    "enforcing",
    "0",
    "0",
    "0",
    "1",
    "user",
    "release-keys",
    "0",
    NULL
};

std::vector<std::string> ro_props_default_source_order = {
    "",
    "odm.",
    "product.",
    "system.",
    "vendor.",
};

void property_override(char const prop[], char const value[], bool add = true)
{
    prop_info *pi;
    pi = (prop_info *)__system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else if (add)
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void load_dalvik_properties() 
{
    struct sysinfo sys;

    sysinfo(&sys);
    if (sys.totalram > 3072ull * 1024 * 1024)
	{
		// from - phone-xxhdpi-6144-dalvik-heap.mk
		property_override("dalvik.vm.heapstartsize", "8m");
		property_override("dalvik.vm.heaptargetutilization", "0.75");
		property_override("dalvik.vm.heapgrowthlimit", "192m");
		property_override("dalvik.vm.heapsize", "512m");
		property_override("dalvik.vm.heapmaxfree", "8m");
		property_override("dalvik.vm.heapminfree", "512k");
	}
	else
	{
                // from - phone-xhdpi-4096-dalvik-heap.mk
		property_override("dalvik.vm.heapstartsize", "8m");
		property_override("dalvik.vm.heaptargetutilization", "0.7");
		property_override("dalvik.vm.heapgrowthlimit", "192m");
		property_override("dalvik.vm.heapsize", "512m");
		property_override("dalvik.vm.heapmaxfree", "16m");
		property_override("dalvik.vm.heapminfree", "8m");
	}
}

static void workaround_snet_properties() {
    for (int i = 0; snet_prop_key[i]; ++i)
        property_override(snet_prop_key[i], snet_prop_value[i]);
}

void vendor_load_properties()
{
    SetProperty("dalvik.vm.heaptargetutilization", heaptargetutilization);
    load_dalvik_properties();
    workaround_snet_properties();
    const auto set_ro_build_prop = [](const std::string &source,
            const std::string &prop, const std::string &value) {
        auto prop_name = "ro." + source + "build." + prop;
        property_override(prop_name.c_str(), value.c_str(), false);
    };

    const auto set_ro_product_prop = [](const std::string &source,
            const std::string &prop, const std::string &value) {
        auto prop_name = "ro.product." + source + prop;
        property_override(prop_name.c_str(), value.c_str(), false);
    };

    char const *operator_name_file = "/proc/oppoVersion/operatorName";
    std::string build_epoch, device, operator_name;
    build_epoch = "1611387308";

    if (ReadFileToString(operator_name_file, &operator_name)) {
        /* CHINA */
        if ((Trim(operator_name) == "8")) {
        device = "RMX1851CN";
           property_override("ro.build.fingerprint", "Realme/RMX1851/RMX1851:11/RKQ1.201217.002/1632356164254:user/release-keys");
           property_override("ro.build.product", device.c_str());
           property_override("ro.boot.verifiedbootstate", "green");
           for (const auto &source : ro_props_default_source_order) {
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", "RMX1851");
           }
           SetProperty("ro.separate.soft", "18637");
        /* FOREIGN */
        } else if ((Trim(operator_name) == "30")) {
        device = "RMX1851";
           property_override("ro.build.fingerprint", "Realme/RMX1851/RMX1851:11/RKQ1.201217.002/1632356164254:user/release-keys");
           property_override("ro.build.product", device.c_str());
           property_override("ro.boot.verifiedbootstate", "green");
           for (const auto &source : ro_props_default_source_order) {
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18623");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        /* FOREIGN INDIA */
        } else if ((Trim(operator_name) == "31")) {
        device = "RMX1851";
           property_override("ro.build.fingerprint", "Realme/RMX1851/RMX1851:11/RKQ1.201217.002/1632356164254:user/release-keys");
           property_override("ro.build.product", device.c_str());
           property_override("ro.boot.verifiedbootstate", "green");
           for (const auto &source : ro_props_default_source_order) {
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18621");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        /* VIETNAM_128GB */
        } else if ((Trim(operator_name) == "32")) {
        device = "RMX1853";
           property_override("ro.build.fingerprint", "Realme/RMX1851/RMX1851:11/RKQ1.201217.002/1632356164254:user/release-keys");
           property_override("ro.build.product", device.c_str());
           property_override("ro.boot.verifiedbootstate", "green");
           for (const auto &source : ro_props_default_source_order) {
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18625");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        /* VIETNAM_64GB */
        } else if ((Trim(operator_name) == "33")) {
        device = "RMX1855";
           property_override("ro.build.fingerprint", "Realme/RMX1851/RMX1851:11/RKQ1.201217.002/1632356164254:user/release-keys");
           property_override("ro.build.product", device.c_str());
           property_override("ro.boot.verifiedbootstate", "green");
           for (const auto &source : ro_props_default_source_order) {
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18627");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        /* FOREIGN EUROPE*/
        } else if ((Trim(operator_name) == "34")) {
        device = "RMX1851";
           property_override("ro.build.fingerprint", "Realme/RMX1851/RMX1851:11/RKQ1.201217.002/1632356164254:user/release-keys");
           property_override("ro.build.product", device.c_str());
           property_override("ro.boot.verifiedbootstate", "green");
           for (const auto &source : ro_props_default_source_order) {
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18633");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        } else {
        LOG(ERROR) << "Unsupported variant";
        }
    property_override("ro.apex.updatable", "false");
    }
}
