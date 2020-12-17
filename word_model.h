/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#ifndef _WORD_MODEL_H
#define _WORD_MODEL_H

#include <map>
#include <vector>

#include "model.h"

using namespace std;

class word_model : public markov_model {
public:
    virtual void initialize(string text, int order);

    virtual string generate(int size);

    // Add any helper methods you want here
    void vector_words(string str);
protected:
    // Add any variables you may need here
    map<string, vector<string>> text_map; //initialize the map
    int ord; //get the order so generate can use it
    vector<string> text_words;
};

#endif
