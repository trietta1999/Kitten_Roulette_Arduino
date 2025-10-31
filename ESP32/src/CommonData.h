/**
 * @brief Common data
 */

#ifndef _COMMON_DATA_H
#define _COMMON_DATA_H

#include "CommonDataType.h"
#include "CData.h"

extern CData<std::vector<std::string>> InputParamList;
extern CData<JsonDocument> JsonResponse;

void UpdateAll();

#endif // !_COMMON_DATA_H
