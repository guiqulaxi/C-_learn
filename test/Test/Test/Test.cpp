#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <functional>
#include<iomanip>
#include<set>
#include<algorithm>
#include <bitset>  
#include<stack>

using std::bitset;
using namespace std;
#pragma region 字符串分割
void  split(const string & src, const string& delim, vector<string> &ret){
	string::size_type begin = 0;
	string::size_type end = src.find_first_of(delim, begin);
	while (end!=string::npos){
		ret.push_back(src.substr(begin, end - begin));
		begin = end + 1;
		end=src.find_first_of(delim, begin);
	}
	if ( begin <src.size()){
		ret.push_back(src.substr(begin, src.size() - begin));
	}
	
	
}
#pragma endregion
#pragma region Map 排序
typedef pair<string,int> PAIR;
int cmp (const PAIR& lhs, const PAIR& rhs) {
	return lhs.first < rhs.first ;
}

int sort_test() {
	map<string, int> name_score_map;
	name_score_map["LiMin"] = 90;
	name_score_map["ZiLinMi"] = 79;
	name_score_map["BoB"] = 92;
	name_score_map.insert(make_pair("Bing", 99));
	name_score_map.insert(make_pair("Albert", 86));
	//把map中元素转存到vector中   
	vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());
	sort(name_score_vec.begin(), name_score_vec.end(), cmp);
	
	for (int i = 0; i != name_score_vec.size(); ++i) {
		cout << name_score_vec[i].first << endl;
	}
	return 0;
}
#pragma endregion

# pragma region 图
struct Graph{
	vector<vector<int>> edges;
	vector<string> vexs;
	vector<bool> isvisit;

};
#define M 1000
void create(Graph &g){
	vector<int> a1 = { 0, 2, M, M, 10 };
	vector<int> a2 = { M, 0, 3, M, 7 };
	vector<int> a3 = { 4, M, 0, 4, M };
	vector<int> a4 = { M, M, M, 0, 5 };
	vector<int> a5 = { M, M, 3, M, 0 };
	
	g.edges.push_back(a1);
	g.edges.push_back(a2);
	g.edges.push_back(a3);
	g.edges.push_back(a4);
	g.edges.push_back(a5);
	
	g.vexs.push_back("1");
	g.vexs.push_back("2");
	g.vexs.push_back("3");
	g.vexs.push_back("4");
	g.vexs.push_back("5");
	
	for (int i = 0;i< g.vexs.size(); i++){
		g.isvisit.push_back(false);
	}
}
int getindex(const Graph &g,const string &vex){
	for (int i = 0; i < g.vexs.size(); i++){
		if (g.vexs[i] == vex){
			return i;
		}
	}
}
string getvex(const Graph &g, int index){
	return g.vexs[index];
}
#pragma region 深度优先
//
//void dfs( Graph &g, queue<int> &q){
//	if (q.empty()) return;
//	int index = q.front();
//
//	cout << getvex(g,index);
//	g.isvisit[index] = true;
//	q.pop();
//	for (int i = 0; i < g.edges[index].size(); i++){
//		if (!g.isvisit[i] && g.edges[index][i]<M){
//			q.push(i);
//			dfs(g, q);
//		};
//	}
//}
//void dfs_browse(Graph &g, const string &start, const  string &end){
//	int start_indx = getindex(g, start);
//	int end_indx = getindex(g, end);
//
//	queue<int> q;
//	q.push(start_indx);
//	for (int i = 0; i < g.vexs.size(); i++){
//		if (g.isvisit[i])continue;
//		dfs(g, q);
//	}
//
//}
#pragma endregion
#pragma region 图中两点最短路径
int min_dist = INT_MAX;
deque<int> min_path;
void dfs(Graph &g, int cur_indx, int end_indx, int dst, deque<int>& path){
	
	if (dst > min_dist){
		return;
	}
	if (cur_indx == end_indx){
		if (min_dist > dst){
			min_dist = dst;
			min_path = path;
			return;
		}
	}
	for (int i = 0; i < g.edges[cur_indx].size(); i++){
		if (!g.isvisit[i] && g.edges[cur_indx][i]<M){
			path.push_back(i);
			g.isvisit[i] = true;
			dfs(g, i, end_indx, dst + g.edges[cur_indx][i], path);
			g.isvisit[i] = false;
			path.pop_back();
		};
	}
}
void find_min_path( Graph &g,const string &start,const  string &end){
	int start_indx = getindex(g,start);
	int end_indx = getindex(g,end );

	deque<int> path;
	path.push_back(start_indx);
	dfs(g, start_indx, end_indx, 0, path);
	
	for (int i = 0; i < min_path.size(); i++){
		cout << getvex(g, min_path[i]) << " ";
	}

}
#pragma endregion


