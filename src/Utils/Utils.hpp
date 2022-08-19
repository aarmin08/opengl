#pragma once

//create utils

#include <string>
#include "../Window.hpp"

class Utils {
public :
    enum LogInfo {
        TEST_ERR,
        TEST_WARNING,
        TEST_LOG,
        TEST_FATAL
    };

    static const char *vertexSrc;
    static const char *fragmentSource;

    static void PerformLoading(Window *window);

    template<typename T>
    static void Log(T t, LogInfo info);
};
