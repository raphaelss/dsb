#include "definitions.hpp"
#include <algorithm>
#include <json/json.h>
#include <iostream>

namespace sblocks {

static std::vector<std::unique_ptr<parameter_descriptor>>
read_parameters(Json::Value &json_params) {
  std::vector<std::unique_ptr<parameter_descriptor>> vec(json_params.size());
  for (auto &obj : json_params) {
    std::cout << obj["name"] << std::endl;
  }
  return std::move(vec);
}

definition_handler::definition_handler(std::istream &in) {
  Json::Value root;
  in >> root;
  Json::Value &json_params = root["parameters"];
  if (!(json_params.isArray() && json_params.size()))
    throw -1;
  _parameter_descriptors = std::move(read_parameters(json_params));
}

}
