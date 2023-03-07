#include "Advanced.h"
#include <CSGO/Constants/ConVarNames.h>
#include <CSGO/ConVar.h>
#include <RetSpoof/RetSpoofGadgets.h>

struct AdvancedConfig
{
    bool recoilCrosshair;
} advancedConfig;

void Advanced::recoilCrosshair() noexcept
{
    static auto recoilCrosshairVar{ interfaces.getCvar().findVar(csgo::cl_crosshair_recoil) };

    recoilCrosshairVar->onChangeCallbacks.size = 0;
    csgo::ConVar::from(retSpoofGadgets->client, recoilCrosshairVar).setValue(advancedConfig.recoilCrosshair);
}

static bool windowOpen = false;

void Advanced::menuBarItem() noexcept
{
    if (ImGui::MenuItem("Advanced"))
    {
        windowOpen = true;
        ImGui::SetWindowFocus("Advanced");
        ImGui::SetWindowPos("Advanced", { 100.0f, 100.0f });
    }
}

void Advanced::tabItem() noexcept
{
    if (ImGui::BeginTabItem("Advanced"))
    {
        drawGUI(true);
        ImGui::EndTabItem();
    }
}

void Advanced::drawGUI(bool contentOnly) noexcept
{
    if (!contentOnly)
    {
        if (!windowOpen)
            return;
        ImGui::SetNextWindowSize({ 580.0f, 0.0f });
        ImGui::Begin("Advanced", &windowOpen, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize
            | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    }

    // content start

    ImGui::Checkbox("Recoil Crosshair", &advancedConfig.recoilCrosshair);

    // content end

    if (!contentOnly)
        ImGui::End();
}