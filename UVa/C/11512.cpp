#include <bits/stdc++.h>

using namespace std;

#define MAX_CHAR 1002

string sigma, s;
int sigmaSize = 40;

struct Node{
  int depth, begin, end, suffixIndex;
  int children[40];
  int parent, suffixLink;

  Node(){}

  Node(int begin, int end, int depth, int parent, int suf){
    for(int i = 0; i < sigmaSize; ++i)
      children[i] = -1;
    this->begin = begin;
    this->end = end;
    this->parent = parent;
    this->depth = depth;
    suffixLink = -1;
    suffixIndex = suf;
  }

  bool contains(int d){
    return depth <= d && d < depth + (end - begin);
  }

  int length(){
    return end - begin;
  }
};

vector<Node> tree(3000);

string get(int l, int r){
  int i;
  string cad = "";

  for(i = l; i < r; ++i)
    cad.push_back(s[i]);

  return cad;
}

void suffixIndexDFS(int n, string ac){
  int i;
  bool leaf = true;

  printf("Nodo %d %d\n", tree[n].begin, tree[n].end);
  ac += get(tree[n].begin, tree[n].end);

  for(i = 0; i < sigmaSize; i++){
    if(tree[n].children[i] != -1){
      leaf = false;
      suffixIndexDFS(tree[n].children[i], ac);
    }
  }

  if(leaf)
    printf("Hoja %d %d %s [%d]\n", tree[n].begin, tree[n].end, ac.c_str(), tree[n].suffixIndex);
}

void buildSuffixTree(){
  int n = s.length(), i, cur, curDepth, k, end, lastRule, remSuffix;
  int *a = new int[n];
  int curr, pos = 0, activeNode = -1;

  for(i = 0; i < n; i++)
    a[i] = sigma.find(s[i]);
  curr = pos;
  tree[pos++] = Node(0, 0, 0, 0, -1); 
  tree[0].suffixLink = 0;
  
  lastRule = remSuffix = 0;

  for(i = 0; i < n; ++i){
    cur = a[i];

    while(remSuffix <= i){
      curDepth = i - remSuffix;

      if(lastRule != 3){
	if(tree[curr].suffixLink != -1)
	  curr = tree[curr].suffixLink;
	else
	  curr = tree[tree[curr].parent].suffixLink;

	k = remSuffix + tree[curr].depth;
	while(curDepth > 0 && !tree[curr].contains(curDepth - 1)){
	  k += tree[curr].end - tree[curr].begin;
	  curr = tree[curr].children[a[k]];
	}
      }

      if(!tree[curr].contains(curDepth)){
	if(activeNode != -1){
	  tree[activeNode].suffixLink = curr;
	  activeNode = -1;
	}

	if(tree[curr].children[cur] == -1){
	  tree[pos++] = Node(i, n, curDepth, curr, i);
	  tree[curr].children[cur] = pos - 1;
	  lastRule = 2;
	}
	else{
	  curr = tree[curr].children[cur];
	  lastRule = 3;
	  break;
	}
      }
      else{
	end = tree[curr].begin + curDepth - tree[curr].depth;

	if(a[end] != cur){
	  tree[pos++] = Node(tree[curr].begin, end, tree[curr].depth, tree[curr].parent, -1);
	  int newn = pos - 1;
	  tree[pos++] = Node(i, n, curDepth, newn, i);
	  tree[newn].children[cur] = pos - 1;
	  tree[newn].children[a[end]] = curr;
	  tree[tree[curr].parent].children[a[tree[curr].begin]] = newn;

	  if(activeNode != -1)
	    tree[activeNode].suffixLink = newn;
	  tree[curr].begin = end;
	  tree[curr].depth = curDepth;
	  tree[curr].parent = newn;
	  curr = activeNode = newn;
	  lastRule = 2;
	}
	else if(tree[curr].end != n || (tree[curr].begin - tree[curr].depth) < remSuffix){
	  lastRule = 3;
	  break;
	}
	else
	  lastRule = 1;
      }

      remSuffix += 1;
    }
  }
  
  tree[0].suffixLink = -1;
  //solo para imprimir
 //suffixIndexDFS(0, "");
}


int distMax, nodoMax, maxlen;
string res;
Node noderes = Node();
int maxtimes = 0;
void DFS(int n, int father, string ac, int len){
  bool leaf = true;
  int times = 0;
  for(int i = 0; i < sigmaSize; i++){
      if(tree[n].children[i] != -1){
          times += 1;
          leaf = false;
      }
  }
  if(!leaf && tree[n].begin != -1){
    ac += get(tree[n].begin, tree[n].end);
    len += tree[n].length(); 
    int temp = len;
    if(temp >= maxlen){
            if(temp != maxlen){
                res = ac;
                noderes = tree[n];
                maxtimes = times;
            }
            maxlen = temp;
    }
  }

  for(int i = 0; i < sigmaSize; i++){
    if(tree[n].children[i] != -1){
      DFS(tree[n].children[i], n, ac, len);
    }
  }

} 

int main(){

    sigma = "ACGT$";
    sigmaSize = sigma.length();
    int cases;
    cin >> cases;
    while(cases--){

        cin >> s;
        distMax = 0; 
        maxlen = 0;
        res = "";
        s += "$";
        noderes = Node();
        maxtimes = 0;
        buildSuffixTree();

        DFS(0, 0, "", 0);

        if(maxtimes > 0){
            cout << res << " " <<  maxtimes << endl;
        }else{
            cout << "No repetitions found!" << endl;

        }

      tree = vector<Node> (3000);
    }
  
  return 0; 
} 
