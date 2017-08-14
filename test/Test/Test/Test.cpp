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
//struct Graph{
//	vector<vector<int>> edges;
//	vector<string> vexs;
//	vector<bool> isvisit;
//
//};
//#define M 1000
//void create(Graph &g){
//	vector<int> a1 = { 0, 2, M, M, 10 };
//	vector<int> a2 = { M, 0, 3, M, 7 };
//	vector<int> a3 = { 4, M, 0, 4, M };
//	vector<int> a4 = { M, M, M, 0, 5 };
//	vector<int> a5 = { M, M, 3, M, 0 };
//	
//	g.edges.push_back(a1);
//	g.edges.push_back(a2);
//	g.edges.push_back(a3);
//	g.edges.push_back(a4);
//	g.edges.push_back(a5);
//	
//	g.vexs.push_back("1");
//	g.vexs.push_back("2");
//	g.vexs.push_back("3");
//	g.vexs.push_back("4");
//	g.vexs.push_back("5");
//	
//	for (int i = 0;i< g.vexs.size(); i++){
//		g.isvisit.push_back(false);
//	}
//}
//int getindex(const Graph &g,const string &vex){
//	for (int i = 0; i < g.vexs.size(); i++){
//		if (g.vexs[i] == vex){
//			return i;
//		}
//	}
//}
//string getvex(const Graph &g, int index){
//	return g.vexs[index];
//}
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
//int min_dist = INT_MAX;
//deque<int> min_path;
//void dfs(Graph &g, int cur_indx, int end_indx, int dst, deque<int>& path){
//	
//	if (dst > min_dist){
//		return;
//	}
//	if (cur_indx == end_indx){
//		if (min_dist > dst){
//			min_dist = dst;
//			min_path = path;
//			return;
//		}
//	}
//	for (int i = 0; i < g.edges[cur_indx].size(); i++){
//		if (!g.isvisit[i] && g.edges[cur_indx][i]<M){
//			path.push_back(i);
//			g.isvisit[i] = true;
//			dfs(g, i, end_indx, dst + g.edges[cur_indx][i], path);
//			g.isvisit[i] = false;
//			path.pop_back();
//		};
//	}
//}
//void find_min_path( Graph &g,const string &start,const  string &end){
//	int start_indx = getindex(g,start);
//	int end_indx = getindex(g,end );
//
//	deque<int> path;
//	path.push_back(start_indx);
//	dfs(g, start_indx, end_indx, 0, path);
//	
//	for (int i = 0; i < min_path.size(); i++){
//		cout << getvex(g, min_path[i]) << " ";
//	}
//
//}
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
//int main()
//{
//	int n, m;
//	vector<int> res;
//	cin >> n >> m;
//	backtrace(0, n, m, 0, res);
//	cout<<count1;
//	return 0; 
//
//}
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib ")

#pragma region String的实现
class  String
{
public:
	
	String(const char *str = NULL); // 普通构造函数 
	String(const String &other); // 拷贝构造函数 
	~String(void); // 析构函数 
	String & operator =(const String &other); // 赋值函数 
private:
	char *m_data; // 用于保存字符串 
};
String::String(const char *str){
	cout << "构造函数" << endl;
	if (str == NULL){
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else{
		int len = strlen(str);
		m_data = new char[len + 1];
		strcpy(m_data, str);
	}

}
String::String(const String &other){
	cout << "拷贝" << endl;
	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, other.m_data);
}
String & String::operator = (const String &other)
{
	cout << "赋值" << endl;
	if (this == &other){
		return *this;
	}
	delete[]m_data;
	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, other.m_data);
	return *this;
}
String::~String(void)
{
	delete[]m_data;
	m_data = NULL;
}
#pragma endregion

#pragma region 四则运算
int gettype(char c){
	if (c >= '0' || c<= '9')
	{
		return 0;
	}
	
	else  if (c == '+' || c == '-' || c == '*' || c == '/')
	{
		return 1;
	}
	else if (c == ')' || c == '（')
	{
		return 2;
	}
	else return 3;

}
int calc(int a, char op, int b){
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a *b;
	if (op == '/') return a /b;
}
 

