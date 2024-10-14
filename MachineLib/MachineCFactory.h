/**
 * @file MachineCFactory.h
 *
 * @author Anik Momtaz
 * @author Joseph Eisho
 *
 * Factory for creating Machine #1
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINECFACTORY_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINECFACTORY_H

#include <memory>
#include <string>

class Machine;
class Shape;

/**
 * Factory for creating Machine #1
 */
class MachineCFactory {
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// Path to the images directory
    std::wstring mImagesDir;

    std::shared_ptr<Shape> CreatePost(int x, int y, int wid, int hit, wxColor color);

public:
    MachineCFactory(std::wstring resourcesDir);

    std::shared_ptr<Machine> Create();

//    std::shared_ptr<Shape> CreatePost(int x, int y, int wid, int hit, wxColor color);

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINECFACTORY_H
