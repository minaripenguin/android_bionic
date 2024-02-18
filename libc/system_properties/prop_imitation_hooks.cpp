/*
 * Copyright (C) 2023 Paranoid Android
 * Copyright (C) 2024 the risingOS Android Project 
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>
#include <string.h>

#include "system_properties/prop_imitation_hooks.h"

#define GMS_UNSTABLE "com.google.android.gms.unstable"

#define PROP_SECURITY_PATCH "ro.build.version.security_patch"
#define PROP_PIH_SECURITY_PATCH "persist.sys.pihooks.security_patch"

#define PROP_FIRST_API_LEVEL "ro.product.first_api_level"
#define PROP_PIH_FIRST_API_LEVEL "persist.sys.pihooks.first_api_level"

#define PROP_PRODUCT_NAME "ro.product.name"
#define PROP_PIH_PRODUCT_NAME "persist.sys.pihooks.product_name"

#define PROP_PRODUCT_MODEL "ro.product.model"
#define PROP_PIH_PRODUCT_MODEL "persist.sys.pihooks.product_model"

#define PROP_BUILD_ID "ro.build.id"
#define PROP_PIH_BUILD_ID "persist.sys.pihooks.build_id"

#define PROP_PRODUCT_DEVICE "ro.product.device"
#define PROP_PIH_PRODUCT_DEVICE "persist.sys.pihooks.product_device"

#define PROP_MANUFACTURER "ro.product.manufacturer"
#define PROP_PIH_MANUFACTURER "persist.sys.pihooks.manufacturer"

#define PROP_BRAND "ro.product.brand"
#define PROP_PIH_BRAND "persist.sys.pihooks.brand"

#define PROP_BUILD_FINGERPRINT "ro.build.fingerprint"
#define PROP_PIH_BUILD_FINGERPRINT "persist.sys.pihooks.build_fingerprint"

#define PROP_BUILD_DESC "ro.build.description"
#define PROP_PIH_BUILD_DESC "persist.sys.pihooks.build_description"

#define PROP_BUILD_TAGS "ro.build.tags"
#define PROP_PIH_BUILD_TAGS "persist.sys.pihooks.build_tags"

#define PROP_BUILD_TYPE "ro.build.type"
#define PROP_PIH_BUILD_TYPE "persist.sys.pihooks.build_type"

struct PropertyMapping {
    const char* buildProperty;
    const char* pihProperty;
};

const PropertyMapping propMappings[] = {
    {PROP_SECURITY_PATCH, PROP_PIH_SECURITY_PATCH},
    {PROP_FIRST_API_LEVEL, PROP_PIH_FIRST_API_LEVEL},
    {PROP_PRODUCT_NAME, PROP_PIH_PRODUCT_NAME},
    {PROP_PRODUCT_MODEL, PROP_PIH_PRODUCT_MODEL},
    {PROP_BUILD_ID, PROP_PIH_BUILD_ID},
    {PROP_PRODUCT_DEVICE, PROP_PIH_PRODUCT_DEVICE},
    {PROP_MANUFACTURER, PROP_PIH_MANUFACTURER},
    {PROP_BRAND, PROP_PIH_BRAND},
    {PROP_BUILD_FINGERPRINT, PROP_PIH_BUILD_FINGERPRINT},
    {PROP_BUILD_DESC, PROP_PIH_BUILD_DESC},
    {PROP_BUILD_TAGS, PROP_PIH_BUILD_TAGS},
    {PROP_BUILD_TYPE, PROP_PIH_BUILD_TYPE}
};

void PropImitationHooks::OnFind(const char **name) {
  if (getprogname() == nullptr || strcmp(getprogname(), GMS_UNSTABLE) != 0) {
    return;
  }
  PIH_LOG("name is %s\n", *name);
  for (const auto& mapping : propMappings) {
    if (strcmp(*name, mapping.buildProperty) == 0) {
      *name = mapping.pihProperty;
      PIH_LOG("name changed to %s\n", *name);
    }
  }
}
