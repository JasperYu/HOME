//
// Created by sugus chan on 2020-02-23.
// 93
#include <vector>
#include <string>
#include <iostream>
#include <queue>
typedef struct state{
    std::string s;
    int seg_now;
    std::string returnstring;
}state;
std::vector<std::string> returnstrings;
std::vector<int> cliplen={1,2,3};
int seg = 4 ;
// bfs 这题很慢，并且没有提升内存消耗。如果解答本身比较深，适合dfs！
std::vector<std::string> restoreIpAddresses(std::string s) {
    state begin = {s,seg,""};
    std::queue<state> q;
    q.push(begin);
    while(!q.empty()){
        state top = q.front();
        q.pop();
        std::string s = top.s;
        std::string returnstring = top.returnstring;
        int seg_now = top.seg_now;
        if(s.empty() && seg_now == 0){
            returnstrings.push_back(returnstring);
            continue;
        }
        if(s.size() > seg_now *3 || s.size() < seg_now){
            continue ;
        }
        for(int i = 1 ; i < 4 ; i ++){
            int val = std::stoi(s.substr(0, i));//不能0，0 所以从1 开始，注意某段第一个字母不能以0开始，因此下面要加上：
            if(val >255|| i != std::to_string(val).size()){//后面这个半句很重要***因为可能不满要截取的大小了，所以要判断下，与i > s.size()等价
                continue;
            }
            state next = {s.substr(i),seg_now-1, returnstring + s.substr(0, i) + (seg_now == 1 ? "" : ".")};
            q.push(next);
        }
    }
    std::cout << "new" <<std::endl;
    return returnstrings;
}

int main(){
    std::string sin ;
    std::cin >> sin ;
    restoreIpAddresses(sin);
    for(int i = 0 ; i < returnstrings.size() ;i ++){
        std::cout << returnstrings[i] << std::endl;
    }
    return 0 ;
};