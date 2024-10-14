/**
 * @file Pulley.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "Pulley.h"

/// The images directory in resources
const std::wstring ImagesDirectory2 = L"/pulley2.png";

/**
 * Constructor
 * @param size
 */
Pulley::Pulley(int size) : mSink(this)
{
    mRadius = size;
    Circle(mRadius);
}

/**
 * Draws pulley and belt lines
 * @param graphics
 * @param point
 */
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point)
{
    Component::Draw(graphics, point + mLocation);

    if (mBeltConnectedPulley != nullptr)
    {
        wxPoint p1 = mLocation;
        wxPoint p2 = mBeltConnectedPulley->GetPosition();
        // for pulley 1
        double r1 = mRadius - 3;
        // for pulley 2
        double r2 = mBeltConnectedPulley->mRadius - 3;

        double theta = atan2(p2.y - p1.y, p2.x - p1.x);

        // phi calculation
        double phi = asin((r2 - r1) / sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));

        // beta is calculated for both sides
        double beta1 = theta + phi + M_PI / 2;
        double beta2 = theta - phi - M_PI / 2;

        // endpoints calculated
        wxPoint start1(p1.x + r1 * cos(beta1), p1.y + r1 * sin(beta1));
        wxPoint end1(p2.x + r2 * cos(beta1), p2.y + r2 * sin(beta1));

        wxPoint start2(p1.x + r1 * cos(beta2), p1.y + r1 * sin(beta2));
        wxPoint end2(p2.x + r2 * cos(beta2), p2.y + r2 * sin(beta2));

        wxPen pen(*wxBLACK, 2);
        graphics->SetPen(pen);
        graphics->StrokeLine(start1.x, start1.y, end1.x, end1.y);
        graphics->StrokeLine(start2.x, start2.y, end2.x, end2.y);
    }
}

/**
 * Sets rotation of pulley
 * @param rotation
 */
void Pulley::SetRotation(double rotation)
{
    // Upcall to ensure the polygon rotation gets set
    Component::SetRotation(rotation);

    // Set the rotation for any source
    mSource.SetRotation(rotation);

    if (mBeltConnectedPulley != nullptr)
    {
        // Set the rotation for any pulley we
        // are connected to by a belt.
        mSpeed = mRadius / mBeltConnectedPulley->mRadius;
        mBeltConnectedPulley->SetRotation(rotation * mSpeed);

    }
}

/**
 * Sets time for pulley
 * @param time
 */
void Pulley::SetTime(double time)
{
//    mRotation = time;
}

/**
 * Gets location position for pulley
 * @return
 */
wxPoint Pulley::GetPosition()
{
    return mLocation;
}

/**
 * Sets position for x, y points
 * in location variable
 * @param x
 * @param y
 */
void Pulley::SetPosition(int x, int y)
{
    mLocation.x = x;
    mLocation.y = y;
}

/**
 * Sets speed for pulley
 * @param speed
 */
void Pulley::SetSpeed(double speed)
{
    mSpeed = speed;
}

/**
 * Drives the rotation of the
 * next pulley by previous pulley
 * @param drivenPulley
 */
void Pulley::Drive(std::shared_ptr<Pulley> drivenPulley)
{
    mBeltConnectedPulley = drivenPulley;
}

/**
 * Used to link pulley and sink
 * and sets rotations of each pulley
 * @param sink
 */
void Pulley::SinkUpdate(MotionSink *sink)
{
    if (sink == &mSink)
    {
        SetRotation(mSink.GetRotation());
    }

}

