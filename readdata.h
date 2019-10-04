/*
 * Donnee.h
 *
 *  Created on: 24 mai 2017
 *      Author: mohamed
 */

#ifndef DONNEE_H_
#define DONNEE_H_

#include <vector>
#include <string>
#include <ostream>
#include <fstream>
#include <memory>


class Data {
friend std::ostream &operator<<(std::ostream &os, const Data &rhs);
public:
    Data(std::string fileName);
    std::unique_ptr<std::vector<std::string>> data;
    std::string fileName;
    
};

#endif /* DONNEE_H_ */
