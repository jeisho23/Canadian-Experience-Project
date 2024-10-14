/**
 * @file MotionSource.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MOTIONSOURCE_H
#define CANADIANEXPERIENCE_MACHINELIB_MOTIONSOURCE_H

class Pulley;
class MotionSink;

/**
 * Gets information from motor
 * and transfers to sink.
 */
class MotionSource
{
private:

    /// Vector of components to be added to machine
    std::vector<MotionSink*> mSinks;

public:
    MotionSource();

    /// Copy constructor (disabled)
    MotionSource(const MotionSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const MotionSource &) = delete;

    void SetRotation(double rotation);

    void AddSink(MotionSink* sinks);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_MOTIONSOURCE_H
