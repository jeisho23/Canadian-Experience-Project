/**
 * @file MachineSystem.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "MachineSystem.h"
#include "Machine.h"
#include "MachineCFactory.h"
#include "Machine2Factory.h"
#include <memory>

/**
 * Constructor
 * @param resourcesDir
 */
MachineSystem::MachineSystem(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
    SetMachineNumber(1);
}

/**
 * Sets location at location
 * variable
 * @param location
 */
void MachineSystem::SetLocation(wxPoint location)
{
     mLocation = location;
}

/**
 * Gets location of location
 * variable
 * @return wxPoint
 */
wxPoint MachineSystem::GetLocation()
{
//    return mLocation;
    return wxPoint();
}

/**
 * Draw the machine
 * @param graphics Graphics context to draw on.
 */
void MachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    // This will put the machine where it is supposed to be drawn
    graphics->PushState();
    graphics->Translate(mLocation.x, mLocation.y);

    mMachine->DrawMachine(graphics);

    graphics->PopState();
}

/**
 * Sets machine frame
 * @param frame frame number
 */
void MachineSystem::SetMachineFrame(int frame)
{
    if (frame < mFrame)
    {
        mMachine->Reset();
        mFrame = frame;
        mMachine->Advance(1.0 / mFrameRate);
        mMachine->SetTime(mFrame / mFrameRate);
        return;
    }

    while (mFrame < frame) {
        mFrame++;
        mMachine->Advance(1.0 / mFrameRate);
        mMachine->SetTime(mFrame / mFrameRate);
    }
}

/**
 * Sets frame rate
 * @param frame rate number
 */
void MachineSystem::SetFrameRate(double frame)
{
    mFrameRate = frame;
}

/**
 * Set the machine number, creating the appropriate machine
 * @param machine Machine number
 */
void MachineSystem::SetMachineNumber(int machine)
{
    if(machine == 1)
    {
        MachineCFactory factory(mResourcesDir);
        mMachine = factory.Create();
//        mMachine = std::make_shared<Machine>(1);
    }
    else
    {
        Machine2Factory factory(mResourcesDir);
        mMachine = factory.Create();
//        mMachine = std::make_shared<Machine>(2);
    }
}

/**
 * Get Machine number to be displayed
 * @return Machine number
 */
int MachineSystem::GetMachineNumber()
{
    return mMachine->GetMachineNumber();
}

/**
 * Gets the machine time
 * @return 0
 */
double MachineSystem::GetMachineTime()
{
    return 0;
}

/**
 * Sets flag
 * @param flag flag to be checked
 */
void MachineSystem::SetFlag(int flag)
{

}
