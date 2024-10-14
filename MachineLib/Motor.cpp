/**
 * @file Motor.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "Motor.h"


/// The images directory in resources
const std::wstring ImagesDirectory = L"/motor3.png";

/// The images directory in resources
const std::wstring ImagesDirectory1 = L"/shaft.png";

/// Size
const double Size = 80;

/**
 * Constructor
 * @param resourcesDir
 */
Motor::Motor(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
    mPolygon.Rectangle(-80/2, 0, 80, 80);
    mPolygon.SetImage(mImagesDir);

    mImagesDir = mResourcesDir + ImagesDirectory1;
    mPolygon1.CenteredSquare(15);
    mPolygon1.SetImage(mImagesDir);
}

/**
 * Draws the motor and the shaft
 * @param graphics
 * @param point
 */
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point)
{
    // Motor
    mPolygon.DrawPolygon(graphics, point.x + mLocation.x, point.y + mLocation.y);

    // Shaft
    mPolygon1.SetRotation(mRotation);
    mPolygon1.DrawPolygon(graphics, point.x + mLocation.x, point.y + 2 * mLocation.y);
}

/**
 * Sets time for shaft
 * @param time
 */
void Motor::SetTime(double time)
{
    mRotation = time * mSpeed;
    mSource.SetRotation(mRotation);
}

/**
 * Gets position of location
 * variable
 * @return location point
 */
wxPoint Motor::GetPosition()
{
    return mLocation;
}

/**
 * Sets position of motor and shaft
 * @param x
 * @param y
 */
void Motor::SetPosition(int x, int y)
{
    mLocation.x = x;
    mLocation.y = y;
}

/**
 * Sets speed of shaft
 * @param speed
 */
void Motor::SetSpeed(double speed)
{
    mSpeed = speed;
}