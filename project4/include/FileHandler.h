#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "TaskManager.h"
#include <string>
#include <memory>

class FileHandler {
private:
    static constexpr const char* DEFAULT_FILENAME = "tasks.json";
    std::string filename;

public:
    FileHandler(const std::string& fname = DEFAULT_FILENAME);

    // File operations
    bool saveTasks(const TaskManager& manager);
    bool loadTasks(TaskManager& manager);
    bool fileExists() const;
    bool deleteFile();

    // Utility
    void setFilename(const std::string& fname);
    std::string getFilename() const;
};

#endif // FILEHANDLER_H
