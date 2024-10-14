/**
 * @file Adapter.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "Adapter.h"
#include "Timeline.h"

#include <memory>
#include <string>
#include <machine-api.h>
#include <wx/graphics.h>
using namespace std;

/**
* Constructor
* @param name of string
* @param resourcesDir path of factory
*/
Adapter::Adapter(std::wstring name, std::wstring resourcesDir) : Drawable(name)
{
    MachineSystemFactory factory(resourcesDir);
    mMachine = factory.CreateMachineSystem();
}

/**
 * Draw this actor
 * @param graphics The Graphics object we are drawing on
 */
void Adapter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(.65, .65);
    mMachine->SetLocation(wxPoint(0, 0));
    mMachine->DrawMachine(graphics);
    graphics->PopState();
    mMachine->SetMachineFrame(mTimeline->GetCurrentFrame());
}

/**
* Sets timeline
* @param timeline to be set
*/
void Adapter::SetTimeline(Timeline* timeline)
{
    Drawable::SetTimeline(timeline);

    mTimeline = timeline;
}


/**
* Sets machine number
* @param machine number of machine to be set
*/
void Adapter::SetMachineNumber(int machine) { mMachine->SetMachineNumber(machine); }

