//
// Created by Vinayak Regmi on 22/04/2025.
//

#ifndef ENGINELOG_H
#define ENGINELOG_H
#include <string>

namespace DebugLog {

class EngineLog {
private:
    static std::string log;
    static std::string warningLog;
    static std::string errorLog;
    static int errorFlag;
public:
    static void print(std::string message);
    static void printError(std::string message);
    static void printWarning(std::string message);
    static void clearLog();
    static void clearWarningLog();
    static void clearErrorLog();
    static void setFlag(int flag);

    static std::string getEngineLog();
    static std::string getEngineWarningLog();
    static std::string getEngineErrorLog();
    static int getErrorFlag();
};

} // DebugLog

#endif //ENGINELOG_H
