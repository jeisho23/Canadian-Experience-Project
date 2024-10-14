/**
 * @file Motor.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MOTOR_H
#define CANADIANEXPERIENCE_MACHINELIB_MOTOR_H

#include "Component.h"
#include "Polygon.h"
#include "MotionSource.h"

/**
 * Class for motor.
 */
class Motor : public Component
{
private:
    /// Speed
    double mSpeed;

    /// Position
    wxPoint mLocation;

    /// The resources directory
    std::wstring mResourcesDir;

    /// Path to the images directory
    std::wstring mImagesDir;

    /// Polygon
    Polygon mPolygon;

    /// Polygon
    Polygon mPolygon1;

    /// Rotation variable
    double mRotation;

    /// Rotation source for this component
    MotionSource mSource;


public:
    Motor(std::wstring resourcesDir);
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point) override;
    void SetTime(double time);
    void SetPosition(int x, int y);
    wxPoint GetPosition();
    void SetSpeed(double speed);

    /**
     * Get a pointer to the source object
     * @return Pointer to RotationSource object
     */
    MotionSource *GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MOTOR_H
