#include <iostream>
#include <vector>
#include <thread>
#include <filesystem>

#include "DataBaseManager.h"
#include "CSVReader.h"


namespace fs = std::filesystem;

void file_processing(const std::string& filePath, DataBaseManager& dbManager){
    try {
        CSVReader reader(filePath);
        auto data = reader.read_data();
        dbManager.insertData(data);
    } catch (const std::exception& e){
        std::cerr<<"Failed to process data"<<filePath<<": "<<e.what()<<std::endl;
    }

}

void logMessage(const std::string& messagge){
    std::ofstream logFile("csv_reading_log_file.log")
}

int main(){
    const std::string directoryPath = "enter directory path of files (.csv format) to be put in the database";
    const std::string dbName = "StockDatabase";
    const std::string collectionName = "StockCollection";

    DataBaseManager dbManager(dbName,collectionName);

    std::vector<std::thread> threads;

    for (const auto& entry : fs::directory_iterator(directoryPath)){
        try {
            if (entry.path().extension() == ".csv"){
                threads.emplace_back(file_processing,entry.path().string(),std::ref(dbManager));
            }
        } catch (const std::exception& e){
            std::cerr<<"Error in processing file: "<<
        }
    }


    
}









