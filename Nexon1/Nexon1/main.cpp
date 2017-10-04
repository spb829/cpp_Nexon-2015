//
//  main.cpp
//  Nexon1
//
//  Created by Macbook Pro on 2017. 10. 1..
//  Copyright © 2017년 Eric Park. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int n;
int* inputs;
int* temp;
int count = -1;

bool isFactorOf(int a, int b){
    return (a % b == 0);
}

void addUp(){
    for (int i = 1; i <= n; i++)
        temp[i] = inputs[i];
    
    for (int i = 1; i <= n; i++){
        if (temp[i])
            for (int j = i * 2; j <= n; j += i ){
                inputs[j]++;
            }
    }
}

void solution(){
    while(1){
        for (int i = 1; i <= n; i++)
            if (inputs[i] < 0){
                addUp();
                return;
            }

        
        count++;
        
        for (int i = 1; i <= n; i++)
            for (int j = i * 2; j <= n; j += i)
                inputs[j]--;
    }
    
}

void printData(){
    cout << "data : " << endl;
    
    for (int i = 1; i <= n; i++)
        cout << inputs[i] << "\t";
    cout << endl;
}

void inputData(){
    cin >> n;
    
    inputs = (int*)calloc(sizeof(int), n + 1);
    temp = (int*)calloc(sizeof(int), n + 1);
    
    for (int i = 1; i <= n; i++)
        cin >> inputs[i];
    
}

int main(int argc, const char * argv[]) {
    inputData();
    printData();
    solution();
    printData();
    
    return 0;
}
