//
//  LordMediator.h
//  MyCppGame
//
//  Created by Apple mac on 15/3/15.
//
//

#ifndef __MyCppGame__LordMediator__
#define __MyCppGame__LordMediator__

#include "iostream"
#include <vector>
#include "Card.h"

using namespace std;

class LordMediator
{
public:
    LordMediator();
    ~LordMediator();
    
    
    void suffle(int *pokes, int length);
    
    int getDZ();
    
    void sort(vector<int> &pokes, size_t length);
    
    void sort(vector<CardData*> &pokes, size_t length);
    
private:
    
};

#endif /* defined(__MyCppGame__LordMediator__) */
