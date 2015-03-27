//
//  LordMediator.cpp
//  MyCppGame
//
//  Created by Apple mac on 15/3/15.
//
//

#include "LordMediator.h"


LordMediator::LordMediator()
{
    
}

LordMediator::~LordMediator()
{
    
}

void LordMediator::suffle(int *pokes, int length)
{
    srand((int)time(0));
    for (int l = 0; l < length; l++) {
        int des = int(rand()%54);
        int temp = pokes[l];
        pokes[l] = pokes[des];
        pokes[des] = temp;
    }
}

void LordMediator::sort(vector<int> &pokes, size_t length)
{
    for (int l = 0; l < length; l++) {
        for (int j = l+1; j<length; j++) {
            if (pokes[l] < pokes[j]) {
                int temp = pokes[l];
                pokes[l] = pokes[j];
                pokes[j] = temp;
            }
        }
    }
}

void LordMediator::sort(vector<CardData *> &pokes, size_t length)
{
    for (int l = 0; l < length; l++) {
        for (int j = l+1; j<length; j++) {
            if (pokes[l]->cardValue < pokes[j]->cardValue) {
                CardData* temp = pokes[l];
                pokes[l] = pokes[j];
                pokes[j] = temp;
            }
            else if (pokes[l]->cardValue == pokes[j]->cardValue)
            {
                if (pokes[l]->cardType < pokes[j]->cardType) {
                    CardData* temp = pokes[l];
                    pokes[l] = pokes[j];
                    pokes[j] = temp;
                }
            }
        }
    }
}

int LordMediator::getDZ()
{
    srand((int)time(0));
    int dz = int(rand()%3);
    
    return dz;
}