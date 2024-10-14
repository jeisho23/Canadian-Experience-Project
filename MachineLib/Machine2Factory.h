/**
 * @file Machine2Factory.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE2FACTORY_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE2FACTORY_H

#include <memory>
#include <string>

class Machine;
class Shape;

/**
 * Machine 2 Factory
 * class.
 */
class Machine2Factory
{
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// Path to the images directory
    std::wstring mImagesDir;

    std::shared_ptr<Shape> CreatePost(int x, int y, int wid, int hit, wxColor color);

public:
    Machine2Factory(std::wstring resourcesDir);

    std::shared_ptr<Machine> Create();

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE2FACTORY_H
