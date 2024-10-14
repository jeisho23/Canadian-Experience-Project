/**
 * @file SnowFlakes.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SNOWFLAKES_H
#define CANADIANEXPERIENCE_MACHINELIB_SNOWFLAKES_H

#include <wx/graphics.h>
#include <random>

/**
 * Snow class to create and
 * support snow functionality.
 */
class SnowFlakes
{
private:
    /// Position of snow
    wxPoint2DDouble mPosition;

    /// Velocity of snow
    wxPoint2DDouble mVelocity;

    /// Boolean to check yellow snow
    bool mIsYellowSnow;

public:
    SnowFlakes(wxPoint2DDouble position, wxPoint2DDouble velocity, bool isYellowSnow);

    void Update(double delta);

    void DrawFlake(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    bool IsOffScreen(int screenHeight);

    void UpdatePosition(const wxPoint2DDouble& velocity);

};

#endif //CANADIANEXPERIENCE_MACHINELIB_SNOWFLAKES_H
