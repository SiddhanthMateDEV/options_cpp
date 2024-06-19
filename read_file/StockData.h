#ifndef STOCKDATA_H
#define STOCKDATA_H

#include <string>

struct StockData{
    std::string date;
    std::string time;
    double open;
    double high;
    double low;
    double close;
    long int volume;
    long int open_interest;
    std::string option_type;
    std::string segment;
    double strike;
    std::string expiry;
};

#endif
