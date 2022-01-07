#ifndef __MODBUS__H__
#define __MODBUS__H__
#include "nlohmann/json.hpp"

using json = nlohmann::json;
bool checkModbusProto(const char *data, int dataLen);
bool ModbusDecode(const char *data, int dataLen, json &jout);
bool ModbusResponseDecode(const char *data, int dataLen, json &jout);

#endif