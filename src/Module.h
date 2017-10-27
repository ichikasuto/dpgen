//
//  Module.h
//  dpgen
//
//  Created by Andrew Camps on 10/22/17.
//

#ifndef Module_h
#define Module_h

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>

#include "Input.h"
#include "Output.h"
#include "Wire.h"

using namespace std;

class Module {
private:
    string name;
    enum Type { INPUT, OUTPUT, WIRE, REGISTER, OPERATION };
    bool readFile(string file);
    bool getDataType(string type, int *size);
    bool parseLine(vector<string> line);
    int getID(Operation::Operations operation);
    vector<string> split(string const &input);
public:
    Module(string name);
    string getName() { return name; }
    bool buildModule(string file); /* Builds the data path graph */
    bool outputModule(string file); /* Prints the module in .v format */
    int criticalPathDelay(); /* Calculates the critical path of the graph */
    vector<Operation *> operations;
    vector<Output *> outputs;
    vector<Input *> inputs;
    vector<Wire *> wires;
};

#endif /* Module_h */
