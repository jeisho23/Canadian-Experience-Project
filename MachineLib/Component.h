/**
 * @file Component.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#define CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H

#include "Polygon.h"
class MotionSink;
class Machine;

/**
 * Component class derived from polygon.
 */
class Component : public cse335::Polygon
{
private:
    /// Time
    double mTime;

    /// Location point
    wxPoint mLocation;

    /// Check for pullies
    bool mMultiplePullies;

    /// Machine Pointer
    Machine *mMachine;

public:
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point);
    void UpdateFrame(int frame);
    virtual void SetTime(double time);
    void SetMachine(Machine *machine);

    /**
     * Used to link pulley and sink
     * @param sink
     */
    virtual void SinkUpdate(MotionSink *sink){}

    /**
     * Advances the snow
     * @param delta
     */
    virtual void Advance(double delta) {}

    /**
     * Sets location of component.
     * @param x
     * @param y
     */
    virtual void SetLocation(int x, int y) {mLocation.x = x, mLocation.y = y;}

    /**
     * Gets location of component
     * @return
     */
    wxPoint GetLocation() {return mLocation;}
};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
