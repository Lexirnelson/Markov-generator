/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Alexa Nelson

   Modified: 12/01/2020
*/

#include "word_model.h"
#include<bits/stdc++.h>

void word_model::vector_words(string str){
    string word;
    stringstream iss(str);
    while(iss >> word){
        text_words.push_back(word);
    }
}

void word_model::initialize(string text, int order) {
    vector_words(text);
    ord = order;
    string key;
    string after;
    for (int i = 0; i < text_words.size(); i++){
        key = "";
        if((i + (order-1)) < text_words.size()) { //normally gets the string keys
            for(int j = 0; j < order; j++){
                if(j == order -1){
                    key += text_words[i + j];
                }else{
                    key += text_words[i + j] + " ";
                }
            }
            after = text_words[i + order];
        }
        else{
            int place = i; //special case if it needs to wrap around
            int words_left = order;
            while (place < text_words.size()){
                key += text_words[place];
                words_left--;
                place++;
            }
            after = text_words[words_left-1];
            for(int i = 0; i< words_left; i++){
                if(i == words_left -1){
                    key += text_words[i];
                }else{
                    key += text_words[i];
                }

            }
        }
        text_map[key].push_back(after); //put key and map values in map
    }

}


string word_model::generate(int size) {
    string word;
    auto it = text_map.begin();
    advance(it, rand() % text_map.size());//get the starting point

    for (int i = 0; i < size; i++){
        string key = it->first;//get key
        vector<string> temp = it -> second; //get the vector of chars
        int random = rand() % temp.size(); //get random char from vector
        string next_string = temp[random];
        word+= next_string + " "; //print character
        key = key.substr(key.find_first_of(" \t")); //get the next key
        key.erase(key.begin());
        key += (" " + next_string);
        it = text_map.find(key);//iterate to key
    }
    return word;
}
