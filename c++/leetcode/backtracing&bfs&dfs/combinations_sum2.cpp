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
//40. https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
#include <vector>
#include <iostream>
std::vector<int> input;

void helper(std::vector<int>& candidates,int index ,int target , int sum,std::vector<int>& path,std::vector<std::vector<int>> &rst ,std::vector<bool> &visited){
    if(target == sum)
    {
        rst.push_back(path);
        return;
    }

    for(int i = index; i < candidates.size(); i++){
        if( sum + candidates[i]  > target){
            return;//if sort
        }
        if(i >=0 && candidates[i] == candidates[i-1] && visited[i-1] == false){
            continue;
        }
        sum = sum + candidates[i] ;
        path.push_back(candidates[i]);
        visited[i] = true;
        helper(candidates,i+1,target,sum,path,rst,visited);
        sum = sum - candidates[i] ;
        path.pop_back();
        visited[i] = false;
    }
    return;//
}
std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<int> path;
    std::vector<std::vector<int>> rst ;
    int sum = 0 ;
    std::vector<bool> visited(candidates.size(),false);//一个初始化引发的血案，。。。没访问应该是false，大意弄错排了好长时间才找到问题
    sort(candidates.begin(),candidates.end());
    helper(candidates,0,target,sum,path,rst,visited);
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

    rst = combinationSum2(can,target);
    for_each (rst.begin(), rst.end(), print_vector);
    return 0 ;
}