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
//39. https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
#include <vector>
#include <iostream>
std::vector<int> input;

void helper(std::vector<int>& candidates,int index ,int target , int sum,std::vector<int>& path,std::vector<std::vector<int>> &rst ){
    if(target == sum)
    {
        rst.push_back(path);
        return;
    }

    for(int i = index; i < candidates.size(); i++){
        if( sum + candidates[i]  > target){
            return;//if sort
        }
        sum = sum + candidates[i] ;
        path.push_back(candidates[i]);
        helper(candidates,i,target,sum,path,rst);
        sum = sum - candidates[i] ;
        path.pop_back();
    }
    return;//
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<int> path;
    std::vector<std::vector<int>> rst ;
    int sum = 0 ;
    sort(candidates.begin(),candidates.end());
    helper(candidates,0,target,sum,path,rst);
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
    std::vector<int> can;
    for(int i = 0 ; i < n ; i ++){
        int temp ;
        std::cin >> temp ;
        can.push_back(temp);
    }
    int target ;
    std::cin >> target;

    std::vector<std::vector<int>> rst;

    rst = combinationSum(can,target);
    for_each (rst.begin(), rst.end(), print_vector);
    return 0 ;
}