/**
 * \file GraphNode.h
 *
 * \ingroup GeoGraph
 * 
 * \brief Class def header for a class geograph::Node
 *
 * @author kazuhiro
 */

/** \addtogroup GeoGraph

    @{*/
#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include "GeoGraphTypes.h"
#include "GeoAlgo/GeoVector.h"
#include "GeoAlgo/GeoAlgoConstants.h"
#include <set>
namespace geograph{

  class Tree;
  
  /**
     \class geograph::Node
     User defined class geograph::Node ... these comments are used to generate
     doxygen documentation!
  */
  class Node{
    friend class Tree;
  public:
    
    /// Default constructor
    Node(geograph::NodeID_t id=geograph::kINVALID_NODE)
      : _vtx(3,::geoalgo::kMAX_DOUBLE)
    { SetID(id); Clear(); }
    
    /// Default destructor
    virtual ~Node(){}
    
    void Clear()
    { 
      _parent_id = geograph::kINVALID_NODE;
      _parentage_score = 0;
      _children_id_s.clear();
      for(auto& v : _vtx) v = geoalgo::kMAX_DOUBLE;
      _leaf_obj_v.clear();
    }
    
    void SetParent(const geograph::NodeID_t id,
		   const float score)
    { _parent_id = id; _parentage_score = score; }
    
    void AddChild(const geograph::NodeID_t id)
    { _children_id_s.insert(id); }
    
    void AddLeaf(const geograph::ObjectID& obj)
    { _leaf_obj_v.push_back(obj); }
    
    void AddLeaf(const size_t index,
		 const geograph::ObjectType_t type)
    { _leaf_obj_v.emplace_back(index,type); }
    
    void SetVertex(const double x, const double y, const double z)
    { _vtx[0] = x; _vtx[1] = y; _vtx[2] = z; }

    void SetVertex(const ::geoalgo::Point_t& vtx)
    { _vtx.compat(vtx); _vtx=vtx; }
    
    const geograph::NodeID_t ID() const
    { return _self_id; }
    
    const geograph::NodeID_t Parent() const
    { return _parent_id; }
    
    const float& ParentageScore() const
    { return _parentage_score; }
    
    const std::set<geograph::NodeID_t>& Children() const
    { return _children_id_s; }
    
    const ::geoalgo::Point_t& Vertex() const 
    { return _vtx; }
    
    const std::vector<geograph::ObjectID>& Leaf() const 
    { return _leaf_obj_v; }
    
  private:
    
    void SetID(size_t id) { _self_id = id; }
    
  private:
    
    NodeID_t _self_id;
    
    NodeID_t _parent_id;
    
    float _parentage_score;
    
    std::set< ::geograph::NodeID_t > _children_id_s;
    
    ::geoalgo::Point_t _vtx;
    
    std::vector< ::geograph::ObjectID> _leaf_obj_v;
    
  };
}

#endif
/** @} */ // end of doxygen group 

