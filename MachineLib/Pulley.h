/**
 * @file Pulley.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
#define CANADIANEXPERIENCE_MACHINELIB_PULLEY_H

#include "Component.h"
#include "MotionSource.h"
#include "MotionSink.h"

/**
 * Class for pulley
 * components.
 */
class Pulley : public Component
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
    Polygon mPolygon2;

    /// Rotation speed
    double mRotation;

    /// Rotation source for this component
    MotionSource mSource;

    /// Rotation sink for this component
    MotionSink mSink;

    /// Radius size
    double mRadius;

    /// Pulley object connected to pulley
    std::shared_ptr<Pulley> mBeltConnectedPulley;

public:
    Pulley(int size);
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point) override;
    virtual void SetRotation(double rotation) override;
    void SetTime(double time);
    void SetPosition(int x, int y);
    wxPoint GetPosition();
    void SetSpeed(double speed);

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    MotionSource *GetSource() { return &mSource; }

    /// Get a pointer to the sink object
    /// @return Pointer to MotionSource object
    MotionSink *GetSink() { return &mSink; }

    void Drive(std::shared_ptr<Pulley> drivenPulley);

    virtual void SinkUpdate(MotionSink *sink) override;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