//#include <iostream>
//#include <vector>
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
///*请完成下面这个函数，实现题目要求的功能*/
///*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
///******************************开始写代码******************************/
////找出下个涨幅最大的的股票
//// n 股票数
////m当前的交易期
//int find_next(int n, int m, const vector<vector<double>>& prices)
//{
//	int max_index = 0;
//	double mx_ic = 0;
//	for (int i = 0; i < n; i++)
//	{
//		double ic = (prices[m + 1][i] - prices[m][i]) / prices[m ][i];
//		if (ic>mx_ic)
//		{
//			mx_ic=ic ;
//			max_index = i;
//		}
//	}
//	return max_index;
//}
//double StockGod(int n, int m, double p, const vector<vector<double>>& prices)
//{
//	double cash = 1;
//
//	for (int i = 0; i < m-1; ++i)
//	{
//		int indx=find_next(n, i, prices);
//		cash = cash / prices[i][indx] * prices[i+1][indx]*(1-p);
//	}
//	return cash;
//}
///******************************结束写代码******************************/
//
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	double p = 0;
//	cin >> n >> m >> p;
//
//	vector<vector<double>> prices;
//	for (int i = 0; i < m; ++i) {
//		prices.push_back(vector<double>());
//		for (int j = 0; j < n; ++j) {
//			double x = 0;
//			cin >> x;
//			prices.back().push_back(x);
//		}
//	}
//
//	double final = StockGod(n, m, p, prices);
//	printf("%.1f\n", final);
//
//	return 0;
//}

//#include <map>
//#include <vector>
//#include <queue>
//#include <stdlib.h>
//#include <stdio.h>
//#include <iostream>
//using namespace std;
///*
//a
///  \
//b    c
/// \  /  \
//d   e f   g
//\  / \
//h j   i
//\
//k
//\
//l
//a:托马斯（Thomas）
//b:艾德华（Edward）
//c:亨利（Henry）
//d:高登（Gordon）
//e:詹姆士（James）
//f:培西（Percy）
//g:托比（Toby）
//h:达克（Duke）
//j:唐纳德&道格拉斯（Donald&Douglas）
//j:奥利佛（Oliver）
//k:亚瑟（Arthur）
//l:艾蜜莉（Emily）
//*/
//
//struct BT
//{
//	int key;
//	BT *l, *r;
//};
//
//BT* create_n(int key)
//{
//	BT *b = new BT;
//	b->key = key - 'a';
//	b->l = NULL;
//	b->r = NULL;
//}
//BT *key_node = NULL;
////找到该节点
//void find(BT* root, int key){
//	if (root){
//		find(root->l, key);
//		find(root->r, key);
//		if (key == root->key)
//		{
//			key_node = root;
//		}
//	}
//}
////
//vector<BT*> path;//
//int  min_high(BT* root){
//	if (root == NULL)
//		return 0;
//	
//	int lh = min_high(root->l), rh = min_high(root->l);
//	if (lh<rh)
//	{
//		if (root->l){
//			path.push_back(root->l);
//		}
//		
//		return lh + 1;
//		
//	}
//	else{
//		if (root->r){
//			path.push_back(root->r);
//		}
//		return rh + 1;
//	}
//}
//bool train_schedule(BT* rt, int index)
//{
//	if (!rt)
//		return false;
//
//	map<int, string> m_train;
//	m_train[0] = "Thomas";
//	m_train[1] = "Edward";
//	m_train[2] = "Henry";
//	m_train[3] = "Gordon";
//
//	m_train[4] = "James";
//	m_train[5] = "Percy";
//	m_train[6] = "Toby";
//	m_train[7] = "Duke";
//
//	m_train[8] = "Donald&Douglas";
//	m_train[9] = "Oliver";
//	m_train[10] = "Arthur";
//	m_train[11] = "Emily";
//	//TODO:write the real train schedule code here 
//	find(rt, index);
//	min_high(key_node);
//	for (int i = 0; i < path.size(); i++)
//	{
//		cout << m_train[path[i]->key] << endl;
//	}
//	return true;
//}
//int main()
//{
//	int i = 0;
//	BT *rt = create_n('a');
//	rt->l = create_n('b');
//	rt->r = create_n('c');
//	rt->l->l = create_n('d');
//	rt->l->r = create_n('e');
//	rt->r->l = create_n('f');
//	rt->r->r = create_n('g');
//	rt->r->l->r = create_n('h');
//	rt->r->r->r = create_n('i');
//	rt->r->r->l = create_n('j');
//	rt->r->r->l->r = create_n('k');
//	rt->r->r->l->r->r = create_n('l');
//	std::cin >> i;
//
//	train_schedule(rt, i);
//	return 0;
//}
//class Solution {
//public:
//	/**
//	* @param nums: A list of integers
//	* @return: A list of integers includes the index of the first number
//	*          and the index of the last number
//	*/
//	vector<int> subarraySum(vector<int> nums){
//		vector<int> res;
//		vector<vector<int>> L(nums.size(), vector<int>(nums.size(), INT_MIN));
//		for (int i = 0; i < nums.size(); i++)
//		{
//			L[i][i] = nums[i];
//		}
//		for (int i = 0; i < nums.size(); i++)
//		{
//			for (int j = i+1; j < nums.size(); j++)
//			{
//				L[i][j] = L[i][j - 1] + nums[j];
//			}
//		}
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//			for (int j = i ; j < nums.size(); j++)
//			{
//				if (L[i][j] == 0)
//				{
//
//					res.push_back(i);
//					res.push_back(j);
//				}
//
//			}
//		}
//		return res;
//	}
//};


