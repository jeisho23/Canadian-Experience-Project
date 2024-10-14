/**
 * @file SnowFlakes.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "SnowFlakes.h"


/**
 * Initializes pos and velocity of the flakes.
 * @param position
 * @param velocity
 * @param isYellowSnow
 */
SnowFlakes::SnowFlakes(wxPoint2DDouble position, wxPoint2DDouble velocity, bool isYellowSnow)
    : mPosition(position), mVelocity(velocity), mIsYellowSnow(isYellowSnow) {}


/**
 * Updates pos of flakes based on velocity
 * and gravity.
 * @param delta
 */
void SnowFlakes::Update(double delta) {
    const float Gravity = 15;
    mVelocity.m_y += Gravity * delta;
    mPosition.m_x += mVelocity.m_x * delta;
    mPosition.m_y += mVelocity.m_y * delta;
}

/**
 * Draws individual snowflakes
 * @param graphics
 * @param x
 * @param y
 */
void SnowFlakes::DrawFlake(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) {
    wxBrush brush(*wxWHITE);
    if (mIsYellowSnow) {
        brush.SetColour(*wxYELLOW);
    }
    graphics->SetBrush(brush);
    graphics->SetPen(*wxWHITE);
    graphics->DrawRectangle( (int)mPosition.m_x ,  (int)mPosition.m_y, 2, 2);
}

/**
 * Check if snow has fallen off
 * @param screenHeight
 * @return
 */
bool SnowFlakes::IsOffScreen(int screenHeight) {
    return mPosition.m_y > screenHeight;
}

/**
 * Updates snow position
 * @param velocity
 */
void SnowFlakes::UpdatePosition(const wxPoint2DDouble& velocity) {
    mPosition += velocity;
}