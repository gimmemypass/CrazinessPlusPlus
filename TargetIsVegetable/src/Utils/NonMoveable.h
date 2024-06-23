#pragma once

struct NonMoveable
{
    NonMoveable() = default;
    NonMoveable& operator=(NonMoveable&&) = delete;
    NonMoveable(NonMoveable&&) = delete;
};
