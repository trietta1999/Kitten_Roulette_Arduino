/**
 * @brief Common data type
 */

#ifndef _COMMON_DATATYPE_H
#define _COMMON_DATATYPE_H

#include <cstdint>
#include <tuple>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include "ArduinoJson-v7.4.1.h"

#define STR(a) #a

#ifdef _WIN64
#include <Windows.h>
#define MILLISEC_GET ::GetTickCount64()
#define debug_println(a) std::cout << std::string(a) << "\n"
#else
#include <Arduino.h>
#define debug_println(a) Serial.println(std::string(a).c_str())
#define MILLISEC_GET millis()
#endif

#pragma endregion

#endif // !_COMMON_DATATYPE_H
