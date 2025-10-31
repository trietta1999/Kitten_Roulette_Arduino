/**
 * @brief Common service library
 */

#include "CommonService.h"
#include "CommonData.h"
#include "CommonLibrary.h"
#ifdef _WIN64
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <thread>
#include <sstream>
#else
#include <esp_random.h>
#endif

#ifdef _WIN64
void AttachConsoleWindow()
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);
}

void DebugConsoleProcess()
{
    // Debug console
    if (InputParamList.GetState())
    {
        try {
            auto inputParams = InputParamList.GetValue();

            // Test show message box
            if (inputParams.at(0) == "test")
            {
                ::MessageBox(NULL, L"Test show message box", L"Test", MB_OK);
            }

            debug_println("Process debug data done!");
        }
        catch (...)
        {
            debug_println("Process debug data fail! Try again!");
        }

        InputParamList.ResetState();
    }
}
#endif

void CommonBeep(uint16_t frequency, uint16_t duration)
{
//#ifdef _WIN64
//    ::Beep(frequency, duration);
//#else
//    HardwareBeep(frequency, duration);
//#endif
}

void InitData()
{
//#ifndef _WIN64
//    HardwareSetup();
//#endif

#ifdef _WIN64
    AttachConsoleWindow();
#endif

    // Print init data
#ifdef _WIN64

#endif
}

void CommonServiceProcess()
{
#ifdef _WIN64
    std::thread([] {
        std::string inputConsole;

        try
        {
            std::getline(std::cin, inputConsole);

            if (!inputConsole.empty())
            {
                std::istringstream iss(inputConsole);
                std::string param;
                std::vector<std::string> inputParams;

                while (iss >> param) {
                    inputParams.push_back(param);
                }

                InputParamList.SetValue(inputParams);

                DebugConsoleProcess();
            }
        }
        catch (...)
        {
            debug_println("Process debug data fail! Try again!");
        }
        }).detach();
#else
    // Read data from serial
    if (Serial.available()) {
        String read = Serial.readStringUntil('\n');
    }
#endif
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
