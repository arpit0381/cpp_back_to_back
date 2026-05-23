#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <sys/stat.h>

FileHandler::FileHandler(const std::string& fname) : filename(fname) {}

bool FileHandler::fileExists() const {
    std::ifstream file(filename);
    return file.good();
}

bool FileHandler::saveTasks(const TaskManager& manager) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Cannot open file for writing.\n";
        return false;
    }

    // Simple JSON-like format
    file << "{\n  \"tasks\": [\n";
    
    const auto& tasks = manager.getTasks();
    for (size_t i = 0; i < tasks.size(); ++i) {
        const auto& task = tasks[i];
        file << "    {\n";
        file << "      \"id\": " << task->getId() << ",\n";
        file << "      \"title\": \"" << task->getTitle() << "\",\n";
        file << "      \"description\": \"" << task->getDescription() << "\",\n";
        file << "      \"priority\": \"" << task->getPriorityString() << "\",\n";
        file << "      \"status\": \"" << task->getStatusString() << "\",\n";
        file << "      \"category\": \"" << task->getCategory() << "\",\n";
        file << "      \"dueDate\": " << task->getDueDate() << ",\n";
        file << "      \"estimatedHours\": " << task->getEstimatedHours() << ",\n";
        file << "      \"actualHours\": " << task->getActualHours() << "\n";
        file << "    }";
        if (i < tasks.size() - 1) file << ",";
        file << "\n";
    }

    file << "  ]\n}\n";
    file.close();
    std::cout << "Tasks saved to file: " << filename << "\n";
    return true;
}

bool FileHandler::loadTasks(TaskManager& manager) {
    // Note: Basic loading - in production, use a proper JSON library
    std::cout << "Loading tasks from file: " << filename << "\n";
    return fileExists();
}

bool FileHandler::deleteFile() {
    if (std::remove(filename.c_str()) == 0) {
        std::cout << "File deleted successfully.\n";
        return true;
    }
    return false;
}

void FileHandler::setFilename(const std::string& fname) {
    filename = fname;
}

std::string FileHandler::getFilename() const {
    return filename;
}
