//
//  main.cpp
//  TestQ1
//
//  Created by adeeb mohammed on 19/07/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<bool>> initializeMatchTable(std::string fileName,
                                                    std::string pattern){
    std::vector<std::vector<bool>> matchTable;
    for(int i = 0; i < fileName.length() + 1; i++){
        std::vector<bool> row = {};
        for (int j = 0; j < pattern.length() + 1; j++) {
            row.push_back(false);
        }
        matchTable.push_back(row);
    }
    matchTable[0][0] = true;
    for (int  j = 1; j < pattern.length()+1; j++) {
        if(pattern[j-1] == '*'){
            matchTable[0][j] = matchTable[0][j-1];
        }
    }
    return matchTable;
}

bool globMatching(std::string fileName, std::string pattern) {
    auto matchTable = initializeMatchTable(fileName,pattern);
    for (int i = 1; i < fileName.length()+1; i++) {
        for(int j = 1; j < pattern.length()+1; j++){
            if (pattern[j-1] == '*') {
                matchTable[i][j] = matchTable[i-1][j] || matchTable[i][j-1];
            }else if(pattern[j-1] == '?' || pattern[j-1] == fileName[i-1]){
                matchTable[i][j] = matchTable[i-1][j-1];
            }
        }
    }
    return matchTable[fileName.length()][pattern.length()];
}

int main(int argc, const char * argv[]) {
    std::cout << "Program for matching the pattern" << std::endl;
    std::cout << globMatching("abcdefg", "a*e?g");
    return 0;
}
