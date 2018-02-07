/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashNode.h
 * Author: B
 *
 * Created on February 6, 2018, 10:54 PM
 */
#include <iostream>
using namespace std;

#ifndef HASHNODE_H
#define HASHNODE_H

class HashNode{

public:
    int key;
    int value;
    HashNode* next;
    HashNode(int key, int value){
        this->key = key;
        this->value = value;
        next = NULL;
    } 
};

#endif /* HASHNODE_H */

