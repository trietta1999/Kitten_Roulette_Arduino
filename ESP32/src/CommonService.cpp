/**
 * @brief Common service library
 */

#include "CommonService.h"
#include "CommonData.h"
#include "CommonLibrary.h"
#ifdef _WIN64
#include <Windows.h>
#include <iostream>
#include <thread>
#include <sstream>
#else
#include <esp_random.h>
#endif

std::string inputConsole;
std::vector<std::string> listInputParam;

#ifdef _WIN64
void AttachConsoleWindow()
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);
}
#endif

void DebugConsoleProcess()
{
    // Debug console
    if (listInputParam.size())
    {
        try {
            // Test
            if (listInputParam.at(0) == "test")
            {
                debug_println("Test OK");
            }

            debug_println("Process debug data done!");
        }
        catch (...)
        {
            debug_println("Process debug data fail! Try again!");
        }

        listInputParam.clear();
    }
}

void CommonBeep(uint16_t frequency, uint16_t duration)
{
    //#ifdef _WIN64
    //    ::Beep(frequency, duration);
    //#else
    //    HardwareBeep(frequency, duration);
    //#endif
}

void InitService()
{
#ifdef _WIN64
    AttachConsoleWindow();
#endif

#ifdef _WIN64
    std::thread([] {
        std::string input;

        while (true)
        {
            std::getline(std::cin, input);

            if (!input.empty())
            {
                inputConsole = input;
            }
        }
        }).detach();
#endif
}

void ServiceProcess()
{
#ifndef _WIN64
    if (Serial.available()) {
        String read = Serial.readStringUntil('\n');
        inputConsole = read.c_str();
    }
#endif

    try
    {
        if (!inputConsole.empty())
        {
            std::istringstream iss(inputConsole);
            std::string param;

            while (iss >> param) {
                listInputParam.push_back(param);
            }

            DebugConsoleProcess();
        }
    }
    catch (...)
    {
        debug_println("Process debug data fail! Try again!");
    }

    inputConsole.clear();
}

JsonDocument ProcessRequest(uint32_t msg, JsonDocument jsonDocIn)
{
    JsonDocument jsonDoc;
    return jsonDoc;
}

JsonDocument CommonSendRequest(uint32_t msg)
{
    JsonDocument jsonDoc;
    return jsonDoc;
}

JsonDocument CommonSendRequestWithData(uint32_t msg, JsonDocument jsonValue)
{
    JsonDocument jsonDoc;
    return jsonDoc;
}
