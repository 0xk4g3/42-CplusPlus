

#include <iostream>
#include <cstring>
#include <fstream>


std::string replaceLine(const std::string &line, const std::string &s1 , const std::string &s2 ){
  

  std::string result = line;
  std::size_t pos = 0 ;
  while((pos  = result.find(s1 , pos) )!= std::string::npos){

        std::string before = result.substr(0, pos);
        std::string after = result.substr(pos + s1.length());
        result = before + s2 + after;
        pos += s2.length();
  }
  return result;
}

int main(int ac , char **av){

            if(ac != 4){
              std::cout << "Usage: ./replace filename s1 s2" <<  std::endl;
              return 1;
            }
    
            std::ifstream inFile(av[1]);

            if(!inFile.is_open()){
               std::cout << "Error: Could not open input file" << std::endl;
               return 1;
            }

           std::string outFileName = std::string(av[1])  +  ".replace";

           std::ofstream outFile(outFileName.data());
           if(!outFile.is_open()){
             std::cout << "ERROR: Could not create ouput file" << std::endl;
             inFile.close();
             return 1;
           }
           std::string s1 = av[2];
           std::string s2 = av[3];

            if (s1.empty()) {
                   std::cout << "Error: cannot replace empty string" << std::endl;
                   return 1;
              }
           std::string line;
           while (std::getline(inFile , line)) {
                std::string modifiedLine = replaceLine(line,s1 , s2);
                outFile << modifiedLine << std::endl;
           }

           inFile.close();
           outFile.close();

            


            return 0;

   

}