//int main(){
//	Graph g;
//	create(g);
//	find_min_path(g, "5", "2");
//	system("pause");
//	return 0;
//}
#pragma endregion

# pragma region 钢条切割


//int main(){
//	vector<int> p = {0,1,5,8,9,10,17,17,20,24,30};
//	int n;
//	cin >> n;
//	vector<int> r(11, 0), s(11, 0);
//	
//
//	for (int j = 1; j <= n; j++){
//		int q = INT_MIN;
//		for (int i = 1; i <= j; i++){
//			if (q < p[i] + r[j - i])
//			{
//				q = p[i] + r[j - i];
//				s[j] = i;
//
//			}
//		}
//			
//		r[j] = q;
//	}
//	system("pause");
//	return 0;
//}
# pragma endregion 
# pragma region 矩阵链乘法


//int main(){
//	vector<int> p = {30,35,15,5,10,20,25};
//	int n = p.size();
//	/*cin >> n;
//	while (n--)
//	{
//		int a;
//		cin >> a;
//		p.push_back(a);
//	}*/
//	
//	vector<vector<int>>m;
//	vector<vector<int>>s;
//	for (int i = 0; i <n; i++){
//		m.push_back(vector<int>(n, INT_MAX));
//		s.push_back(vector<int>(n, INT_MAX));
//	}
//	for (int i = 0; i <n; i++){
//		m[i][i]=0;
//		s[i][i] = 0;
//	}
//	for (int l = 2; l <= n; l++){
//		for (int i = 1; i <=n - l - 1; i++){
//			int j = i + l - 1;
//			m[i][j] = INT_MAX;
//			for (int k = i; k <= j - 1; k++){
//				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//				cout << "m[" << i << "]" << "[" << k << "]+" << "m[" << k + 1 << "][" << j << "] + p[" << i - 1 << "] * p[" << k << "] * p[" << j << "];" << endl;
//				if (q < m[i][j]){
//					m[i][j] = q;
//					s[i][j] = k;
//				}
//			}
//		}
//	}
//	
//	system("pause");
//	return 0;
//}
# pragma endregion 
# pragma region 回溯
//a[]表示当前获得的部分解；
//
//k表示搜索深度；
//
//input表示用于传递的更多的参数；
//
//is_a_solution(a, k, input)判断当前的部分解向量a[1...k]是否是一个符合条件的解
//
//construct_candidates(a, k, input, c, ncandidates)根据目前状态，构造这一步可能的选择，存入c[]数组，其长度存入ncandidates
//
//process_solution(a, k, input)对于符合条件的解进行处理，通常是输出、计数等
//
//make_move(a, k, input)和unmake_move(a, k, input)前者将采取的选择更新到原始数据结构上，后者把这一行为撤销。

#pragma region 全排列
//bool finished = false; /* 是否获得全部解? */


void construct_candidates(vector<int>&input,vector<int>&res, vector<int> &candinates)
{
	
	for (int i = 0; i < input.size(); i++){
		if (find(res.begin(), res.end(), input[i]) == res.end()){
			candinates.push_back(input[i]);
		}
	}
}

void process_solution(vector<int> &res)
{
	int i;
	printf("{");
	for (i = 0; i < res.size(); i++)
		printf(" %d", res[i]);
	printf(" }\n");
}
void backtrack(vector<int>&input, vector<int>& res, int k, int end)
{
	if (k == end)
	{
		process_solution(res);
	}
	else{
		k++;
		vector<int> candinates;
		construct_candidates(input, res, candinates);
		for (int i = 0; i < candinates.size(); i++){
			res.push_back(candinates[i]);
			backtrack(input, res, k, end);
			res.pop_back();
		}
	
	}
}
//int main(){
//	vector<int> input = { 1, 2, 3,4 };
//	vector<int> res;
//	backtrack(input,res,-1,3);
//	return 0;
//}
#pragma endregion 

#pragma region 手机输入字母组合
bool finished = false; /* 是否获得全部解? */
static char ch[10][5] =
{
	"",
	"",
	"ABC",
	"DEF",
	"GHI",
	"JKL",
	"MNO",
	"PQRS",
	"TUV",
	"WXYZ",
};

static int total[10] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
//int a[]当前结果
//input 输入的数字 
//int k 运行到第k个输入的数字。
//输出 char *c,下一步的可能选择
// 输出 int *ncandidates 可能选择数目
void construct_candidates(char a[], int input[], int k, char * &c, int *ncandidates)
{
	c = ch[input[k]];
	*ncandidates = total[input[k]];
	return;
}
bool is_a_solution(char a[], int k ,int len)
{
	if (k == len)
		return true;
	else
		return false;
	
}
void process_solution(char a[],  int len)
{
	int i;
	printf("{");
	for (i = 1; i <= len; i++)
		printf(" %c", a[i]);
	printf(" }\n");
}

