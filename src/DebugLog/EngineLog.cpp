//
// Created by Vinayak Regmi on 22/04/2025.
//

#include "EngineLog.h"

namespace DebugLog {
    std::string EngineLog::log;
    std::string EngineLog::warningLog;
    std::string EngineLog::errorLog;
    int EngineLog::errorFlag = 0;

    std::string EngineLog::getEngineLog() {
        return  log;
    }

    std::string EngineLog::getEngineWarningLog() {
        return warningLog;
    }

    std::string EngineLog::getEngineErrorLog() {
        return errorLog;
    }

    void EngineLog::print(std::string message) {
        log+=message+"\n";
    }

    void EngineLog::printError(std::string message) {
        errorLog+=message+"\n";
    }

    void EngineLog::printWarning(std::string message) {
        warningLog+=message+"\n";
    }

    void EngineLog::clearLog() {
        log="";
    }

    void EngineLog::clearWarningLog() {
        warningLog="";
    }

    void EngineLog::clearErrorLog() {
        errorLog="";
    }

    void EngineLog::setFlag(int flag) {
        errorFlag=flag;
    }

    int EngineLog::getErrorFlag() {
        return errorFlag;
    }
} // DebugLog
