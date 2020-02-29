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
//46. https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
#include <vector>
#include <iostream>
std::vector<int> input;
std::vector<std::vector<int>> rst;
void helper(std::vector<int>& nums,std::vector<int> & path,std::vector<std::vector<int>>& rst,std::vector<bool>& visited){
    if(path.size()==nums.size()){
        rst.push_back(path);
        return;
    }
    for(int i = 0 ; i < nums.size() ; i++){
        if(visited[i] == true){
            continue;
        }
        visited[i] = true;
        path.push_back(nums[i]);
        helper(nums,path,rst,visited);
        path.pop_back();
        visited[i] = false;
    }
    return ;
}
std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> rst;
    std::vector<int> path;
    std::vector<bool> visited(nums.size(), false);
    helper(nums,path,rst,visited);
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
    for (int i= 0 ; i < n ; i++){
        int temp;
        std::cin >> temp ;
        input.push_back(temp);
    }
    rst = permute(input);
    for_each (rst.begin(), rst.end(), print_vector);
    return 0 ;
}