class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;

	}

};

 struct RandomListNode {
     int label;
    RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };


 class TreeNode {
	 public:
		 int val;
		 TreeNode *left, *right;
		 TreeNode(int val) {
			 this->val = val;
			 this->left = this->right = NULL;
			 
		 } 
 };
#include <unordered_set	>
 
 
  struct DirectedGraphNode {
      int label;
      vector<DirectedGraphNode *> neighbors;
      DirectedGraphNode(int x) : label(x) {};
 };
 
  //class Solution {
  //public:
	 // /**
	 // * @param start, a string
	 // * @param end, a string
	 // * @param dict, a set of string
	 // * @return an integer
	 // */
	 //
	 //
	 // vector<vector<string>> res;
	 //
	 // bool is_mutationOne(const string& seq1, const string& seq2)
	 // {
		//  if (seq1.length() != seq2.length())
		//  {
		//	  return false;
		//  }

		//  int num = 0;
		//  for (int i = 0; i < seq1.length(); i++)
		//  {
		//	  if (seq1[i] != seq2[i])
		//	  {
		//		  num++;
		//		  if (num > 1) return false;
		//	  }
		//  }
		//  if (num == 1) return true;
		//  else return false;
	 // }
	 // void get_cands(unordered_set<string> & dict, string & start,vector<string>& cands)
	 // {

		//  for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++)
		//  {

		//	  if (is_mutationOne(start, *it))
		//	  {
		//		  cands.push_back(*it);
		//	  }
		//  }

	 // }
	 // int  BFS(unordered_set<string> &dict,string &start, string &target)
	 // {
		//  queue<vector<string>> cand_str;
		//  std::vector<std::vector<std::string>> result;
		//  
		// 
		//  bool foundShortest = false;
		//  size_t shortest = 0;
		// 
		//  cand_str.push({ start });
		//  int pre_len = 0;
		//  unordered_set<string> used_words;
		//  while (!cand_str.empty())
		//  {
		//	  vector<string> cur = cand_str.front();
		//	  cand_str.pop();    
		//	  if (pre_len<cur.size())//进行到下一层了
		//	  {
		//		  pre_len = cur.size();
		//		  for (auto iter = used_words.begin(); iter != used_words.end(); ++iter)
		//		  {
		//			  dict.erase(*iter);
		//		  }
		//		  used_words.clear();
		//	  }

		//	  if (foundShortest && cur.size() >= shortest)
		//	  {
		//		  break;
		//	  }
		//	  vector<string> cands;
		//	  get_cands(dict, cur.back(), cands);
		//	 
		//	  for (int i = 0; i < cands.size(); i++)
		//	  {
		//		  used_words.insert(cands[i]);
		//		  cur.push_back(cands[i]);
		//		  cand_str.push(cur);
		//		  
		//		  if (cands[i] == target)
		//		  {
		//			  return cur.size();
		//			  foundShortest = true;
		//			  shortest = cur.size();
		//			  res.push_back(cur);
		//		  }
		//		  cur.pop_back(); 
		//	  }
		//	  
		//	 
		//  }
		//  return 0;

	 // }
	 // int  ladderLength(string start, string end, unordered_set<string> &dict) {
		//  // write your code here
		//  dict.insert(end);
		//  return BFS(dict, start, end);
		//  //return res;
	 // }
	
	 // 
  //};
