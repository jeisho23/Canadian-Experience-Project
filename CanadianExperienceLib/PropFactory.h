/**
 * @file PropFactory.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PROPFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PROPFACTORY_H

class Actor;

/**
 * Factory class for flag prop
 */
class PropFactory
{
private:

public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PROPFACTORY_H
