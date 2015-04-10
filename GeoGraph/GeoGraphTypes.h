#ifndef GEOGRAPHTYPES_H
#define GEOGRAPHTYPES_H

#include <limits>
#include <climits>
#include <stdlib.h>
namespace geograph{
    
  const size_t kINVALID_INDEX = std::numeric_limits<size_t>::max();
  
  typedef size_t NodeID_t;
  
  const NodeID_t kINVALID_NODE = kINVALID_INDEX;
  
  enum ObjectType_t {
    kTrajectory,
    kCone,
    kHalfLine,
    kNoneType
  };

  class ObjectID {
  public:
    size_t _index;
    geograph::ObjectType_t _type;
    ObjectID(const size_t index = geograph::kINVALID_INDEX,
	     const geograph::ObjectType_t type = geograph::kNoneType)
    { _index = index; _type = type; }
  };
  
}
#endif

