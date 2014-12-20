//!
//! @author Yue Wang
//! @date   19.12.2014
//!
//! @brief  test_for_adj_list.cpp
//!

#include <iostream>
#include <string>
#include "adj_list.hpp"


using namespace std;
using V  = clrs::ch22::Vertex<int,std::string>;
using E  = clrs::ch22::Edge<int,std::string>;
using DG = clrs::ch22::DirectedGraph<int,std::string>;
using UG = clrs::ch22::UndirectedGraph<int,std::string>;


inline ostream& operator<<(ostream& os, typename DG::Table const& table)
{
    for(auto const& pair : table)
        os << pair.first << " : " << pair.second << endl;
    return os;
}

vector<E> make_edges()
{
    V v1{1}, v2{2}, v5{5};
    E e12{v1, v2}, e15{v1, v5}, e25{v2, v5};
    return {e12, e15, e25};
}

int main()
{
    vector<E> es = make_edges();

    DG dg(es.cbegin(), es.cend());
    cout << "Directed Graph:\n";
    cout << dg.empty() << endl;
    cout << dg.size()  << endl;
    cout << (dg.find(V{1}) != dg.end() ? "found" : "no such thing") << endl;
    cout << dg;
    cout << "deg+ : \n" << dg.outdegree()   << endl;
    cout << "deg- : \n" << dg.indegre()     << endl;

    cout << "-------------------\n\n";

    UG ug(es.cbegin(),es.cend());

    cout << "Undirected Graph:\n";
    cout << ug.empty() << endl;
    cout << ug.size()  << endl;
    cout << (ug.find(V{1}) != ug.end() ? "found" : "no such thing") << endl;
    cout << ug ;

    cout << "\nexit normally\n";
    return 0;
}
//!
//! output:
//!
//0
//3
//found
//[1]-------{2,5}
//[2]-------{5}
//[5]-------{}


//----------------

//0
//3
//found
//[1]-------{2,5}
//[2]-------{1,5}
//[5]-------{1,2}
