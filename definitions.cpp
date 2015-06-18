#include "definitions.hpp"
#include <algorithm>
#include <string>
#include <json/json.h>

#include <iostream>

namespace sblocks {

static std::string get_string(Json::Value &obj) {
  if (obj.isString()) {
    std::string str(std::move(obj.asString()));
    if (str.size())
      return std::move(str);
  }
  throw -999;
}

static std::unique_ptr<parameter_descriptor>
read_parameter_descriptor(Json::Value &obj) {
  std::string name(std::move(get_string(obj["name"])));
  std::string description(std::move(get_string(obj["description"])));
  Json::Value &options = obj["options"];
  if (options.isArray()) {
    if (options.size() < 2)
      throw -3;
    std::vector<std::string> options_vec;
    for (auto &opt : options) {
      options_vec.emplace_back(std::move(get_string(opt)));
    }
    return std::unique_ptr<parameter_descriptor>(
        new switch_parameter_descriptor(std::move(name),
            std::move(description), std::move(options_vec))
    );
  }
  Json::Value &min = obj["min"];
  Json::Value &max = obj["max"];
  if (!(min.isNumeric() && max.isNumeric()))
    throw -4;
  return std::unique_ptr<parameter_descriptor>(new number_parameter_descriptor(
      std::move(name), std::move(description), min.asDouble(), max.asDouble()
  ));
}

static std::vector<std::unique_ptr<parameter_descriptor>>
read_parameters(Json::Value &json_params) {
  std::vector<std::unique_ptr<parameter_descriptor>> vec(json_params.size());
  for (auto &obj : json_params) {
    vec.emplace_back(std::move(read_parameter_descriptor(obj)));
  }
  return std::move(vec);
}

static block_descriptor read_block_descriptor(Json::Value &obj,
    std::vector<parameter_descriptor> &params) {
  std::string name(std::move(get_string(obj["name"])));
  std::string description(std::move(get_string(obj["description"])));
  unsigned input_n, output_n;
  input_n = obj["input_n"].asUint();
  output_n = obj["output_n"].asUint();
}

static std::vector<block_descriptor>read_blocks(Json::Value &json_blocks,
    const std::vector<parameter_descriptor> &params) {
  std::vector<block_descriptor> vec;
  for (auto &obj : json_blocks) {
    vec.emplace_back(std::move(read_block_descriptor(obj, params)));
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
  Json::Value &json_blocks = root["blocks"];
  if (!(json_blocks.isArray() && json_blocks.size()))
    throw -1;
  _block_descriptors = std::move(read_blocks(json_blocks,
      _parameter_descriptors));
}

}
