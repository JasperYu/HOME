//
// Created by sugus chan on 2020-02-22.
//


//输入: [1,2,3]
//输出:
//[
//[1,2,3],
//[1,3,2],
//[2,1,3],
//[2,3,1],
//[3,1,2],
//[3,2,1]
//]
//77. https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
#include <vector>
#include <iostream>
std::vector<int> input;

void helper(int start,int k , int n ,std::vector<int>& path,std::vector<std::vector<int>>& rst, int sum){
    if(n == sum && path.size() == k ){
        rst.push_back(path);
        return;
    }
    for(int i = start ; i <= 9 ; i++ ){
        path.push_back(i);
        sum = sum + i ;
        helper(i+1,k,n,path,rst,sum);
        path.pop_back();
        sum = sum - i ;
    }

}

std::vector<std::vector<int>> combine(int n,int k) {
    //sort(nums.begin(),nums.end());
    std::vector<std::vector<int>> rst;
    std::vector<int> path;
    //std::vector<bool> visited(nums.size(), false);
    int sum = 0 ;
    helper(1,k,n,path,rst,0);
    return rst;
}
void print_int (int i) {  // function:
    std::cout << i << " ";
}
void print_vector (std::vector<int> v) {  // function:
    int size = v.size();
    for(int i = 0 ; i < size ; i ++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
int main(){
    int n;
    std::cin >> n ;
    int k;
    std::cin >> k ;
    std::vector<std::vector<int>> rst;
    rst = combine(n,k);
    for_each (rst.begin(), rst.end(), print_vector);
    return 0 ;
}