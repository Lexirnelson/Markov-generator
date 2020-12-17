/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#ifndef _MAP_MODEL_H
#define _MAP_MODEL_H

#include <string>
#include <vector>
#include <map>
#include "model.h"

using namespace std;

class map_model : public markov_model {
public:
    virtual void initialize(string text, int order);

    virtual string generate(int size);

    string to_string();

protected:
    map<string, vector<char>> text_map; //initialize the map
    int ord; //get the order so generate can use it
};

#endif
