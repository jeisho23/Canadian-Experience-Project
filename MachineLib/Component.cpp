/**
 * @file Component.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "Component.h"
#include "Machine.h"
#include "Polygon.h"

/**
 * Sets the machine for the components
 * @param machine
 */
void Component::SetMachine(Machine *machine)
{
    mMachine = machine;
}

/**
 * Draws the components
 * @param graphics
 * @param point
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point)
{
    DrawPolygon(graphics, point.x + mLocation.x, point.y + mLocation.y);
}

/**
 * Updates frame
 * @param frame
 */
void Component::UpdateFrame(int frame)
{

}

/**
 * Sets time
 * @param time
 */
void Component::SetTime(double time)
{
    // mTime = time;
}
