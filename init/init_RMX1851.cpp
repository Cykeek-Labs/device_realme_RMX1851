/*
 * Copyright (C) 2020 LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <vector>

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

void vendor_load_properties()
{
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
    std::string build_epoch, build_fingerprint, device, operator_name;
    build_epoch = "1611387308";

    if (ReadFileToString(operator_name_file, &operator_name)) {
        /* CHINA */
        if ((Trim(operator_name) == "8")) {
        device = "RMX1851CN";
        build_fingerprint = "Realme/RMX1851/" + device + ":10/QKQ1.190918.001/" + build_epoch + ":user/release-keys";
           property_override("ro.build.product", device.c_str());
           for (const auto &source : ro_props_default_source_order) {
               set_ro_build_prop(source, "fingerprint", build_fingerprint.c_str());
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", "RMX1851");
           }
           SetProperty("ro.separate.soft", "18637");
        /* FOREIGN */
        } else if ((Trim(operator_name) == "30")) {
        device = "RMX1851";
        build_fingerprint = "Realme/RMX1851/" + device + ":10/QKQ1.190918.001/" + build_epoch + ":user/release-keys";
           property_override("ro.build.product", device.c_str());
           for (const auto &source : ro_props_default_source_order) {
               set_ro_build_prop(source, "fingerprint", build_fingerprint.c_str());
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18623");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        /* FOREIGN INDIA */
        } else if ((Trim(operator_name) == "31")) {
        device = "RMX1851";
        build_fingerprint = "Realme/RMX1851/" + device + ":10/QKQ1.190918.001/" + build_epoch + ":user/release-keys";
           property_override("ro.build.product", device.c_str());
           for (const auto &source : ro_props_default_source_order) {
               set_ro_build_prop(source, "fingerprint", build_fingerprint.c_str());
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18621");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        /* VIETNAM_128GB */
        } else if ((Trim(operator_name) == "32")) {
        device = "RMX1853";
        build_fingerprint = "Realme/RMX1853/" + device + ":10/QKQ1.190918.001/" + build_epoch + ":user/release-keys";
           property_override("ro.build.description", "RMX1853-user 10 QKQ1.190918.001 1597290604 release-keys");
           property_override("ro.build.product", device.c_str());
           for (const auto &source : ro_props_default_source_order) {
               set_ro_build_prop(source, "fingerprint", build_fingerprint.c_str());
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18625");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        /* VIETNAM_64GB */
        } else if ((Trim(operator_name) == "33")) {
        device = "RMX1855";
        build_fingerprint = "Realme/RMX1855/" + device + ":10/QKQ1.190918.001/" + build_epoch + ":user/release-keys";
           property_override("ro.build.description", "RMX1855-user 10 QKQ1.190918.001 1597290604 release-keys");
           property_override("ro.build.product", device.c_str());
           for (const auto &source : ro_props_default_source_order) {
               set_ro_build_prop(source, "fingerprint", build_fingerprint.c_str());
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18627");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        /* FOREIGN EUROPE*/
        } else if ((Trim(operator_name) == "34")) {
        device = "RMX1851";
        build_fingerprint = "Realme/RMX1851/" + device + ":10/QKQ1.190918.001/" + build_epoch + ":user/release-keys";
           property_override("ro.build.product", device.c_str());
           for (const auto &source : ro_props_default_source_order) {
               set_ro_build_prop(source, "fingerprint", build_fingerprint.c_str());
               set_ro_product_prop(source, "device", device.c_str());
               set_ro_product_prop(source, "model", device.c_str());
           }
           SetProperty("ro.separate.soft", "18633");
           SetProperty("ro.com.google.clientidbase.cr", "android-oppo");
           SetProperty("ro.com.google.clientidbase.ms", "android-oppo");
        } else {
        LOG(ERROR) << "Unsupported variant";
        }
    }
}
