/*
http://www.mitbbs.com/article_t/JobHunting/32608947.html
2014年1月
第一题的印象有点模糊了。。大概是给一个数组，然后有一些数是重复的，然后找到重
复最多的那个数，比如说 int input[]={3,7,4,3,6,1,3,6}，重复最多的数是3，这些3
的index分别是0 3 6，那么要求程序以相等的概率返回这3个index,
int computeIndex(int[] input);
33.3% return 0
33.3% return 3
33.3% return 6
当时因为叙述的比较绕，所以光题目就理解了半天，最后在他的提示下找到答案：先扫
第一遍，找到出现最多的那个数（比如3），然后写个random函数, 再扫第二遍，每次
遇到3就调用这个Random函数，若Random返回值大于一个阈值就返回当前的index。比如
这个函数可以是
bool ran(int size){
  	if(random()*size<1)
       	return true;
  	return false;

}
叙述的不好，见谅！有问题请提问~
*/

int findIndex(vector<int>& input) {
    int num = findMostFreqNum(input);
    int rand_num = rand()%3 + 1; // a random number between 1~3
    int count  = 0;
    for(int  i = 0; i < input.size(); ++i) {
	if(input[i] == num) {
               count++;
               if(count == rand_num) {
                    return i;
               }
           }
    }
}
