/**
 * @file MachineSystem.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H

#include <wx/gdicmn.h>
#include <wx/graphics.h>
#include <memory>

#include "IMachineSystem.h"
class Machine;

/**
 * Class to choose machine
 * to draw.
 */
class MachineSystem : public IMachineSystem
{
private:
    /// Machine Pointer
    std::shared_ptr<Machine> mMachine;

    /// Machine frame number
    int mMachineFrame = 0;

    /// Time
    double mTime = 0;

    /// Framerate
    double mFrameRate = 30;

    /// Frame
    int mFrame = 0;

    /// Position point
    wxPoint mPosition;

    /// The resources directory
    std::wstring mResourcesDir;

    /// Machine location
    wxPoint mLocation;
public:
    /// Copy constructor (disabled)
    MachineSystem(const MachineSystem &) = delete;

    /// Assignment operator
    void operator=(const MachineSystem &) = delete;

    ~MachineSystem() override = default;

    MachineSystem(std::wstring resourcesDir);

    void SetLocation(wxPoint location) override;
    wxPoint GetLocation() override;
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;
    void SetMachineFrame(int frame) override;
    void SetFrameRate(double rate) override;
    void SetMachineNumber(int machine) override;
    int GetMachineNumber() override;
    double GetMachineTime() override;
    void SetFlag(int flag) override;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H
