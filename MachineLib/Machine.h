/**
 * @file Machine.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_H

class MachineSystem;
class Component;

/**
 * Machine class to set
 * and draw machine.
 */
class Machine
{
private:
    /// Location point
    wxPoint mLocation;

    /// Machine number
    int mMachineNumber;

    /// Frame
    int mFrame;

    /// Flag
    int mFlag;

    /// Time
    int mTime;

    /// Machine system Pointer
    std::shared_ptr<MachineSystem> mMachineSystem;

    /// Vector of components to be added to machine
    std::vector<std::shared_ptr<Component>> mComponents;

public:
    /**
     * Constructor
     * @param machineNumber The machine number to set
     */
    Machine(int machineNumber) : mMachineNumber(machineNumber) {}

    /// Copy constructor (disabled)
    Machine(const Machine &) = delete;

    /// Assignment operator
    void operator=(const Machine &) = delete;

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics);

    void SetTime(double time);

    void AddComponent(std::shared_ptr<Component> component);

    void Reset();

    void Advance(double delta);

    /**
     * Gets machine number
     * @return
     */
    int GetMachineNumber() const {return mMachineNumber;}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
