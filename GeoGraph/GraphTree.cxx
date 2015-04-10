#ifndef GRAPHTREE_CXX
#define GRAPHTREE_CXX

#include "GraphTree.h"

namespace geograph {

  Node& Tree::CreateNode(NodeID_t mother_id)
  { 
    if(!_node_v.size() && mother_id != kINVALID_NODE) 
      
      throw ::geoalgo::GeoAlgoException("Invalid mother ID!");
    
    else if(_node_v.size() && _node_v.size() <= mother_id)
      
      throw ::geoalgo::GeoAlgoException("Invalid mother ID!");
    
    Node new_node(_node_v.size());
    
    new_node.SetParent(mother_id,0);
    
    _node_v.emplace_back(new_node);
    
    return _node_v.back();
  }
  
  const std::vector<const geograph::Node*> Tree::GetNodeArray(const NodeID_t id)
  {
    std::vector<const geograph::Node*> res;
    if(id==kINVALID_NODE) {
      for(auto const& n : _node_v) res.push_back((&n));
      return res;
    }
    
    std::deque<NodeID_t> target_node_v(1,id);
    std::vector<NodeID_t> node_id_v;
    
    while(target_node_v.size()) {
      res.reserve(res.size()+target_node_v.size());
      size_t rm_size = target_node_v.size();
      for(auto const& n_id : target_node_v) {
	auto& n = this->GetNode(n_id);
	res.push_back(&n);
	for(auto const& child_id : n.Children())
	  target_node_v.push_back(child_id);
      }
      target_node_v.erase(target_node_v.begin(),target_node_v.begin()+rm_size);
    }
    return res;
  }
  
  void Tree::Merge(const Tree& child,
		   const NodeID_t child_node_id, const NodeID_t parent_node_id, 
		   float parent_score)
    
  {
    if(parent_node_id >= _node_v.size())
      throw ::geoalgo::GeoAlgoException("Invalid \"from\" node ID!");
    if(child_node_id >= child.GetNode().size())
      throw ::geoalgo::GeoAlgoException("Invalid \"to\" node ID!");
    
    auto id_offset = _node_v.size();
    
    _node_v[parent_node_id].AddChild(child_node_id + id_offset);
    
    for(auto const& n : child.GetNode()) {
      _node_v.push_back(n);
      NodeID_t new_id = n.ID() + id_offset;
      _node_v.back().SetID(new_id);
      if(n.ID() == child_node_id)
	_node_v.back().SetParent(parent_node_id,parent_score);
    }
  }

  /*
  void Tree::Migrate(Tree& dest_t,
		     const NodeID_t dest_node_id,
		     const NodeID_t orig_node_id)
  {
    auto& dest_n = dest_t.WriteableNode(dest_node_id);
    NodeID_t offset = dest_t.Node().size();
  }
  */
}

#endif
