/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HashTable.h"

HashTable::HashTable(){
    table = new HashNode*[SIZE];
    for(int i = 0; i < SIZE; i++)
        table[i] = NULL;
}

HashTable::~HashTable(){
    for(int i = 0; i < SIZE; i++){
        if(table[i] != NULL){
            HashNode* begin = table[i];
            while(begin != NULL){
                HashNode* previous = begin;
                begin = begin->next;
                delete previous;
            }
        }
    }
    delete[] table;
}
int HashTable::HashKeyFunc(int key){
    return key % SIZE;
}

void HashTable::input(int key, int value){
    int HashKey = HashKeyFunc(key);
    HashNode* prev = NULL;
    if(table[HashKey] == NULL)
        table[HashKey] = new HashNode(key, value);
    else{
        HashNode* begin = table[HashKey];
        while(begin != NULL && begin->value < value){
            prev = begin;
            begin = begin->next;
        }
        if(begin == NULL)
            begin = new HashNode(key, value);
        else{
            prev->next = new HashNode(key, value);
            prev->next->next = begin;
        }
    }
}

void HashTable::removeKey(int key){
    int HashKey = HashKeyFunc(key);
    HashNode* begin = table[HashKey];
    HashNode* prev = NULL;
    if(begin == NULL || begin->key != key){
        return;
    }
    while(begin->next != NULL){
        prev = begin;
        begin = begin->next;
    }
    if(prev != NULL){
        prev->next = begin->next;
    }
    delete begin;
}

bool HashTable::searchKey(int key){
    int HashKey = HashKeyFunc(key);
    if(table[HashKey] == NULL)
        return false;
    else{
        HashNode* begin = table[HashKey];
        while(begin != NULL){
            if(begin->key == key){
                cout << begin->value << " ";
            }
            begin = begin->next;
        }
        return true;
    }
}