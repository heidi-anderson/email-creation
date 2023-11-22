#pragma once
#include <string>
#include <cmath>

using namespace std;

void splitNameLF(string fullName, string &first, string &last);
string createEmail(string first, string last, string domain);
void splitNameFL(string fullName, string &first, string &last);
void fixList(string mixed[], string firstLast[], string lastFirst[], string email[], int size, string domain);
