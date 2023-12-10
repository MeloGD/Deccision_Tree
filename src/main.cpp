#include "../include/csv_reader.hpp"

int main(void) {
  std::vector<std::string> fields_vector, age_field, workclass_field,
                           education_field, marital_field, occupation_field,
                           relation_field, race_field, sex_field, 
                           country_field, income_field, person_vector;
  
  CSVReader csv("../include/adult[89].csv");
  fields_vector = csv.getFields();
  age_field = csv.extractColumnByField(fields_vector[0]);
  workclass_field = csv.extractColumnByField(fields_vector[1]);
  education_field = csv.extractColumnByField(fields_vector[2]);
  marital_field = csv.extractColumnByField(fields_vector[3]);
  occupation_field = csv.extractColumnByField(fields_vector[4]);
  relation_field = csv.extractColumnByField(fields_vector[5]);
  race_field = csv.extractColumnByField(fields_vector[6]);
  sex_field = csv.extractColumnByField(fields_vector[7]);
  country_field = csv.extractColumnByField(fields_vector[8]);
  income_field = csv.extractColumnByField(fields_vector[9]);
  
  /*
  person_vector = csv.extractRowByIndex(2);  
  std::cout << "\nPerson by index:\n";
  for (int i = 0; i < person_vector.size(); i++) {
    std::cout << person_vector[i] << " : ";
  }
  std::cout << "\n";
  */

  
  // age
  std::vector<CSVFieldData> filter_vector = csv.getDataFromField(age_field);
  
  std::cout << "\nAge field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }
  // workclass_field
  filter_vector = csv.getDataFromField(workclass_field);

  std::cout << "\nWorkclass field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }
  
  // education_field
  filter_vector = csv.getDataFromField(education_field);
  
  std::cout << "\nEducation field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }

  // marital_field
  filter_vector = csv.getDataFromField(marital_field);
  
  std::cout << "\nMarital status field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }

  // occupation_field
  filter_vector = csv.getDataFromField(occupation_field);
  
  std::cout << "\nOccupation field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }

  // relation_field
  filter_vector = csv.getDataFromField(relation_field);
  
  std::cout << "\nRelationship field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }

  // race_field
  filter_vector = csv.getDataFromField(race_field);
  
  std::cout << "\nRace field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }

  // sex_field
  filter_vector = csv.getDataFromField(sex_field);
  
  std::cout << "\nSex field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }

  // country_field
  filter_vector = csv.getDataFromField(country_field);
  
  std::cout << "\nNative country field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }

  // income_field
  filter_vector = csv.getDataFromField(income_field);
  
  std::cout <<  "\nIncome field:\n";
  for (int i = 0; i < filter_vector.size(); i++) {
    std::cout << filter_vector[i].first << ": ";
    std::cout << filter_vector[i].second << std::endl;
  }
  
}

