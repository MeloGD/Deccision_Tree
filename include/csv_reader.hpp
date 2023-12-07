#ifndef CSV_READER
#define CSV_READER

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <assert.h>

typedef std::pair<std::string , int > CSVFieldData;

class CSVReader {
  private:
    std::fstream file_;
    std::vector<std::string> fields_vector_;
    int columns_number_;
    int rows_number;

  public:
    CSVReader(const char* input_file);
    ~CSVReader();

    std::vector<std::string> getFields(void);
    std::vector<std::string> extractRowByIndex(const int index);
    std::vector<std::string> extractColumnByField(std::string field);
    std::vector<CSVFieldData> getDataFromField(std::vector<std::string> &field_vector);

};

#endif