class Solution {
public:
	/**
	* @param tokens The Reverse Polish Notation
	* @return the value
	*/
	int evalRPN(vector<string>& tokens) {
		// Write your code here
		stack<int> s;
		int res;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				if (tokens[i] == "+")
				{
					s.push(a + b);

				}
				else if(tokens[i] == "-")
				{
					s.push(a - b);
				}
				else if (tokens[i] == "*")
				{
					s.push(a * b);
				}
				else if (tokens[i] == "/")
				{
					s.push(a / b);
				}

			}
			else
			{
				s.push(std::stoi(tokens[i]));
			}
		}
		return s.top();

	}
};
class WidgetImpl{
public:
private:
	int a, b, c;
	std::vector<double>v;
};
class Widget{
public:
	Widget(const Widget&rhs);
	Widget&operator = (const Widget& rhs)
	{
		*pImpl = *(rhs.pImpl);
	}
	void swap(Widget &other)
	{
		using std::swap;
		swap(pImpl, other.pImpl);
	}
private:
	WidgetImpl* pImpl;
};

template<class T>
class auto_ptr {
public:
	explicit auto_ptr(T *p = 0) : pointee(p) {}
	template<class U>
	auto_ptr(auto_ptr<U>& rhs) : pointee(rhs.release()) {}
	~auto_ptr() { delete pointee; }
	template<class U>
	auto_ptr<T>& operator=(auto_ptr<U>& rhs)
	{
		if (this != &rhs) reset(rhs.release());
		return *this;
	}
	T& operator*() const { return *pointee; }
	T* operator->() const { return pointee; }
	T* get() const { return pointee; }
	T* release()
	{
		bbs.theithome.comT *oldPointee = pointee;
		pointee = 0;
		return oldPointee;
	}
	void reset(T *p = 0)
	{
		if (pointee != p) {
			delete pointee;
			pointee = p;
		}
	}
private:
	T *pointee;
	//template<class U> friend class auto_ptr<U>;
};
#include<thread>
class A{
	
public:
	int a=0;
	void task()
	{
		cout << a << endl;
	}
};

#include<windows.h>
#pragma comment(lib,"Ws2_32.lib")
class CClient{
private :
	SOCKET m_socket;
public :
	int Connect(int port, const char *address)
	{
		int rlt = 0;
		int iErrMsg;
		WSAData wsaData;
		iErrMsg = WSAStartup(MAKEWORD(1, 1), &wsaData);
		if (iErrMsg != NO_ERROR)
		{
			return iErrMsg;
		}
		m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (m_socket == INVALID_SOCKET)
		{
			return -1;
		}
		
		sockaddr_in server;
		server.sin_family = AF_INET;
		server.sin_port = port;
		server.sin_addr.S_un.S_addr = inet_addr(address);
		iErrMsg = connect(m_socket, (sockaddr*)&server, sizeof(server));
		return iErrMsg;
	}
	int SendMsg(const char* msg, int len)
	{
		int rlt = 0;
		int iErrMsg=0;
		iErrMsg = send(m_socket, msg, len, 0);
		return iErrMsg;

	}
	void Close()
	{
		closesocket(m_socket);
	}
};


