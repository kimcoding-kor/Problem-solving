#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct bufferedreader{
    char* buffer;
    int i = 0;
    bufferedreader(){
        buffer = new char [2300005];
    }
    void readinput(){
        fread(buffer,1,2300005,stdin);
    }
    int readint(){
        int ret = buffer[i++] - '0';
        while(buffer[i] >= '0' && buffer[i] <= '9')
            ret *= 10, ret += buffer[i] - '0', i++;
        return i++, ret;
    }
    void clear(){
        delete[] buffer;
    }
}bufferedreader;
typedef struct unionfind{
    int *arr,*size;
    unionfind(int n){
        arr = new int [n];
        size = new int [n];
        for(int i=0;i<n;i++)
            arr[i] = i, size[i] = 1;
    }
    int find(int x){
        if(x == arr[x]) return x;
        return arr[x] = find(arr[x]);
    }
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(size[x] > size[y]) swap(x,y);
        arr[x] = y, size[y] += size[x];
    }
    void clear(){
        delete[] arr, delete[] size;
    }
}unionfind;
typedef struct p{
    int a,b,weight;
    bool operator<(const p& u){
        return weight > u.weight;
    }
}p;
int main(){
    bufferedreader br;
    br.readinput();
    int n = br.readint(),m = br.readint();
    unionfind uf(n + 1);
    p* edge = new p [m + 1];
    for(int i=1,a,b,w;i<=m;i++){
        a = br.readint(), b = br.readint(), w = br.readint();
        edge[i] = p{a,b,w};
    }
    int st = br.readint(), ed = br.readint();
    sort(edge + 1,edge + m + 1);
    for(int i=1;i<=m;i++){
        uf.merge(edge[i].a, edge[i].b);
        if(uf.find(st) == uf.find(ed)) {
            printf("%d\n",edge[i].weight);
            break;
        }
    }
    delete[] edge,br.clear(),uf.clear();
    return 0;
}