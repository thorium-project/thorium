// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/obsolete_system/obsolete_system.h"

#include "base/linux_util.h"
#include "base/strings/string_util.h"
#include "chrome/grit/chromium_strings.h"
#include "ui/base/l10n/l10n_util.h"

const char kLinuxObsoleteUrl[] =
    "https://support.google.com/chrome/?p=unsupported_linux";

// This list contains the 2 most recently obsoleted distros according to
// `kLinuxObsoleteUrl`.
const char* const kObsoleteDistros[] = {
    "Ubuntu 12.04", "Ubuntu 14.04", "Debian 7",           "Debian 8",
    "Fedora 30",    "Fedora 31",    "openSUSE Leap 15.0", "openSUSE Leap 15.1",
};

// static
bool ObsoleteSystem::IsObsoleteNowOrSoon() {
  auto distro = base::GetLinuxDistro();
  for (const char* obsolete : kObsoleteDistros) {
    if (base::StartsWith(distro, obsolete))
      return true;
  }
  return false;
}

// static
std::u16string ObsoleteSystem::LocalizedObsoleteString() {
  return l10n_util::GetStringUTF16(IDS_LINUX_OBSOLETE);
}

// static
bool ObsoleteSystem::IsEndOfTheLine() {
  return false;
}

// static
const char* ObsoleteSystem::GetLinkURL() {
  return kLinuxObsoleteUrl;
}