void backtrack(char a[], int input[], int k, int len)
{
	char *c =NULL; /*下一步候选 */
	int ncandidates; /* 候选数目 */
	int i; /* counter */
	if (is_a_solution(a,k, len))
		process_solution(a,  len);
	else {
		k = k + 1;
		construct_candidates(a, input,k, c, &ncandidates);
		for (i = 0; i < ncandidates; i++) {
			a[k] = c[i];
			//make_move(a, k, input);
			backtrack(a, input, k, len);
			//unmake_move(a, k, input);
			//if (finished) return; /* 如果符合终止条件就提前退出 */
		}
		
		
	}
}
//int main(){
//	int input[5] = { 0 ,5, 3, 4,5 };
//	char a[4];
//	backtrack(a, input, 0, 4);
//	return 0;
//	set<int> s;
//	
//}
#pragma endregion

#pragma region 八皇后
void process_solution(vector<vector<int>>& res)
{
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++){
			cout << " " << res[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void  construct_candidates(vector<vector<int>>&res, int r, vector<int> &candidates,int input){
	for (int col = 0; col < input; col++){
		bool isfit = true;
		for (int i = 1; r - i >= 0 && col - i >= 0; i++){
			if (res[r - i][col - i] == 1) {
				isfit = false;
			};
		}
		for (int i = 1; r - i >= 0 && col + i < input; i++){
			if (res[r - i][col + i] == 1) {
				isfit = false;
			}
		}
		for (int i = 1; r -i >=0; i++){
			if (res[r - i][col] == 1) {
				isfit = false;
			}
		}

		if (isfit){
			candidates.push_back(col);
		}
	}
}
void backtrack(vector<vector<int>>& res, int r, int end){
	if (r >=end){
		//process_solution(res);
	}
	else{
		
		r++;
		vector<int> candinates;
		construct_candidates(res, r, candinates, end+1);
		for (int i = 0; i < candinates.size(); i++){
			res[r][candinates[i]] = 1;
			backtrack(res, r, end);
			res[r][candinates[i]] = 0;
		}
	}
}
//int main(){
//	vector<vector<int>> res;
//	int n = 11;
//	for (int i = 0; i < n; i++){
//		vector<int>  cols;
//		for (int j = 0; j < n; j++){
//			cols.push_back(0);
//		}
//		res.push_back(cols);
//	}
//	backtrack(res, -1, n-1);
//}


#pragma endregion
#pragma endregion

#include <stdio.h>
#include <stdlib.h>
//class A{
//public:
//	int a = 9;
//	A(){ cout << "cotr" << endl; }
//	A(const  A& a){ cout << "Copy " << endl; }
//	A& operator = (const  A& a){ cout << "assign " << endl; return *this; }
//};
//void fun(int *pl, int *p2, int *&s)
//{
//	s = (int *)malloc(sizeof(int));
//	*s = *pl + *(p2++);
//	
//}

#pragma region 红黑树

class Node{
public:
	friend class RBTree;
	Node *left;
	Node *right;
	Node *p;
	int val;
	int size;//相同值出现的次数
	bool color;

	Node(int val) :val(val),size(0){}
};
class RBTree{
private:
	inline Node* Grandparent(Node *n){
		if (n == Nil || n->p == Nil || n->p->p == Nil) return  Nil;
		return n->p->p;
	};
	inline Node * Uncle(Node *n){
		if (n == Nil || n->p == Nil  ) return  Nil;
		if (n->p == Grandparent(n)->left)
			return Grandparent(n)->right;
		else
			return Grandparent(n)->left;
	}
	void LeftRotate(Node *x);//左旋
	void RightRotate(Node *x);//右旋
	void InsertFixUp(Node *&z);//插入后维护
	void InsertCase1(Node *z);
	void InsertCase2(Node *z);
	void InsertCase3(Node *z);
	void InsertCase4(Node *z);
	void InsertCase5(Node *z);
	//void DelteFixUp(Node *&z);//删除后维护
	//void Empty(Node *&z);//清空指定节点
	Node *Root, *Nil;//根节点，哨兵节点
	unsigned int NUM;//节点个数
	static bool BLACK;
	static bool RED;
public:
	RBTree(){
		Nil = new Node(-1);
		Nil->color = BLACK;
		Root = Nil;
		NUM = 0;
	}
	~RBTree(){
		delete Nil;
		//Empty(Root);
	}
	void Insert(int val);
	//void Delete(Node *& z);
	//void Delete(int val);
	//Node *Successor(Node *z);//返回指定节点的后继
	//Node* Predecessor(Node *x);//返回指定节点的前驱
	//Node * Minimum(Node  * x);//返回指定子树的最小值 
	//Node * Maximum(Node  * x);//返回指定子树的最大值 
	//Node* Search(Node  * x, int & k);//检索指定子树中是否存在指定值 
	//void  Print(Node  * &x);// 升序打印指定子树 
	//void  Print();// 升序打印整棵树 
	//Node* Minimum();//返回整棵树的最小值 
	//Node* Maximum();//返回整棵树的最大值 
	//Node* Search(int & k);//检索整棵子树中是否存在指定值 
	//void Empty();//清空整棵树 
	//bool IsEmpty();//判断树是否为空 
	//unsigned int Num(); //返回整棵树

};
bool  RBTree::BLACK = false;
bool  RBTree::RED = true;
void RBTree::Insert(int val){
	NUM++;
	Node *y = Nil, *x = Root;//y记录插入位置的父节点
	while (x != Nil&&val != x->val){
		y = x;
		if (val < x->val){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	if (x != NULL&&val == x->val){
		x->size++;
		return;
	}
	Node *z = new Node(val);
	if (y == Nil){
		Root = z;
	}
	z->p = y;
	if (z->val<y->val){
		y->left = z;
	}
	else{
		y->right = z;
	}
	z->left = Nil;
	z->right = Nil;
	z->color = RED;
	InsertFixUp(z);
}

void RBTree::InsertFixUp(Node * &n){
	
	InsertCase1(n);
}
void RBTree::InsertCase1(Node *n){
	if (n->p == Nil){
		n->color = BLACK;
	}
	else{
		InsertCase2(n);
	}
	
}
void RBTree::InsertCase2(Node *n){
	if (n->p->color == BLACK)
		return;
	else
		InsertCase3(n);
}
void RBTree::InsertCase3(Node *n){
	if (Uncle(n) != Nil&&Uncle(n)->color == RED){
		n->p->color = BLACK;
		Uncle(n)->color = BLACK;
		Grandparent(n)->color = RED;
		InsertCase1(Grandparent(n));
	}
	else{
		InsertCase4(n);
	}
}
void RBTree::InsertCase4(Node *n){
	if (n == n->p->right&&n->p == Grandparent(n)->left)
	{
		LeftRotate(n->p);
		n = n->left;
	}
	else if (n == n->p->left&&n->p == Grandparent(n)->right)
	{
		RightRotate(n->p);
		n = n->right;
	}
	InsertCase5(n);

}
void RBTree::InsertCase5(Node* n) {
	n->p->color = BLACK;
	Grandparent(n)->color = RED;
	if (n == n->p->left && n->p == Grandparent(n)->left) {
		RightRotate(Grandparent(n));
	}
	else {
		/* Here, n == n->parent->right && n->parent == grandparent(n)->right */
		RightRotate(Grandparent(n));
	}
}
void RBTree::LeftRotate(Node *h){
	Node *x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	x->p = h->p;
	h->p = x;
	h->color = RED;
}
void RBTree::RightRotate(Node *h){
	Node *x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	x->p = h->p;
	h->p = x;
	h->color = RED;
}
#pragma endregion

class ClassA
{
public:
	virtual ~ClassA(){};
	virtual void FunctionA(){};
};
class ClassB
{
public:
	virtual void FunctionB(){};
};
class ClassC : public ClassA, public ClassB
{
public:
};

#include <iostream>
#include <vector>
using namespace std;

bool is_a_solution(int sum, int m){
	if (sum == m) return true;
	return false;
}
void  construct_candidates(int cur, int n, int sum, vector<int> &candiantes){
	for (int i = cur + 1; i <= n; i++)
	{
		if (sum + i <= n) {
			candiantes.push_back(i);
		}
	}
}
int count1 = 0;
void backtrace(int cur, int n, int m, int sum, vector<int>& res)
{
	if (is_a_solution(sum, m)){
		/*for (size_t i = 0; i < res.size(); i++)
		{
			cout << res[i] << " ";
		}
		cout << endl;*/
	}

	else{
		
		if (sum > n) return;
		vector<int>candiantes;
		construct_candidates(cur, n, sum, candiantes);
		for (int i = 0; i < candiantes.size(); i++)
		{
			sum += candiantes[i];
			res.push_back(candiantes[i]);
			backtrace(candiantes[i], n, m, sum, res);
			sum -= candiantes[i];
			res.pop_back();
		}
	}
}
int main()
{
	int n, m;
	vector<int> res;
	cin >> n >> m;
	backtrace(0, n, m, 0, res);
	cout<<count1;
	return 0; 

}