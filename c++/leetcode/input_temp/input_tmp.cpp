//
// Created by sugus chan on 2020-04-14.
//
#include <vector>
#include <string>
#include <iostream>
int main(){

//1. n m
std::vector<int> candicate;

//2. string
std::string str ;

//3. 123456
int nums = 5 ;
int matrix[5][5]; //动态长度需要vector！
char char_in ;
for(int i = 0 ; i < nums ; i ++){
    for(int j = 0 ;j < nums ;j ++){
        std::cin >> char_in;
        matrix[i][j] = char_in - 48;

    }
}
//4. 1001100


}
