/**
 * @file IObserver.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include "src/stop.h"
#include "src/data_structs.h"
class Stop;
template <typename T>
/*
 *@brief The Observer (Abstract (and uninstantiable)) Interface Classs
 */
class IObserver {
 public:
    // virtual function to be override
    // update all observers with bus data
    virtual void UpdateObserver(T info) = 0;
};
#endif  // SRC_IOBSERVER_H_
