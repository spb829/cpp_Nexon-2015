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

void printData(){
    for (int i = 1; i <= n; i++)
        cout << inputs[i] << " ";
    cout << endl;
}

void inputData(){
    cin >> n;
    
    inputs = (int*)calloc(sizeof(int), n + 1);
    
    for (int i = 1; i <= n; i++)
        cin >> inputs[i];
}

void solution(){
    int count = 0;
    
    while(1){
        // Check if there is only 0 or 1.
        bool check = true;
        for (int i = 1; i <= n; i++){
            if (inputs[i] < 0){
                cout << "-1" << endl;
                return;
            }
            
            if (!(inputs[i] == 0 || inputs[i] == 1)){
                check = false;
                break;
            }
        }
        if (check){
            cout << count << endl;
            printData();
            return;
        }
        
        count++;
        
        for (int i = 1; i <= n; i++)
            for (int j = i * 2; j <= n; j += i)
                inputs[j]--;
    }
}

int main(int argc, const char * argv[]) {
    inputData();
    solution();
    
    return 0;
}
