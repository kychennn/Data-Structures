#include <iostream>
using namespace std;

/************************************************/
/* Programmer: Anna Salvati                             */        
/* Date:  September 29, 2020                    */     
/* Purpose:  Queue class - array implementation */
 /***********************************************/

#ifndef QUEUE_H
#define QUEUE_H

template <class T>
struct node{
   T info;
   node *next;
};

template <class T>
class Queue
{
   private:
      
      node<T> *front;
      node<T> *rear;
        
   public:
      //Constructor : creates an array of maximum size specified by the 
      // parameter size -  default maximum size is 100; 
      Queue();
      // Destructor: releases memory allocated for the array
      ~Queue();
      //Copy constructor
      Queue ( const Queue<T> & other);
      //Overload the assignment operator 
      const Queue<T> & operator= (const Queue<T> & other);
      //Returns true if queue  is empty, false otherwise
      bool isEmpty();
      //If queue is not full, inserts parameter item and increases length // of the queue. 
      // If queue is full, prints error message
      void enqueue (T item);
      //If queue is not empty removes front item
      void dequeue ();
      // Returns copy of front item
      void getFront ( T & item);
      // Returns copy of back item
      void getRear ( T & item);
      void destroy();
      void copy (const Queue<T> &other);
};
#endif