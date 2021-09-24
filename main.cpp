#include "node_dl.h"
#include "list_dls.h"
#include <iostream>

using namespace std; 

int main(){
    
    ListDLS<int> list;

    list.insertHead(10);
    cout<< list << endl ;

    list.insertTail(22);
    cout<< list << endl ;
    
    list.insert(8); 
    cout<< list << endl ;
    
    list.insert(30); 
    cout<< list << endl ;
    
    list.insert(15); 
    cout<< list << endl ;


}