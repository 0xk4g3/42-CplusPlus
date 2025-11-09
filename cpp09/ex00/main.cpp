
#include "BitcoinExchange.hpp"
int main(int ac, char **av __attribute__((unused))) {

  if (ac != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }

  BitcoinExchange btc;

  btc.loadDatabase("./data.csv");
  if (!btc.isDatabaseLoaded()) {
    std::cerr << "Error: failed to load database. Exiting." << std::endl;
    return 1;
  }
  btc.processInputFile(av[1]);

  return 0;
}
