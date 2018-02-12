/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashTable.h
 * Author: B
 *
 * Created on February 6, 2018, 11:03 PM
 */
#include "HashNode.h"

const int SIZE = 13;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable{
    
private:
    HashNode** table;
    
public:
    HashTable();
    ~HashTable();
    int HashKeyFunc(int key); //reinitializes key for the limited size of the list
    void input(int key, int value);
    void removeKey(int key);
    bool searchKey(int key);
};

#endif /* HASHTABLE_H */

