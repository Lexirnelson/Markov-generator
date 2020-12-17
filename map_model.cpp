/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Alexa Nelson

   Modified: 12/01/2020
*/
using namespace std;
#include "map_model.h"
#include <vector>
#include <map>
#include <iostream>


void map_model::initialize(string text, int order) {
    ord = order;
    string key;
    char after;
    for (int i = 0; i < text.size(); i++){
        if((i + (order-1)) < text.size()) { //normally gets the string keys
            key = text.substr(i, order);
            after =text[i+order];
        }
        else{
            string remaining = text.substr(i);
            int the_rest = order - remaining.size();
            key = remaining + text.substr(0, the_rest-1);
            after= text[the_rest];
        }
        text_map[key].push_back(after); //put key and map values in map
    }

}

string map_model::generate(int size) {
    string word;
    auto it = text_map.begin();
    advance(it, rand() % text_map.size());//get the starting point

    for (int i = 0; i < size; i++){
        string key = it->first;//get key
        vector<char> temp = it -> second; //get the vector of chars
        int random = rand() % temp.size(); //get random char from vector
        char next_char = temp[random];
        word+= next_char; //print character
        string new_seed(key.begin()+1, key.end()); //get the next key
        new_seed += next_char;
        it = text_map.find(new_seed);//iterate to key
    }
    return word;
}
