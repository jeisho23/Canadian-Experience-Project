/**
 * @file SnowBlower.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SNOWBLOWER_H
#define CANADIANEXPERIENCE_MACHINELIB_SNOWBLOWER_H

#include "Component.h"
#include "Polygon.h"
#include "MotionSource.h"
#include "MotionSink.h"
#include "SnowFlakes.h"

#include <wx/graphics.h>
#include <random>

/**
 * Class for snowblower
 * component.
 */
class SnowBlower : public Component
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
    Polygon mSnowBlower;

    /// Rotation
    double mRotation;

    /// Rotation source for this component
    MotionSource mSource;

    /// Random numbers
    std::mt19937 mRandom;

    /// Snowflake vector
    std::vector<SnowFlakes> mSnowFlakes;

    /// Rotation sink for this component
    MotionSink mSink;

    /// Previous rotation
    double mPrevRotation = 0;

public:
    SnowBlower(std::wstring resourcesDir, int machineNumber);
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point) override;
    virtual void SetRotation(double rotation) override;
    void SetPosition(int x, int y);
    wxPoint GetPosition();
    double Random(double fmValue, double toValue);
    void EmitSnow(double rotation);

    /**
     * Gets a pointer to a motion sink object
     * @return de-referenced source object
     */
    MotionSource *GetSource() { return &mSource; }

    /**
     * Gets a pointer to a motion sink object
     * @return de-referenced sink object
     */
    MotionSink *GetSink() { return &mSink; }

    void InitialRot(double rotation);

    void Advance(double delta) override;

    void SinkUpdate(MotionSink *mSink) override;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_SNOWBLOWER_H
