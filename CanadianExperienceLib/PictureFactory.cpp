/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 * @author Joseph Eisho
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "PropFactory.h"
#include "Adapter.h"

#include <memory>

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();

    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 620));
    picture->AddActor(sparty);

    // Create and add flag prop
    PropFactory propFactory;
    auto flag = propFactory.Create(imagesDir);

    flag->SetPosition(wxPoint(220, 380));
    picture->AddActor(flag);

    // Create machine 1
    auto machineActor = std::make_shared<Actor>(L"Machine Actor1");
    auto machine = std::make_shared<Adapter>(L"Machine 1", resourcesDir);
    machineActor->AddDrawable(machine);
    machine->Place(wxPoint(1050, 400), 0);
    machine->SetMachineNumber(1);
    machine->SetStartFrame(600);

    // Create machine 2
    auto machineActor2 = std::make_shared<Actor>(L"Machine Actor2");
    auto machine2 = std::make_shared<Adapter>(L"Machine 2", resourcesDir);
    machineActor->AddDrawable(machine2);
    machine2->Place(wxPoint(120, 400), 0);
    machine2->SetMachineNumber(2);
    machine2->SetStartFrame(600);
//
    picture->AddActor(machineActor);
    picture->AddActor(machineActor2);

    return picture;
}

