#pragma once

#include "Hazel/Core/Base.h"
#include "Hazel/Events/Event.h"

namespace Hazel
{
class HAZEL_API Layer {
public:
    explicit Layer(std::string name);
    virtual ~Layer() = default;
    Layer& operator=(Layer&&) noexcept = delete;

    virtual void onAttach() = 0;
    virtual void onDetach() = 0;
    virtual void onUpdate(float time_delta_seconds) = 0;
    virtual void onImGuiRender() = 0;
    virtual void onEvent(Event&) = 0;

    inline const std::string& getName() const { return debugName_; }

private:
    std::string debugName_{"Layer"};
};

} // namespace Hazel
