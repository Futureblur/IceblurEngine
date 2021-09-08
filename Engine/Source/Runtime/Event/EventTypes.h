// Copyright (c) 2021 Futureblur. All rights reserved. Visit https://ice.futureblur.com for more information.

#pragma once

#include "IEvent.h"

namespace Iceblur
{
    //---------------EVENT TYPE DECLARATIONS---------------//

    struct MousePositionEvent : IEvent
    {
        ICE_EVENT_DECL(MousePositionEvent)

        MousePositionEvent(float x, float y)
                : m_X(x), m_Y(y)
        {
        }

        ~MousePositionEvent() override = default;

        NODISCARD inline float GetX() const
        {
            return m_X;
        }

        NODISCARD inline float GetY() const
        {
            return m_Y;
        }

    private:
        float m_X = 0;
        float m_Y = 0;
    };

    //---------------DEBUG OVERLOADS---------------//

    inline std::ostream& operator<<(std::ostream& os, const MousePositionEvent& event)
    {
        os << event.DebugString() << "X: " << event.GetX() << " Y: " << event.GetY();
        return os;
    }
}
