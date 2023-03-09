#pragma once

#include "JsonForward.h"

#include <InventoryChanger/InventoryChanger.h>
#include <Platform/Macros/IsPlatform.h>
#include <Interfaces/ClientInterfaces.h>
#include <Interfaces/OtherInterfaces.h>
#include <RetSpoof/FunctionInvoker.h>
#include <CSGO/Functions.h>
#include <MemorySearch/BytePatternLiteral.h>
#include <MemorySearch/PatternFinder.h>

class Advanced
{
public:
    Advanced(OtherInterfaces interfaces);

    // GUI
    void menuBarItem() noexcept;
    void tabItem() noexcept;
    void drawGUI(bool contentOnly) noexcept;

    // Config
    json toJson() noexcept;
    void fromJson(const json& j) noexcept;
    void resetConfig() noexcept;

    void recoilCrosshair() noexcept;

private:
    OtherInterfaces interfaces;
};