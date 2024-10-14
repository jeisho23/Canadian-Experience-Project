/**
 * @file Shape.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
#define CANADIANEXPERIENCE_MACHINELIB_SHAPE_H

#include "Component.h"
#include "MotionSink.h"

/**
 * An class for an image or a polygon.
 */
class Shape : public Component
{
private:
    /// Polygon object
    Polygon mPolygon;

    /// Location point
    wxPoint mLocation;

    /// Rotation sink for this component
    MotionSink mSink;

public:
    Shape();

    /// Copy constructor (disabled)
    Shape(const Shape &) = delete;

    /// Assignment operator
    void operator=(const Shape &) = delete;

    /**
     * Gets y point of
     * location variable
     * @return
     */
    int GetY() {return mLocation.y;}

    /**
     * Sets location of location
     * variable
     * @param x
     * @param y
     */
    virtual void SetLocation(int x, int y) override {Component::SetLocation(x , y); mLocation.x = x, mLocation.y = y;}

    /**
     * Gets motion sink object
     * @return de-referenced sink object
     */
    MotionSink *GetSink() { return &mSink; }

    /**
     * Used to link pulley and sink
     * @param sink
     */
    virtual void SinkUpdate(MotionSink sink) ;
};

#endif //CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
