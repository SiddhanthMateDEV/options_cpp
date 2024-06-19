#ifndef CSVREADER_H
#define CSVREADER_H

#include "StockData.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>


class CSVReader {
    private:
        std::string filename;
    public:
        CSVReader(const std::string& filename) : filename(filename) {}
        std::vector<StockData> read_data(){
            std::vector<StockData> data;
            std::ifstream file(filename);

            // char comma; use this only if std::ws does not work below

            if (!file.is_open){
                throw std::runtime_error("Could not open the file");
            }
            
            std::string line;
            //skipping the header file here
            
            getline(file,line);
            
            while (getline(file,line)){
                std::stringstream ss(line);
            
                std::string cell;
                
                StockData row_entry;

                std::getline(ss,row_entry.date,",");
                std::getline(ss,row_entry.time,",");
                    
                ss>>row_entry.open>>std::ws;
                ss>>row_entry.high>>std::ws;
                ss>>row_entry.low>>std::ws;
                ss>>row_entry.close>>std::ws;
                ss>>row_entry.volume>>std::ws;
                
                std::getline(ss,row_entry.ticker,",");
                std::getline(ss,row_entry.datetime,",");
                
                data.push_back(row_entry);
            
            }
            file.close();
            return data;
        }
}

#endif

