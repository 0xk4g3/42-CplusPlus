#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
class BitcoinExchange {

private:
  std::map<std::string, float> _database;

public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange &operator=(const BitcoinExchange &src);
  BitcoinExchange(const BitcoinExchange &src);
  // implementation from the program side
  void loadDatabase(const std::string &fileName);
  // process the user side
  void processInputFile(const std::string &fileName);

  // handle the subject requiremnt look to the page 6
  bool parseLine(const std::string &line, std::string &date, float &value);
  bool isValidDate(const std::string &date);
  bool isValidValue(float value);
  bool isValidNumberString(const std::string &str);
  // get the data from the database
  float getExchangeRate(const std::string &date);
  bool isDatabaseLoaded() const;
};
#endif
