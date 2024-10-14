/**
 * @file Adapter.h
 * @author Joseph Eisho
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ADAPTER_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ADAPTER_H


#include "Drawable.h"
#include <memory>
#include <string>

class IMachineSystem;

/**
* Adapter class to adapt machine to
* Canadian Experience
*/
class Adapter : public Drawable
{
private:
    /// Associated machine
    std::shared_ptr<IMachineSystem> mMachine;

    /// Timeline which controls machine
    Timeline* mTimeline = nullptr;

    ///  Which frame to start playing at
    int mStartFrame = 0;

public:
    /** Default constructor disabled */
    Adapter() = delete;

    /** Copy constructor disabled */
    Adapter(const Adapter &) = delete;

    /** Assignment operator disabled */
    void operator=(const Adapter &) = delete;

    /**
    * Constructor
    * @param name of string
    * @param resourcesDir path of factory
    */
    Adapter(std::wstring name, std::wstring resourcesDir);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void SetMachineNumber(int machine);
    void SetTimeline(Timeline* timeline) override;

    /**
    * Hit test
    * @param pos of point
    * @return false
    */
    bool HitTest(wxPoint pos) override { return false; }

    /**
	 * Sets frame when machine starts to play
	 * @param startFrame starting frame
	 */
    void SetStartFrame(int startFrame) { mStartFrame = startFrame; }
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ADAPTER_H
