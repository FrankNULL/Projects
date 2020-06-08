/**
 * @file IObservable.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_IOBSERVABLE_H_
#define SRC_IOBSERVABLE_H_
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include "src/data_structs.h"
#include "src/IObserver.h"
#include "src/stop.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Stop;
template <typename T>
/*
 *@brief IObserverable class (base class for stop and bus)
 */
class IObservable {
 public:
     // List of pointers to keep a track of all the shops that are observing
    std::vector<IObserver<T>*> observer_;
    void RegisterObservers(IObserver<T> *observer);
    void ClearObservers();
    void NotifyObservers(T info);
};

template <typename T>
/*
*@brief RegisterObservers() method to add an observer
*@param observer : observer to be added
*/
void IObservable <T>::RegisterObservers(IObserver<T> *observer) {
  observer_.push_back(observer);
}
template <typename T>
/*
*@brief void IObservable::ClearObservers() method to clear all observers
*/
void IObservable<T>::ClearObservers() {
  observer_.clear();
}
template <typename T>
/*
*@brief NotifyObservers() method to notify all observers
*@param info : bus data to be undated to each observer
*/
void IObservable<T>::NotifyObservers(T info) {
  for (typename vector<IObserver<T>*>::const_iterator iter = observer_.begin();
    iter != observer_.end(); ++iter) {
        if (*iter != 0) {
          (*iter)->UpdateObserver(info);
        }
    }
}
#endif  // SRC_IOBSERVABLE_H_
