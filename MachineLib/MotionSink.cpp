/**
 * @file MotionSink.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "MotionSink.h"
#include "Component.h"

/**
 * Constructor
 * @param component
 */
MotionSink::MotionSink(Component *component) : mComponent(component)
{

}

/**
 * Sets rotation for all components
 * @param rotation
 */
void MotionSink::SetRotation(double rotation)
{
    mRotation = rotation * mSpeed;
    mComponent->SetRotation(mRotation);
}

/**
 * Used to link pulley and sink
 * @param sink
 */
void MotionSink::SinkUpdate(MotionSink sink)
{

}
