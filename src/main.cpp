#include "../include/csv_reader.hpp"

int main(void) {
  std::vector<std::string> fields_vector, age_field, workclass_vector,
                           education_vector, marital_vector, occupation_vector,
                           relation_vector, race_vector, sex_vector, 
                           country_vector, inconme_vector;
  
  CSVReader csv("../include/adult[89].csv");
  fields_vector = csv.getFields();
  age_field = csv.extractColumnByField(fields_vector[0]);
  //person_vector = csv.extractRowByIndex(1);  

  std::vector<CSVFieldData> couting_vector = csv.getDataFromField(age_field);
  
  for (int i = 0; i < couting_vector.size(); i++) {
    std::cout << couting_vector[i].first << ":";
    std::cout << couting_vector[i].second << std::endl;
  }


  //csv.~CSVReader();
  
}

