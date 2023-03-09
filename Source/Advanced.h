#pragma once

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

    void menuBarItem() noexcept;
    void tabItem() noexcept;
    void drawGUI(bool contentOnly) noexcept;

    void recoilCrosshair() noexcept;

private:
    OtherInterfaces interfaces;
};