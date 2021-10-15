// Copyright (c) 2021 Futureblur. All rights reserved. Visit https://ice.futureblur.com for more information.

#pragma once

#include "Core/Core.h"

#define INVALID_ENUM_ARRAY_LENGTH "Enum length doesn't match array length!"

namespace Iceblur
{
    struct ICE_API Error
    {
        //Generic error types
        //Letter 'A' means it needs one or more arguments
        enum class ETypes
        {
            NONE,
            A_SINGLETON,
            A_MUST_BE_GREATER_THAN_ZERO,
            A_UNKNOWN,
            NO_PIPELINE,
            A_INVALID_PATH,
            LAST
        };

        //Letter 'A' means it needs one or more arguments
        enum class EFailed
        {
            GLAD_INIT,
            GLFW_INIT,
            WINDOW_CREATION,
            A_CAST_EVENT,
            A_COMPILE_SHADER,
            LINK_SHADER,
            LAST
        };

        using ErrorArgs = std::vector<std::string>;

        //Returns full error string of ETypes enum
        NODISCARD static std::string ToString(ETypes error, const ErrorArgs& args = { });

        //Returns full error string of EFailed enum
        NODISCARD static std::string ToString(EFailed error, const ErrorArgs& args = { });

    private:
        //Searches for argument indexes in a string and replaces them with the corresponding args.
        //Arguments are created with '%', followed by any non-negative number.
        static void ProcessArgs(std::string_view sourceStr, std::string& outResult, const ErrorArgs& args);
    };
}
