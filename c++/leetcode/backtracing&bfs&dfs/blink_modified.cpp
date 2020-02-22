//
// Created by sugus chan on 2020-02-22.
//
#include <iostream>
#include <queue>
int nums ;
int matrix[51][51];
int directions[8][2] = {{2, 2}, {2, -2}, {-2, 2}, {2, -2}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int visited[51][51]={0};
int cnt_array[51][51] = {0};//是静的，是不管多少路径、选择、搜索，到达这点的一个记录，可以用来标记最小的，如果是搜路径，可以用类似方式表达最小的路径的上一个点，这样可以串联起来一个路径
int min_value = 250000;
//
//4
//0000
//0000
//0000
//0000

//4
//0000
//0100
//0012
//0020


//类似递归树分析、注意时空分析，先定格每个空or时上的状态
typedef struct state{
    int x;
    int y;
    int count;
}state ;//一步的状态，是动的状态。
std::queue<state> q;//用这个去存放要访问的状态

void bfs() {

    while (!q.empty()) {
        state head = q.front();
        q.pop();
        if(head.x >= nums || head.y >= nums || head.x < 0 ||
        head.y < 0 || matrix[head.x][head.y] == 1 ||
        visited[head.x][head.y]==1 && cnt_array[head.x][head.y] <= head.count){
            //因为有反向-1等状态，所以必须有visited 来判断是否被访问过，如果被访问过那么要看当前访问的count是否比之前的要小，如果小的话就要更新，这样做剪枝操作
            continue;
        }
        //下面就是要不跳而是进行进一步处理*，visited不能在判断之前去处理*
        visited[head.x][head.y] = 1;//建议整体处理完后设置访问
        //如果一些状态判断在遍历处而不是在本次出栈处，与递归的思维是不同的。另外，也会带来不必要的for循环判断，也就是会内存溢出！！
        cnt_array[head.x][head.y] = head.count;
        int tc = head.count +1 ;//如果是head count ++ 会出错！因为这个位置比较靠前，是希望动作+1 是针对不同方向的消耗，而这里后面可能会进入if （head.x等的判断）
        if(matrix[head.x][head.y]==2){
            tc++;
            matrix[head.x][head.y]=0;//这个带上会出错
        }
        if(head.x== nums -1 && head.y == nums-1){
            if(head.count < min_value){
                min_value = head.count;
            }
        }

        for(int i = 0 ; i < 8 ;i++){
            state search = {head.x+directions[i][0],head.y+directions[i][1],tc};
            q.push(search);
        }
    }
    return ;
}
int main(){
    std::cin >> nums ;
    char char_in ;
    for(int i = 0 ; i < nums ; i ++){
        for(int j = 0 ;j < nums ;j ++){
            std::cin >> char_in;
            matrix[i][j] = char_in - 48;

        }
    }
    state begin = {0,0,0};
    q.push(begin);
    bfs();

    for(int i = 0 ; i < nums ; i ++){
        for(int j = 0 ;j < nums ;j ++){
            std::cout <<  matrix[i][j] ;
        }
        std::cout << std::endl;
    }

    std::cout << "rst" << min_value << std::endl;//可以用最终cnt_array[nums-1][nums-1] 来判断最后的值，因为这个数组就是记录最少的步数，上面过程执行完毕之后就可以直接用这个值了
    return 0;

}