/**
 * @file MotionSource.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "MotionSource.h"
#include "pulley.h"

/**
 * Constructor
 */
MotionSource::MotionSource()
{

}

/**
 * Sets rotation for all sinks
 * @param rotation
 */
void MotionSource::SetRotation(double rotation)
{
    // iterate over vector of sinks and set the rotation in each of those sinks.
    for (auto sink : mSinks)
    {
        sink->SetRotation(rotation);
    }
}

/**
 * Adds sink to sink vector
 * @param sinks
 */
void MotionSource::AddSink(MotionSink* sinks)
{
    mSinks.push_back(sinks);
    sinks->SetSource(this);
}