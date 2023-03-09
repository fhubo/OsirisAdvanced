#pragma once

#include <Interfaces/OtherInterfaces.h>

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