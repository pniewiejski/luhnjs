#include "luhnNapi.hpp"

Napi::Boolean luhnAddon::IsValid(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
  }

  Napi::String numberToCheck = info[0].As<Napi::String>();
  bool isValid = false;
  try {
    isValid = luhn::isValid(std::string(numberToCheck));
  } catch (const std::exception& e) {
    Napi::TypeError::New(env, "Invalid argument").ThrowAsJavaScriptException();
  }

  return Napi::Boolean::New(env, isValid);
}

Napi::Number luhnAddon::GenerateCheckDigit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
  }

  Napi::String input = info[0].As<Napi::String>();
  int checkDigit = 0;
  try {
    checkDigit = luhn::generateCheckDigit(std::string(input));
  } catch (const std::exception& e) {
    Napi::TypeError::New(env, "Invalid argument").ThrowAsJavaScriptException();
  }

  return Napi::Number::New(env, checkDigit);
}

Napi::Number luhnAddon::calculateLuhnRemainder(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
  }

  Napi::String input = info[0].As<Napi::String>();
  int luhnRemainder = 0;
  try {
    luhnRemainder =
        luhn::calculateLuhnRemainderWithValidation(std::string(input));
  } catch (const std::exception& e) {
    Napi::TypeError::New(env, "Invalid argument").ThrowAsJavaScriptException();
  }

  return Napi::Number::New(env, luhnRemainder);
}

/**
 * This code is our entry-point. We receive two arguments here, the first is the
 * environment that represent an independent instance of the JavaScript runtime,
 * the second is exports, the same as module.exports in a .js file.
 * You can either add properties to the exports object passed in or create your
 * own exports object. In either case you must return the object to be used as
 * the exports for the module when you return from the Init function.
 */
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("isValid", Napi::Function::New(env, luhnAddon::IsValid));
  exports.Set("generateCheckDigit",
              Napi::Function::New(env, luhnAddon::GenerateCheckDigit));
  exports.Set("calculateLuhnRemainder",
              Napi::Function::New(env, luhnAddon::calculateLuhnRemainder));

  return exports;
}

/**
 * This code defines the entry-point for the Node addon, it tells Node where to
 * go once the library has been loaded into active memory. The first argument
 * must match the "target" in our *binding.gyp*. Using NODE_GYP_MODULE_NAME
 * ensures that the argument will be correct, as long as the module is built
 * with node-gyp (which is the usual way of building modules). The second
 * argument points to the function to invoke. The function must not be
 * namespaced.
 */
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
