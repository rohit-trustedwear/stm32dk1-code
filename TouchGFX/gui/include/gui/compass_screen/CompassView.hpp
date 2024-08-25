#pragma once

#include <gui_generated/compass_screen/CompassViewBase.hpp>
#include <gui/compass_screen/CompassPresenter.hpp>

#include <array>
#include <cmath>
#include <string>

class CompassView : public CompassViewBase
{
public:
    struct Wheel
    {
        bool update(float dt); //!< returns \c true if UI requires an update

        float _angle_rad = 0.0f;
        float _velocity = 0.0f;
        bool _dirty = false;
    };
    CompassView();
    virtual ~CompassView() {}
    void setupScreen();


protected:

    void handleDragEvent(const touchgfx::DragEvent& event);
    void handleGestureEvent(const touchgfx::GestureEvent& event);
    void handleTickEvent() override;
    void updateView();

private:
    int32_t computeRangeIndex(float angle_deg);
    Wheel _wheel;
    uint32_t _tick;
    const float wheel_center_x = 240.0f;
    const float wheel_center_y = 240.0f;
    const float rad_to_deg = 57.2958f;
    static constexpr float update_epsilon = 0.001f;
    static constexpr float wheel_friction = 0.95f;
    std::array<std::string, 8> angle_names{ "N", "NE", "E", "SE", "S", "SW", "W", "NW"};
    uint32_t tick;
    int32_t angle_verbose_deg;
    int32_t angle_range_index;
    bool initialized;
    float last_drag_delta;
};
