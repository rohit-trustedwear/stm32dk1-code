/**
  ******************************************************************************
  * This file is part of the TouchGFX 4.13.0 distribution.
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#ifndef ANALOGCLOCKEXTENDED_HPP
#define ANALOGCLOCKEXTENDED_HPP

#include <touchgfx/containers/clock/AnalogClock.hpp>

namespace touchgfx
{
class AnalogClockExtended : public AnalogClock
{
public:
    AnalogClockExtended();
    virtual ~AnalogClockExtended();

    void setAlpha(uint8_t alpha);
    uint8_t getAlpha() const override;

    void setMinuteZAngle(float angle);
    void setSecondsZAngle(float angle);
protected:
};
}

#endif // ANALOGCLOCKEXTENDED_HPP