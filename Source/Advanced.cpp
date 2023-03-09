#include "Advanced.h"
#include "ConfigStructs.h"
#include "InputUtil.h"
#include "Memory.h"
#include "ProtobufReader.h"

#include <CSGO/Constants/ConVarNames.h>
#include <CSGO/ConVar.h>
#include <RetSpoof/RetSpoofGadgets.h>
#include <CSGO/PODs/ConVar.h>

struct AdvancedConfig
{
    bool recoilCrosshair;
} advancedConfig;

Advanced::Advanced(OtherInterfaces otherInterfaces) : interfaces{ otherInterfaces }
{

}

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

static void from_json(const json& j, AdvancedConfig& m)
{
    read(j, "Recoil Crosshair", m.recoilCrosshair);
}

static void to_json(json& j, const AdvancedConfig& o)
{
    const AdvancedConfig dummy;

    WRITE("Recoil Crosshair", recoilCrosshair);
}

json Advanced::toJson() noexcept
{
    json j;
    to_json(j, advancedConfig);
    return j;
}

void Advanced::fromJson(const json& j) noexcept
{
    from_json(j, advancedConfig);
}

void Advanced::resetConfig() noexcept
{
    advancedConfig = {};
}