class CServer
{
private:
	SOCKET m_socket;
public:
	int Init(const char* address, int port)
	{
		int rlt = 0;
		int iErrMsg;
		WSAData wsaData;
		iErrMsg = WSAStartup(MAKEWORD(1, 1), &wsaData);
		if (iErrMsg != NO_ERROR)
		{
			return iErrMsg;
		}
		m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (m_socket == INVALID_SOCKET)
		{
			return -1;
		}
		sockaddr_in server;
		server.sin_family = AF_INET;
		server.sin_port = port;
		server.sin_addr.S_un.S_addr = inet_addr(address);
		iErrMsg = ::bind(m_socket, (sockaddr*)&server, sizeof(server));
		
		return iErrMsg;
	}
	void Run()
	{
		listen(m_socket, 5);
		sockaddr_in tcpAddr;
		SOCKET newSocket;
		int len = sizeof(sockaddr_in);
		char buff[1024];
		int rval;
		do{
			newSocket = accept(m_socket, (sockaddr*)&tcpAddr, &len);
			if (newSocket == INVALID_SOCKET)
			{
			}
			else
			{
				do{
					memset(buff, 0, sizeof(buff));
					rval = recv(newSocket, buff, 1024, 0);
					if (rval == SOCKET_ERROR)
					{
						
					}
					//cout << buff << endl;
				} while (rval!=0);
				closesocket(newSocket);
			}
		
		} while (true);
		closesocket(m_socket);
	}
};
struct R {
	int r1;
	virtual void pvf(){}; // new
	virtual void rvf(){}; // new
};
struct P {
	int p1;
	void pf(){}; // new
	virtual void pvf(){}; // new
};
struct S : P, R {
	int s1=1;
	void pvf(){ cout << "S::pvf" <<s1<< endl; }; // overrides P::pvf and R::pvf
	void rvf(){ cout << "S::rvf" << endl; }; // overrides R::rvf
	void svf(){ cout << "S::svf" << endl; }; // new
};
template <typename T>
T &getItem(T begin ) {
	return *begin; // 返回序列中一个元素的引用
}
//void main()
//{
//	int a = 1, *b = &a;
//	getItem<int*>(b);
//	//typedef void(*fp)(void);
//	//S s; S* ps = &s;
//	///*int _vfptr_addr =(*(int*)ps);
//	//int _vfptr_fn_0_addr = *((int *)_vfptr_addr);
//	//int _vfptr_fn_1_addr = *((int *)(_vfptr_addr+4));
//
//	//fp f0 = (fp)_vfptr_fn_0_addr;
//	//f0();*/
//	//
//	//P* pp = (P*)ps;
//	//R* pr = (R*)ps;
//
//	//int _vfptr_addr = (*(int*)pr);
//	//int _vfptr_fn_0_addr = *((int *)_vfptr_addr);
//	//int _vfptr_fn_1_addr = *((int *)(_vfptr_addr + 4));
//
//	//fp f0 = (fp)_vfptr_fn_0_addr;
//	//f0();
//	//fp f1 = (fp)_vfptr_fn_1_addr;
//	//f1();
//	//
//	//((P*)ps)->pvf(); // (*(P*)ps)->P::vfptr[0])((S*)(P*)ps)
//	//((R*)ps)->pvf(); // (*(R*)ps)->R::vfptr[0])((S*)(R*)ps)
//	//ps->pvf(); // one of the above; calls S::pvf()
//	
//	/*CServer server;
//	
//	if (server.Init("127.0.0.1", 8888) == 0)
//	{
//		server.Run();
//	}*/
//
//	CClient client;
//	client.Connect(8888, "127.0.0.1");
//	char buf[1024];
//	memset(buf, '9', sizeof(buf));
//	while (true){
//		
//		client.SendMsg(buf, sizeof(buf));
//	}
//	
//	client.Close();
//	
//	//vector<int> a = { 3, 1, 2, 3, 2, 3, 3, 4, 4, 4 };
//
//	/*string chiefs[5] = { "1", "2", "3", "34", "44" };
//	foo();
//
//	Base* p1 = new Derived(1);
//	delete p1;
//	 Derived(1);*/
//	
//	
//
//	
//	vector<int> v = { 1,2,3 };
//	string start = "hit";
//
//	string end = "cog";
//	unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
//	//unordered_set<string> dict = { "si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye" };
//	//unordered_set<string> dict = { "kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay", "sip", "kay", "per", "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die", "war", "hay", "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali", "pay", "col", "gum", "ger", "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui", "ark", "has", "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu", "ana", "gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh", "sew", "ono", "tam", "flu", "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax", "jim", "san", "pan", "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye", "oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot", "bow", "fob", "for", "joe", "ivy", "fan", "age", "fax", "hip", "jib", "mel", "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm", "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk", "far", "mew", "wit", "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy", "nag", "ron", "soy", "gin", "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop", "but", "orb", "fen", "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew", "web", "hod", "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub", "ere", "dig", "era", "cat", "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam", "new", "aye", "ani", "and", "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip", "cup", "dye", "lyx", "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set", "qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas", "pro", "few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may", "shy", "rid", "bat", "sum", "rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox", "ibo", "hey", "saw", "vim", "sec", "ltd", "you", "its", "tat", "dew", "eva", "tog", "ram", "let", "see", "zit", "maw", "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam", "zoo", "any", "dow", "cod", "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao", "aug", "mum", "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who", "bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur", "ada", "bin", "nil", "mia", "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax", "mid", "tad", "ken", "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin", "mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi", "yep", "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig", "sly", "rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum", "rio", "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw", "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw", "eel", "dix", "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt", "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode", "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism", "err", "him", "all", "pad", "hah", "hie", "aim", "ike", "jed", "ego", "mac", "baa", "min", "com", "ill", "was", "cab", "ago", "ina", "big", "ilk", "gal", "tap", "duh", "ola", "ran", "lab", "top", "gob", "hot", "ora", "tia", "kip", "han", "met", "hut", "she", "sac", "fed", "goo", "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig", "cid", "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref", "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned", "coo", "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid", "mai", "sup", "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax", "aft", "alb", "len", "air", "pug", "pox", "vow", "got", "meg", "zoe", "amp", "ale", "bud", "gee", "pin", "dun", "pat", "ten", "mob" };
//	//Solution s;
//	//s.evalRPN(vector<string>{ "0", "3", "/" });
//	
//}
#/*include "iostream"
#include "queue"
#define N 100005

