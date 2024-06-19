#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "StockData.h"
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <vector>
#include <string>

class DataBaseManager {
    private:
        mongocxx::instance instance{};
        mongocxx::client client;
        mongocxx::database db;
        mongocxx::collection coll;
    public:
    DataBaseManager(const std::string& dbName, const std::string& collectionName) : client{mongocxx::uri{}}, db{client[dbName]}, coll{db[collectionName]} {}

        void insertData(const std::vector<StockData>& data){
            for (const auto& entry: data){
                bsoncxx::builder::stream::document document{};
                document<<"Ticker"<<entry.ticker
                        <<"Date"<<entry.date
                        <<"Time"<<entry.time
                        <<"Open"<<entry.open
                        <<"High"<<entry.high
                        <<"Low"<<entry.low
                        <<"Close"<<entry.close
                        <<"Volume"<<entry.volume
                        <<"DateTime"<<entry.datetime;
                
                coll.insert_one(document.view());
            }
        }
};

#endif
