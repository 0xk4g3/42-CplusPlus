#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {

  if (this != &src) {
    this->_database = src._database;
  }
  return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {

  this->_database = src._database;
}
// To check the database

bool BitcoinExchange::isDatabaseLoaded() const { return !_database.empty(); }
void BitcoinExchange::loadDatabase(const std::string &fileName) {

  std::ifstream file(fileName.c_str());
  if (!file.is_open()) {

    std::cout << "Error: could not open database file." << std::endl;
    return;
  }
  std::string line;
  // std::getline(file, line);
  if (!std::getline(file, line)) {
    std::cerr << "Error: empty database file." << std::endl;
    file.close();
    return;
  }

  size_t start = line.find_first_not_of(" \t\r");
  size_t end = line.find_last_not_of(" \t\r");
  if (start != std::string::npos && end != std::string::npos)
    line = line.substr(start, end - start + 1);

  if (line != "date,exchange_rate") {
    std::cerr << "Error: invalid database header. Expected 'date,exchange_rate'"
              << std::endl;
    file.close();
    return;
  }
  while (std::getline(file, line)) {

    size_t commaPos = line.find(',');
    if (commaPos == std::string::npos)
      continue;

    std::string date = line.substr(0, commaPos);
    std::string priceStr = line.substr(commaPos + 1);
    float Price_int_to_float = static_cast<float>(std::atof(priceStr.c_str()));

    _database[date] = Price_int_to_float;
  }
  file.close();
}

void BitcoinExchange::processInputFile(const std::string &fileName) {
  std::ifstream file(fileName.c_str());

  if (!file.is_open()) {

    std::cout << "Error: could not open database file." << std::endl;
    return;
  }

  std::string line;
  if (!std::getline(file, line)) {
    std::cerr << "Error: empty file." << std::endl;
    file.close();
    return;
  }
  size_t start = line.find_first_not_of(" \t\r");
  size_t end = line.find_last_not_of(" \t\r");
  if (start != std::string::npos && end != std::string::npos)
    line = line.substr(start, end - start + 1);
  if (line != "date | value") {
    std::cerr << "Error: invalid header. Expected 'date | value'" << std::endl;
    file.close();
    return;
  }

  while (std::getline(file, line)) {

    std::string date;
    float value;

    if (!parseLine(line, date, value))
      continue;

    if (!isValidDate(date)) {
      std::cerr << "Error: bad input => " << date << std::endl;
      continue;
    }

    if (!isValidValue(value))
      continue;

    float exchangeRate = getExchangeRate(date);

    if (exchangeRate < 0) {
      std::cerr << "Error: no exchange rate found for date => " << date
                << std::endl;
      continue;
    }

    float result = value * exchangeRate;
    std::cout << date << " => " << value << " = " << result << std::endl;
  }
}

// Subject implementation page 6 in the cpp09

// The Date and  value
bool BitcoinExchange::parseLine(const std::string &line, std::string &date,
                                float &value) {

  size_t pipePos = line.find('|');
  if (pipePos == std::string::npos) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return false;
  }
  date = line.substr(0, pipePos);

  std::string ValueStr = line.substr(pipePos + 1);

  size_t start = date.find_first_not_of(" \t");
  size_t end = date.find_last_not_of(" \t");

  if (start != std::string::npos && end != std::string::npos)
    date = date.substr(start, end - start + 1);

  start = ValueStr.find_first_not_of(" \t");
  end = ValueStr.find_last_not_of(" \t");

  if (start != std::string::npos && end != std::string::npos)
    ValueStr = ValueStr.substr(start, end - start + 1);
  if (!isValidNumberString(ValueStr)) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return false;
  }

  value = static_cast<float>(std::atof(ValueStr.c_str()));
  return true;
}

// The date validation

bool BitcoinExchange::isValidDate(const std::string &date) {

  if (date.length() != 10)
    return false;

  if (date[4] != '-' || date[7] != '-')
    return false;
  std::string yearStr = date.substr(0, 4);
  std::string monthStr = date.substr(5, 2);
  std::string dayStr = date.substr(8, 2);

  for (size_t i = 0; i < yearStr.length(); i++)
    if (!isdigit(yearStr[i]))
      return false;

  for (size_t i = 0; i < monthStr.length(); i++)
    if (!isdigit(monthStr[i]))
      return false;

  for (size_t i = 0; i < dayStr.length(); i++)
    if (!isdigit(dayStr[i]))
      return false;

  int year = std::atoi(yearStr.c_str());
  int month = std::atoi(monthStr.c_str());
  int day = std::atoi(dayStr.c_str());

  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  return true;
}

bool BitcoinExchange::isValidNumberString(const std::string &str) {
  if (str.empty())
    return false;

  size_t i = 0;

  // Check for optional minus sign
  if (str[0] == '-' || str[0] == '+')
    i++;

  if (i >= str.length())
    return false;

  bool hasDigit = false;
  bool hasDot = false;

  while (i < str.length()) {
    if (std::isdigit(str[i])) {
      hasDigit = true;
    } else if (str[i] == '.' && !hasDot) {
      hasDot = true;
    } else {
      return false;
    }
    i++;
  }

  return hasDigit;
}
bool BitcoinExchange::isValidValue(float value) {

  if (value < 0) {
    std::cerr << "Error: not a positive number." << std::endl;
    return false;
  }

  if (value > 1000) {
    std::cerr << "Error: too large a number." << std::endl;
    return false;
  }

  return true;
}

// Get the data from the database  after the validation

float BitcoinExchange::getExchangeRate(const std::string &date) {

  std::map<std::string, float>::iterator it = _database.find(date);

  if (it != _database.end())
    return it->second;
  it = _database.lower_bound(date);

  if (it == _database.begin())
    return -0.1f;

  --it;
  return it->second;
}
BitcoinExchange::~BitcoinExchange() {}