using namespace std;

int n, a[N], b[N];
void f( vector<int> &v ,int k)
{
	vector<int> res(v.begin(),v.end());
	for (int i = 0; i < k; i++){
		int idx = 0;
		int left_idx = v.size()/2-1,right_idx=v.size()-1;
		for (int j = 0; j < v.size() / 2; j++)
		{
			res[idx++] = v[right_idx - j];
			res[idx++] = v[left_idx - j];
		}
	}
	std::reverse(res.begin(), res.end());
	v = res;
	for (int i = 0; i < v.size(); i++){
		cout << v[i]<<" ";
	}
	cout << endl;
	
}*/
//int main() {
//	int t;
//	cin >> t;
//	while (t--){
//		int n, k;
//		cin >> n>>k;
//		vector<int > v;
//		for (int i = 0; i < 2*n; i++){
//			int  c;
//			cin >> c;
//			v.push_back(c);
//		}
//		f(v, k);
//	}
//	
//	
//}

struct point{
	int x;
	int y;
	bool operator<(const point& p2)const
	{
		if (x < p2.x || (x == p2.x&&y < p2.y))
			return true;
		else
			return false;
	}
	bool operator==(const point &p2)const
	{
		return (x == p2.x&&y == p2.y);
	}

};
struct segment{
	point p1, p2;
};
bool is_rect(vector<segment>& ss)
{
	set<point> se;
	for (int i = 0; i < ss.size(); i++){
		se.insert(ss[i].p1);
		se.insert(ss[i].p2);
		
	}
	if (se.size()>4) return false;
	for (int i = 0; i < ss.size(); i++){
		for (int j = i + 1; j < ss.size(); j++){
			if ((ss[i].p1.x - ss[i].p1.x)*(ss[i].p2.x - ss[i].p2.x) == (ss[i].p1.y - ss[i].p1.y)*(ss[i].p2.y - ss[i].p2.y)){ continue; }//平行
			if ((ss[i].p1.x - ss[i].p1.x)*(ss[i].p2.x - ss[i].p2.x) == -(ss[i].p1.y - ss[i].p1.y)*(ss[i].p2.y - ss[i].p2.y)){ continue; }//垂直
			return false;
		}
	}
	return true;
}
vector<segment> res;
void trace_back(vector<segment>&ss, vector<segment>&re){
	if (re.size() == 4 && is_rect(re)){
		res = re;
		return;
	}
	else if (re.size() > 4) return;
	else
	{
		for (int i = 0;i < ss.size(); i++){
			segment s = ss[i];
			ss.pop_back();
			re.push_back(s);

			trace_back(ss, re);

			re.pop_back();
			ss.push_back(s);

		}
	}

}
//int main() {
//	int n;
//	cin >> n;
//	vector<segment> ss;
//	vector<segment>re;
//	while (n--){
//		segment s;
//		cin >> s.p1.x >> s.p1.y >> s.p2.x >> s.p2.y;
//		ss.push_back(s);
//	}
//	trace_back(ss, re);
//	
//	vector<point> v;
//	for (int i = 0; i < res.size(); i++){
//		v.push_back(res[i].p1);
//		v.push_back(res[i].p2);
//	}
//	sort(v.begin(), v.end());
//	
//
//}



