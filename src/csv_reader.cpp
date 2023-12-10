#include "../include/csv_reader.hpp"

CSVReader::CSVReader(const char* input_file) {
  file_.open(input_file , std::ios::in);
}

CSVReader::~CSVReader() { 
  file_.close();
}

std::vector<std::string> 
CSVReader::getFields(void) {
  std::string line , word; 
  
  getline(file_ , line);
  std::stringstream line_buffer(line);

  while (getline(line_buffer , word , ';')) {
    fields_vector_.push_back(word);
  }
  return fields_vector_;
}

// hay que añadir la limpieza de flags y el set a la linea 0 en esta
// funcion y corregirla. Ej: Funcion anterior --> 78 y 79
std::vector<std::string> 
CSVReader::extractRowByIndex(const int index) {
  std::vector<std::string> row_vector;
  std::string line , value; 
  std::stringstream line_buffer;
  int count = 0;

  while (getline(file_ , line)) {
    count++;
    if (index == 0 || index >= columns_number_ + 2) {
      std::cout << "\nIndex is out of boundaries\n";
      file_.clear();
      file_.seekg(0);
      break;
    } else if (index == count) {
        line_buffer << line;
        while (getline(line_buffer, value, ';')) {
          row_vector.push_back(value);
        }
        line_buffer.str("");
        line_buffer.clear();  
        rows_number = row_vector.size();
        file_.clear();
        file_.seekg(0);
        return row_vector;
      }
  }
  file_.clear();
  file_.seekg(0);
}

std::vector<std::string> 
CSVReader::extractColumnByField(std::string field) {
  std::vector<std::string> column_vector;
  std::vector<std::string> auxiliar_vector;
  std::string line , value; 
  std::stringstream line_buffer;
  int index;
  
  for (int i = 0; i < fields_vector_.size(); i++) {
    if (fields_vector_[i] == field) {
      index = i;
    }
  }
  
  while (getline(file_ , line)) {
    if (line[0] != '#') {
      line_buffer << line;
      while (getline(line_buffer, value, ';')) {
        auxiliar_vector.push_back(value);
      }
      for (int i = 0; i < fields_vector_.size(); i++) {
        if (i == index) {
          column_vector.push_back(auxiliar_vector[i]);
        }
      }
      line_buffer.str("");
      line_buffer.clear();
      auxiliar_vector.clear();
    }
  }
  file_.clear();
  file_.seekg(0);
  columns_number_ = column_vector.size();
  return column_vector;  
}

std::vector<CSVFieldData>
CSVReader::getDataFromField(std::vector<std::string> &field_vector) {
  
  CSVFieldData key_value_pair;
  std::vector<CSVFieldData> key_value_vector;
  std::string value;

  assert (!field_vector.empty());

  key_value_pair.first = field_vector[0];
  key_value_pair.second = 1;
  key_value_vector.push_back(key_value_pair);
  bool value_found = false;
    
  for (int i = 1; i < field_vector.size(); i++) {
    value = field_vector[i];
    for (int i = 0; i < key_value_vector.size(); i++) {
        if (key_value_vector[i].first == value) {
          key_value_vector[i].second += 1;
          value_found = true;
          break;
        } else {
          value_found = false;
        }
    }

    if (!value_found) {
      key_value_pair.first = field_vector[i];
      key_value_pair.second = 1;
      key_value_vector.push_back(key_value_pair);
    }
    
  }
  return key_value_vector;
}

