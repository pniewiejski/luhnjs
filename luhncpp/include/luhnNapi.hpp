#pragma once
#include <napi.h>
#include "luhn.hpp"

namespace luhnAddon {
Napi::Boolean IsValid(const Napi::CallbackInfo& info);
Napi::Number GenerateCheckDigit(const Napi::CallbackInfo& info);
Napi::Number calculateLuhnRemainder(const Napi::CallbackInfo& info);
Napi::Object Init(Napi::Env env, Napi::Object exports);
}  // namespace luhnAddon