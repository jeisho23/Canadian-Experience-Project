/**
 * @file PropFactory.cpp
 * @author Joseph Eisho
 */

#include "pch.h"
#include "PropFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"

/**
 * Factory to creat flag prop.
 * @param imagesDir Directory that contains the image of this prop.
 * @return Pointer to an actor object.
 */
std::shared_ptr<Actor> PropFactory::Create(std::wstring imagesDir)
{
    std::shared_ptr<Actor> prop = std::make_shared<Actor>(L"Flag");

    auto flag = std::make_shared<ImageDrawable>(L"US", imagesDir +L"/us_flag.png");
    flag->SetCenter(wxPoint(74, 200));
    flag->SetPosition(wxPoint(0, -100));
    prop->SetRoot(flag);

    prop->AddDrawable(flag);

    return prop;
}
