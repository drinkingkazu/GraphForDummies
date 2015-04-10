/**
 * \file GraphTree.h
 *
 * \ingroup GeoGraph
 * 
 * \brief Class def header for a class geograph::Tree
 *
 * @author kazuhiro
 */

/** \addtogroup GeoGraph

    @{*/
#ifndef GRAPH_TREE_H
#define GRAPH_TREE_H

#include <deque>
#include "GraphNode.h"
namespace geograph{

  class Tree{
    
  public:
    Tree(){}
    ~Tree(){}
    
    Node& CreateNode(NodeID_t mother_id=kINVALID_NODE);

    void Clear()
    { _node_v.clear(); }
    
    const std::deque<geograph::Node>& GetNode() const
    { return _node_v; }

    const geograph::Node& GetNode(const NodeID_t id) const
    { return _node_v.at(id); }
    
    Node& WriteableNode(const NodeID_t id)
    { return _node_v.at(id); }

    const std::vector<const geograph::Node*> GetNodeArray(const NodeID_t id=kINVALID_NODE);
    
    void Merge(const Tree& child,
	       const NodeID_t child_node_id, const NodeID_t parent_node_id, 
	       float parent_score);
    
    //void MoveNode(Tree& dest_t, const NodeID_t dest_n, const NodeID_t orig_n);
    
  private:
    
    std::deque<geograph::Node> _node_v;
    
  };
}

#endif
/** @} */ // end of doxygen group 

