/**
 * @file Machine.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "Machine.h"
#include "MachineSystem.h"
#include "Component.h"

/**
 * Adds Component to machine
 * @param component
 */
void Machine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetMachine(this);
}

/**
 * Draws the components of the machine
 * @param graphics
 */
void Machine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{

    for (auto component : mComponents)
    {
        component->Draw(graphics, mLocation);
    }
}

/**
 * Sets time for all components
 * @param time
 */
void Machine::SetTime(double time)
{
    mTime = time;
    for (auto component : mComponents)
    {
        component->SetTime(time);
    }
}

/**
 * Resets time
 */
void Machine::Reset()
{
    mTime = 0;
}

/**
 * Advances the snow
 * @param delta
 */
void Machine::Advance(double delta)
{
    for(auto component : mComponents)
    {
        component->Advance(delta);
    }
}


