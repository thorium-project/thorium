// Copyright 2022 The Chromium Authors and Alex313031. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/privacy_sandbox/privacy_sandbox_prefs.h"

#include "components/pref_registry/pref_registry_syncable.h"
#include "components/prefs/pref_registry_simple.h"
#include "components/prefs/pref_service.h"

namespace prefs {

const char kPrivacySandboxApisEnabled[] = "privacy_sandbox.apis_enabled";

const char kPrivacySandboxManuallyControlled[] =
    "privacy_sandbox.manually_controlled";

const char kPrivacySandboxPreferencesReconciled[] =
    "privacy_sandbox.preferences_reconciled";

const char kPrivacySandboxPageViewed[] = "privacy_sandbox.page_viewed";

const char kPrivacySandboxFlocDataAccessibleSince[] =
    "privacy_sandbox.floc_data_accessible_since";

extern const char kPrivacySandboxFlocEnabled[] = "privacy_sandbox.floc_enabled";

extern const char kPrivacySandboxFledgeJoinBlocked[] =
    "privacy_sandbox.fledge_join_blocked";

}  // namespace prefs

namespace privacy_sandbox {

void RegisterProfilePrefs(PrefRegistrySimple* registry) {
  registry->RegisterBooleanPref(
      prefs::kPrivacySandboxApisEnabled, false,
      user_prefs::PrefRegistrySyncable::SYNCABLE_PREF);
  registry->RegisterBooleanPref(
      prefs::kPrivacySandboxManuallyControlled, false,
      user_prefs::PrefRegistrySyncable::SYNCABLE_PREF);
  registry->RegisterBooleanPref(prefs::kPrivacySandboxPreferencesReconciled,
                                false);
  registry->RegisterBooleanPref(prefs::kPrivacySandboxPageViewed, false);
  registry->RegisterTimePref(prefs::kPrivacySandboxFlocDataAccessibleSince,
                             base::Time());
  registry->RegisterBooleanPref(
      prefs::kPrivacySandboxFlocEnabled, false,
      user_prefs::PrefRegistrySyncable::SYNCABLE_PREF);
  registry->RegisterDictionaryPref(prefs::kPrivacySandboxFledgeJoinBlocked);
}

}  // namespace privacy_sandbox
