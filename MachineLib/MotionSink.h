/**
 * @file MotionSink.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MOTIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_MOTIONSINK_H
class MotionSource;
class Component;

/**
 * Retrieves info from source and
 * transfers to source.
 */
class MotionSink
{
private:
    /// Rotation variable
    double mRotation = 0;

    /// Speed variable
    int mSpeed = 1;

    /// Source pointer object
    MotionSource* mSource;

    /// Component pointer object
    Component *mComponent;

public:
    MotionSink(Component *component);

    /// Copy constructor (disabled)
    MotionSink(const MotionSink &) = delete;

    /// Assignment operator (disabled)
    void operator=(const MotionSink &) = delete;

    void SetRotation(double rotation);

    virtual void SinkUpdate(MotionSink sink);

    /**
     * Sets source object
     * @param motionSource
     */
    void SetSource(MotionSource* motionSource) {mSource = motionSource;}

    /**
     * Gets rotation variable
     * @return
     */
    double GetRotation() { return mRotation; }

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MOTIONSINK_H