//struct Val{
//	long long min_val;
//	long long max_val;
//	Val(){
//		min_val = 0;
//		max_val = 0;
//	}
//};
//int main(){
//	int n, k, d;
//	cin >> n;
//	vector<int > a;
//	
//	for (int i = 0; i<n;i++){
//		int t;
//		cin >> t;
//		
//		a.push_back(t);
//	}
//	cin >> k >> d;
//	
//	vector<vector<Val>> dp(n, vector<Val>(k));
//	for (int i = 0; i < n; i++){
//		dp[i][0].max_val = a[i];
//		dp[i][0].min_val = a[i];
//	}
//
//	
//	for (int ki = 1; ki < k; ki++){
//	    for (int i = 0; i < n; i++){
//		    dp[i][ki] = dp[i][ki - 1];
//			
//			for (int j = 0; j < i; j++){
//				if (i - j > d) continue;
//				dp[i][ki].max_val = max(dp[i][ki].max_val, max(dp[j][ki - 1].max_val * a[i], dp[j][ki - 1].min_val * a[i]));
//				dp[i][ki].min_val = min(dp[i][ki].min_val, min(dp[j][ki - 1].max_val * a[i], dp[j][ki - 1].min_val * a[i]));
//				
//			}
//			
//		}
//	}
//	/*for (int i = 0; i < n; i++){
//		for (int  j = 0; j < k; j++){
//			cout << "(" << dp[i][j].max_val << "," << dp[i][j].min_val << "),\t"<<setw(4);
//		}
//		cout << endl;
//	}*/
//	long long max_val = 0;
//	for (int i = 0; i < dp.size(); i++){
//		cout << dp[i][k - 1].max_val << endl;
//		if (max_val < dp[i][k - 1].max_val)
//		{
//			max_val = dp[i][k - 1].max_val;
//		}
//	}
//
//	cout << max_val << endl;
//	return 0;
//}
//int gcd(int a, int b)
//{
//	if (a < b){
//		swap(a, b);
//	}
//	while (a)
//	{
//		a = a%b;
//		if (a == 0) return b;
//		if (a < b){
//			swap(a, b);
//		}
//	}
//	return 1;
//}
//int main(){
//	int n, a;
//
//	cin >> n >> a;
//	
//	for (int i = 0; i < n; i++)
//	{
//		int b;
//		cin >> b;
//		if (a >= b){
//			a += b;
//		}
//		else{
//			a += gcd(a, b);
//		}
//	}
//
//	cout << a << endl;
//
//
//}

