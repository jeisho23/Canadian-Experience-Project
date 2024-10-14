/**
 * @file SnowBlower.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "SnowBlower.h"
#include <random>

/// The images directory in resources
const std::wstring SnowBlowerImageL = L"/blowerL.png";

/// The images directory in resources
const std::wstring SnowBlowerImageR = L"/blowerR.png";

/// Width of the snow blower in pixels
const int SnowBlowerWidth = 120;

/// Height of the snow blower in pixels
const int SnowBlowerHeight = 174;

/// Y offset to the center of the snow blower in pixels
const int SnowBlowerCenterOffset = 60;

/// Average amount of snow created per rotation
const double SnowPerRotation = 1000;

/// Variance in how much snow is created
const double SnowVariancePerSecond = 100;

/// Range of the random angle snow will be thrown in
const double SnowAngleVariance = 0.1;

/// Angle range for the end of the snow machine in radians.
const double SnowMachineAngleRange = 0.25;

/// Offset to end of snow blower from middle in pixels
const double SnowBlowerOffset = 100;

/// Random variance in the snowblower offset
const double SnowBlowerOffsetVariance = 5;

/// Minimum snow particle velocity
const double SnowMinimumVelocity = 90;

/// Maximum snow particle velocity
const double SnowMaximumVelocity = 110;

/// Probability of a snow particle being a yellow snow
const double YellowSnowProbability = 0.1;

/**
 * Constructor
 * @param resourcesDir
 * @param machineNumber
 */
SnowBlower::SnowBlower(std::wstring resourcesDir, int machineNumber) :
    mResourcesDir(resourcesDir), mSink(this)
{
    if(machineNumber == 1)
        mImagesDir = mResourcesDir + SnowBlowerImageL;
    else
        mImagesDir = mResourcesDir + SnowBlowerImageR;

    mSnowBlower.SetImage(mImagesDir);
    mSnowBlower.Rectangle(-SnowBlowerWidth / 2, SnowBlowerCenterOffset, SnowBlowerWidth, SnowBlowerHeight);
    mSnowBlower.SetImage(mImagesDir);

    std::random_device rd;
    mRandom.seed(rd());
}

/**
 * Draws snowblower and snow flakes
 * @param graphics
 * @param point
 */
void SnowBlower::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point)
{
    for (auto& snowflake : mSnowFlakes)
    {
        snowflake.DrawFlake(graphics, mLocation.x , mLocation.y );
    }
    mSnowBlower.DrawPolygon(graphics,  mLocation.x, mLocation.y);
}

/**
 * Calls emit snow function to emit snow
 * @param rotation
 */
void SnowBlower::SetRotation(double rotation)
{
    double driveRot = rotation - mPrevRotation;
    mPrevRotation = rotation;

    EmitSnow(driveRot);
}

/**
 * Sets angle of snowblower
 * @param rotation
 */
void SnowBlower::InitialRot(double rotation)
{
    mSnowBlower.SetRotation(rotation);

}

/**
 * Gets position of location
 * variable
 * @return
 */
wxPoint SnowBlower::GetPosition()
{
    return mLocation;
}

/**
 * Sets x, y points
 * location variable
 * @param x
 * @param y
 */
void SnowBlower::SetPosition(int x, int y)
{
    mLocation.x = x;
    mLocation.y = y;
}

/**
 * Generate a uniform distribution random number from fmValue to toValue
 * \param fmValue Minimum value to generate
 * \param toValue Maximum value to generate
 * \return Random number
 */
double SnowBlower::Random(double fmValue, double toValue)
{
    std::uniform_real_distribution<> distribution(fmValue, toValue);
    return distribution(mRandom);
}

/**
 * Calculates number of flakes to emit
 * based ont he rotation.
 * @param rotation
 */
void SnowBlower::EmitSnow(double rotation)
{
    // Compute how much snow to generate for this amount of rotation.
    auto num = (int)(rotation * (SnowPerRotation + Random(-SnowVariancePerSecond, SnowVariancePerSecond)));

    for (int i = 0; i < num; ++i) {
        // GetRotation gets the rotation of the snow machine.
        // This code computes a vector to the emitting end of the
        // snow machine. The random value means that position is over
        // the entire end of the machine, not just a single point.
        auto angle = mSnowBlower.GetRotation() * 2 * M_PI + Random(-SnowMachineAngleRange, SnowMachineAngleRange);
        auto dx = sin(angle);
        auto dy = -cos(angle);


        auto angle1 = angle + Random(-SnowAngleVariance, SnowAngleVariance);
        auto dx1 = sin(angle1);
        auto dy1 = -cos(angle1);

        double offset = SnowBlowerOffset + Random(-SnowBlowerOffsetVariance, SnowBlowerOffsetVariance);
        double velocity = Random(SnowMinimumVelocity, SnowMaximumVelocity);

        wxPoint2DDouble snowPosition((float)(GetPosition().x+dx * offset), (float)(GetPosition().y+dy * offset));
        wxPoint2DDouble snowVelocity((float)(dx1 * velocity), (float)(dy1 * velocity));

        bool isYellowSnow = Random(0, 1) > YellowSnowProbability;

        // Create a new snowflake and add it to the vector
        SnowFlakes snowFlake(snowPosition, snowVelocity, isYellowSnow);
        mSnowFlakes.push_back(snowFlake);
    }
}

/**
 * Used to link pulley and sink
 * @param mSink
 */
void SnowBlower::SinkUpdate(MotionSink *mSink)
{
//    wxPoint2DDouble snowblowerVelocity = mSink->GetVelocity();
//    for (auto& snowflake : mSnowFlakes)
//    {
//        snowflake.UpdatePosition(snowblowerVelocity);
//    }
}

/**
 * Updates snow to move forward
 * @param deltaTime
 */
void SnowBlower::Advance(double deltaTime)
{
    for (auto& snowflake : mSnowFlakes)
    {
        snowflake.Update(deltaTime);
    }
}
