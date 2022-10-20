#include "mylib.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

std::string version = std::string(CSINTEROP_VERSION_STRING);

int TestMe() {
  return 2;
}

std::string& GetVersion() {
  return version;
}

std::string GetLongString()
{
    // TODO: insert return statement here
    return std::string("This is a longer string");
}


SpaceExclusion::SpaceExclusion() {
  std::cout << "Constructed" << std::endl;
}

int SpaceExclusion::InitializeVertices(const float* pVertices, int nVertices, const int* pIndices, int nIndices,  float strength)
{
  for (size_t i = 0 ; i < nVertices ; i++) {
    std::cout << pVertices[i] << std::endl;
  }
  return EXIT_SUCCESS;
}

int SpaceExclusion::AddDepthMap(const float* pDepths, int nWidth, int nDepth, float minZ)
{
  for (size_t i = 0 ; i < nWidth ; i++) {
    for (size_t j = 0 ; j < nDepth ; j++) {
      std::cout << pDepths[i * nDepth + j] << std::endl;
    }
  }

  return EXIT_SUCCESS;
}

int SpaceExclusion::Execute(bool** pExcluded, int* nExclusions)
{
  *nExclusions = 1000;
  *pExcluded = (bool*) malloc(*nExclusions * sizeof(bool));
  return EXIT_SUCCESS;
}

void SpaceExclusion::Throwing()
{
  int k = 2;
  int l = 5*k;
  std::cout << l << std::endl;
  throw std::runtime_error("Shit");
}
