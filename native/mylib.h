#pragma once

#include "config.h"
#include "mylibrary_export.h"
#include <string>

MYLIBRARY_EXPORT int TestMe();

MYLIBRARY_EXPORT std::string& GetVersion();

MYLIBRARY_EXPORT std::string GetLongString();

class MYLIBRARY_EXPORT SpaceExclusion {
 public:
  SpaceExclusion();
  int InitializeVertices(const float* pVertices, int nVertices, const int* pIndices, int nIndices,  float strength);
  int AddDepthMap(const float* pDepths, int nWidth, int nDepth, float minZ);
  int Execute(bool** pExcluded, int* nExclusions);
};
