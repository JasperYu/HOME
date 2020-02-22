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
        if(head.x== nums -1 && head.y == nums-1){
            if(head.count < min_value){
                min_value = head.count;
            }
        }
        //前面都是判断，后面是对一个node进行处理
        //下面就是要不跳而是进行进一步处理*，visited不能在判断之前去处理*
        visited[head.x][head.y] = 1;//建议整体处理完后设置访问

        //如果一些状态判断在遍历处而不是在本次出栈处，与递归的思维是不同的。另外，也会带来不必要的for循环判断，也就是会内存溢出！！
        cnt_array[head.x][head.y] = head.count;//如果访问过要看head.count当前是不是比历史记录要小，前面已经判断过，所以直接赋值。如果没有访问过我们就直接赋值就好了
        //head.count一开始是0，正好记录之前迭代传下的count就可以了
        head.count ++ ;//这个是为了之后遍历的情况，如果不同方向不同的话，可以放到for循环里面
        if(matrix[head.x][head.y]==2){
            head.count++;
        }

        for(int i = 0 ; i < 8 ;i++){
            state search = {head.x+directions[i][0],head.y+directions[i][1],head.count};
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

    if(cnt_array[nums-1][nums-1]){
        std::cout << cnt_array[nums-1][nums-1] << std::endl;
    }else{
        std::cout << "Impossible" << endl;
    }//可以用最终cnt_array[nums-1][nums-1] 来判断最后的值，因为这个数组就是记录最少的步数，上面过程执行完毕之后就可以直接用这个值了

    return 0;

}