//bool is_attacked(int R, int x1, int y1, int  x0, int y0)
//{
//	return ((x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0) <= R*R);
//}
//int main()
//{
//	int  R, x1, y1, x2, y2, x3, y3, x0, y0;
//	cin >> R>>x1>> y1>> x2>> y2>> x3>> y3>> x0>> y0;
//	int count = 0;
//	if (is_attacked(R, x1, y1, x0, y0)){
//		count++;
//	}
//	if (is_attacked(R, x2, y2, x0, y0)){
//		count++;
//	}
//	if (is_attacked(R, x3, y3, x0, y0)){
//		count++;
//	}
//	cout << count << "x" << endl;
//	return 0;
//}
int cl(vector<vector<int>> t, int x, int y){
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++){
		for (int j = y - 1; j<= y + 1; j++){
			if (i < 0 || j < 0 || i>=t.size()||j>=t[0].size()){ continue; }
			if (t[i][j]>0){
				count++;
				t[i][j]--;
			}
		}

	}
		return count;
	}
	/*int main()
	{
		int N, M, K; cin >> N >> M >> K;
		vector<vector<int>> a(N, vector<int>(M, 0));
		for (int i = 0; i < K; i++){
			int x, y;
			cin >> x >> y;
			a[x-1][y-1]++;
		}
		int max_val = 0;
		int count1 = 0;
		for (int x1 = 0; x1 < N; x1++)
		{
			for (int y1 = 0; y1 < M; y1++)
			{
				vector<vector<int>> t = a;
				count1 = cl(t, x1, y1);

				
			}
		}
		for (int x2 = 0; x2 < N; x2++)
		{
			for (int y2 = 0; y2 < M; y2++)
			{
				int count2 = cl(t, x2, y2);

				if (max_val < count1 + count2)
				{
					max_val = count1 + count2;
				}
			}
		}
		cout << max_val << endl;
		return 0;

	
}*/

template<class T>
class SmartPtr{
public:
	SmartPtr(T* p = NULL) :ptr(p), ref_count(new size_t(1))
	{
		cout << "new" << endl;
	}
	SmartPtr(const SmartPtr &other){
		if (this != &other){
			ptr = other.ptr;
			ref_count=other.ref_count;
			(*ref_count)++;
		}
		
	}
	SmartPtr& operator=(const SmartPtr &other ){
		if (this != &other){
			release();
			ptr = other.ptr;
			ref_count = other.ref_count;
			(*ref_count)++;
		}
		return *this;
	}
	T* operator->(){
		if (ptr){
			return ptr;
		}
	}
	T& operator *(){
		if (ptr){
			return *ptr;
		}
	}
	~SmartPtr(){
		release();
	}
private :
	void release()
	{
		if (ptr){
			if ((--(*ref_count)) == 0){
				delete ref_count;
				delete ptr;
				cout << "delete" << endl;
			}
		}
	}
	T *ptr;
	size_t * ref_count;
};

void f1(void){
	cout << "";
}
class Base{
public:
	int a = 1;

	virtual void f1(){
		cout << "Base::f1()" << endl;
	}
	virtual void f2(){
		cout << "Base1::f2()" << endl;
	}
};

class Base1 :public virtual Base {
public:
	int b=2;
	
	virtual void f3(){
		cout << "Base1::f3()" << endl;
	}
	
};



class Base2 :public virtual Base {
public:
	int c = 3;

	virtual void f3(){
		cout << "Base2::f3()" << endl;
	}

};

class Derived : public Base1, public Base2{
	int  d = 4;
	void f1(){
		cout << "Derived::f1()" << endl;
	}

	void f3(){
		cout << "Derived::f3()" << endl;
	}
};

bool is_slution(vector<int>&re){
	int sum = 0;
	int mul = 1;
	for (int i = 0; i < re.size(); i++){
		
			sum += re[i];
			mul *= re[i];
		
	}
	if (sum>mul){
		return true;
	}
	else{
		return false;
	}
	

}
/*
int n;
cin >> n;
vector<int> A;
int sum = 0;
for (int i = 0; i < n; i++){
int t;
cin >> t;
A.push_back(t);
sum += t;
}
vector<int >a(sum / 2 + 1, 0);
for (int i = 0; i < A.size(); i++){
for (int j = sum / 2; j >= 1; j--){
if (A[i] <= j){
a[j] = max(a[j], a[j - A[i]] + A[i]);
}
}
}
cout << a[sum / 2] << endl;
if (a[sum / 2] == sum - a[sum / 2])

cout << sum / 2 << endl;
else
cout << -1 << endl;
return 0;*/

using std::bitset;
using namespace std;
int main()
{
	string s; cin >> s;

	int max_l = 0;
	int cur_l = 1;
	for (int i = 1; i < s.size(); i++){
		if (s[i] != s[i - 1]){
			cur_l++;
			if (max_l < cur_l){
				max_l = cur_l;
			}
		}
		else{
			cur_l = 1;
		}
	}
	cout << max_l << endl;


}






